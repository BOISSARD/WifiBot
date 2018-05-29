#ifndef TCPCONNEXIONMANAGER_H
#define TCPCONNEXIONMANAGER_H

#include <iostream>
#include <stdlib.h>
//#include <unistd.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <QNetworkAccessManager>
//#include <QNetworkRequest>

#include "connexionmanager.h"

class TCPConnexionManager : virtual public ConnexionManager
{
    public:
        TCPConnexionManager();
        void envoyer();//const Commandes);
        void recevoir();
        void connect();
        void disconnect();
};

#endif // WIFICONNEXIONMANAGER_H
