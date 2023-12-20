//
// Created by at991 on 12/17/2023.
//

#ifndef NEW_FOLDER_5X5BOARD_H
#define NEW_FOLDER_5X5BOARD_H

#include "BoardGame_Classes.hpp"

class FiveXFiveBoard : public Board
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

    bool undo_move(int x, int y);
    // Return the board as string
    string get_board() const;
    // Return n_moves
    int get_n_moves() const;
    // Return n_rows
    int get_n_rows() const;
    // Return n_rows
    int get_n_cols() const;

    int eval_game();
};

#endif //NEW_FOLDER_5X5BOARD_H
