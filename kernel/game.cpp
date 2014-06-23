#ifndef GAME_CPP
#define GAME_CPP

#include "game.h"
#include "game_kernel.h"
#include <exception>
#include <QDebug>
// #include "logging.h"

Game::Game(int size) 
        : QObject(), first_player(0), second_player(0), game(size) {
            qDebug() << "game constuctor";
}

void Game::setPlayers(BasePlayer* new_first_player, BasePlayer* new_second_player) {

    qDebug() << "game set players";

    delete first_player;
    delete second_player;

    first_player = new_first_player;
    second_player = new_second_player;

    first_player->setGame(this);
    second_player->setGame(this);

    connect(first_player, SIGNAL(turnDid(Position)), this, SLOT(getTurn(Position)));
    connect(second_player, SIGNAL(turnDid(Position)), this, SLOT(getTurn(Position)));
}

void Game::play() {
    qDebug() << "game play";
    emit requestTurn(first_player);
}

void Game::reset() {
    qDebug() << "game reset";
    game.reset();
    first_player = NULL;
    second_player = NULL;
}

int Game::size() const {
    return game.size();
}

void Game::getTurn(const Position& decision) {
    qDebug() << "game get turn start" << sender();
    try {
        if (!game.emptyCell(decision)) {
            throw std::logic_error("not empty cell");
        }
        game.makeTurn(decision);
    } catch (std::logic_error) {
        emit requestTurn(dynamic_cast<BasePlayer*>(sender()));
        return;
    }

    emit newTurn(decision);
    game.print();

    if (game.status() == TICK_WIN ||
            game.status() == TOE_WIN ||
            game.status() == DRAW) {
        emit endGame(game.status());
        return;
    }

    if (sender() == first_player) {
        emit requestTurn(second_player);
    } else {
        emit requestTurn(first_player);
    }


    qDebug() << "game get turn end" << sender();
}

GameStatus Game::status() const {
    return game.status();
}

#endif
