#include "playing_field_widget.h"
#include "playing_field.h"
#include <Qt>
#include <QtWidgets>
#include <exception>

const int TIC_TOE_SMALL_COEF = 4;

PlayingFieldWidget::PlayingFieldWidget(int size_of_field, int cell_size, QWidget* widget) 
    : QWidget(widget), field(size_of_field), 
    cell_size(cell_size), field_size(size_of_field) {

    play_enable = true;
    resize(size_of_field * cell_size + 1, size_of_field * cell_size + 1);
    setMinimumSize(size());
    setMaximumSize(size());
}

void PlayingFieldWidget::mouseReleaseEvent(QMouseEvent* pe) {
    if (!play_enable) {
        return;
    }


    QPoint center = pe->pos();

    center.rx() = (center.x() / cell_size) * cell_size + cell_size / 2;
    center.ry() = (center.y() / cell_size) * cell_size + cell_size / 2;
    Player turn = field.get_turn();
    try {
        field.do_turn(Position(int(center.x()) / cell_size, int(center.y()) / cell_size), turn);
    } catch (std::logic_error) {
        return;
    }

    if (turn == TICK) {
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
   
    if (field.end_game_check() != IN_PROGRESS) {
        emit end_game(field.end_game_check());
        play_enable = false;
    }
}

void PlayingFieldWidget::paintEvent(QPaintEvent* pe) {
    
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

