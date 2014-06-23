#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H

#include "game_kernel.h"
#include "game.h"

#include <QDebug>

class RandomPlayer : public BasePlayer {
Q_OBJECT
public slots:
    void doTurn(BasePlayer* player) {
        qDebug() << "random player turn did";
        if (player != this) {
            return;
        }

        Position decision;

        decision.x_cor = rand() % game->size();
        decision.y_cor = rand() % game->size();

        emit turnDid(decision);
        qDebug() << "random player turn did end";
    }    

};

#endif