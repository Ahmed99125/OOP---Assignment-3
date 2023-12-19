//
// Created by at991 on 12/18/2023.
//

#ifndef MOHAMED_FINAL_TEST_PYRAMID_X_O_AI_H
#define MOHAMED_FINAL_TEST_PYRAMID_X_O_AI_H

#include "BoardGame_Classes.hpp"
#include "Pyramid_X_O_Board.h"
#include <unordered_map>

class Pyramid_X_O_AI : public Player {
private:
    pair <int, int> bestMove;
    int minimax(int depth, char curr_Player, int alpha, int beta);
    Board* board;
    unordered_map <string, int> dp;
public:
    Pyramid_X_O_AI(char symbol, Board* board_ptr);
    void get_move(int& x, int& y);
};


#endif //MOHAMED_FINAL_TEST_PYRAMID_X_O_AI_H
