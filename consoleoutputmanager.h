#ifndef CONSOLEOUTPUTMANAGER_H
#define CONSOLEOUTPUTMANAGER_H

#include "outputmanager.h"

using namespace std;

class ConsoleOutputManager : public OutputManager
{
    public:
        ConsoleOutputManager();
        void display(string text);
        void move(Direction direction, float vitesse);
        void moveCamera(Direction direction);
};

#endif // CONSOLEOUTPUTMANAGER_H
