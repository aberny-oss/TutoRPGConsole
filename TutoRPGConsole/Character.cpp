#include "Character.h"
#include <iostream>

Character::Character(const std::string& n, int hp, int atk)
    : name(n), health(hp), attackPower(atk) {
    std::cout << "[Character] " << name << " cree (HP: " << health << ")" << std::endl;
}

Character::~Character() {
    std::cout << "[Character] " << name << " detruit" << std::endl;
}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << name << " prend " << damage << " degats (HP restants: " << health << ")" << std::endl;
}

bool Character::isAlive() const {
    return health > 0;
}

std::string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}
