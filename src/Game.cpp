#include "../include/Game.hpp"
#include <iostream>

Game::Game() : grid() {}

void Game::start() {
    char move;
    while (true) {
        grid.display();

        if (grid.isGameOver()) {
            std::cout << "Game Over!" << std::endl;
            break;
        }

        std::cout << "Z/Q/S/D to move (Up/Left/Down/Right): ";
        std::cin >> move;

        if (handleInput(move)) {
            grid.addRandomTile();
        }
    }
}

bool Game::handleInput(char input) {
    switch (input) {
        case 'Z': case 'z': return grid.moveUp();
        case 'Q': case 'q': return grid.moveLeft();
        case 'S': case 's': return grid.moveDown();
        case 'D': case 'd': return grid.moveRight();
        default:
            std::cout << "Invalid move!" << std::endl;
            return false;
    }
}