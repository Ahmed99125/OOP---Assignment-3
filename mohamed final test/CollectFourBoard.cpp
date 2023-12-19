#include "BoardGame_Classes.hpp"
#include "CollectFourBoard.h"
#include <iomanip>
CollectFourBoard::CollectFourBoard() {
    n_rows =6;
    n_cols =7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool CollectFourBoard::update_board (int x, int y, char mark){
    // Only update if move is valid

    if (!(x < 0 || x > 5 || y < 0 || y > 6) ) {
        bool isBottom = (x==5 || board[x+1][y] != 0) ;
        if(isBottom && board[x][y] == 0){
        cout<< x << " " << y<< endl ;
        cout.flush();
        board[x][y] = toupper(mark);
        n_moves++;
        lastPlayX = x;
        lastPlayY = y;
        lastPlaySymbol = toupper(mark);
        return true;
        } else{
            return false;
        }
    }
    else
        return false;
}
void CollectFourBoard::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool CollectFourBoard::is_winner() {
    // horizontally
    for(int i =max(0, lastPlayY-3); i<=min(lastPlayY,3) ;i++){
        for(int j =i ; j<i+4 ;j++){
            if( board[lastPlayX][j] != lastPlaySymbol ){
                goto st ;
            }
        }
        return true;
        st:;
    }
    // vertically
    for(int i =max(0, lastPlayX-3); i<=min(lastPlayX,3) ;i++){
        for(int j =i ; j<i+4 ;j++){
            if( board[j][lastPlayY] != lastPlaySymbol ){
                goto st1 ;
            }
        }
        return true;
        st1:;
    }
    // diagonally
    for(int i =lastPlayX - min(lastPlayX,lastPlayY), j = lastPlayY - min(lastPlayX,lastPlayY); i<= min(lastPlayX,2) && j<= min(lastPlayY,3); i++, j++){
        for(int k = 0; k<4 ; k++){
            if( board[i+k][j+k] != lastPlaySymbol ){
                goto st2;
            }
        }
        return true;
        st2:;
    }
    for(int i =lastPlayX + min(5-lastPlayX,lastPlayY), j = lastPlayY - min(5-lastPlayX,lastPlayY); i>= max(lastPlayX,3) && j<= min(lastPlayY,3); i--, j++){
        for(int k = 0; k<4 ; k++){
            if( board[i-k][j+k] != lastPlaySymbol ){
                goto st3;
            }
        }
        return true;
        st3:;
        return false;
    }
    return false;
}
bool CollectFourBoard::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool CollectFourBoard::game_is_over () {
    return n_moves >= 42;
}

int CollectFourBoard::getMoves() {
    return n_moves;
}


bool CollectFourBoard::undo_move(int x, int y) {
    if (x < 0 || x >= n_rows || y < 0 || y >= n_cols)
        return false;
    board[x][y] = 0;
    n_moves--;
    return true;
}

int CollectFourBoard::get_n_moves() const {
    return n_moves;
}

string CollectFourBoard::get_board() const {
    string ans = "";
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            ans += board[i][j];
        }
    }
    return ans;
}