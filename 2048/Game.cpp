#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() : isGameOver(false) {
    srand(time(0));
    grid.generateTile();
    grid.generateTile();
}

void Game::play() {
    char input;
    while (!isGameOver) {
        grid.display();
        std::cout << "Entrer le mouvement (w: haut, s: bas, a: gauche, d: droite): ";
        std::cin >> input;
        processInput(input);
        if (checkGameOver()) {
            std::cout << "Fin du jeu!\n";
            isGameOver = true;
        }
    }
}

void Game::processInput(char input) {
    switch (input) {
        case 'a': grid.moveLeft(); break;
        case 'd': grid.moveRight(); break;
        case 'w': grid.moveUp(); break;
        case 's': grid.moveDown(); break;
        default: std::cout << "Mouvement invalide!" << std::endl; return;
    }
    grid.generateTile();
}

bool Game::checkGameOver() {
    return grid.isFull() && !grid.canMove();
}
