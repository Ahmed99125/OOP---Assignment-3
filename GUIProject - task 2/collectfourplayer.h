//
// Created by at991 on 12/17/2023.
//

#ifndef NEW_FOLDER_COLLECTFOURPLAYER_H
#define NEW_FOLDER_COLLECTFOURPLAYER_H

#include "boardgame_classes.h"

class CollectFourPlayer : public Player {
public:
    void get_move(int& x, int& y);
    CollectFourPlayer(int order, char symbol);
    CollectFourPlayer(char symbol);
};

#endif //NEW_FOLDER_COLLECTFOURPLAYER_H
