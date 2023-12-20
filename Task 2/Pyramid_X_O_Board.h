//
// Created by at991 on 12/15/2023.
//

#ifndef TASK_2_PYRAMID_X_O_BOARD_H
#define TASK_2_PYRAMID_X_O_BOARD_H

#include "BoardGame_Classes.hpp"

using namespace std;

class Pyramid_X_O_Board : public Board {
public:
    Pyramid_X_O_Board();
    bool update_board (int x, int y, char mark);
    bool undo_move(int x, int y);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int get_n_moves() const;
    string get_board() const;
    // Return n_rows
    int get_n_rows() const;
    // Return n_rows
    int get_n_cols() const;

    int eval_game();
};

#endif //TASK_2_PYRAMID_X_O_BOARD_H
