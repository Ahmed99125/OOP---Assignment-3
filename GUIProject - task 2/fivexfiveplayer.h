//
// Created by at991 on 12/17/2023.
//

#ifndef NEW_FOLDER_FIVEXFIVEPLAYER_H
#define NEW_FOLDER_FIVEXFIVEPLAYER_H

#include "boardgame_classes.h"

class FiveXFivePlayer : public Player {
public:
    void get_move(int& x, int& y);
    FiveXFivePlayer(int order, char symbol);
    FiveXFivePlayer(char symbol);
};

#endif //NEW_FOLDER_FIVEXFIVEPLAYER_H
