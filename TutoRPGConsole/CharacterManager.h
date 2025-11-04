#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Character.h"
#include "Warrior.h"

class CharacterManager {
private:
    std::vector<std::unique_ptr<Character>> allies;
    std::vector<std::unique_ptr<Character>> enemies;

public:
    CharacterManager();

    void AddAlly(std::unique_ptr<Character> character);
    void AddEnemy(std::unique_ptr<Character> character);

    Character* GetAlly(int index);
    Character* GetEnemy(int index);

    void RemoveAlly(int index);
    void RemoveEnemy(int index);

    int GetAllyCount() const;
    int GetEnemyCount() const;
};
