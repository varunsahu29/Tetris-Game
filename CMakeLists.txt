cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(include)


# Source files
add_executable(Tetris
    src/main.cpp
    src/core/Board.cpp
    src/core/Tetromino.cpp
    src/game/Game.cpp
)
target_link_libraries(Tetris pthread)
