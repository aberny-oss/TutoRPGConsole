#include "Warrior.h"

Warrior::Warrior(const std::string& n, int hp, int atk, int arm)
    : Character(n, hp, atk), armor(arm) {
    std::cout << "[Warrior] " << name << " est un guerrier (Armure: " << armor << ")" << std::endl;
}

void Warrior::Attack(Character* target) {
    if (target && target->IsAlive()) {
        std::cout << name << " attaque " << target->GetName() << " avec " << attackPower << " de dégâts !" << std::endl;
        target->TakeDamage(attackPower);
    }
}

void Warrior::TakeDamage(int damage) {
    int realDamage = damage - armor;
    if (realDamage < 0) realDamage = 0;
    std::cout << name << " bloque " << armor << " dégâts avec son armure." << std::endl;
    Character::TakeDamage(realDamage);
}
