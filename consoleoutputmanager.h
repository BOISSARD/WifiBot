#ifndef CONSOLEOUTPUTMANAGER_H
#define CONSOLEOUTPUTMANAGER_H

#include "outputmanager.h"

using namespace std;

class ConsoleOutputManager : virtual public OutputManager
{
    public:
        ConsoleOutputManager();
        void display(string text);
        void moveRobot(Direction direction, float vitesse);
        void moveCamera(Direction direction, float vitesse);
};

#endif // CONSOLEOUTPUTMANAGER_H
