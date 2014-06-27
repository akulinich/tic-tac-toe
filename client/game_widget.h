#ifndef PLAYING_FIELD_WIDGET_H
#define PLAYING_FIELD_WIDGET_H

#include <Qt>
#include <QtWidgets>
#include <QList>
#include "game_base.h"
#include "structurs.h"


enum GameType {
    PlVsPl,
    PlVsCPU,
    PlVsNet
};

class GameBase;

class GameWidget : public QWidget {
Q_OBJECT

private:
    QList<QLine> ticks;
    QList<QRect> toes;

    GameBase* game;
    GameType type;

    int cell_size;
    int field_size;
    QString ip;
    int port;

protected:
    void paintEvent(QPaintEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);

public:
    GameWidget(int size_of_field, int cell_size, QWidget* widget = 0);

signals:
    void endGame(GameState);
    void mouseClicked(Position);

public slots:
    void raizeEndGame();
    void newGame();
    void addTurn(Turn);

    void setPlayerVsPlayer();
    void setPlayerVsCPU();
    void setPlayerVsNet();
};

#endif