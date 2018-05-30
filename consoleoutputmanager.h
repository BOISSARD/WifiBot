#ifndef CONSOLEOUTPUTMANAGER_H
#define CONSOLEOUTPUTMANAGER_H

#include "outputmanager.h"

using namespace std;

class ConsoleOutputManager : virtual public OutputManager
{
    public:
        ConsoleOutputManager();
        void moveRobot(Direction direction, float speed);
        void moveCamera(Direction direction, float speed);
};

#endif // CONSOLEOUTPUTMANAGER_H
