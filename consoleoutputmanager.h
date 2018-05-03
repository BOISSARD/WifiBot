#ifndef CONSOLEOUTPUTMANAGER_H
#define CONSOLEOUTPUTMANAGER_H

#include "outputmanager.h"

using namespace std;

class ConsoleOutputManager : public OutputManager
{
    public:
        ConsoleOutputManager();
        virtual void display(string text);
};

#endif // CONSOLEOUTPUTMANAGER_H
