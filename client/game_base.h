#ifndef GAME_BASE_H
#define GAME_BASE_H

#include "game_widget.h"
#include "game_kernel.h"
#include "cpu_player.h"
#include "structurs.h"

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

#include <iostream>

class GameWidget;

class GameBase : public QObject {
Q_OBJECT

public:
    explicit GameBase(int size) : QObject(), game(size) {
        resetStat();
    }

    virtual void play() = 0;
    virtual void reset() = 0;

// statistics
    void resetStat() {
        player_one_wins = 0;
        player_two_wins = 0;
        draws = 0;
    }

    int getPlayerOneWins() {
        return player_one_wins;
    }

    int getPlayerTwoWins() {
        return player_two_wins;
    }
    int getDraws() {
        return draws;
    }
    Side getPlayerSide(Player player) {
        return game.getPlayerSide(player);
    }
    GameState getGameState() {
        return game.state();
    }

public slots:
    virtual void slotGetUserTurn(Position) = 0;
    virtual void slotNewGame(bool) = 0;
    virtual void slotGetNewGameDecision(bool) = 0;

signals:
// public signals
    void signalNewGame();
    void signalNewTurn(Turn);
    void signalGameOver();

// private signals


protected:
    GameKernel game;


// statistics
    int player_one_wins;
    int player_two_wins;
    int draws;
};


////////////////////////////////////////////////
////////////////////////////////////////////////
/////////////////// NET GAME ///////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////
//
// discribe package:
// info of package:
//
// 1 - player number info: one int 
//   (number)
//     1 - you first player
//     2 - you second player
//
// 2 - user info: 
//     1 - turn info: four int
//       (x) (y) 
//           line and column
//       (side)
//         1 - you tick side
//         2 - you toe side
//       (player)
//         1 - turn from first player
//         2 - turn from second player
//     2 - new_game_info: one int
//       (decision)
//         1 - yes, 2 - no  
// 3 - end game (no data)
// 4 - disconnection 
//


struct UserInfo {
    int type_of_package, x, y, side, player, decision;
    UserInfo(int x, int y, int side, int player) : type_of_package(1), x(x), y(y), side(side), player(player) {}
    UserInfo(int decision) : type_of_package(2), decision(decision) {}
    UserInfo() {}
};


enum ClientState {
    NOT_CONNECTED,
    CONNECTED,
    
    WAIT_PLAYER_NUMBER,

    WAIT_USER_DECISION,
    SEND_USER_DECISION,
    WAIT_NET_USER_DECISION,

    WAIT_NEW_GAME_INFO 
};

class NetGame : public GameBase {
Q_OBJECT

public:
    NetGame(GameWidget* widget, int size, const QString& ip, int port);
    ClientState getClientStatus();
    void reset();
    void play() {}

private slots:
    
    void slotConnected();
    void slotReadInfo();
    void slotError(QAbstractSocket::SocketError);

    void slotGetNetPlayerTurn(Turn decision);
    void slotGetUserTurn(Position pos);

    void slotGetNewGameDecision(bool);
    void slotGetNewGameDecisionNetPLayer(bool);

    void slotNewGame(bool);

private:
    void sendPlayerNumber(int number);
    void sendUserInfo(UserInfo info);
    void sendEndGame();

    void readPlayerNumber();
    void readUserInfo();
    void readEndGame();
    void readPlayerDisconnected();

    

    QTcpSocket* socket;
    ClientState state;
    Player local_player;
    Player net_player;
    Side local_player_side;
    Side net_player_side;

    GameWidget* game_widget;

    int get_decisions_about_new_game;
    bool need_new_game;


signals:
    void signalNewGame(bool); // need or not need
    void signalWaitUserDecision();
};



////////////////////////////////////////////////
////////////////////////////////////////////////
/////////////////// CPU GAME ///////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

enum CPUGameStatus {
    NOT_STARTED_CPU_GAME,
    USER_TURN,
    CPU_TURN,
    WAIT_NEXT_GAME_INFO
};

class CPUGame : public GameBase {
Q_OBJECT
public:
    CPUGame(GameWidget* widget, int size);

    void play();
    void reset();

public slots:
    void slotGetUserTurn(Position pos);
    void slotNewGame(bool) {}

    void slotGetCPUTurn();

    void slotGetNewGameDecision(bool);


signals:
    void signalWaitUserDecision();
    void signalWaitCPUDecision();
    void signalWaitUserNewGameDecision();

private:

    GameWidget* game_widget;
    CPUplayer CPU;
    Player user_player;
    Player cpu_player;
    Side user_player_side;
    Side cpu_player_side;
    CPUGameStatus state;
};


////////////////////////////////////////////////
////////////////////////////////////////////////
/////////////////// USER GAME //////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////


class UserGame : public GameBase {
Q_OBJECT

    enum UserGameState {
        NOT_STARTED_USER_GAME,
        PLAYER_ONE_TURN,
        PLAYER_TWO_TURN,
        WAIT_NEXT_GAME_INFO
    };

public slots:
    void slotGetUserTurn(Position);
    void slotNewGame(bool);
    void slotGetNewGameDecision(bool);

public:
    void play();
    UserGame(GameWidget*, int size);
    void reset();

protected:
    GameWidget* game_widget;
    Player left_player;
    Player right_player;
    Side left_player_side;
    Side right_player_side;
    UserGameState state;  
};




#endif