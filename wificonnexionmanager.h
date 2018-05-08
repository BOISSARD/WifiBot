#ifndef WIFICONNEXIONMANAGER_H
#define WIFICONNEXIONMANAGER_H


class WifiConnexionManager
{
public:
    WifiConnexionManager();
    WifiConnexionManager(int ip, int port);
    void envoyer();//const Commandes);
    void recevoir();
    void connect();
    void disconnect();
};

#endif // WIFICONNEXIONMANAGER_H
