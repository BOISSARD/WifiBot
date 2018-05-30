#include "consoleoutputmanager.h"

ConsoleOutputManager::ConsoleOutputManager(){}

void ConsoleOutputManager::moveRobot(Direction direction, float speed){
    cout << "Le robot se déplace dans la direction " << (int)direction << " à la vitesse " << speed;
}

void ConsoleOutputManager::moveCamera(Direction direction, float speed){
    cout << "La caméra se déplace dans la direction " << (int)direction << " à la vitesse " << speed;
}
