#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <string>

// Enum pour les actions possibles
enum class Action {
    NONE,
    ATTACK,
    DEFEND,
    MENU_START,
    MENU_QUIT,
    CONTINUE,
    QUIT
};

class InputManager {
private:
    char lastKey;

public:
    InputManager();
    ~InputManager();

    void update();                    // Capture l'entrée clavier
    Action getAction();               // Retourne l'action correspondante
    char getLastKey() const;          // Retourne la dernière touche pressée
    bool isKeyPressed(char key);      // Vérifie si une touche spécifique est pressée
};

#endif
