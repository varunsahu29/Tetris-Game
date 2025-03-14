#pragma once
#include "Board.h"
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>

class Game {
    Board board;
    Tetromino currentTetromino;
    std::atomic<bool> gameOver{false};
    std::mutex mtx;
    std::condition_variable cv;
    char playerInput;
public:
    Game(int w, int h);
    void start() noexcept;
    void renderThread() noexcept;
    void inputThread() noexcept;
};
