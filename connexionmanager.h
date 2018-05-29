#ifndef CONNEXIONMANAGER_H
#define CONNEXIONMANAGER_H

class ConnexionManager
{
    public:
        ConnexionManager();
        //ConnexionManager(int ip, int port);
        void envoyer();//const Commandes);
        void recevoir();
        virtual void connect();
        virtual void disconnect();
        /*virtual void envoyer();//const Commandes);
        virtual void recevoir();
        virtual void connect();
        virtual void disconnect();*/
};

#endif // CONNEXIONMANAGER_H
