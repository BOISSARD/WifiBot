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
        qDebug() << "Joy2 x: " << x << " y: " << ui->widget2->y();
    });
    connect(ui->widget2, &JoyPad::yChanged, this, [this](float y){
        qDebug() << "Joy2 x: " << ui->widget2->x() << " y: " << y;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
