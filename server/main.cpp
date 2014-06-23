#include "server.h"
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
    Server server(8080);
    server.show();

    return app.exec();
}