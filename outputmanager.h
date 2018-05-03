#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include <QTextStream>
#include <iostream>

using namespace std;

class OutputManager
{
    public:
        OutputManager();
        void display(int number);
        virtual void display(string text = "");
};

#endif // OUTPUTMANAGER_H
