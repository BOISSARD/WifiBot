#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "joypad.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->widget1, &JoyPad::xChanged, this, [this](float x){
        qDebug() << "Joy1 x: " << x << " y: " << ui->widget1->y();
    });
    connect(ui->widget1, &JoyPad::yChanged, this, [this](float y){
        qDebug() << "Joy1 x: " << ui->widget1->x() << " y: " << y;
    });

    connect(ui->widget2, &JoyPad::xChanged, this, [this](float x){
        //qDebug() << "Joy2 x: " << x << " y: " << ui->widget2->y();
        joypadCamera(x,ui->widget2->y());
        if(x < 0)
            turnCamera(Direction::forward);
        else
            turnCamera(Direction::backward);
    });
    connect(ui->widget2, &JoyPad::yChanged, this, [this](float y){
        //qDebug() << "Joy2 x: " << ui->widget2->x() << " y: " << y;
        joypadCamera(ui->widget2->x(),y);
    });


}

void MainWindow::setOutputManager(OutputManager *output){
    this->output = output;
    qDebug() << "Setter de output";
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
}

void MainWindow::turnCamera(Direction direction){
    qDebug() << "Tourne caméra vers " << direction;
}
