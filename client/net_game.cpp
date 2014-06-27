#include "game_base.h"
#include "net_game.h"
#include "structurs.h"

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

NetGame::NetGame(GameWigget* widget, int size, const QString& ip, int port) 
: GameBase(size), game_widget(widget) {
    socket = new QTcpSocket(this);
    socket->connectToHost(ip, port);

    connect(socket, SIGNAL(connected()), this, SLOT(slotReadyToPlay())); // do when connect to server
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead())); // do when information arrived
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), 
            this, SLOT(slotError(QAbstractSocket::SocketError)));

    connect(this, SIGNAL(signalTurnRecived(Turn)), this, SLOT(getNetPlayerTurn(Turn)));
    connect(widget, SIGNAL(mouseClicked(Position)), this, SLOT(getUserTurn(Position)));
    connect(this, SIGNAL(signalGameOver()), this, SLOT(sendToServerGameOverSignal()));
    connect(this, SIGNAL(signalNewTurn(Turn)), this, SLOT(sendToServerUserTurn(Turn)));

    status = NOT_CONNECTED;
}

// wait side info then wait user decision or net user decision
void NetGame::play() {
    if (status == CONNECTED) {
        status = WAIT_SIDE_INFO;
    }
}

ClientStatus NetGame::getClientStatus() {
    return status;
}

void NetGame::slotReadyRead() {
    if (status == WAIT_SIDE_INFO) {
        readSideInfo();
    }
    if (status == WAIT_NET_USER_DECISION) {
        readNetUserDecision();
    }
    if (status == WAIT_NEW_GAME_INFO) {
        readNewGameInfo();
    }
}

void NetGame::slotError(QAbstractSocket::SocketError) {

} 

void NetGame::slotReadyToPlay() {
    status = CONNECTED;
}

void NetGame::getNetPlayerTurn(Turn decision) {
    if (status != WAIT_NET_USER_DECISION) {
        return;
    }

    if (game.possiblyDecision(decision.pos)) {
        game.playerDecision(decision.pos, decision.player);
        emit signalNewTurn(decision);
        status = WAIT_USER_DECISION;
        if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                || game.state() == DRAW) {
            status = WAIT_NEW_GAME_INFO;
            emit signalGameOver();
        }
    }
}

void NetGame::getUserTurn(Position pos) {
    if (status == WAIT_USER_DECISION) {
        game.playerDecision(pos, local_player);
        emit signalNewTurn(Turn(pos, game.getPlayerSide(local_player), local_player));
        status = WAIT_NET_USER_DECISION;
        if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                || game.state() == DRAW) {
            status = WAIT_NEW_GAME_INFO;
            emit signalGameOver();
        }
    }
}


// send (-1, need new game == true ? 1 : -1, -1, -1) when game end
void NetGame::sendToServerGameOverSignal(bool need_new_game) {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << -1 << (need_new_game ? 1 : -1) << -1 << -1;
    socket->write(data);
    status = WAIT_NEW_GAME_INFO;
}


void NetGame::sendToServerUserTurn(Turn decision) {
    if (decision.player == local_player) {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_8);
        out << decision.pos.x_cor << decision.pos.y_cor 
            << (decision.side == TICK_SIDE ? 1 : 2)
            << (local_player == PLAYER_ONE ? 1 : 2);

        socket->write(data);
        status = WAIT_NET_USER_DECISION;
    }
}


// recive side of player one
void NetGame::readSideInfo() {
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);
    
    if (socket->bytesAvailable() < qint64(sizeof(int))) { return; }

    int player;
    in >> player;
    if (player == 1) {
        status = WAIT_USER_DECISION;
        local_player = PLAYER_ONE;
    } else {
        status = WAIT_NET_USER_DECISION;
        local_player = PLAYER_TWO;
    }

    game.start(TICK_SIDE, TOE_SIDE);

    if (status == WAIT_USER_DECISION) {
        emit signalWaitUserDecision();
    }
}

void NetGame::readNetUserDecision() {
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);

    if (socket->bytesAvailable() < 4 * qint64(sizeof(int))) {return;}

    int x, y, side, player;

    in >> x >> y >> side >> player;

    status = WAIT_USER_DECISION;

    emit signalTurnRecived(Turn(Position(x,y), 
        side == 1 ? TICK_SIDE : TOE_SIDE, 
        player == 1 ? PLAYER_ONE : PLAYER_TWO));
}

void NetGame::readNewGameInfo() {
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_8);

    if (socket->bytesAvailable() < qint64(sizeof(bool))) {return;}

    bool decision;

    in >> decision;

    status = CONNECTED;

    emit signalNewGameDecisionNetPlayer(decision);
}
