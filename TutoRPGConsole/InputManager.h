#pragma once
#include <iostream>
#include <string>

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

    void Update();               // Capture l'entrée clavier
    Action GetAction();          // Retourne l'action correspondante
    char GetLastKey() const;     // Retourne la dernière touche pressée
    bool IsKeyPressed(char key); // Vérifie si une touche spécifique est pressée
};
