#ifndef KEYBOARDINPUTMANAGER_H
#define KEYBOARDINPUTMANAGER_H

#include "inputmanager.h"

#include <iostream>

using namespace std;

class KeyboardInputManager : public InputManager
{
    public:
        KeyboardInputManager();
        virtual int getDirection();
};

#endif // KEYBOARDINPUTMANAGER_H
