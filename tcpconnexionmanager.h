#ifndef TCPCONNEXIONMANAGER_H
#define TCPCONNEXIONMANAGER_H

#define CAMERAPORCENT 2000

#include <iostream>
#include <stdlib.h>

#include <QTcpSocket>
#include <QString>
#include <QTimer>
#include <QByteArray>
#include <QDataStream>
#include <QHostAddress>

#include "connexionmanager.h"

class TCPConnexionManager : virtual public ConnexionManager
{
    public:
        TCPConnexionManager();
        void send(int LSpeed, int RSpeed);//const Commandes);
        void receive();
        bool connect(QString botHost, QString port);
        void disconnect();

    private:
        QTcpSocket* tcpSocket;
        QByteArray* sendingByteArray;
        QTimer* sendingTimer;
        PIDSettings pidMode;
};

#endif // WIFICONNEXIONMANAGER_H
