#ifndef GAME_WIDGET_CPP
#define GAME_WIDGET_CPP

#include "game_widget.h"
#include "game_kernel.h"
#include "game_base.h"
#include "structurs.h"
#include "main_window.h"


#include <Qt>
#include <QtWidgets>
#include <exception>
#include <QtDebug>


class MainWindow;

const int TIC_TOE_SMALL_COEF = 4;

GameWidget::GameWidget(int size_of_field, int cell_size, QWidget* widget) 
    : QWidget(widget), 
    cell_size(cell_size), field_size(size_of_field) {

    game = NULL;

    qDebug() << "game widget constructor";

    slotSetPlayerVsCPU();

    resize(size_of_field * cell_size + 1, size_of_field * cell_size + 1);
    setMinimumSize(size());
    setMaximumSize(size());

    ip = "0.0.0.0";
    port = 8080;
}


void GameWidget::newTurn(Turn turn) {
    QPoint center(turn.pos.x_cor * cell_size, turn.pos.y_cor * cell_size);

    center.rx() = (center.x() / cell_size) * cell_size + cell_size / 2;
    center.ry() = (center.y() / cell_size) * cell_size + cell_size / 2;
    
    qDebug() << center.rx() << " " << center.ry();

    if (turn.side == TICK_SIDE) {
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
}

void GameWidget::mouseReleaseEvent(QMouseEvent* pe) {
    qDebug() << "mouse event start";

    QPoint center = pe->pos();

    center.rx() = (center.x() / cell_size) * cell_size + cell_size / 2;
    center.ry() = (center.y() / cell_size) * cell_size + cell_size / 2;

    emit signalMouseClicked(Position(int(center.x()) / cell_size, 
                               int(center.y()) / cell_size));
    qDebug() << "mouse event end";
}

void GameWidget::paintEvent(QPaintEvent* pe) {
    
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

void GameWidget::clear() {
    ticks.clear();
    toes.clear();

    repaint();
}

void GameWidget::endGame(GameState result) {
    qDebug() << "GameWidget::endGame" << sender();
    
    if (result == PLAYER_ONE_WIN) {
        emit signalSendMessage("player one win");
    }
    if (result == PLAYER_TWO_WIN) {
        emit signalSendMessage("player two win");
    }
    if (result == DRAW) {
        emit signalSendMessage("draw");
    }

    showNeedNewGameWindow();

    emit signalEndGame(result);
}

void GameWidget::raizeEndGame() {
    emit endGame(game->getGameState());
}

void GameWidget::slotSetPlayerVsPlayer() {
    emit signalSendMessage("player vs player game started");
    delete game;
    game = new UserGame(this, field_size);
    connect(this, SIGNAL(signalMouseClicked(Position)), 
        game, SLOT(slotGetUserTurn(Position)));
    type = PlVsPl;
    clear();
}

void GameWidget::slotSetPlayerVsCPU() {
    emit signalSendMessage("player vs cpu game started");
    delete game;
    game = new CPUGame(this, field_size);
    connect(this, SIGNAL(signalMouseClicked(Position)), 
        game, SLOT(slotGetUserTurn(Position)));
    type = PlVsCPU;
    clear();
}

void GameWidget::slotSetIpAndPort() {
    ip = ip_line->text();
    port = port_line->text().toInt();
    input_ip_and_port->close();
    delete input_ip_and_port;
}

void GameWidget::slotCreatePlayerVsNetGame() {
    qDebug() << "createPlayerVsNetGame";

    delete game;

    game = new NetGame(this, field_size, ip, port);
    connect(this, SIGNAL(signalMouseClicked(Position)), 
        game, SLOT(slotGetUserTurn(Position)));

    type = PlVsNet;

    clear();
}


void GameWidget::slotSetPlayerVsNet() {
    emit signalSendMessage("player vs net game started");
    input_ip_and_port = new QWidget;
    QLabel* ip_label = new QLabel("ip");
    QLabel* port_label = new QLabel("port");
    ip_line = new QLineEdit;
    ip_line->setText("localhost");
    port_line = new QLineEdit;
    port_line->setText("8080");
    QPushButton* button = new QPushButton("Ok");
    QVBoxLayout* main_layout = new QVBoxLayout;
    QHBoxLayout* ip_layout = new QHBoxLayout;
    QHBoxLayout* port_layout = new QHBoxLayout;

    connect(button, SIGNAL(clicked()), this, SLOT(slotSetIpAndPort()));
    connect(input_ip_and_port, SIGNAL(destroyed()), 
        this, SLOT(slotCreatePlayerVsNetGame()));

    ip_layout->addWidget(ip_label);
    ip_layout->addWidget(ip_line);

    port_layout->addWidget(port_label);
    port_layout->addWidget(port_line);

    main_layout->addLayout(ip_layout);
    main_layout->addLayout(port_layout);
    main_layout->addWidget(button);

    input_ip_and_port->setLayout(main_layout);
    input_ip_and_port->show();
}

void GameWidget::showNeedNewGameWindow() {
    qDebug() << "showNeedNewGameWindow" << sender();

    need_new_game_widget = new QWidget;
    QLabel* quation_label = new QLabel("Do you want new game whit this player?");
    QPushButton* need_button = new QPushButton("Yes");
    QPushButton* not_need_button = new QPushButton("No");

    QVBoxLayout* main_layout = new QVBoxLayout;

    main_layout->addWidget(quation_label);

    QHBoxLayout* button_layout = new QHBoxLayout;
    button_layout->addWidget(not_need_button);
    button_layout->addWidget(need_button);

    main_layout->addLayout(button_layout);

    need_new_game_widget->setLayout(main_layout);
    need_new_game_widget->show();

    connect(need_button, SIGNAL(clicked()), this, SLOT(slotNeedNewGameYes()));
    connect(not_need_button, SIGNAL(clicked()), this, SLOT(slotNeedNewGameNo()));
}

void GameWidget::slotNeedNewGameYes() {
    delete need_new_game_widget;
    game->slotGetNewGameDecision(true);

    if (type == PlVsNet) {
        emit signalSendMessage("player vs net game started");
    }
    if (type == PlVsCPU) {
        emit signalSendMessage("player vs cpu game started");
    }
    if (type == PlVsPl) {
        emit signalSendMessage("player vs player game started");
    }
}

void GameWidget::slotNeedNewGameNo() {
    delete need_new_game_widget;
    game->slotGetNewGameDecision(false);
    emit signalNoGame();
    emit signalSendMessage("no game");
}

void GameWidget::emitNoGameSignal() {
    emit signalNoGame();
}

void GameWidget::emitSendMessage(const QString& text) {
    emit signalSendMessage(text);
}


#endif
