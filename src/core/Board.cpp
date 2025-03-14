#include "Board.h"
#include <iostream>

Board::Board(int w, int h) : width(w), height(h), grid(h, std::vector<int>(w, 0)) {}

void Board::displayBoard() const noexcept {
    for (const auto& row : grid) {
        for (int cell : row) std::cout << (cell ? "#" : " ") << ' ';
        std::cout << '\n';
    }
}

bool Board::isValidPosition(const Tetromino& tetromino) const noexcept {
    for (size_t i = 0; i < tetromino.getShape().size(); ++i) {
        for (size_t j = 0; j < tetromino.getShape()[0].size(); ++j) {
            if (tetromino.getShape()[i][j]) {
                int newX = tetromino.getX() + j;
                int newY = tetromino.getY() + i;
                if (newX < 0 || newX >= width || newY < 0 || newY >= height || grid[newY][newX])
                    return false;
            }
        }
    }
    return true;
}

void Board::lockTetromino(const Tetromino& tetromino) noexcept {
    for (size_t i = 0; i < tetromino.getShape().size(); ++i) {
        for (size_t j = 0; j < tetromino.getShape()[0].size(); ++j) {
            if (tetromino.getShape()[i][j]) {
                grid[tetromino.getY() + i][tetromino.getX() + j] = 1;
            }
        }
    }
}
