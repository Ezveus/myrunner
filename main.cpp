//
// main.cpp for project MyRunner
//
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
//
// Started by Matthieu Ciappara on Thu Apr 14 16:20:59 2011
//

#include <QObject>
#include <QApplication>
#include <QTranslator>
#include <QString>
#include <QLocale>
#include "runner.hpp"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    Runner win;

    win.show();

    return (app.exec());
}
