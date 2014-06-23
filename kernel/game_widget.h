#ifndef PLAYING_FIELD_WIDGET_H
#define PLAYING_FIELD_WIDGET_H

#include <Qt>
#include <QtWidgets>
#include <QList>
#include "game.h"


enum GameType {
    PlVsPl,
    PlVsCPU,
    PlVsNet
};


class GameWidget : public QWidget {
Q_OBJECT

private:
    QList<QLine> ticks;
    QList<QRect> toes;

    Game game;
    GameType type;

    bool play_enable;

    

    int cell_size;
    int field_size;

protected:
    void paintEvent(QPaintEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);

public:
    GameWidget(int size_of_field, int cell_size, QWidget* widget = 0);
    bool getPlayEnable();

signals:
    void endGame(GameStatus);
    void mouseClicked(Position);

public slots:
    void raizeEndGame(GameStatus);
    void newGame();
    void addTurn(const Position& position);
    void setPlayDisable();
    void setPlayEnable();

    void setPlayerVsPlayer();
    void setPlayerVsCPU();
    void setPlayerVsNet();
};

#endif