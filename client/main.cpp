#include "playing_field.h"
#include "playing_field_widget.h"
#include "game_stat_widget.h"
#include <main_window.h>
#include <iostream>
#include <exception>
#include <QtGui>
#include <QtWidgets>


using std::cin;
using std::cout;
using std::endl;


int main(int argc, char *argv[])
{   

    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("asdfs");


    MainWindow main_window;
    main_window.show();


    // QWidget main_window;

    
    // // size computition
    // int screen_height = QApplication::desktop()->height();
    // int screen_width = QApplication::desktop()->width();

    // int field_size = 10;
    // int width_cell_size = (screen_width - 25) / field_size;
    // int height_cell_size = (screen_height - 200) / field_size;
    // int cell_size = height_cell_size < width_cell_size ? 
    //                 height_cell_size : width_cell_size;
   
    // cell_size = 30;

    

    // // main widgets
    // PlayingFieldWidget* game_field = new PlayingFieldWidget(field_size, cell_size);
    // QPushButton* new_game_button = new QPushButton("new game");
    // GameStatWidget* stat = new GameStatWidget;
    


    
    // // signal-slot conection
    // QObject::connect(new_game_button, SIGNAL(clicked()), 
    //                 game_field, SLOT(new_game()));
    // QObject::connect(game_field, SIGNAL(end_game(GameStatus)), 
    //                  stat, SLOT(increase_counter(GameStatus)));
    // // layout setup

    // QVBoxLayout* main_layout = new QVBoxLayout;

    // main_layout->addWidget(stat);
    // main_layout->addWidget(game_field);
    // main_layout->addWidget(new_game_button);

    // main_window.setLayout(main_layout); 



    // main_window.show();



    

    return app.exec();
}