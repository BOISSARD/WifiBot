#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "joypad.h"

#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cameraStream(ui->IpName->text(),ui->HTTPPort->text());

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
    if(!connected){
        if(output->getConnexion()->connect(ui->IpName->text(),ui->TCPPort->text())){
            ui->connectionBtn->setText("Déconnexion");
            connected = true;
        }
    }else{
        output->getConnexion()->disconnect();
        ui->connectionBtn->setText("Connexion");
        connected = false;
    }
    cameraStream(ui->IpName->text(),ui->HTTPPort->text());
}

void MainWindow::on_resetCamera_pressed()
{
    turnCamera(Direction::none,0);
}

void MainWindow::on_resetRobot_pressed()
{
    moveRobot(Direction::none,0);
}

void MainWindow::joypadCamera(float x, float y){
    //qDebug() << "Camera : x = " << x << ", y = " << y ;
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
    //qDebug() << "Robot x: " << x << " y: " << y;
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

void MainWindow::keyPressEvent(QKeyEvent *event){
    int speedR = 1, speedC = 80;

    switch(event->key()){
        //bot commands
        case Qt::Key_Z:
            moveRobot(Direction::forward,speedR);
            break;
        case Qt::Key_S:
            moveRobot(Direction::backward,speedR);
            break;
        case Qt::Key_D:
            moveRobot(Direction::rightward,speedR);
            break;
        case Qt::Key_Q:
            moveRobot(Direction::leftward,speedR);
            break;
        /*case Qt::Key_Control:
            cameraCommands(CAMERA_RESET);
            break;*/
        case Qt::Key_Up:
            turnCamera(Direction::forward,speedC);
            break;
        case Qt::Key_Left:
            turnCamera(Direction::leftward,speedC);
            break;
        case Qt::Key_Down:
            turnCamera(Direction::backward,speedC);
            break;
        case Qt::Key_Right:
            turnCamera(Direction::rightward,speedC);
            break;
        case Qt::CTRL:
            turnCamera(Direction::none,0);
            break;
        default :
            moveRobot(Direction::none,0);
    }
}

void MainWindow::cameraStream(QString ip, QString port){
    QUrl url = QUrl("http://"+ip+":"+port+"/?action=stream");
    qDebug() << url;
    QWebEngineView *view = new QWebEngineView(ui->video);
    view->load(url);
    view->show();
}
