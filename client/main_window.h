#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui>
#include <QtWidgets>

#include "game_kernel.h"
#include "game_widget.h"
#include "game_stat_widget.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public: 
    MainWindow();

public slots:
    void slotSetAllGameTypeCheckedFalse();
    void slotSetGameStateLine(const QString& str);
    void slotEndGame(GameState result);

private:
    void create_menus();
    void create_actios();


    // game attributes
    GameWidget* game_field;
    GameStatWidget* stat;
    QLabel* game_state_line;


    // menus
    QMenu* main_menu;
    QMenu* help;

    // actions
    QAction* reset_stat_act;
    QAction* author; 
    QAction* new_game;
    QActionGroup* game_type;
    QAction* set_pl_vs_pl; 
    QAction* set_pl_vs_cpu;
    QAction* set_net;
};


#endif