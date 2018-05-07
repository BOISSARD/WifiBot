#ifndef KEYBOARDINPUTMANAGER_H
#define KEYBOARDINPUTMANAGER_H

#include <iostream>
//#include <conio.h>

#include "inputmanager.h"

using namespace std;

class KeyboardInputManager : public InputManager
{
    public:
        KeyboardInputManager();
        virtual Direction getDirection();

    private:
        Direction intToDirection(int c);
};

#endif // KEYBOARDINPUTMANAGER_H
