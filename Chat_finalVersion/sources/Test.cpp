#include <iostream>
#include "CommandLineInterface.h"
#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include "serverpanel.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator myappTranslator;
    myappTranslator.load("translations/my_ru.qm");
    a.installTranslator(&myappTranslator);

    QTranslator qtTranslator;
    qtTranslator.load("translations/qt_ru.qm");
    a.installTranslator(&qtTranslator);

    auto DB = make_shared<Database>();

    //ServerPanel s(DB);
    //s.show();

    auto w = MainWindow::createClient(DB);
    if(w)
        w->show();
    else
        return 0;

    return a.exec();

}


