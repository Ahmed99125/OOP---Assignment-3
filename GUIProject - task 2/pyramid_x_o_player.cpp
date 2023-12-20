#include "pyramid_x_o_player.h"

void Pyramid_X_O_Player::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x and y from the shown cells separated by spaces: ";
    cin >> x >> y;
}

Pyramid_X_O_Player::Pyramid_X_O_Player(int order, char symbol) : Player(order, symbol) {

}

Pyramid_X_O_Player::Pyramid_X_O_Player(char symbol) : Player(symbol) {

}
