#include "CollectFourPlayer.h"

void CollectFourPlayer::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x (0 to 5) and y (0 to 6) separated by spaces: ";
    cin >> x >> y;
}

CollectFourPlayer::CollectFourPlayer(int order, char symbol) : Player(order, symbol) {

}

CollectFourPlayer::CollectFourPlayer(char symbol) : Player(symbol) {

}
