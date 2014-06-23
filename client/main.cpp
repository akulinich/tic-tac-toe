#include "playing_field.h"
#include "playing_field_widget.h"
#include "game_stat_widget.h"
#include "main_window.h"
#include "client.h"
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
    MainWindow main_window;
    main_window.show();
    return app.exec();
}