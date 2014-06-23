#ifndef GAME_WIDGET_CPP
#define GAME_WIDGET_CPP

#include "game_widget.h"
#include "game_kernel.h"
#include "game.h"
#include "user_player.h"
#include "random_player.h"
#include <Qt>
#include <QtWidgets>
#include <exception>
#include <QtDebug>




const int TIC_TOE_SMALL_COEF = 4;

GameWidget::GameWidget(int size_of_field, int cell_size, QWidget* widget) 
    : QWidget(widget), game(size_of_field), 
    cell_size(cell_size), field_size(size_of_field) {


    qDebug() << "game widget constructor";

    setPlayerVsPlayer();

    connect(&game, SIGNAL(newTurn(Position)), this, SLOT(addTurn(Position)));
    connect(&game, SIGNAL(endGame(GameStatus)), this, SLOT(setPlayDisable()));
    connect(&game, SIGNAL(endGame(GameStatus)), this, SLOT(raizeEndGame(GameStatus)));

    play_enable = true;
    resize(size_of_field * cell_size + 1, size_of_field * cell_size + 1);
    setMinimumSize(size());
    setMaximumSize(size());

    type = PlVsPl;

    game.play();
}


void GameWidget::addTurn(const Position& position) {
    QPoint center(position.x_cor * cell_size, position.y_cor * cell_size);

    center.rx() = (center.x() / cell_size) * cell_size + cell_size / 2;
    center.ry() = (center.y() / cell_size) * cell_size + cell_size / 2;
    
    qDebug() << center.rx() << " " << center.ry();

    if (game.status() == TOE_TURN || game.status() == TICK_WIN) {
        ticks.push_back(QLine(center.x() - cell_size / 2 + TIC_TOE_SMALL_COEF, 
            center.y() - cell_size / 2 + TIC_TOE_SMALL_COEF,
            center.x() + cell_size / 2 - TIC_TOE_SMALL_COEF, 
            center.y() + cell_size / 2 - TIC_TOE_SMALL_COEF));
        ticks.push_back(QLine(center.x() + cell_size / 2 - TIC_TOE_SMALL_COEF, 
            center.y() - cell_size / 2 + TIC_TOE_SMALL_COEF,
            center.x() - cell_size / 2 + TIC_TOE_SMALL_COEF, 
            center.y() + cell_size / 2 - TIC_TOE_SMALL_COEF));
    } else {
        toes.push_back(QRect(QPoint(center.x() - cell_size / 2 + TIC_TOE_SMALL_COEF, 
                   center.y() - cell_size / 2 + TIC_TOE_SMALL_COEF),
            QPoint(center.x() + cell_size / 2 - TIC_TOE_SMALL_COEF, 
                    center.y() + cell_size / 2 - TIC_TOE_SMALL_COEF)));
    }

    repaint();
}

void GameWidget::mouseReleaseEvent(QMouseEvent* pe) {
    qDebug() << "mouse event start";
    if (!play_enable) {
        return;
    }

    QPoint center = pe->pos();

    center.rx() = (center.x() / cell_size) * cell_size + cell_size / 2;
    center.ry() = (center.y() / cell_size) * cell_size + cell_size / 2;

    emit mouseClicked(Position(int(center.x()) / cell_size, 
                               int(center.y()) / cell_size));
    qDebug() << "mouse event end";
}

void GameWidget::paintEvent(QPaintEvent* pe) {
    
    QPainter painter(this);
    painter.setPen(Qt::blue);

    for (int line = 0; line <= field_size; ++line) {
        painter.drawLine(QPoint(line * cell_size, 0), 
            QPoint(line * cell_size, field_size * cell_size));
    }

    for (int line = 0; line <= field_size; ++line) {
        painter.drawLine(QPoint(0, line * cell_size), 
            QPoint(cell_size * field_size, line * cell_size));
    }

    painter.setPen(QPen(Qt::red, 3));
    for (auto& obj : ticks) {
        painter.drawLine(obj);
    }
    painter.setPen(QPen(Qt::blue, 3));
    for (auto& obj : toes) {
        painter.drawEllipse(obj);
    }
}

void GameWidget::setPlayDisable() {
    qDebug() << "game widget set disable";
    play_enable = false;
}

void GameWidget::setPlayEnable() {
    qDebug() << "game widget set enable";
    play_enable = true;
}

bool GameWidget::getPlayEnable() {
    return play_enable;
}

void GameWidget::newGame() {
    qDebug() << "game widget new game";
    play_enable = true;
    ticks.clear();
    toes.clear();
    game.reset();
    repaint();

    if (type == PlVsPl) {
        setPlayerVsPlayer();
    }

    if (type == PlVsCPU) {
        setPlayerVsCPU();
    }

    if (type == PlVsNet) {
        setPlayerVsNet();
    }
    
    game.play();
}

void GameWidget::raizeEndGame(GameStatus status) {
    emit endGame(status);
}

void GameWidget::setPlayerVsPlayer() {
    UserPlayer* first = new UserPlayer(this);
    UserPlayer* second = new UserPlayer(this);

    game.setPlayers(first, second);

    type = PlVsPl;
}

void GameWidget::setPlayerVsCPU() {

    UserPlayer* first = new UserPlayer(this);
    RandomPlayer* second = new RandomPlayer();

    game.setPlayers(first, second);

    type = PlVsCPU;
}

void GameWidget::setPlayerVsNet() {

    type = PlVsNet;
}

#endif
