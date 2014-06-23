#ifndef GAME_STAT_WIDGET_H
#define GAME_STAT_WIDGET_H

#include <QtGui>
#include <QtWidgets>

#include "game_widget.h"
#include "game.h"
#include "game_kernel.h"

class GameStatWidget : public QWidget {
Q_OBJECT

private:
    int count_tick_win;
    int count_toe_win;
    int count_draws;

    QGridLayout* main_layout;

    QLCDNumber* tick_wins_visual;
    QLCDNumber* toe_wins_visual;
    QLCDNumber* draws_visual;

public:
    GameStatWidget(QWidget* widget = 0);


public slots:
    void increase_counter(GameStatus result);
    void reset_counters();

};

#endif