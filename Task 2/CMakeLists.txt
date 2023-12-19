cmake_minimum_required(VERSION 3.23.2)
project(mohamed_final_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(mohamed_final_test main.cpp BoardGame_Classes.hpp CollectFourBoard.cpp CollectFourBoard.h CollectFourPlayer.cpp CollectFourPlayer.h FiveXFive_GameManager.cpp FiveXFive_GameManager.h FiveXFiveBoard.cpp FiveXFiveBoard.h FiveXFivePlayer.cpp FiveXFivePlayer.h GameManager.cpp Player.cpp Pyramid_X_O_Board.cpp Pyramid_X_O_Board.h Pyramid_X_O_Player.cpp Pyramid_X_O_Player.h RandomPlayer.cpp Pyramid_X_O_AI.h Pyramid_X_O_AI.cpp)
