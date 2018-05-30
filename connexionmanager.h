#ifndef CONNEXIONMANAGER_H
#define CONNEXIONMANAGER_H

class ConnexionManager
{
    public:
        ConnexionManager();
        //ConnexionManager(int ip, int port);
        virtual void envoyer() = 0;
        virtual void recevoir() = 0;
        virtual void connect() = 0;
        virtual void disconnect() = 0;
};

#endif // CONNEXIONMANAGER_H
