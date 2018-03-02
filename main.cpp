#include "mainwindow.h"
#include "outputmanager.h"
#include "consoleoutputmanager.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    OutputManager *op;
    op = new ConsoleOutputManager();

    op->display("\n==========\nYOLO TEST\n=========");
    //op->display();

    return a.exec();
}
