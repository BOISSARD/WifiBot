#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include <QTextStream>
#include <iostream>

using namespace std;

class OutputManager
{
    public:
        OutputManager();
        virtual void display(string text);
};

#endif // OUTPUTMANAGER_H
