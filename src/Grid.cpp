#include "../include/Grid.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <iostream>

Grid::Grid() : grid(4, std::vector<Tile>(4)) {
    srand(time(0));
    addRandomTile();
    addRandomTile();
}

void Grid::display() {
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            std::cout << tile.getValue() << "\t";
        }
        std::cout << std::endl;
    }
}

bool Grid::canMerge(Tile a, Tile b) {
    return (a.getValue() == b.getValue() && !a.isEmpty());
}

bool Grid::slide(std::vector<Tile>& row) {
    bool moved = false;
    for (size_t i = 0; i < row.size(); ++i) {
        for (size_t j = i + 1; j < row.size(); ++j) {
            if (row[j].isEmpty()) continue;
            if (row[i].isEmpty()) {
                row[i].setValue(row[j].getValue());
                row[j].setValue(0);
                moved = true;
            } else if (canMerge(row[i], row[j])) {
                row[i].setValue(row[i].getValue() * 2);
                row[j].setValue(0);
                moved = true;
            }
            break;
        }
    }
    return moved;
}

bool Grid::moveLeft() {
    bool moved = false;
    for (auto& row : grid) {
        if (slide(row)) {
            moved = true;
        }
    }
    return moved;
}

bool Grid::moveRight() {
    bool moved = false;
    for (auto& row : grid) {
        std::reverse(row.begin(), row.end());
        if (slide(row)) {
            moved = true;
        }
        std::reverse(row.begin(), row.end());
    }
    return moved;
}

bool Grid::moveUp() {
    bool moved = false;
    for (int col = 0; col < 4; ++col) {
        std::vector<Tile> column;
        for (int row = 0; row < 4; ++row) {
            column.push_back(grid[row][col]);
        }
        if (slide(column)) {
            moved = true;
        }
        for (int row = 0; row < 4; ++row) {
            grid[row][col] = column[row];
        }
    }
    return moved;
}

bool Grid::moveDown() {
    bool moved = false;
    for (int col = 0; col < 4; ++col) {
        std::vector<Tile> column;
        for (int row = 0; row < 4; ++row) {
            column.push_back(grid[row][col]);
        }
        std::reverse(column.begin(), column.end());
        if (slide(column)) {
            moved = true;
        }
        std::reverse(column.begin(), column.end());
        for (int row = 0; row < 2; ++row) {
            grid[row][col] = column[row];
        }
    }
    return moved;
}

bool Grid::addRandomTile() {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j].isEmpty()) {
                emptyTiles.push_back({i, j});
            }
        }
    }
    if (emptyTiles.empty()) return false;

    int x, y;
    std::tie(x, y) = emptyTiles[rand() % emptyTiles.size()];  // Récupère x et y depuis emptyTiles
    grid[x][y].setValue((rand() % 2 + 1) * 2);  // Utilisation correcte de x et y
    return true;
}

bool Grid::isGameOver() {
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            if (tile.isEmpty()) return false;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i < 3 && canMerge(grid[i][j], grid[i + 1][j])) return false;
            if (j < 3 && canMerge(grid[i][j], grid[i][j + 1])) return false;
        }
    }
    return true;
}