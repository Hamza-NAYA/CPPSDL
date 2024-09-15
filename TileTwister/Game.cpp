#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>  // Pour std::rand()

Game::Game() : isRunning(false) {}

Game::~Game() {}

bool Game::init(const char* title, int width, int height) {
    if (!window.init(title, width, height)) {
        return false;
    }
    resetGame();
    isRunning = true;
    return true;
}

void Game::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
    }
}

void Game::cleanup() {
    window.cleanup();
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    // Logique de déplacement vers le haut
                    break;
                case SDLK_DOWN:
                    // Logique de déplacement vers le bas
                    break;
                case SDLK_LEFT:
                    // Logique de déplacement vers la gauche
                    break;
                case SDLK_RIGHT:
                    // Logique de déplacement vers la droite
                    break;
            }
        }
    }
}

void Game::update() {
    // Logique de mise à jour du jeu (ex : déplacement des tuiles)
}

void Game::render() {
    window.clear();

    // Affichage des tuiles
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            tile.render(window.getRenderer());
        }
    }

    window.present();
}

void Game::resetGame() {
    // Initialisation d'une grille vide de 4x4
    grid = std::vector<std::vector<Tile>>(4, std::vector<Tile>(4));

    // Ajouter deux tuiles aléatoires avec 2 ou 4 comme valeur
    int x1 = std::rand() % 4, y1 = std::rand() % 4;
    int x2 = std::rand() % 4, y2 = std::rand() % 4;

    // Assurer que les deux positions ne soient pas identiques
    while (x1 == x2 && y1 == y2) {
        x2 = std::rand() % 4;
        y2 = std::rand() % 4;
    }

    grid[x1][y1].setValue((std::rand() % 2 + 1) * 2);  // Valeur 2 ou 4
    grid[x2][y2].setValue((std::rand() % 2 + 1) * 2);  // Valeur 2 ou 4
}
