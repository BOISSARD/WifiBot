#ifndef TCPCONNEXIONMANAGER_H
#define TCPCONNEXIONMANAGER_H

#include <iostream>
//#include <unistd.h>
#include <stdlib.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <QNetworkAccessManager>
//#include <QNetworkRequest>

#include "connexionmanager.h"

class TCPConnexionManager// : virtual public ConnexionManager
{
public:
    TCPConnexionManager();

private:
    void envoyer();//const Commandes);
    void recevoir();
    void connect();
    void disconnect();
};

#endif // WIFICONNEXIONMANAGER_H
