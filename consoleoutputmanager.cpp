#include "consoleoutputmanager.h"

ConsoleOutputManager::ConsoleOutputManager(){}

void ConsoleOutputManager::display(string text){
    cout << text << endl;
}

void ConsoleOutputManager::move(Direction direction, float vitesse){
    this->display("Le robot se déplace dans la direction " + to_string((int)direction) + " à la vitesse " + to_string(vitesse));
}

void ConsoleOutputManager::moveCamera(Direction direction){
    this->display("La caméra se déplace dans la direction " + to_string((int)direction));
}
