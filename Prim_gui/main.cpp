#include "MVC_view/mainwindow.h"
#include <QApplication>
#include <QLayout>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setFixedSize(640,480);
    w.show();

    return a.exec();
}


// se le librerie non funzionano: ldconfig /usr/local/lib/