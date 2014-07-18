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
    PlVsNet,
    NoGame
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

    QWidget* input_ip_and_port;
    QLineEdit* ip_line;
    QLineEdit* port_line;
    QString ip;
    int port;

    bool need_new_game;

    QWidget* need_new_game_widget;

protected:
    void paintEvent(QPaintEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);

public:
    GameWidget(int size_of_field, int cell_size, QWidget* widget = 0);

signals:
    void signalEndGame(GameState);
    void mouseClicked(Position);
    void needNewGame(bool);
    void signalNoGame();
    void signalSendMessage(const QString&);

public slots:
    void emitNoGameSignal();

    void raizeEndGame();
    void clear();
    void endGame(GameState);

    void setPlayerVsPlayer();
    void setPlayerVsCPU();
    void setPlayerVsNet();

    void setIpAndPort();
    void createPlayerVsNetGame();

    void showNeedNewGameWindow();

    void needNewGameYes();
    void needNewGameNo();

    void slotNewTurn(Turn turn);
};

#endif