cmake_minimum_required(VERSION 3.23)
project(Task_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task_2
        AI_Player.cpp
        AI_Player.h
        BoardGame_Classes.hpp
        CollectFourBoard.cpp
        CollectFourBoard.h
        CollectFourPlayer.cpp
        CollectFourPlayer.h
        FiveXFive_GameManager.cpp
        FiveXFive_GameManager.h
        FiveXFiveBoard.cpp
        FiveXFiveBoard.h
        FiveXFivePlayer.cpp
        FiveXFivePlayer.h
        GameManager.cpp
        main.cpp
        Player.cpp
        Pyramid_X_O_Board.cpp
        Pyramid_X_O_Board.h
        Pyramid_X_O_Player.cpp
        Pyramid_X_O_Player.h
        RandomPlayer.cpp)
