#include "playing_field_widget.h"
#include "playing_field.h"
#include <Qt>
#include <QtWidgets>
#include <exception>


const int WIGHT_IN_CELL = 15;
const int HIGHT_IN_CELL = 15;
const int CELL_WIGHT = 40;
const int CELL_HIGHT = 40;

const int TIC_TOE_SMALL_COEF = 4;

PlayingFieldWidget::PlayingFieldWidget(QWidget* widget) 
    : QWidget(widget), field(WIGHT_IN_CELL) {

    play_enable = true;
    resize(WIGHT_IN_CELL * CELL_WIGHT + 1, HIGHT_IN_CELL * CELL_HIGHT + 1);
    setMinimumSize(size());
    setMaximumSize(size());
}

void PlayingFieldWidget::mouseReleaseEvent(QMouseEvent* pe) {
    if (!play_enable) {
        return;
    }

    QPoint center = pe->pos();

    center.rx() = (center.x() / CELL_WIGHT) * CELL_WIGHT + CELL_WIGHT / 2;
    center.ry() = (center.y() / CELL_HIGHT) * CELL_HIGHT + CELL_HIGHT / 2;
    Player turn = field.get_turn();
    try {
        field.do_turn(Position(int(center.x()) / CELL_WIGHT, int(center.y()) / CELL_HIGHT), turn);
    } catch (std::logic_error) {
        return;
    }

    if (turn == TICK) {
        ticks.push_back(QLine(center.x() - CELL_WIGHT / 2 + TIC_TOE_SMALL_COEF, 
            center.y() - CELL_HIGHT / 2 + TIC_TOE_SMALL_COEF,
            center.x() + CELL_WIGHT / 2 - TIC_TOE_SMALL_COEF, 
            center.y() + CELL_HIGHT / 2 - TIC_TOE_SMALL_COEF));
        ticks.push_back(QLine(center.x() + CELL_WIGHT / 2 - TIC_TOE_SMALL_COEF, 
            center.y() - CELL_HIGHT / 2 + TIC_TOE_SMALL_COEF,
            center.x() - CELL_WIGHT / 2 + TIC_TOE_SMALL_COEF, 
            center.y() + CELL_HIGHT / 2 - TIC_TOE_SMALL_COEF));
    } else {
        toes.push_back(QRect(QPoint(center.x() - CELL_WIGHT / 2 + TIC_TOE_SMALL_COEF, 
                   center.y() - CELL_HIGHT / 2 + TIC_TOE_SMALL_COEF),
            QPoint(center.x() + CELL_WIGHT / 2 - TIC_TOE_SMALL_COEF, 
                    center.y() + CELL_HIGHT / 2 - TIC_TOE_SMALL_COEF)));
    }

    repaint();
   
    if (field.end_game_check() != IN_PROGRESS) {
        emit end_game(field.end_game_check());
        play_enable = false;
    }
}

void PlayingFieldWidget::paintEvent(QPaintEvent* pe) {
    
    QPainter painter(this);
    painter.setPen(Qt::blue);

    for (int line = 0; line <= WIGHT_IN_CELL; ++line) {
        painter.drawLine(QPoint(line * CELL_WIGHT, 0), 
            QPoint(line * CELL_WIGHT, HIGHT_IN_CELL * CELL_HIGHT));
    }

    for (int line = 0; line <= HIGHT_IN_CELL; ++line) {
        painter.drawLine(QPoint(0, line * CELL_HIGHT), 
            QPoint(CELL_WIGHT * WIGHT_IN_CELL, line * CELL_HIGHT));
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

void PlayingFieldWidget::set_play_disable() {
    play_enable = false;
}

void PlayingFieldWidget::set_play_enable() {
    play_enable = true;
}

bool PlayingFieldWidget::get_play_enable() {
    return play_enable;
}

void PlayingFieldWidget::new_game() {
        play_enable = true;
        ticks.clear();
        toes.clear();
        field.reset_game();
        repaint();
}

