#include <iostream>
#include "gui.h"
#include <QApplication>
#include "ui.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    GUI *gui = new GUI;
    gui->show();
    return a.exec();
}
