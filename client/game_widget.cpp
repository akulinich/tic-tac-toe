#ifndef GAME_WIDGET_CPP
#define GAME_WIDGET_CPP

#include "game_widget.h"
#include "game_kernel.h"
#include "game_base.h"
#include "structurs.h"

#include <Qt>
#include <QtWidgets>
#include <exception>
#include <QtDebug>




const int TIC_TOE_SMALL_COEF = 4;

GameWidget::GameWidget(int size_of_field, int cell_size, QWidget* widget) 
    : QWidget(widget), 
    cell_size(cell_size), field_size(size_of_field) {

    game = NULL;

    qDebug() << "game widget constructor";

    setPlayerVsCPU();

    resize(size_of_field * cell_size + 1, size_of_field * cell_size + 1);
    setMinimumSize(size());
    setMaximumSize(size());

    game->play();

    ip = "0.0.0.0";
    port = 8080;
}


void GameWidget::addTurn(Turn turn) {
    QPoint center(turn.pos.x_cor * cell_size, turn.pos.y_cor * cell_size);

    center.rx() = (center.x() / cell_size) * cell_size + cell_size / 2;
    center.ry() = (center.y() / cell_size) * cell_size + cell_size / 2;
    
    qDebug() << center.rx() << " " << center.ry();

    if (turn.side == TICK_SIDE) {
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

void GameWidget::newGame() {
    qDebug() << "game widget new game";
    ticks.clear();
    toes.clear();
    game->reset();
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
    
    game->play();
}

void GameWidget::raizeEndGame() {
    emit endGame(game->getGameState());
}

void GameWidget::setPlayerVsPlayer() {
    delete game;
    game = new UserGame();
    connect(this, SIGNAL(mouseClicked(Position)), game, SLOT(getUserTurn(Position)));
    connect(game, SIGNAL(signalNewTurn(Turn)), this, SLOT(addTurn(Turn)));
    connect(game, SIGNAL(signalGameOver()), this, SLOT(raizeEndGame()));

    type = PlVsPl;
}

void GameWidget::setPlayerVsCPU() {
    delete game;
    game = new CPUGame(this, field_size);
    connect(this, SIGNAL(mouseClicked(Position)), game, SLOT(getUserTurn(Position)));
    connect(game, SIGNAL(signalNewTurn(Turn)), this, SLOT(addTurn(Turn)));
    connect(game, SIGNAL(signalGameOver()), this, SLOT(raizeEndGame()));

    type = PlVsCPU;
}

void GameWidget::setPlayerVsNet() {
    delete game;
    game = new NetGame(this, field_size, ip, port);
    connect(this, SIGNAL(mouseClicked(Position)), game, SLOT(getUserTurn(Position)));
    connect(game, SIGNAL(signalNewTurn(Turn)), this, SLOT(addTurn(Turn)));
    connect(game, SIGNAL(signalGameOver()), this, SLOT(raizeEndGame()));

    type = PlVsNet;
}

#endif
