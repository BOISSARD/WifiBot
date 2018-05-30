#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "joypad.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->widget1, &JoyPad::xChanged, this, [this](float x){
        joypadRobot(x, ui->widget1->y());
    });
    connect(ui->widget1, &JoyPad::yChanged, this, [this](float y){
        joypadRobot(ui->widget1->x(),y);
    });

    connect(ui->widget2, &JoyPad::xChanged, this, [this](float x){
        joypadCamera(x,ui->widget2->y());
    });
    connect(ui->widget2, &JoyPad::yChanged, this, [this](float y){
        joypadCamera(ui->widget2->x(),y);
    });

}

void MainWindow::setOutputManager(OutputManager *output){
    this->output = output;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectionBtn_pressed()
{
    qDebug() << "Demande de connexion !";
}

void MainWindow::joypadCamera(float x, float y){
    qDebug() << "Camera : x = " << x << ", y = " << y ;
    float xAbs = x < 0 ? x * -1 : x, yAbs = y < 0 ? y * -1 : y;

    if(x < 0 && xAbs >= yAbs)
        turnCamera(Direction::rightward,xAbs);
    else if(x > 0 && xAbs >= yAbs)
        turnCamera(Direction::leftward,xAbs);

    if(y < 0 && yAbs >= xAbs)
        turnCamera(Direction::backward,yAbs);
    else if(y > 0 && yAbs >= xAbs)
        turnCamera(Direction::forward,yAbs);

    if(x == 0 && y == 0) turnCamera(Direction::none,0);
}

void MainWindow::turnCamera(Direction direction, float speed){
    output->moveCamera(direction,speed);
}

void MainWindow::joypadRobot(float x, float y){
    qDebug() << "Robot x: " << x << " y: " << y;
    float xAbs = x < 0 ? x * -1 : x, yAbs = y < 0 ? y * -1 : y;

    if(x < 0 && xAbs >= yAbs)
        moveRobot(Direction::rightward,xAbs);
    else if(x > 0 && xAbs >= yAbs)
        moveRobot(Direction::leftward,xAbs);

    if(y < 0 && yAbs >= xAbs)
        moveRobot(Direction::backward,yAbs);
    else if(y > 0 && yAbs >= xAbs)
        moveRobot(Direction::forward,yAbs);
}

void MainWindow::moveRobot(Direction direction, float speed){
    output->moveRobot(direction,speed);
}
