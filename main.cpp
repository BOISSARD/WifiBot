#include <QApplication>

#include "mainwindow.h"
#include "outputmanager.h"
#include "robotoutputmanager.h"
#include "inputmanager.h"
#include "keyboardinputmanager.h"
#include "direction.h"
#include "connexionmanager.h"
#include "tcpconnexionmanager.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConnexionManager* cm;// = new TCPConnexionManager();//TCP
    OutputManager* om = new RobotOutputManager();
    om->setConnexionManager(cm);

    MainWindow w;
    w.setOutputManager(om);
    w.show();

    return a.exec();
}
