#include "client.h"
#include "package.h"

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

Client::Client(const QString& ip, int port, QWidget* widget)
        :QWidget(widget) {
    socket = new QTcpSocket(this);
    socket->connectToHost(ip, port);
    connect(socket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));

    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), 
        this, SLOT(slotError(QAbstractSocket::SocketError)));

    status = NOT_CONNECTED;
}

void Client::sendTurn(Player player, const Position& decision) {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << player << decision.x_cor << decision.y_cor;

    socket->write(data);
    status = WAIT_TURN_INFO;
}

void Client::sendEndGameDicision(bool need_new_game) {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << need_new_game;

    socket->write(data);
    status = WAIT_SIDE_INFO;
}


void Client::slotError(QAbstractSocket::SocketError) {
}

void Client::slotConnected() {
    status = WAIT_SIDE_INFO;
}

void Client::slotReadyRead() {
    if (status == WAIT_SIDE_INFO) {
        readSideInfo();
    }

    if (status == WAIT_TURN_INFO) {
        readTurn();
    }

    if (status == WAIT_NEW_GAME_INFO) {
        readNewGameInfo();
    }
}

void Client::readSideInfo() {
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    for (;;) {
        
        if (socket->bytesAvailable() < sizeof(SideInfo)) {
            break;
        }

        SideInfo player_side;
        int side;
        in >> side;
        if (side == 1) {
            player_side.side = TICK;
        } else {
            player_side.side = TOE;
        }
        
        emit signalSideArrived(player_side);
        if (player_side.side == TICK) {
            status = WAIT_USER_DECISION;
        } else {
            status = WAIT_TURN_INFO;
        }
    }
}

void Client::readTurn() {
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    for (;;) {
        if (socket->bytesAvailable() < sizeof(Turn)) {
            break;
        }
        Turn turn;
        int turn_player;
        in >> turn_player >> turn.decision.x_cor >> turn.decision.y_cor;
        if (turn_player == 1) {
            turn.player = TICK;
        } else {
            turn.player = TOE;
        }

        emit signalTurnArrived(turn);
        status = WAIT_USER_DECISION;
    }
}

void Client::readNewGameInfo() {
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    for (;;) {
        if (socket->bytesAvailable() < sizeof(Turn)) {
            break;
        }
        bool need_new_game;
        in >> need_new_game;
        emit signalNewGameInfo(need_new_game);
        if (need_new_game) {
            status = WAIT_SIDE_INFO;
        } else {
            status = NOT_CONNECTED;
        }
    }
}


