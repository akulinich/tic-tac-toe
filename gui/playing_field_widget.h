#ifndef PLAYING_FIELD_WIDGET_H
#define PLAYING_FIELD_WIDGET_H

#include <Qt>
#include <QtWidgets>
#include <QList>
#include "playing_field.h"



class PlayingFieldWidget : public QWidget {

private:
    QList<QLine> ticks;
    QList<QRect> toes;

    PlayingField field;

protected:
    void paintEvent(QPaintEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);

public:
    PlayingFieldWidget(QWidget* widget = 0);
};

#endif