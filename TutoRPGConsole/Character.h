#pragma once
#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    int health;
    int attackPower;

public:
    Character(const std::string& n, int hp, int atk);

    // Fonctions virtuelles pures (classe abstraite)
    virtual void Attack(Character* target) = 0;
    virtual void TakeDamage(int damage);

    bool IsAlive() const;
    std::string GetName() const;
    int GetHealth() const;
};
