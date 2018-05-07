#include "keyboardinputmanager.h"

KeyboardInputManager::KeyboardInputManager()
{

}

Direction KeyboardInputManager::getDirection(){
    int c = 0;//getch();
    do {
        //c = getch();
    }while(c == 224);
    return intToDirection(c);//Direction::rightward;
}

Direction KeyboardInputManager::intToDirection(int c){
    switch (c) {
        case 72:
            return Direction::forward;
        case 80:
            return Direction::backward;
        case 75:
            return Direction::leftward;
        case 77:
            return Direction::rightward;
        default:
            return Direction::none;
    }
}
