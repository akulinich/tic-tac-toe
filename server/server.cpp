#ifndef SERVER_CPP
#define SERVER_CPP
#include "server.h"

#include <iostream>

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>
#include <QtDebug>


QDataStream& operator<<(QDataStream& stream, UserInfo& info) {
    stream << info.type_of_package;
    if (info.type_of_package == 1) {
        stream << info.x << info.y << info.side << info.player;
    }

    if (info.type_of_package == 2) {
        stream << info.decision << 0 << 0 << 0;
    }
    return stream;
}

QDataStream& operator>>(QDataStream& stream, UserInfo& info) {
    stream >> info.type_of_package;
    if (info.type_of_package == 1) {
        stream >> info.x >> info.y >> info.side >> info.player;
    }

    if (info.type_of_package == 2) {
        int fake;
        stream >> info.decision >> fake >> fake >> fake;
    }
    return stream;
}

Server::Server(int port, QWidget* widget) : QWidget(widget) {
    qDebug() << "constructor";
    server = new QTcpServer(this);
    if (!server->listen(QHostAddress("10.7.8.47"), port)) {
            QMessageBox::critical(this, tr("Server Erorr"),
                              tr("Unable to start the server: %1.")
                              .arg(server->errorString()));
            close();
            return;
    }
    set_players = new QPushButton("Connect players");
    clear_players = new QPushButton("Clear players");

    state = PLAYERS_NOT_SETED;


    // layout
    QVBoxLayout* main_layout = new QVBoxLayout;

    server_state_info = new QLabel("PLayers not seted");

    all_avaliable_players = new QListWidget;
    choosen_players = new QListWidget;

    QHBoxLayout* lists_of_player_layout = new QHBoxLayout;
    lists_of_player_layout->addWidget(choosen_players);
    lists_of_player_layout->addWidget(all_avaliable_players);

    QHBoxLayout* list_of_buttons = new QHBoxLayout;
    list_of_buttons->addWidget(clear_players);
    list_of_buttons->addWidget(set_players);

    main_layout->addWidget(server_state_info);
    main_layout->addLayout(lists_of_player_layout);
    main_layout->addLayout(list_of_buttons);

    setLayout(main_layout);


    // connections
    connect(server, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
    connect(set_players, SIGNAL(clicked()), this, SLOT(slotSetNewPlayers()));
    connect(clear_players, SIGNAL(clicked()), this, SLOT(slotResetPlayers()));
    connect(all_avaliable_players, SIGNAL(itemClicked(QListWidgetItem*)),
        this, SLOT(slotAddPlayerInChoosenList(QListWidgetItem*)));
}

/////////////////////////////
// manipulations with players

void Server::slotNewConnection() {
    qDebug() << "slotNewConnection";
    QTcpSocket* socket = server->nextPendingConnection();
    sockets.push_back(NetPlayer(socket, QString("player %1").arg(sockets.size())));

    connect(socket, SIGNAL(disconnected()), this, SLOT(slotLoseConnection()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadInfo()));

    redrawLists();
}

void Server::slotLoseConnection() {
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    socket->deleteLater();

    for (int i = 0; i < sockets.size(); ++i) {
        if (sockets[i].socket == socket) {
            qDebug() << "remove " << i; 
            sockets.remove(i);
            break;
        }
    }

    if (choosen_sockets.size() == 1) {
        if (choosen_sockets[0].socket == socket) {
            choosen_sockets.remove(0);
        }
    } else 
    if (choosen_sockets.size() == 2) {
        if (state == PLAYERS_NOT_SETED) {
            if (choosen_sockets[0].socket == socket) {
                choosen_sockets.remove(0);
                redrawLists();
                return;
            }
            if (choosen_sockets[1].socket == socket) {
                choosen_sockets.remove(1);
            }
        } else {
            if (choosen_sockets[0].socket == socket) {
                sendPlayerDisconnected(choosen_sockets[1].socket);
                choosen_sockets.remove(0);
                state = PLAYERS_NOT_SETED;
                redrawLists();
                return;
            }
            if (choosen_sockets[1].socket == socket) {
                sendPlayerDisconnected(choosen_sockets[0].socket);
                choosen_sockets.remove(1);
                state = PLAYERS_NOT_SETED;
            }
        }
    }
    redrawLists();   
}


void Server::redrawLists() {
    all_avaliable_players->clear();
    choosen_players->clear();
    for (int i = 0; i < sockets.size(); ++i) {   
        QListWidgetItem* item = new QListWidgetItem(sockets[i].name);
        all_avaliable_players->insertItem(all_avaliable_players->count(), item);
    }

    for (int i = 0; i < choosen_sockets.size(); ++i) {
        QListWidgetItem* item = new QListWidgetItem(choosen_sockets[i].name);
        choosen_players->insertItem(choosen_players->count(), item);
    }
}

void Server::slotSetNewPlayers() {
    qDebug() << "slotSetNewPlayers";
    if (state != PLAYERS_NOT_SETED) {
        std::cout << "players already seted" << std::endl;
        return;
    }

    if (choosen_players->count() == 2) {
        player_one = choosen_sockets[0];
        player_two = choosen_sockets[1];
        connect(player_one.socket, SIGNAL(readyRead()), this, SLOT(slotReadInfo()));
        connect(player_two.socket, SIGNAL(readyRead()), this, SLOT(slotReadInfo()));

        state = PLAYERS_SETED;

        sendPlayerNumber(player_one.socket, 1);
        sendPlayerNumber(player_two.socket, 2);
    } else {
        std::cout << "wrong count of players" << std::endl;
    }
}

void Server::slotResetPlayers() {
    qDebug() << "slotResetPlayers";
    player_one.socket = NULL;
    player_two.socket = NULL;
    choosen_players->clear();
    choosen_sockets.clear();
}


void Server::slotAddPlayerInChoosenList(QListWidgetItem* choosen_item) {
    std::cout << "add player in chosen list" << std::endl;
    if (choosen_players->count() < 2) {
        std::cout << "add : " << choosen_item << std::endl;
        choosen_sockets.push_back(sockets[all_avaliable_players->row(choosen_item)]);
        redrawLists();
    }
}



/////////////////////
// read and send info

void Server::slotReadInfo() {
    qDebug() << "slotReadInfo";
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    if (socket->bytesAvailable() < qint64(sizeof(int))) {return;}

    int type_of_package;

    in >> type_of_package;

    switch (type_of_package) {
        case 1: readPlayerNumber(socket);
            break;
        case 2: readUserInfo(socket);
            break;
        case 3: readEndGame(socket);
            break;
    }
}

void Server::readPlayerNumber(QTcpSocket* socket) {
    qDebug() << "readPlayerNumber";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    while(true) {
        if (socket->bytesAvailable() < qint64(sizeof(int))) {
            continue;
        }

        int number;
        in >> number;
        break;
    }
}

void Server::readUserInfo(QTcpSocket* socket) {
    qDebug() << "readUserInfo";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    while(true) {
        if (socket->bytesAvailable() < 5 * qint64(sizeof(int))) {
            continue;
        }
        UserInfo info;
        in >> info;
        if (socket == player_one.socket) {
            sendUserInfo(player_two.socket, info);    
        } else {
            sendUserInfo(player_one.socket, info);
        }
        break;
    }
}

void Server::readEndGame(QTcpSocket* socket) {
    qDebug() << "readEndGame";
}

void Server::sendPlayerNumber(QTcpSocket* socket, int number) {
    qDebug() << "sendPlayerNumber";

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << int(1) << number;
    socket->write(data);
}

void Server::sendUserInfo(QTcpSocket* socket, UserInfo info) {
    qDebug() << "sendUserInfo";

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << int(2) << info;
    socket->write(data);
}

void Server::sendEndGame(QTcpSocket* socket) {
    qDebug() << "sendEndGame";
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << int(3);
    socket->write(data);
}

void Server::sendPlayerDisconnected(QTcpSocket* socket) {
    qDebug() << "sendPlayerDisconnected";
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << int(4);
    socket->write(data);
}

#endif



