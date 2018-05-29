#ifndef ROBOTOUTPUTMANAGER_H
#define ROBOTOUTPUTMANAGER_H

#include "outputmanager.h"

class RobotOutputManager : virtual public OutputManager
{
public:
    RobotOutputManager();
    void moveRobot(Direction direction, float vitesse);
    void moveCamera(Direction direction, float vitesse);
};

#endif // ROBOTOUTPUTMANAGER_H
