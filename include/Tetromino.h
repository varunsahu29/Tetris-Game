#pragma once
#include <vector>
#include <random>

enum class Shape { I, O, T, S, Z, J, L };

class Tetromino {
    std::vector<std::vector<int>> shape;
    int x, y;
public:
    Tetromino(int startX, int startY);
    const std::vector<std::vector<int>>& getShape() const noexcept;
    int getX() const noexcept;
    int getY() const noexcept;
    void moveDown() noexcept;
    void moveLeft() noexcept;
    void moveRight() noexcept;
};
