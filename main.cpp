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
    w.show();

    OutputManager *op;
    op = new ConsoleOutputManager();

    InputManager *ip;
    ip = new KeyboardInputManager();

    op->display("=========\nYOLO TEST\n=========");
    op->display();
    while(1)
    op->display((int)ip->getDirection());

    return a.exec();
}
