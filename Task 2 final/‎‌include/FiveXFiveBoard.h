//
// Created by at991 on 12/17/2023.
//

#ifndef NEW_FOLDER_5X5BOARD_H
#define NEW_FOLDER_5X5BOARD_H

#include "BoardGame_Classes.hpp"

class FiveXFiveBoard : public X_O_Board
{
protected:
    int n_rows;
    int n_cols;
    char **board;
    int n_moves = 0;

public:
    FiveXFiveBoard();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

#endif //NEW_FOLDER_5X5BOARD_H
