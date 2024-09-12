#ifndef GRID_H
#define GRID_H

#include <vector>
#include "../include/Tile.hpp"

class Grid {
public:
    Grid();
    void display();
    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();
    bool addRandomTile();
    bool isGameOver();

private:
    std::vector<std::vector<Tile>> grid;
    bool canMerge(Tile a, Tile b);
    bool slide(std::vector<Tile>& row);
};

#endif