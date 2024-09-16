#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>

class Grid {
private:
    std::vector<std::vector<int>> grid;
    
public:
    Grid();
    void display();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void generateTile();
    bool isFull();
    bool canMove();
};

#endif
