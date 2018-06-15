#ifndef ROBOTOUTPUTMANAGER_H
#define ROBOTOUTPUTMANAGER_H

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QByteArray>

#include "outputmanager.h"

#define CAMERAPORCENT 2500

class RobotOutputManager : virtual public OutputManager
{
public:
    RobotOutputManager();
    void moveRobot(Direction direction, float speed);
    void moveCamera(Direction direction, float speed);

private:
    QNetworkAccessManager *manager =new QNetworkAccessManager();
    QNetworkRequest request;
    QNetworkReply *reply;
};

#endif // ROBOTOUTPUTMANAGER_H
