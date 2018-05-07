#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <iostream>
#include <QInputEvent>

#include "direction.h"

using namespace std;

class InputManager
{
    public:
        InputManager();
        virtual Direction getDirection();

    private:

};

#endif // INPUTMANAGER_H
