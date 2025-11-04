#include "CharacterManager.h"

CharacterManager::CharacterManager() {
    std::cout << "[CharacterManager] Initialisation" << std::endl;
    // Exemple : création automatique de deux personnages dans chaque camp
    AddAlly(std::make_unique<Warrior>("Joueur", 100, 20, 5));
    AddEnemy(std::make_unique<Warrior>("Ennemi", 80, 15, 3));
}

void CharacterManager::AddAlly(std::unique_ptr<Character> character) {
    allies.push_back(std::move(character));
    std::cout << "[CharacterManager] Allié ajouté" << std::endl;
}

void CharacterManager::AddEnemy(std::unique_ptr<Character> character) {
    enemies.push_back(std::move(character));
    std::cout << "[CharacterManager] Ennemi ajouté" << std::endl;
}

Character* CharacterManager::GetAlly(int index) {
    if (index >= 0 && index < static_cast<int>(allies.size())) {
        return allies[index].get();
    }
    return nullptr;
}

Character* CharacterManager::GetEnemy(int index) {
    if (index >= 0 && index < static_cast<int>(enemies.size())) {
        return enemies[index].get();
    }
    return nullptr;
}

void CharacterManager::RemoveAlly(int index) {
    if (index >= 0 && index < static_cast<int>(allies.size())) {
        allies.erase(allies.begin() + index);
    }
}

void CharacterManager::RemoveEnemy(int index) {
    if (index >= 0 && index < static_cast<int>(enemies.size())) {
        enemies.erase(enemies.begin() + index);
    }
}

int CharacterManager::GetAllyCount() const {
    return static_cast<int>(allies.size());
}

int CharacterManager::GetEnemyCount() const {
    return static_cast<int>(enemies.size());
}
