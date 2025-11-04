#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

#include "Character.h"
#include <vector>

class CharacterManager {
private:
    std::vector<Character*> characters;

public:
    CharacterManager();
    ~CharacterManager();

    void addCharacter(Character* character);
    Character* getCharacter(int index);
    void removeCharacter(int index);
    int getCharacterCount() const;
};

#endif
