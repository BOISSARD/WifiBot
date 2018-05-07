#ifndef ROBOTOUTPUTMANAGER_H
#define ROBOTOUTPUTMANAGER_H

#include "outputmanager.h"

class RobotOutputManager : public OutputManager
{
public:
    RobotOutputManager();
    void move(Direction direction, float vitesse);
    void moveCamera(Direction direction);
};

#endif // ROBOTOUTPUTMANAGER_H
