#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include <QTextStream>
#include <iostream>
#include "direction.h"

using namespace std;

class OutputManager
{
    public:
        OutputManager();
        ~OutputManager();

        void display(int number);
        virtual void display(string text = "");
        virtual void move(Direction direction, float vitesse) = 0;
        virtual void moveCamera(Direction direction) = 0;

};

#endif // OUTPUTMANAGER_H
