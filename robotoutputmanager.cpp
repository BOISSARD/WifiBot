#include "robotoutputmanager.h"

RobotOutputManager::RobotOutputManager(){}

void RobotOutputManager::moveRobot(Direction direction, float speed){
    int speedI = speed*1000;
    qDebug() << "Le robot se déplace dans la direction " << (int)direction << " à la vitesse " << speedI;
    connexion->send(speedI,speedI);
}

void RobotOutputManager::moveCamera(Direction direction, float speed){
    //qDebug() << "La camera se déplace dans la direction " << (int)direction << " à la vitesse " << speed;
    int value = 200*speed, id = 0;
    switch(direction){
    case Direction::forward :
        value *= -1;
        id = 53;
        break;
    case Direction::backward :
        id = 53;
        break;
    case Direction::rightward :
        value *= -1;
        id = 52;
        break;
    case Direction::leftward :
        id = 52;
        break;
    default : return;
    }
    string str = "http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=100948";
    str.append(to_string(id));
    str.append("&group=1&value=");
    str.append(to_string(value));
    request.setUrl(QUrl(QString::fromStdString(str)));
    reply = manager->get(request);
    /*while (reply->isRunning()) {
        QThread::msleep(100);
    }*/
}

