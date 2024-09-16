#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game {
private:
    Grid grid;
    bool isGameOver;
    
public:
    Game();
    void play();
    void processInput(char input);
    bool checkGameOver();
};

#endif
