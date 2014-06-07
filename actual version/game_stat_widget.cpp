#include "game_stat_widget.h"
#include "playing_field_widget.h"
#include "playing_field.h"

GameStatWidget::GameStatWidget(QWidget* widget)
    : QWidget(widget) {

    main_layout = new QGridLayout;

    tick_wins_visual = new QLCDNumber(3);
    draws_visual = new QLCDNumber(3);
    toe_wins_visual = new QLCDNumber(3);

    tick_wins_visual->setSegmentStyle(QLCDNumber::Flat);
    toe_wins_visual->setSegmentStyle(QLCDNumber::Flat);
    draws_visual->setSegmentStyle(QLCDNumber::Flat);

    main_layout->addWidget(new QWidget(this), 2, 1);
    main_layout->addWidget(tick_wins_visual, 2, 2);
    main_layout->addWidget(new QWidget(this), 2, 3);
    main_layout->addWidget(draws_visual, 2, 4);
    main_layout->addWidget(new QWidget(this), 2, 5);
    main_layout->addWidget(toe_wins_visual, 2, 6);
    main_layout->addWidget(new QWidget(this), 2, 7);

    main_layout->addWidget(new QWidget(this), 1, 1);
    main_layout->addWidget(new QLabel("tick wins"), 1, 2);
    main_layout->addWidget(new QWidget(this), 1, 3);
    main_layout->addWidget(new QLabel("draws"), 1, 4);
    main_layout->addWidget(new QWidget(this), 1, 5);
    main_layout->addWidget(new QLabel("toe wins"), 1, 6);
    main_layout->addWidget(new QWidget(this), 1, 7);
    setLayout(main_layout);

    count_tick_win = 0;
    count_toe_win = 0;
    count_draws = 0;
}


void GameStatWidget::increase_counter(GameStatus result) {
    
    if (result == DRAW) {
        ++count_draws;
        draws_visual->display(count_draws);
    }
    if (result == TICK_WIN) {
        ++count_tick_win;
        tick_wins_visual->display(count_tick_win);
    }
    if (result == TOE_WIN) {
        ++count_toe_win;
        toe_wins_visual->display(count_toe_win);
    }
}

void GameStatWidget::reset_counters() {
    count_draws = 0;
    count_toe_win = 0;
    count_tick_win = 0;
    draws_visual->display(count_draws);
    tick_wins_visual->display(count_tick_win);
    toe_wins_visual->display(count_toe_win);
}