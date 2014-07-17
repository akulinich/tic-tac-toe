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

private slots:
    void setAllGameTypeCheckedFalse();

private:
    void create_menus();
    void create_actios();


    // game attributes
    GameWidget* game_field;
    GameStatWidget* stat;


    // menus
    QMenu* main_menu;
    QMenu* help;

    // actions
    QAction* reset_stat_act;
    QAction* author; 
    QAction* new_game;
    QActionGroup* game_type; // ( net ) or ( pl vs pl ) or ( pl vs cpu )
    QAction* set_pl_vs_pl; 
    QAction* set_pl_vs_cpu;
    QAction* set_net;
};


#endif