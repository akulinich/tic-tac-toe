#ifndef GAME_H
#define GAME_H


#include <QObject>
#include "game_kernel.h"
#include <Qt>
#include <QDebug>


class BasePlayer;

class Game : public QObject {
Q_OBJECT

public:
    Game(int size);

    void play();
    void reset();
    int size() const;
    void setPlayers(BasePlayer* first_player, BasePlayer* second_player);
    GameStatus status() const;

private slots:
    void getTurn(const Position& decision);

signals:
    void requestTurn(BasePlayer*); // then compare with this*
    void endGame(GameStatus);
    void newTurn(Position); // for interface

private:
    BasePlayer* first_player;
    BasePlayer* second_player;
    GameKernel game;
};


class BasePlayer : public QObject {
Q_OBJECT

public:
    BasePlayer() : QObject() {}

    void setGame(Game* new_game) {
        qDebug() << "base player set game" << this;
        game = new_game;
        connect(game, SIGNAL(requestTurn(BasePlayer*)), this, SLOT(doTurn(BasePlayer*)));
    }

public slots:
    virtual void doTurn(BasePlayer* player) = 0;

signals:
    void turnDid(const Position& decision);

protected:
    Game* game;
};  


#endif