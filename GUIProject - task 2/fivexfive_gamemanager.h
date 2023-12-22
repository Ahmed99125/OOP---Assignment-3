//
// Created by at991 on 12/17/2023.
//

#ifndef NEW_FOLDER_FIVEXFIVE_GAMEMANAGER_H
#define NEW_FOLDER_FIVEXFIVE_GAMEMANAGER_H

#include "BoardGame_Classes.hpp"

class FiveXFive_GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    FiveXFive_GameManager(Board* bPtr, Player* playerPtr[2]) ;
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end

};


#endif //NEW_FOLDER_FIVEXFIVE_GAMEMANAGER_H
