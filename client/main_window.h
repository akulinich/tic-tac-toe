#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui>
#include <QtWidgets>

#include "playing_field.h"
#include "playing_field_widget.h"
#include "game_stat_widget.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public: 
    MainWindow();

private:
    void create_menus();
    void create_actios();


    // game attributes
    PlayingFieldWidget* game_field;
    GameStatWidget* stat;
    QPushButton* new_game_button;


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