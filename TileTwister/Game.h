#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Tile.h"
#include <vector>

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height);
    void run();
    void cleanup();

private:
    void handleEvents();
    void update();
    void render();
    void resetGame();

    Window window;
    bool isRunning;
    std::vector<std::vector<Tile>> grid;
};

#endif
