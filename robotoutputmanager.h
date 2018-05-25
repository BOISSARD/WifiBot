#ifndef ROBOTOUTPUTMANAGER_H
#define ROBOTOUTPUTMANAGER_H

#include "outputmanager.h"

class RobotOutputManager : public OutputManager
{
public:
    RobotOutputManager();
    void moveRobot(Direction direction, float vitesse) = 0;
    void moveCamera(Direction direction, float vitesse) = 0;
};

#endif // ROBOTOUTPUTMANAGER_H
