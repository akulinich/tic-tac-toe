#ifndef PLAYING_FIELD_WIDGET_H
#define PLAYING_FIELD_WIDGET_H

#include <Qt>
#include <QtWidgets>
#include <QList>
#include "playing_field.h"



class PlayingFieldWidget : public QWidget {
Q_OBJECT

private:
    QList<QLine> ticks;
    QList<QRect> toes;

    PlayingField field;

    bool play_enable;

    void set_play_disable();
    void set_play_enable();

    int cell_size;
    int field_size;

protected:
    void paintEvent(QPaintEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);

public:
    PlayingFieldWidget(int size_of_field, int cell_size, QWidget* widget = 0);
    bool get_play_enable();

signals:
    void end_game(GameStatus result);

public slots:
    void new_game();
};

#endif