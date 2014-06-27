#ifndef NET_GAME_H
#define NET_GAME_H

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

#include "game_base.h"

enum ClientStatus {
    NOT_CONNECTED,
    CONNECTED,
    WAIT_SIDE_INFO,
    WAIT_TURN_INFO,
    WAIT_USER_DECISION,
    WAIT_NET_USER_DECISION,
    WAIT_NEW_GAME_INFO
};

class NetGame : public GameBase {
Q_OBJECT

public:
    NetGame(GameWigget* widget, int size, c);
    void play();
    ClientStatus getClientStatus();

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotReadyToPlay();

    void getNetPlayerTurn(Turn decision);
    void getUserTurn(Position pos);


    // send (-1, need new game == true ? 1 : -1, -1, -1) when game end
    void sendToServerGameOverSignal(bool need_new_game);
    void sendToServerUserTurn(Turn decision);

private:
// net methods
    void readSideInfo();
    void readNetUserDecision();
    void readNewGameInfo();

    QTcpSocket* socket;
    ClientStatus status;
    Player local_player;

    GameWigget* game_widget;

signals:
    void signalTurnRecived(Turn);
    void signalNewGameDecisionNetPlayer(bool);
    void signalWaitUserDecision();
};


#endif