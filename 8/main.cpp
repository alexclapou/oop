#include <QtWidgets/QApplication>
#include <iostream>
#include <string>
#include "ui.h"
#include "gui.h"
#include "test.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI gui;
    gui.show();
    return a.exec();
}
