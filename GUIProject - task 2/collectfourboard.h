#ifndef _COLLECTFOURBOARD_H_
#define _COLLECTFOURBOARD_H_

#include "boardgame_classes.h"

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
};

#endif
