#include "InputManager.h"
#include <iostream>
#include <cstdio>

// Pour les entrées non bloquantes (optionnel selon l'OS)
#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

InputManager::InputManager() : lastKey('\0') {
    std::cout << "[InputManager] Initialisation" << std::endl;
}

InputManager::~InputManager() {
    std::cout << "[InputManager] Destruction" << std::endl;
}

void InputManager::update() {
    // Version simple : lecture bloquante (attente de l'entrée)
    // Pour une vraie boucle de jeu, tu voudrais une lecture non-bloquante
    
    std::cout << "\n> Entrez une action (a=attaquer, d=defendre, s=start, q=quitter, c=continuer): ";
    std::cin >> lastKey;
    
    // Conversion en minuscule
    if (lastKey >= 'A' && lastKey <= 'Z') {
        lastKey = lastKey + 32;
    }
}

Action InputManager::getAction() {
    switch (lastKey) {
        case 'a':
            return Action::ATTACK;
        case 'd':
            return Action::DEFEND;
        case 's':
            return Action::MENU_START;
        case 'q':
            return Action::QUIT;
        case 'c':
            return Action::CONTINUE;
        default:
            return Action::NONE;
    }
}

char InputManager::getLastKey() const {
    return lastKey;
}

bool InputManager::isKeyPressed(char key) {
    return lastKey == key;
}
