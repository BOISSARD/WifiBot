#include "outputmanager.h"

OutputManager::OutputManager(){

}

OutputManager::~OutputManager(){

}

void OutputManager::setConnexionManager(ConnexionManager* connexion){
    this->connexion = connexion;
}
