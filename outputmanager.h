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

        virtual void moveRobot(Direction direction, float vitesse) = 0;
        virtual void moveCamera(Direction direction, float vitesse) = 0;

    private:
        ConnexionManager* connexion;
};

#endif // OUTPUTMANAGER_H
