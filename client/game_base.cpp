#include "game_base.h"
#include "game_widget.h"
#include "structurs.h"

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

#include <algorithm>

const int WAIT_SIDE_INFO_CONSTANT = 10;


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

NetGame::NetGame(GameWidget* widget, int size, const QString& ip, int port) 
: GameBase(size), game_widget(widget) {
    socket = new QTcpSocket(this);
    socket->connectToHost(ip, port);

    connect(socket, SIGNAL(connected()), this, SLOT(slotConnected())); // do when connect to server
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadInfo())); // do when information arrived
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), 
            this, SLOT(slotError(QAbstractSocket::SocketError)));

    get_decisions_about_new_game = 0;
    need_new_game = true;

    state = NOT_CONNECTED;
}


void NetGame::slotError(QAbstractSocket::SocketError) {
    QMessageBox::critical(game_widget, tr("Server Erorr "), tr("Unable to connect to server"));
} 


void NetGame::slotConnected() {
    qDebug() << "slotConnected";
    state = CONNECTED;
}


void NetGame::slotGetNetPlayerTurn(Turn decision) {
    qDebug() << "slotGetNetPlayerTurn begin";
    if (state != WAIT_NET_USER_DECISION) {
        return;
    }

    if (game.possiblyDecision(decision.pos)) {
        game.playerDecision(decision.pos, decision.player);
        game_widget->slotNewTurn(decision);
        state = WAIT_USER_DECISION;
        if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                || game.state() == DRAW) {
            state = WAIT_NEW_GAME_INFO;
            game_widget->endGame(game.state());
        }
    }
    qDebug() << "slotGetNetPlayerTurn end";
}

void NetGame::slotGetUserTurn(Position pos) {
    qDebug() << "slotGetUserTurn start";
    if (state != WAIT_USER_DECISION) {
        return;
    }
    if (game.possiblyDecision(pos)) {
        game.playerDecision(pos, local_player);
        game_widget->slotNewTurn(Turn(pos, local_player_side, local_player));
        sendUserInfo(UserInfo(pos.x_cor, pos.y_cor, 
            local_player_side == TICK_SIDE ? 1 : 2,
            local_player == PLAYER_ONE ? 1 : 2));
        state = WAIT_NET_USER_DECISION;
        if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                || game.state() == DRAW) {
            state = WAIT_NEW_GAME_INFO;
            game_widget->endGame(game.state());
        }
    }
    qDebug() << "slotGetUserTurn end";
}

void NetGame::reset() {
    qDebug() << "NetGame::reset";
    game.resetGame();
}


ClientState NetGame::getClientStatus() {
    return state;
}


// read and send methods
void NetGame::slotReadInfo() {
    qDebug() << "slotReadInfo";
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    if (socket->bytesAvailable() < qint64(sizeof(int))) {return;}

    int type_of_package;

    in >> type_of_package;

    switch (type_of_package) {
        case 1: readPlayerNumber();
            break;
        case 2: readUserInfo();
            break;
        case 3: readEndGame();
            break;
        case 4: readPlayerDisconnected();
            break;
    } 
}

void NetGame::readPlayerNumber() {
    qDebug() << "readPlayerNumber";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    while(true) {
        if (socket->bytesAvailable() < qint64(sizeof(int))) {
            continue;
        }

        int number;
        in >> number;


        qDebug() << number;
        if (number == 1) {
            state = WAIT_USER_DECISION;
            local_player = PLAYER_ONE;
            local_player_side = TICK_SIDE;
        } else {
            state = WAIT_NET_USER_DECISION;
            local_player = PLAYER_TWO;
            local_player_side = TOE_SIDE;
        }

        game.start(TICK_SIDE, TOE_SIDE);

        break;
    }
}

void NetGame::readUserInfo() {
    qDebug() << "readUserInfo";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    while(true) {
        if (socket->bytesAvailable() < 5 * qint64(sizeof(int))) {
            continue;
        }
        UserInfo info;
        in >> info;

        if (info.type_of_package == 1) {
            slotGetNetPlayerTurn(Turn(Position(info.x, info.y), 
                info.side == 1 ? TICK_SIDE : TOE_SIDE, 
                info.player == 1 ? PLAYER_ONE : PLAYER_TWO));
        }
        
        if (info.type_of_package == 2) {
            if (info.decision == 1) {
                slotGetNewGameDecisionNetPLayer(true);   
            } 
            if (info.decision == 2) {
                slotGetNewGameDecisionNetPLayer(false);
            }
        }
        break;
    }
}

void NetGame::readPlayerDisconnected() {
    qDebug() << "readPlayerDisconnected";
        qDebug() << "readPlayerNumber";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    while(true) {
        if (socket->bytesAvailable() < qint64(sizeof(int))) {
            continue;
        }

        int number;
        in >> number;

        // what do when disconnected?

        break;
    }

}

void NetGame::readEndGame() {
    qDebug() << "readEndGame";
}

void NetGame::sendPlayerNumber(int number) {
    qDebug() << "sendPlayerNumber";

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << int(1) << number;
    socket->write(data);
}



void NetGame::sendUserInfo(UserInfo info) {
    qDebug() << "sendUserInfo";

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << int(2) << info;
    socket->write(data);
}

void NetGame::sendEndGame() {
    qDebug() << "sendEndGame";
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << int(3);
    socket->write(data);
}

void NetGame::slotGetNewGameDecision(bool decision) { // вызвать в интерфесе
    qDebug() << "slotGetNewGameDecision";
    sendUserInfo(UserInfo(decision ? 1 : 2));
    get_decisions_about_new_game++;
    need_new_game = need_new_game && decision;
    if (get_decisions_about_new_game == 2) {
        if (need_new_game == true) {
            slotNewGame(true);
        } else {
            sendEndGame();
            state = NOT_CONNECTED;
        }
        get_decisions_about_new_game = 0;
    }
}

void NetGame::slotGetNewGameDecisionNetPLayer(bool decision) {
    qDebug() << "slotGetNewGameDecisionNetPLayer";
    get_decisions_about_new_game++;
    need_new_game = need_new_game && decision;
    if (get_decisions_about_new_game == 2) {
        if (need_new_game == true) {
            slotNewGame(true);
        } else {
            sendEndGame();
            state = NOT_CONNECTED;
            game_widget->emitNoGameSignal();
        }
        get_decisions_about_new_game = 0;
    }
}

void NetGame::slotNewGame(bool) {
    qDebug() << "slotNewGame";
    game_widget->clear();
    game.resetGame();
    local_player_side = local_player_side == TICK_SIDE ? TOE_SIDE : TICK_SIDE;
    game.start(TICK_SIDE, TOE_SIDE);

    if (local_player_side == TICK_SIDE) {
        state = WAIT_USER_DECISION;
    } else {
        state = WAIT_NET_USER_DECISION;
    }
}


//////////////////////////////////////////////////
////////////////// CPUGame methods ///////////////
//////////////////////////////////////////////////



CPUGame::CPUGame(GameWidget* widget, int size) : GameBase(size), game_widget(widget) {
    user_player = PLAYER_ONE;
    cpu_player = PLAYER_TWO;
    user_player_side = TICK_SIDE;
    cpu_player_side = TOE_SIDE;
    state = USER_TURN;
    game.start(TICK_SIDE, TOE_SIDE);
}

void CPUGame::play() {
}

void CPUGame::reset() {
    game.resetGame();
}


void CPUGame::slotGetUserTurn(Position pos) {
    if (state == CPUGameStatus::USER_TURN) {
        if (!game.possiblyDecision(pos)) {
            return;
        }
        game.playerDecision(pos, user_player);
        game_widget->slotNewTurn(Turn(pos, user_player_side, user_player));
        state = CPUGameStatus::CPU_TURN;
        if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                || game.state() == DRAW) {
            state = WAIT_NEXT_GAME_INFO;
            game_widget->endGame(game.state());
        } else {
            slotGetCPUTurn();
        } 
    }
}

void CPUGame::slotGetCPUTurn() {
    if (state == CPU_TURN) {
        Position pos;
        do {
            pos.x_cor = rand() % game.size();
            pos.y_cor = rand() % game.size();
        } while(!game.possiblyDecision(pos));
        game.playerDecision(pos, cpu_player);
        game_widget->slotNewTurn(Turn(pos, cpu_player_side, cpu_player));
        state = USER_TURN;
        if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                || game.state() == DRAW) {
            state = CPUGameStatus::WAIT_NEXT_GAME_INFO;
            game_widget->endGame(game.state());
        }       
    }
}

void CPUGame::slotGetNewGameDecision(bool decision) {
    if (decision) {
        game_widget->clear();
        game.resetGame();
        std::swap(cpu_player_side, user_player_side);
        game.start(TICK_SIDE, TOE_SIDE);

        if (user_player_side == TICK_SIDE) {
            state = USER_TURN;
        } else {
            state = CPU_TURN;
            slotGetCPUTurn();
        }
    } else {
        state = NOT_STARTED_CPU_GAME;
    }

}


