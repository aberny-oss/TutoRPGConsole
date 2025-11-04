#include "Game.h"

Game::Game()
    : currentState(GameState::MENU),
    isRunning(false)
{
    // On NE créé PAS de manager ici,
    // juste suffisant pour un objet valide.
}

void Game::Init() {
    currentState = GameState::MENU;
    isRunning = true;
    characterManager = std::make_unique<CharacterManager>();
    inputManager = std::make_unique<InputManager>();
    std::cout << "\n=== Nouvelle partie initialisée ===" << std::endl;
}


void Game::Run() {
    Init(); // On démarre systématiquement par un Init

    while (isRunning) {
        inputManager->Update();
        Update();
        Display();
    }
    std::cout << "\n=== Fin du jeu ===" << std::endl;
}

void Game::Shutdown() {
    // Nettoyage si nécessaire
    std::cout << "Nettoyage des ressources du jeu..." << std::endl;
}

void Game::Update() {
    switch (currentState) {
    case GameState::MENU:
        HandleMenu();
        break;
    case GameState::COMBAT:
        HandleCombat();
        break;
    case GameState::VICTOIRE:
        HandleVictoire();
        break;
    case GameState::DEFAITE:
        HandleDefaite();
        break;
    }
}

void Game::Display() {
    std::cout << "--- Affichage de l'état du jeu ---" << std::endl;
    // Ici, on pourrait afficher les états, la vie, etc.
}

void Game::HandleMenu() {
    std::cout << "[MENU] (s: start, q: quitter)" << std::endl;
    Action action = inputManager->GetAction();

    if (action == Action::MENU_START) {
        ChangeState(GameState::COMBAT);
    }
    else if (action == Action::QUIT) {
        isRunning = false;
    }
}

void Game::HandleCombat() {
    std::cout << "[COMBAT] (a: attaquer, d: défendre, q: quitter)" << std::endl;

    // Affiche les PV de chaque combattant
    std::cout << "Alliés :" << std::endl;
    for (int i = 0; i < characterManager->GetAllyCount(); ++i) {
        Character* ally = characterManager->GetAlly(i);
        if (ally)
            std::cout << "- " << ally->GetName() << " : " << ally->GetHealth() << " HP" << std::endl;
    }
    std::cout << "Ennemis :" << std::endl;
    for (int j = 0; j < characterManager->GetEnemyCount(); ++j) {
        Character* enemy = characterManager->GetEnemy(j);
        if (enemy)
            std::cout << "- " << enemy->GetName() << " : " << enemy->GetHealth() << " HP" << std::endl;
    }

    Action action = inputManager->GetAction();

    // Exemple : faire attaquer chaque allié le premier ennemi encore vivant
    if (action == Action::ATTACK) {
        for (int i = 0; i < characterManager->GetAllyCount(); ++i) {
            Character* ally = characterManager->GetAlly(i);
            // Trouve la première cible encore vivante
            for (int j = 0; j < characterManager->GetEnemyCount(); ++j) {
                Character* enemy = characterManager->GetEnemy(j);
                if (ally && enemy && enemy->IsAlive()) {
                    ally->Attack(enemy);
                    break; // Chaque allié attaque un ennemi
                }
            }
        }
        // Les ennemis peuvent riposter...
    }
}


void Game::HandleVictoire() {
    std::cout << "[VICTOIRE] (c: rejouer, q: quitter)" << std::endl;
    Action action = inputManager->GetAction();

    if (action == Action::CONTINUE) {
        Init(); // Une nouvelle partie démarre
    }
    else if (action == Action::QUIT) {
        isRunning = false;
    }
}

void Game::HandleDefaite() {
    std::cout << "[DEFAITE] (c: rejouer, q: quitter)" << std::endl;
    Action action = inputManager->GetAction();

    if (action == Action::CONTINUE) {
        Init();
    }
    else if (action == Action::QUIT) {
        isRunning = false;
    }
}

void Game::ChangeState(GameState newState) {
    currentState = newState;
    std::cout << ">>> Changement d'état <<<" << std::endl;
}
