#include "FiveXFivePlayer.h"

void FiveXFivePlayer::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

FiveXFivePlayer::FiveXFivePlayer(int order, char symbol) : Player(order, symbol) {

}

FiveXFivePlayer::FiveXFivePlayer(char symbol) : Player(symbol) {

}
