#ifndef USER_PLAYER_H
#define USER_PLAYER_H

#include <QObject>
#include <QDebug>

#include "game_widget.h"


class UserPlayer : public BasePlayer {
Q_OBJECT

public:
    UserPlayer(GameWidget* game_widget) : BasePlayer() {
        qDebug() << "user player constructor" << this;
        need_turn = false;
        connect(game_widget, SIGNAL(mouseClicked(Position)), 
            this, SLOT(sendTurn(Position)));
    }

public slots:
    void doTurn(BasePlayer* player) {
        qDebug() << "do turn start" << player << this;
        if (player != this) {
            return;
        }
        qDebug() << "do turn end" << player << this;
        need_turn = true;
    }
    void sendTurn(Position decision) {
        qDebug() << "send turn start" << this;
        if (need_turn) {
            need_turn = false;
            qDebug() << "turn sended" << this;
            emit turnDid(decision);
        }
        qDebug() << "send turn end" << this;
    }

private:
    bool need_turn;  
};

#endif