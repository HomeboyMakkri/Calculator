#include "mainwindow.h"
#include <QStyle>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Calculator");
    w.show();

    return a.exec();
}