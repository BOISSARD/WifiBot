#include <QApplication>

#include "mainwindow.h"
#include "outputmanager.h"
#include "consoleoutputmanager.h"
#include "inputmanager.h"
#include "keyboardinputmanager.h"
#include "direction.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setOutputManager(new ConsoleOutputManager());
    w.show();

    return a.exec();
}
