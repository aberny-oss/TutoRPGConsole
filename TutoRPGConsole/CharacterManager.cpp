#include "CharacterManager.h"
#include "Warrior.h"
#include <iostream>

CharacterManager::CharacterManager() {
    std::cout << "[CharacterManager] Initialisation" << std::endl;

    // Création automatique de 2 guerriers pour le combat
    addCharacter(new Warrior("Joueur", 100, 20, 5));
    addCharacter(new Warrior("Ennemi", 80, 15, 3));
}

CharacterManager::~CharacterManager() {
    std::cout << "[CharacterManager] Destruction" << std::endl;
    for (Character* character : characters) {
        delete character;
    }
    characters.clear();
}

void CharacterManager::addCharacter(Character* character) {
    characters.push_back(character);
    std::cout << "[CharacterManager] Personnage ajoute" << std::endl;
}

Character* CharacterManager::getCharacter(int index) {
    if (index >= 0 && index < characters.size()) {
        return characters[index];
    }
    return nullptr;
}

void CharacterManager::removeCharacter(int index) {
    if (index >= 0 && index < characters.size()) {
        delete characters[index];
        characters.erase(characters.begin() + index);
    }
}

int CharacterManager::getCharacterCount() const {
    return characters.size();
}
