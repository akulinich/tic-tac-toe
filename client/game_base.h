#ifndef GAME_BASE_H
#define GAME_BASE_H

#include "game_widget.h"
#include "game_kernel.h"
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
    virtual void getUserTurn(Position) = 0;

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
    NetGame(GameWidget* widget, int size, const QString& ip, int port);
    void play();
    ClientStatus getClientStatus();
    void reset() {
        game.resetGame();
    }

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

    GameWidget* game_widget;

signals:
    void signalTurnRecived(Turn);
    void signalNewGameDecisionNetPlayer(bool);
    void signalWaitUserDecision();
};



enum CPUGameStatus {
    NOT_STARTED_CPU_GAME,
    USER_TURN,
    CPU_TURN,
    WAIT_NEXT_GAME_INFO
};

class CPUGame : public GameBase {
Q_OBJECT
public:
    CPUGame(GameWidget* widget, int size) : GameBase(size), widget(widget) {
        connect(this, SIGNAL(signalWaitCPUDecision()), this, SLOT(getCPUTurn()));
        user_player = PLAYER_ONE;
        cpu_player = PLAYER_TWO;
        user_player_side = TOE_SIDE;
        cpu_player_side = TICK_SIDE;
        state = NOT_STARTED_CPU_GAME;
    }

    void play() {
        user_player_side = user_player_side == TOE_SIDE ? TICK_SIDE : TOE_SIDE;
        cpu_player_side = user_player_side == TOE_SIDE ? TICK_SIDE : TOE_SIDE;
        game.start(user_player_side, cpu_player_side);
        state = user_player_side == TICK_SIDE ? USER_TURN : CPU_TURN;

        if (state == CPU_TURN) {
            emit signalWaitCPUDecision();
        } else {
            emit signalWaitUserDecision();
        }

    }
    void reset() {
        game.resetGame();
    }

public slots:
    void getUserTurn(Position pos) {
        if (state == CPUGameStatus::USER_TURN) {
            if (!game.possiblyDecision(pos)) {
                return;
            }

            game.playerDecision(pos, user_player);
            emit signalNewTurn(Turn(pos, game.getPlayerSide(user_player), user_player));
            state = CPUGameStatus::CPU_TURN;
            if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                    || game.state() == DRAW) {
                state = WAIT_NEXT_GAME_INFO;
                emit signalGameOver();
            } else {
                emit signalWaitCPUDecision();
            }
            game.print();
        }
    }

    void getCPUTurn() {
        if (state == CPU_TURN) {
            Position pos;
            do {
                pos.x_cor = rand() % game.size();
                pos.y_cor = rand() % game.size();
            } while(!game.possiblyDecision(pos));
            std::cout << game.playerDecision(pos, cpu_player) << std::endl;
            emit signalNewTurn(Turn(pos, game.getPlayerSide(cpu_player), cpu_player));
            state = USER_TURN;
            if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                    || game.state() == DRAW) {
                state = CPUGameStatus::WAIT_NEXT_GAME_INFO;
                emit signalGameOver();
            }
            game.print();
        }
    }


signals:
    void signalWaitUserDecision();
    void signalWaitCPUDecision();
    void signalWaitUserNewGameDecision();

private:

    GameWidget* widget;
    Player user_player;
    Player cpu_player;
    Side user_player_side;
    Side cpu_player_side;
    CPUGameStatus state;
};



class UserGame : public GameBase {
Q_OBJECT

public slots:
    void getUserTurn(Position) {}

public:
    void play() {}
    UserGame() : GameBase(5) {}
    void reset() {}

};



#endif