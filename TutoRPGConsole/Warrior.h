#pragma once
#include <iostream>
#include "Character.h"

class Warrior : public Character {
private:
    int armor;

public:
    Warrior(const std::string& n, int hp, int atk, int arm);

    void Attack(Character* target) override;
    void TakeDamage(int damage) override;
};
