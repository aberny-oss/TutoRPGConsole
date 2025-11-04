#include "InputManager.h"

InputManager::InputManager() : lastKey('\0') {
    std::cout << "[InputManager] Initialisation" << std::endl;
}

void InputManager::Update() {
    std::cout << "\n> Entrez une action (a=attaquer, d=defendre, s=start, q=quitter, c=continuer): ";
    std::cin >> lastKey;

    // Conversion en minuscule
    if (lastKey >= 'A' && lastKey <= 'Z') {
        lastKey = lastKey + 32;
    }
}

Action InputManager::GetAction() {
    switch (lastKey) {
    case 'a': return Action::ATTACK;
    case 'd': return Action::DEFEND;
    case 's': return Action::MENU_START;
    case 'q': return Action::QUIT;
    case 'c': return Action::CONTINUE;
    default:  return Action::NONE;
    }
}

char InputManager::GetLastKey() const {
    return lastKey;
}

bool InputManager::IsKeyPressed(char key) {
    return lastKey == key;
}
