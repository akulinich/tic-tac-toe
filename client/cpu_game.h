#ifndef CPU_GAME_H
#define CPU_GAME_H

#include "structurs.h"

#include <QtGui>
#include <QtWidgets>

struct CPUGameStatus {
    NOT_STARTED,
    USER_TURN,
    CPU_TURN,
    WAIT_NEXT_GAME_INFO
};

class CPUGame : public GameBase {
Q_OBJECT
public:
    CPUGame(GameWidget* widget, int size) : GameBase(size), widget(widget) {
        connect(widget, SIGNAL(mouseClicked(Position)), this, SLOT(getUserTurn(Position)));
        connect(this, SIGNAL(signalWaitCPUDecision()), this, SLOT(getCPUTurn()));
        user_player = PLAYER_ONE;
        cpu_player = PLAYER_TWO;
        user_player_side = TOE;
        cpu_player_side = TICK;
        state = NOT_STARTED;
    }

    void play() {
        user_player_side = user_player_side == TOE_SIDE ? TICK_SIDE : TOE_SIDE;
        cpu_player_side = user_player_side == TOE_SIDE ? TOE_SIDE : TICK_SIDE;
        game.start(user_player_side, cpu_player_side);
        state = user_player_side == TICK_SIDE ? USER_TURN : CPU_TURN;

        if (state == CPU_TURN) {
            emit signalWaitCPUDecision();
        } else {
            emit signalWaitUserDecision();
        }

    }

public slots:
    void getUserTurn(Position pos) {
        if (status == USER_TURN) {
            game.playerDecision(decision.pos, user_player);
            emit signalNewTurn(Turn(pos, game.getPlayerSide(user_player), user_player));
            status = CPU_TURN;
            if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                    || game.state() == DRAW) {
                status = WAIT_NEW_GAME_INFO;
                emit signalGameOver;
            } else {
                emit signalWaitCPUDecision();
            }
        }
    }

    void getCPUTurn(Position pos) {
        if (status == CPU_TURN) {
            Position pos;
            pos.x_cor = rand() % game.size() + 1;
            pos.y_cor = rand() % game.size() + 1;
            game.playerDecision(pos, cpu_player);
            emit signalNewTurn(Turn(pos, game.getPlayerSide(cpu_player), cpu_player));
            status = USER_TURN;
            if (game.state() == PLAYER_ONE_WIN || game.state() == PLAYER_TWO_WIN 
                    || game.state() == DRAW) {
                status = WAIT_NEW_GAME_INFO;
                emit signalGameOver;
            }
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


#endif