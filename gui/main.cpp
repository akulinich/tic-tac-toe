#include "playing_field.h"
#include "playing_field_widget.h"
#include "game_stat_widget.h"
#include <iostream>
#include <exception>
#include <QtGui>
#include <QtWidgets>


using std::cin;
using std::cout;
using std::endl;


const int SIZE_OF_FIELD = 10;

int main(int argc, char *argv[])
{   

    QApplication app(argc, argv);
    QWidget main_window;

    PlayingFieldWidget* game_field = new PlayingFieldWidget;
    QPushButton* new_game_button = new QPushButton("new game");
    GameStatWidget* stat = new GameStatWidget;


    QObject::connect(new_game_button, SIGNAL(clicked()), 
                    game_field, SLOT(new_game()));
    QObject::connect(game_field, SIGNAL(end_game(GameStatus)), 
                     stat, SLOT(increase_counter(GameStatus)));
    // layout setup

    QVBoxLayout* main_layout = new QVBoxLayout;

    main_layout->addWidget(stat);
    main_layout->addWidget(game_field);
    main_layout->addWidget(new_game_button);

    main_window.setLayout(main_layout); 

    main_window.show();

    

    return app.exec();
}