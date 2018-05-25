#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include <QTextStream>
#include <iostream>
#include "direction.h"

using namespace std;

class OutputManager
{
    public:
        OutputManager();
        ~OutputManager();

        virtual void moveRobot(Direction direction, float vitesse) = 0;
        virtual void moveCamera(Direction direction, float vitesse) = 0;

};

#endif // OUTPUTMANAGER_H
