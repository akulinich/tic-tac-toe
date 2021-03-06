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

    void clear();
    void emitNoGameSignal();
    void emitSendMessage(const QString&);
    void raizeEndGame();
    void endGame(GameState);
    void showNeedNewGameWindow();
    void newTurn(Turn turn);

signals:
    void signalEndGame(GameState);
    void signalMouseClicked(Position);
    void signalNeedNewGame(bool);
    void signalNoGame();
    void signalSendMessage(const QString&);

public slots:

    void slotSetPlayerVsPlayer();
    void slotSetPlayerVsCPU();
    void slotSetPlayerVsNet(); 

    void slotSetIpAndPort(); 
    void slotCreatePlayerVsNetGame(); 

    void slotNeedNewGameYes();
    void slotNeedNewGameNo();
};

#endif