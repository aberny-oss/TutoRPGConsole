#include "Game.h"
#include <iostream>

Game::Game() : currentState(GameState::MENU), isRunning(true) {
    characterManager = new CharacterManager();
    inputManager = new InputManager();  // <-- AJOUT
    std::cout << "=== JEU INITIALISE ===" << std::endl;
}

Game::~Game() {
    delete characterManager;
    delete inputManager;  // <-- AJOUT
}

void Game::run() {
    while (isRunning) {
        inputManager->update();  // <-- AJOUT : Capture des entrées
        update();
        display();
    }
    std::cout << "\n=== FIN DU JEU ===" << std::endl;
}

void Game::update() {
    switch (currentState) {
    case GameState::MENU:
        handleMenu();
        break;
    case GameState::COMBAT:
        handleCombat();
        break;
    case GameState::VICTOIRE:
        handleVictoire();
        break;
    case GameState::DEFAITE:
        handleDefaite();
        break;
    }
}

void Game::display() {
    std::cout << "\n--- AFFICHAGE ---" << std::endl;
}

void Game::handleMenu() {
    std::cout << "\n===== MENU PRINCIPAL =====" << std::endl;
    std::cout << "Appuyez sur 's' pour commencer" << std::endl;
    std::cout << "Appuyez sur 'q' pour quitter" << std::endl;

    Action action = inputManager->getAction();  // <-- UTILISATION

    if (action == Action::MENU_START) {
        changeState(GameState::COMBAT);
    }
    else if (action == Action::QUIT) {
        isRunning = false;
    }
}

void Game::handleCombat() {
    std::cout << "\n===== COMBAT =====" << std::endl;

    Character* player = characterManager->getCharacter(0);
    Character* enemy = characterManager->getCharacter(1);

    if (player && enemy) {
        std::cout << "Joueur HP: " << player->getHealth() << " | ";
        std::cout << "Ennemi HP: " << enemy->getHealth() << std::endl;

        Action action = inputManager->getAction();  // <-- UTILISATION

        if (action == Action::ATTACK) {
            player->attack(enemy);

            // L'ennemi riposte si vivant
            if (enemy->isAlive()) {
                enemy->attack(player);
            }
        }
        else if (action == Action::DEFEND) {
            std::cout << player->getName() << " se defend !" << std::endl;
            // Logique de défense ici
        }
        else if (action == Action::QUIT) {
            isRunning = false;
            return;
        }

        // Vérification victoire/défaite
        if (!enemy->isAlive()) {
            changeState(GameState::VICTOIRE);
        }
        else if (!player->isAlive()) {
            changeState(GameState::DEFAITE);
        }
    }
}

void Game::handleVictoire() {
    std::cout << "\n===== VICTOIRE =====" << std::endl;
    std::cout << "Felicitations, vous avez gagne !" << std::endl;
    std::cout << "Appuyez sur 'c' pour continuer ou 'q' pour quitter" << std::endl;

    Action action = inputManager->getAction();  // <-- UTILISATION

    if (action == Action::CONTINUE) {
        changeState(GameState::MENU);
    }
    else if (action == Action::QUIT) {
        isRunning = false;
    }
}

void Game::handleDefaite() {
    std::cout << "\n===== DEFAITE =====" << std::endl;
    std::cout << "Vous avez perdu..." << std::endl;
    std::cout << "Appuyez sur 'c' pour rejouer ou 'q' pour quitter" << std::endl;

    Action action = inputManager->getAction();  // <-- UTILISATION

    if (action == Action::CONTINUE) {
        // Réinitialiser le jeu
        delete characterManager;
        characterManager = new CharacterManager();
        changeState(GameState::MENU);
    }
    else if (action == Action::QUIT) {
        isRunning = false;
    }
}

void Game::changeState(GameState newState) {
    currentState = newState;
    std::cout << "\n>>> Changement d'etat <<<" << std::endl;
}
