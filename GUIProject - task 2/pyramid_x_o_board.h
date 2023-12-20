//
// Created by at991 on 12/15/2023.
//

#ifndef TASK_2_PYRAMID_X_O_BOARD_H
#define TASK_2_PYRAMID_X_O_BOARD_H

#include "boardgame_classes.h"

using namespace std;

class Pyramid_X_O_Board : public Board {
public:
    Pyramid_X_O_Board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

#endif //TASK_2_PYRAMID_X_O_BOARD_H
