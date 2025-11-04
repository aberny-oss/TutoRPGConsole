#include "Character.h"

Character::Character(const std::string& n, int hp, int atk)
    : name(n), health(hp), attackPower(atk) {
    std::cout << "[Character] " << name << " créé (HP: " << health << ")" << std::endl;
}

void Character::TakeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << name << " prend " << damage << " dégâts (HP restants: " << health << ")" << std::endl;
}

bool Character::IsAlive() const {
    return health > 0;
}

std::string Character::GetName() const {
    return name;
}

int Character::GetHealth() const {
    return health;
}
