cmake_minimum_required(VERSION 3.16)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameOfLife main.cpp Grid.cpp Grid.h Cell.cpp Cell.h AliveCell.cpp AliveCell.h DeadCell.cpp DeadCell.h Game.cpp Game.h)
