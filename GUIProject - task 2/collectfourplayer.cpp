#include "CollectFourPlayer.h"
#include <QInputDialog>

void CollectFourPlayer::get_move(int &x, int &y) {
    bool okx , oky;
    int x1 = QInputDialog::getInt(NULL,"Enter X","X:",0,INT_MIN,INT_MAX,1,&okx );
    if(okx){
        int Y1 = QInputDialog::getInt(NULL,"Enter Y","Y:",0,INT_MIN,INT_MAX,1,&oky );
        if(oky){
            x= x1;
            y = Y1;
        }
    }
}

CollectFourPlayer::CollectFourPlayer(int order, char symbol) : Player(order, symbol) {

}

CollectFourPlayer::CollectFourPlayer(char symbol) : Player(symbol) {

}
