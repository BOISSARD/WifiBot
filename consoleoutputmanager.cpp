#include "consoleoutputmanager.h"

ConsoleOutputManager::ConsoleOutputManager(){}

void ConsoleOutputManager::display(string text){
    cout << text << endl;
}

void move(Direction direction, float vitesse){
    display("Le robot se déplace dans la direction " + direction + " à la vitesse " + vitesse);
}

void moveCamera(Direction direction){
    display("La caméra se déplace dans la direction " + direction);
}
