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

protected:
    void paintEvent(QPaintEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);

public:
    PlayingFieldWidget(QWidget* widget = 0);
    bool get_play_enable();

signals:
    void end_game();
};

#endif