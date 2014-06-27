#include <iostream>
#include <exception>
#include <QtGui>
#include <QtWidgets>

#include "main_window.h"

#include <QDebug>


int main(int argc, char *argv[])
{   
    qDebug() << "start";
    QApplication app(argc, argv);
    MainWindow main_window;
    main_window.show();
    return app.exec();
}