#include "playing_field_widget.h"
#include "playing_field.h"
#include <Qt>
#include <QtWidgets>
#include <exception>


const int WIGHT_IN_CELL = 10;
const int HIGHT_IN_CELL = 10;
const int CELL_WIGHT = 40;
const int CELL_HIGHT = 40;

PlayingFieldWidget::PlayingFieldWidget(QWidget* widget) 
    : QWidget(widget), field(WIGHT_IN_CELL) {

    resize(WIGHT_IN_CELL * CELL_WIGHT, HIGHT_IN_CELL * CELL_HIGHT);
    setMinimumSize(size());
    setMaximumSize(size());
}

void PlayingFieldWidget::mouseReleaseEvent(QMouseEvent* pe) {
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
        ticks.push_back(QLine(center.x() - CELL_WIGHT / 2, center.y() - CELL_HIGHT / 2,
                          center.x() + CELL_WIGHT / 2, center.y() + CELL_HIGHT / 2));
        ticks.push_back(QLine(center.x() + CELL_WIGHT / 2, center.y() - CELL_HIGHT / 2,
                          center.x() - CELL_WIGHT / 2, center.y() + CELL_HIGHT / 2));
    } else {
        toes.push_back(QRect(QPoint(center.x() - CELL_WIGHT / 2, center.y() - CELL_HIGHT / 2),
                            QPoint(center.x() + CELL_WIGHT / 2, center.y() + CELL_HIGHT / 2)));
    }
   
    if (field.end_game_check() != IN_PROGRESS) {
        ticks.clear();
        toes.clear();
        field.reset_game();
    }

    repaint();
}

void PlayingFieldWidget::paintEvent(QPaintEvent* pe) {
    
    QPainter painter(this);
    painter.setPen(Qt::blue);
    for (int line = 1; line < WIGHT_IN_CELL; ++line) {
        painter.drawLine(QPoint(line * CELL_WIGHT, 0), 
            QPoint(line * CELL_WIGHT, HIGHT_IN_CELL * CELL_HIGHT));
    }

    for (int line = 1; line < HIGHT_IN_CELL; ++line) {
        painter.drawLine(QPoint(0, line * CELL_HIGHT), 
            QPoint(CELL_WIGHT * WIGHT_IN_CELL, line * CELL_HIGHT));
    }

    painter.setPen(Qt::red);
    for (auto& obj : ticks) {
        painter.drawLine(obj);
    }
    painter.setPen(Qt::blue);
    for (auto& obj : toes) {
        painter.drawEllipse(obj);
    }
}

