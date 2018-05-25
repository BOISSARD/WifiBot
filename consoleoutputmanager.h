#ifndef CONSOLEOUTPUTMANAGER_H
#define CONSOLEOUTPUTMANAGER_H

#include "outputmanager.h"

using namespace std;

class ConsoleOutputManager : public OutputManager
{
    public:
        ConsoleOutputManager();
        void display(string text);
        void moveRobot(Direction direction, float vitesse) = 0;
        void moveCamera(Direction direction, float vitesse) = 0;
};

#endif // CONSOLEOUTPUTMANAGER_H
