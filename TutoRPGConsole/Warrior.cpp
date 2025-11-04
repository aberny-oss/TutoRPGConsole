#include "Warrior.h"
#include <iostream>

Warrior::Warrior(const std::string& n, int hp, int atk, int arm)
    : Character(n, hp, atk), armor(arm) {
    std::cout << "[Warrior] " << name << " est un guerrier (Armure: " << armor << ")" << std::endl;
}

Warrior::~Warrior() {
    std::cout << "[Warrior] " << name << " (guerrier) detruit" << std::endl;
}

void Warrior::attack(Character* target) {
    if (target && target->isAlive()) {
        std::cout << name << " attaque " << target->getName() << " avec " << attackPower << " de degats !" << std::endl;
        target->takeDamage(attackPower);
    }
}

void Warrior::takeDamage(int damage) {
    int realDamage = damage - armor;
    if (realDamage < 0) realDamage = 0;

    std::cout << name << " bloque " << armor << " degats avec son armure" << std::endl;
    Character::takeDamage(realDamage);
}
