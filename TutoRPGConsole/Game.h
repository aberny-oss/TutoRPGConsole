#pragma once
#include <iostream>
#include <memory>
#include "CharacterManager.h"
#include "InputManager.h"  // <-- AJOUT

enum class GameState {
    MENU,
    COMBAT,
    VICTOIRE,
    DEFAITE
};

class Game {
private:
    GameState currentState;
    std::unique_ptr<CharacterManager> characterManager;
    std::unique_ptr<InputManager> inputManager;

    bool isRunning;

    void HandleMenu();
    void HandleCombat();
    void HandleVictoire();
    void HandleDefaite();

public:
    Game();

    void Init();           // Initialise une nouvelle partie
    void Run();            // Boucle principale
    void Shutdown();       // Nettoyage

    void Update();         // Mise à jour logique
    void Display();        // Affichage
    void ChangeState(GameState newState);
};
