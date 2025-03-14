#include "Tetromino.h"

Tetromino::Tetromino(int startX, int startY) : x(startX), y(startY) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 6);

    switch (static_cast<Shape>(dist(gen))) {
        case Shape::I: shape = {{1, 1, 1, 1}}; break;
        case Shape::O: shape = {{1, 1}, {1, 1}}; break;
        case Shape::T: shape = {{0, 1, 0}, {1, 1, 1}}; break;
        case Shape::S: shape = {{0, 1, 1}, {1, 1, 0}}; break;
        case Shape::Z: shape = {{1, 1, 0}, {0, 1, 1}}; break;
        case Shape::J: shape = {{1, 0, 0}, {1, 1, 1}}; break;
        case Shape::L: shape = {{0, 0, 1}, {1, 1, 1}}; break;
    }
}

const std::vector<std::vector<int>>& Tetromino::getShape() const noexcept {
    return shape;
}

int Tetromino::getX() const noexcept { return x; }
int Tetromino::getY() const noexcept { return y; }

void Tetromino::moveDown() noexcept { ++y; }
void Tetromino::moveLeft() noexcept { --x; }
void Tetromino::moveRight() noexcept { ++x; }
