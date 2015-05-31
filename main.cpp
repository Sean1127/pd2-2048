#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.start();
    w.show();
    w.win();
    w.end();
    return a.exec();
}
