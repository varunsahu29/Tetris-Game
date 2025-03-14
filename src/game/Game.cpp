#include "Game.h"
#include <iostream>
#include <chrono>
#include <cstdlib>

Game::Game(int w, int h) : board(w, h), currentTetromino(w / 2, 0) {}

void Game::renderThread() noexcept {
    while (!gameOver.load()) {
        // system("clear");
        board.displayBoard();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::inputThread() noexcept {
    while (!gameOver.load()) {
        // std::cin >> playerInput;
        playerInput = 'a';  // For demonstration purposes
        cv.notify_one();  // Notify game logic thread for immediate action
    }
}
void Game::start() noexcept {
    std::thread renderThread(&Game::renderThread, this);
    std::thread inputThread(&Game::inputThread, this);

    while (!gameOver.load()) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait_for(lock, std::chrono::milliseconds(500));  // Regular game logic tick

        switch (playerInput) {
            case 'a': currentTetromino.moveLeft(); break;
            case 'd': currentTetromino.moveRight(); break;
            case 's': currentTetromino.moveDown(); break;
            default: currentTetromino.moveDown(); break;
        }

        if (!board.isValidPosition(currentTetromino)) {
            std::cout << "Invalid position!\n";
            board.lockTetromino(currentTetromino);
            currentTetromino = Tetromino(board.getWidth() / 2, 0);
            if (!board.isValidPosition(currentTetromino)) {
                gameOver.store(true);
                std::cout << "Game Over!\n";
            }
        }
        playerInput = '\0';  // Reset input after processing
    }

    renderThread.join();
    inputThread.join();
}
