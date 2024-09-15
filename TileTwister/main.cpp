#include "Game.h"

int main(int argc, char* argv[]) {
    Game game;
    if (!game.init("Tile Twister", 800, 600)) {
        return -1;
    }

    game.run();
    game.cleanup();

    return 0;
}
