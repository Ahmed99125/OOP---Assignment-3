//
// Created by at991 on 12/17/2023.
//

#ifndef NEW_FOLDER_PYRAMID_X_O_PLAYER_H
#define NEW_FOLDER_PYRAMID_X_O_PLAYER_H

#include "BoardGame_Classes.hpp"

class Pyramid_X_O_Player : public Player {
public:
    void get_move(int& x, int& y);
    Pyramid_X_O_Player(int order, char symbol);
    Pyramid_X_O_Player(char symbol);
};

#endif //NEW_FOLDER_PYRAMID_X_O_PLAYER_H
