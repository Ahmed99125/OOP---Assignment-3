#ifndef _COLLECTFOURBOARD_H_
#define _COLLECTFOURBOARD_H_

#include "BoardGame_Classes.hpp"
#include <unordered_map>

class CollectFourBoard:public Board {
private:
    int lastPlayX ;
    int lastPlayY ;
    char lastPlaySymbol;
public:
    CollectFourBoard ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int getMoves();

    bool undo_move(int x, int y);
    // Return the board as string
    string get_board() const;
    // Return n_moves
    int get_n_moves() const;
    // Return n_rows
    int get_n_rows() const;
    // Return n_rows
    int get_n_cols() const;

    int eval_game(char curr_player, int depth);
};

#endif