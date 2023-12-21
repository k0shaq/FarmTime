#include "mainwindow.h"
#include "startwindow.h"
#include <QApplication>
#include "cabinet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    StartWindow s;
    s.show();
    return s.exec();
}
