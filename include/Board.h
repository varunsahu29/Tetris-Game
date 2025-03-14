#pragma once
#include "Tetromino.h"
#include <vector>

class Board {
    std::vector<std::vector<int>> grid;
    int width, height;
public:
    Board(int w, int h);
    ~Board() = default;
    void displayBoard() const noexcept;
    bool isValidPosition(const Tetromino& tetromino) const noexcept;
    void lockTetromino(const Tetromino& tetromino) noexcept;
    int getWidth() const noexcept { return width; }
    int getHeight() const noexcept { return height; }
};
