#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include <QTextStream>
#include <iostream>
#include "direction.h"
#include "connexionmanager.h"

using namespace std;

class OutputManager
{
    public:
        OutputManager();
        ~OutputManager();

        void setConnexionManager(ConnexionManager* connexion);

        virtual void moveRobot(Direction direction, float speed) = 0;
        virtual void moveCamera(Direction direction, float speed) = 0;

        ConnexionManager* getConnexion(){
            return connexion;
        }

    protected:
        ConnexionManager* connexion;
};

#endif // OUTPUTMANAGER_H
