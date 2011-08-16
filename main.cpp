#include <QtGui/QApplication>
#include "mainwindow.h"
#include "cstalker.h"
#include "cscene.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
