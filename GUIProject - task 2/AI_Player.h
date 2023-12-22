//
// Created by at991 on 12/18/2023.
//

#ifndef MOHAMED_FINAL_TEST_AI_PLAYER_H
#define MOHAMED_FINAL_TEST_AI_PLAYER_H

#include "BoardGame_Classes.hpp"
#include "Pyramid_X_O_Board.h"
#include <unordered_map>
#include <vector>

class AI_Player : public Player {
private:
    pair <int, int> bestMove;
    int minimax(int depth, char curr_Player, int alpha, int beta);
    Board* board;
    unordered_map <string, int> dp;
    bool is_pruned;
    vector <int> dimensionX, dimensionY;
    int type;
public:
    AI_Player(char symbol, Board* board_ptr, int type);
    void get_move(int& x, int& y);
};


#endif //MOHAMED_FINAL_TEST_AI_PLAYER_H
