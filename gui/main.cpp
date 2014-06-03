#include "playing_field.h"
#include "playing_field_widget.h"
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
    
    QList<QLine> l;
    PlayingFieldWidget window;

    window.show();

    return app.exec();
}