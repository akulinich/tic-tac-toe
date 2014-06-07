#include <main_window.h>

#include <QtGui>
#include <QtWidgets>

#include "playing_field.h"
#include "playing_field_widget.h"
#include "game_stat_widget.h"

MainWindow::MainWindow() {
    QWidget* main_widget = new QWidget;
    setCentralWidget(main_widget);

    // size computition
    int screen_height = QApplication::desktop()->height();
    int screen_width = QApplication::desktop()->width();

    int field_size = 10;
    int width_cell_size = (screen_width - 25) / field_size;
    int height_cell_size = (screen_height - 200) / field_size;
    int cell_size = height_cell_size < width_cell_size ? 
                    height_cell_size : width_cell_size;
   
    cell_size = 30;

    // main widgets
    game_field = new PlayingFieldWidget(field_size, cell_size);
    new_game_button = new QPushButton("new game");
    stat = new GameStatWidget;
    
    // signal-slot conection
    QObject::connect(new_game_button, SIGNAL(clicked()), 
                    game_field, SLOT(new_game()));
    QObject::connect(game_field, SIGNAL(end_game(GameStatus)), 
                     stat, SLOT(increase_counter(GameStatus)));
    // layout setup

    QVBoxLayout* main_layout = new QVBoxLayout;

    main_layout->addWidget(stat);
    main_layout->addWidget(game_field);
    main_layout->addWidget(new_game_button);

    main_widget->setLayout(main_layout); 

    create_actios();
    create_menus();

    setWindowTitle(tr("Tic-Tac-Toe"));
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
    connect(new_game, SIGNAL(triggered()), game_field, SLOT(new_game()));

    author = new QAction("Author", this); 
    // добавить информацию о авторе

    game_type = new QActionGroup(this); 

    set_pl_vs_pl = new QAction("Player vs Player", this);
    set_pl_vs_pl->setCheckable(true); 
    set_pl_vs_pl->setChecked(true);

    set_pl_vs_cpu = new QAction("Player vs CPU", this);
    set_pl_vs_cpu->setCheckable(true);
    set_pl_vs_cpu->setEnabled(false);

    set_net = new QAction("Net game", this);
    set_net->setCheckable(true);
    set_net->setEnabled(false);
    
    game_type->addAction(set_pl_vs_pl);
    game_type->addAction(set_pl_vs_cpu);
    game_type->addAction(set_net);
}