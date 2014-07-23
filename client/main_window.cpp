#include <main_window.h>

#include <QtGui>
#include <QtWidgets>

#include "game_kernel.h"
#include "game_widget.h"
#include "game_stat_widget.h"
#include "structurs.h"

const int FIELD_SIZE = 10;
const int CELL_SIZE = 30;

MainWindow::MainWindow() {
    QWidget* main_widget = new QWidget;
    setCentralWidget(main_widget);
    
    // main widgets
    game_field = new GameWidget(FIELD_SIZE, CELL_SIZE);
    stat = new GameStatWidget;
    
    // signal-slot conection
    connect(game_field, SIGNAL(signalNoGame()), 
        this, SLOT(slotSetAllGameTypeCheckedFalse()));
    connect(game_field, SIGNAL(signalEndGame(GameState)),
        this, SLOT(slotEndGame(GameState)));
    connect(game_field, SIGNAL(signalSendMessage(const QString&)), 
        this, SLOT(slotSetGameStateLine(const QString&)));

    // layout setup

    QVBoxLayout* main_layout = new QVBoxLayout;

    main_layout->addWidget(stat);
    main_layout->addWidget(game_field);
    game_state_line = new QLabel("");
    main_layout->addWidget(game_state_line);

    main_widget->setLayout(main_layout); 

    create_actios();
    create_menus();

    setWindowTitle(tr("Tic-Tac-Toe"));
    slotSetGameStateLine("player vs cpu game stareted");
}

void MainWindow::slotEndGame(GameState result) {
    stat->increase_counter(result);
}

void MainWindow::slotSetGameStateLine(const QString& str) {
    game_state_line->setText(str);
}

void MainWindow::slotSetAllGameTypeCheckedFalse() {
    set_pl_vs_cpu->setChecked(false);
    set_pl_vs_pl->setChecked(false);
    set_net->setChecked(false);
}

void MainWindow::create_menus() {
    main_menu = menuBar()->addMenu("Game Menu");
    
    main_menu->addAction(new_game);
    main_menu->addAction(reset_stat_act);
    main_menu->addSeparator()->setText(tr("Game Type"));
    main_menu->addAction(set_pl_vs_pl);
    main_menu->addAction(set_pl_vs_cpu);
    main_menu->addAction(set_net);
    main_menu->addSeparator();
    main_menu->addAction(author); 
}

void MainWindow::create_actios() {
    reset_stat_act = new QAction("Clear score", this);
    connect(reset_stat_act, SIGNAL(triggered()), stat, SLOT(reset_counters()));

    new_game = new QAction("New game", this);
    

    author = new QAction("Author", this); 
    // добавить информацию о авторе

    game_type = new QActionGroup(this); 

    set_pl_vs_pl = new QAction("Player vs Player", this);
    connect(set_pl_vs_pl, SIGNAL(triggered()), game_field, SLOT(slotSetPlayerVsPlayer()));
    connect(set_pl_vs_pl, SIGNAL(triggered()), stat, SLOT(reset_counters()));
    set_pl_vs_pl->setCheckable(true); 
    // set_pl_vs_pl->setChecked(true);

    set_pl_vs_cpu = new QAction("Player vs CPU", this);
    connect(set_pl_vs_cpu, SIGNAL(triggered()), game_field, SLOT(slotSetPlayerVsCPU()));
    connect(set_pl_vs_cpu, SIGNAL(triggered()), stat, SLOT(reset_counters()));
    set_pl_vs_cpu->setCheckable(true);
    set_pl_vs_cpu->setChecked(true);
    // set_pl_vs_cpu->setEnabled(false);

    set_net = new QAction("Net game", this);
    connect(set_net, SIGNAL(triggered()), game_field, SLOT(slotSetPlayerVsNet()));
    connect(set_net, SIGNAL(triggered()), stat, SLOT(reset_counters()));
    set_net->setCheckable(true);
    // set_net->setEnabled(false);
    
    game_type->addAction(set_pl_vs_pl);
    game_type->addAction(set_pl_vs_cpu);
    game_type->addAction(set_net);
}