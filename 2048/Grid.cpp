#include "Grid.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Grid::Grid() : grid(4, std::vector<int>(4, 0)) {}

void Grid::display() {
    for (const auto &row : grid) {
        for (int tile : row) {
            if (tile == 0) std::cout << std::setw(5) << ".";
            else std::cout << std::setw(5) << tile;
        }
        std::cout << std::endl;
    }
}

void Grid::moveLeft() {
    for (auto &row : grid) {
        std::vector<int> newRow(4, 0);
        int index = 0;
        for (int i = 0; i < 4; i++) {
            if (row[i] != 0) {
                if (index > 0 && newRow[index - 1] == row[i]) {
                    newRow[index - 1] *= 2;
                } else {
                    newRow[index] = row[i];
                    index++;
                }
            }
        }
        row = newRow;
    }
}

void Grid::moveRight() {
    for (auto &row : grid) {
        std::vector<int> newRow(4, 0);
        int index = 3;
        for (int i = 3; i >= 0; i--) {
            if (row[i] != 0) {
                if (index < 3 && newRow[index + 1] == row[i]) {
                    newRow[index + 1] *= 2;
                } else {
                    newRow[index] = row[i];
                    index--;
                }
            }
        }
        row = newRow;
    }
}

void Grid::moveUp() {
    for (int col = 0; col < 4; col++) {
        std::vector<int> newCol(4, 0);
        int index = 0;
        for (int row = 0; row < 4; row++) {
            if (grid[row][col] != 0) {
                if (index > 0 && newCol[index - 1] == grid[row][col]) {
                    newCol[index - 1] *= 2;
                } else {
                    newCol[index] = grid[row][col];
                    index++;
                }
            }
        }
        for (int row = 0; row < 4; row++) {
            grid[row][col] = newCol[row];
        }
    }
}

void Grid::moveDown() {
    for (int col = 0; col < 4; col++) {
        std::vector<int> newCol(4, 0);
        int index = 3;
        for (int row = 3; row >= 0; row--) {
            if (grid[row][col] != 0) {
                if (index < 3 && newCol[index + 1] == grid[row][col]) {
                    newCol[index + 1] *= 2;
                } else {
                    newCol[index] = grid[row][col];
                    index--;
                }
            }
        }
        for (int row = 0; row < 4; row++) {
            grid[row][col] = newCol[row];
        }
    }
}

void Grid::generateTile() {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                emptyTiles.push_back({i, j});
            }
        }
    }

    if (!emptyTiles.empty()) {
        int randomIndex = rand() % emptyTiles.size();
        int randomValue = (rand() % 2 + 1) * 2;  // ici ça genère soit 2 ou 4
        grid[emptyTiles[randomIndex].first][emptyTiles[randomIndex].second] = randomValue;
    }
}

bool Grid::isFull() {
    for (const auto &row : grid) {
        for (int tile : row) {
            if (tile == 0) return false;
        }
    }
    return true;
}

bool Grid::canMove() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) return true;
            if (i < 3 && grid[i][j] == grid[i + 1][j]) return true;
            if (j < 3 && grid[i][j] == grid[i][j + 1]) return true;
        }
    }
    return false;
}
