#include "robotoutputmanager.h"

RobotOutputManager::RobotOutputManager(){}

void RobotOutputManager::moveRobot(Direction direction, float speed){
    int speedI = speed*CAMERAPORCENT;
    int speedL, speedR;
    //qDebug() << "Le robot se déplace dans la direction " << (int)direction << " à la vitesse " << speedI;
    switch(direction){
        case Direction::forward :
            speedL = speedI;
            speedR = speedI;
        break;
        case Direction::backward :
            speedL = -speedI;
            speedR = -speedI;
        break;
        case Direction::leftward :
            speedL = speedI;
            speedR = -speedI;
        break;
        case Direction::rightward :
            speedL = -speedI;
            speedR = speedI;
        break;
        default :
        speedL = speedR = 0;
    }

    QByteArray* sendingByteArray;
    sendingByteArray = new QByteArray();
    quint32 Lvalue=qMin(qAbs(speedL),CAMERAPORCENT);
    quint32 Rvalue=qMin(qAbs(speedR),CAMERAPORCENT);
    sendingByteArray->clear();
    sendingByteArray->append((char)0xff);
    sendingByteArray->append((char)0x07);
    sendingByteArray->append((char)(Lvalue*240/CAMERAPORCENT));
    sendingByteArray->append((char)0x00);
    sendingByteArray->append((char)(Rvalue*240/CAMERAPORCENT));
    sendingByteArray->append((char)0x00);
    sendingByteArray->append(((char)connexion->pidMode&0b10101000)|(speedL<0?0b00000000:0b01000000)|(speedR<0?0b00000000:0b00010000));
    connexion->send(sendingByteArray);
}

void RobotOutputManager::moveCamera(Direction direction, float speed){
    int value = 200*speed, id = 100948;
    string str = "http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=";
    switch(direction){
    case Direction::forward :
        value *= -1;
        id = 10094853;
        break;
    case Direction::backward :
        id = 10094853;
        break;
    case Direction::rightward :
        value *= -1;
        id = 10094852;
        break;
    case Direction::leftward :
        id = 10094852;
        break;
    default :
        id = 168062211;
        value = 3;
        break;
    }
    str.append(to_string(id));
    str.append("&group=1&value=");
    str.append(to_string(value));
    request.setUrl(QUrl(QString::fromStdString(str)));
    reply = manager->get(request);
}

