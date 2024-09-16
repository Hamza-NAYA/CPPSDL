#ifndef GAME_H
#define GAME_H

#include "../include/Grid.hpp"

class Game {
public:
    Game();
    void start();

private:
    Grid grid;
    bool handleInput(char input);
};

#endif