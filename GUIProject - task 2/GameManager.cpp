// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include "boardgame_classes.h"
#include "QDebug"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    qDebug()<< "hi";
    int x, y;

   boardPtr->display_board();
qDebug()<< "hi";
    while (!boardPtr->game_is_over()) {
       qDebug()<< "hi";
        for (int i:{0,1}) {
           qDebug()<< "hi";
            players[i]->get_move(x, y);
           qDebug()<< "hi";
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}
