#ifndef CLIENT_H
#define CLIENT_H

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

#include "playing_field.h"
#include "package.h"

enum ClientStatus {
    NOT_CONNECTED,
    WAIT_SIDE_INFO,
    WAIT_TURN_INFO,
    WAIT_USER_DECISION,
    WAIT_NEW_GAME_INFO
};


class Client : public QWidget {
Q_OBJECT

private:
    QTcpSocket* socket;
    ClientStatus status;

    void readSideInfo();
    void readTurn();
    void readNewGameInfo();
    
public:
    Client(const QString& ip, int port, QWidget* widget = 0);
    void sendTurn(Player player, const Position& decision);
    void sendEndGameDicision(bool need_new_game);

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotConnected();

signals:
    void signalTurnArrived(Turn);
    void signalSideArrived(SideInfo);
    void signalNewGameInfo(bool);
};

#endif