cmake_minimum_required(VERSION 3.25)
project(part_two_collect_four_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(part_two_collect_four_game main.cpp board.cpp BoardGame_Classes.hpp Player.cpp RandomPlayer.cpp GameManager.cpp)
