#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int attackPower;

public:
    Character(const std::string& n, int hp, int atk);
    virtual ~Character();

    // Fonctions virtuelles pures (classe abstraite)
    virtual void attack(Character* target) = 0;
    virtual void takeDamage(int damage);

    bool isAlive() const;
    std::string getName() const;
    int getHealth() const;
};

#endif
