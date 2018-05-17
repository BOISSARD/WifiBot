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
    float xAbs = x < 0 ? x * -1 : x, yAbs = y < 0 ? y * -1 : y;

    if(x < 0 && xAbs >= yAbs)
        turnCamera(Direction::rightward);
    else if(x > 0 && xAbs >= yAbs)
        turnCamera(Direction::leftward);

    if(y < 0 && yAbs >= xAbs)
        turnCamera(Direction::backward);
    else if(y > 0 && yAbs >= xAbs)
        turnCamera(Direction::forward);

    if(x == 0 && y == 0) turnCamera(Direction::none);
}

void MainWindow::turnCamera(Direction direction){
    qDebug() << "Tourne caméra vers " << direction;
    int value = 0, id = 0;
    switch(direction){
    case Direction::forward :
        value = -200;
        id = 53;
        request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"));
        break;
    case Direction::backward :
        value = 200;
        id = 53;
        request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"));
        break;
    case Direction::rightward :
        value = -200;
        id = 52;
        request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"));
        break;
    case Direction::leftward :
        value = 200;
        id = 52;
        request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"));
        break;
    default : return;
    }
    /*stringstream ss;
    ss << "http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=100948" << id << "&group=1&value=" << value;
    //string *url; url = new string(ss.str());
    //qDebug() << "L'url est : " << ss.str();
    request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"));*/
}
