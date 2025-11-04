#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
private:
    int armor;

public:
    Warrior(const std::string& n, int hp, int atk, int arm);
    ~Warrior();

    void attack(Character* target) override;
    void takeDamage(int damage) override;
};

#endif
