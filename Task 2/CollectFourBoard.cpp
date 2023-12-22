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
    for(int i =max(0, lastPlayX-3); i<=min(lastPlayX,2) ;i++){
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

int CollectFourBoard::get_n_rows() const {
    return n_rows;
}

int CollectFourBoard::get_n_cols() const {
    return n_cols;
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

//int CollectFourBoard::eval_game(char curr_player) {
//    unordered_map <int, int> xy_counterX, diag_counterX, xy_counterO, diag_counterO;
//
//    auto check = [this] (int &x, int &y) -> bool {
//        return !(x < 0 || x >= n_rows || y < 0 || y >= n_cols);
//    };
//
//    auto diagCnt = [this, check] (int x, int y, char prev, int i, int j, auto&& diagCnt) -> int {
//        if (!check(x, y) || board[x][y] != prev)
//            return 0;
//        return 1 + diagCnt(x+i, y+j, board[x][y], i, j, diagCnt);
//    };
//
//    int cntX_H = 0, cntO_H = 0;
//    for (int i = 0; i < n_rows; i++) {
//        cntX_H = 0, cntO_H = 0;
//        for (int j = 0; j < n_cols; j++) {
//            // Horizontal
//            if (board[i][j] == 'X') {
//                cntX_H++;
//                xy_counterO[cntO_H]++;
//                cntO_H = 0;
//            }
//            else if (board[i][j] == 'O') {
//                cntO_H++;
//                xy_counterX[cntX_H]++;
//                cntX_H = 0;
//            }
////            else {
////                xy_counterX[cntX_H]++;
////                xy_counterO[cntO_H]++;
////            }
//
//            // Diagonal
//            if (board[i][j] == 'X') {
//                int diag1 = diagCnt(i - 1, j + 1, board[i][j], -1, 1, diagCnt) +
//                            diagCnt(i + 1, j - 1, board[i][j], 1, -1, diagCnt) + 1,
//                    diag2 = diagCnt(i - 1, j - 1, board[i][j], -1, -1, diagCnt) +
//                            diagCnt(i + 1, j + 1, board[i][j], 1, 1, diagCnt) + 1;
//
//                diag_counterX[diag1]++;
//                diag_counterX[diag2]++;
//            }
//            else if (board[i][j] == 'O') {
//                int diag1 = diagCnt(i - 1, j + 1, board[i][j], -1, 1, diagCnt) +
//                            diagCnt(i + 1, j - 1, board[i][j], 1, -1, diagCnt) + 1,
//                    diag2 = diagCnt(i - 1, j - 1, board[i][j], -1, -1, diagCnt) +
//                            diagCnt(i + 1, j + 1, board[i][j], 1, 1, diagCnt) + 1;
//
//                diag_counterO[diag1]++;
//                diag_counterO[diag2]++;
//            }
//        }
//        xy_counterX[cntX_H]++;
//        xy_counterO[cntO_H]++;
//    }
//
//    for (int j = 0; j < n_cols; j++) {
//        int cntX_V = 0, cntO_V = 0;
//        for (int i = 0; i < n_rows; i++) {
//            // Vertical
//            if (board[i][j] == 'X') {
//                cntX_V++;
//                xy_counterO[cntO_V]++;
//                cntO_V = 0;
//            }
//            else if (board[i][j] == 'O') {
//                cntO_V++;
//                xy_counterX[cntX_V]++;
//                cntX_V = 0;
//            }
////            else {
////                xy_counterX[cntX_V]++;
////                xy_counterO[cntO_V]++;
////            }
//        }
//        xy_counterX[cntX_V]++;
//        xy_counterO[cntO_V]++;
//    }
//
//    if (curr_player == 'X') {
//        return -(1000 * (xy_counterX[4] + diag_counterX[4]/4) -
//               100 * (xy_counterO[4] + diag_counterO[4]/4) +
//               15 * (xy_counterX[3] + diag_counterX[3]/3) -
//               15 * (xy_counterO[3] + diag_counterO[3]/3) +
//               3 * (xy_counterX[2] + diag_counterX[2]/2) -
//               3 * (xy_counterO[2] + diag_counterO[2]/2) +
//               xy_counterX[1] -
//               xy_counterO[1]);
//    }
//    else {
//        return 1000 * (xy_counterO[4] + diag_counterO[4]/4) -
//               100 * (xy_counterX[4] + diag_counterX[4]/4) +
//               15 * (xy_counterO[3] + diag_counterO[3]/3) -
//               15 * (xy_counterX[3] + diag_counterX[3]/3) +
//               3 * (xy_counterO[2] + diag_counterO[2]/2) -
//               3 * (xy_counterX[2] + diag_counterX[2]/2) +
//               xy_counterO[1] -
//               xy_counterX[1];
//    }
//}

int CollectFourBoard::eval_game(char curr_player) {
    int scoreX = 0, scoreO = 0;

    auto check = [] (int i, int j, int limit) -> bool {
        return (i + j < 0 || i + j >= limit);
    };

    auto update = [&] (int i, int j, int i1, int j1, int i2, int j2, int i3, int j3) {
        if (check(i, i1, 6) || check(i, i3, 6) || check(j, j1, 7) || check(j, j3, 7))
            return 0;
        int ans = board[i][j] + board[i + i1][j + j1] + board[i + i2][j + i2] + board[i + i3][j + j3];
        if (ans % board[i][j] == 0) {
            ans /= board[i][j];
            return (ans * ans);
        }
        return 0;
    };


    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            int score = 0;
            int arr[] = {-3, -2, -1, 1, 2, 3};
            if (board[i][j] != 0) {
                for (int k = 0; k < 4; k++) {
                    // horizontal
                    score += update(i, j, 0, arr[k], 0, arr[k+1], 0, arr[k+2]);
                    // vertical
                    score += 3 * update(i, j, arr[k], 0, arr[k+1], 0, arr[k+2], 0);
                    // diagonal
                    score += update(i, j, arr[k], arr[k], arr[k+1], arr[k+1], arr[k+2], arr[k+2]);
                    score += update(i, j, -arr[k], arr[k], -arr[k+1], arr[k+1], -arr[k+2], arr[k+2]);
                }

//                // horizontal
//                if (j < 4)
//                    score += update(i, j, 0, 1, 0, 2, 0, 3);
//                if (j > 0 && j < 5)
//                    score += update(i, j, 0, -1, 0, 1, 0, 2);
//                if (j > 1 && j < 6)
//                    score += update(i, j, 0, -2, 0, -1, 0, 1);
//                if (j > 2)
//                    score += update(i, j, 0, -1, 0, -2, 0, -3);
//
//                // vertical
//                if (i < 3)
//                    score += update(i, j, 1, 0, 2, 0, 3, 0);
//                if (i > 0 && i < 4)
//                    score += update(i, j, -1, 0, 1, 0, 2, 0);
//                if (i > 1 && i < 5)
//                    score += update(i, j, -2, 0, -1, 0, 1, 0);
//
//                // diagonal
//                if (i < 3 && j < 4)
//                    score += update(i, j, 1, 1, 2, 2, 3, 3);
//                if (i > 0 && i < 4 && j > 0 && j < 5)
//                    score += update(i, j, -1, -1, 1, 1, 2, 2);
//                if (i > 1 && i < 5 && j > 1 && j < 6)
//                    score += update(i, j, -2, -2, -1, -1, 1, 1);
//                if (i > 2 && j > 2)
//                    score += update(i, j, -3, -3, -2, -2, -1, -1);
//
//                if (i > 2 && j < 4)
//                    score += update(i, j, -3, 3, -2, 2, -1, 1);
//                if (i > 1 && j > 1 && j < 6)
//                    score += update(i, j, -2, 2, -1, 1, 1, -1);
//                if (i > 2 && j > 0 && j < 5)
//                    score += update(i, j, -1, 1, 1, -1, 2, -2);
//                if (i < 3 && j < 4)
//                    score += update(i, j, 1, -1, 2, -2, 3, -3);
            }

            if (board[i][j] == 'X')
                scoreX += score;
            else if (board[i][j] == 'O')
                scoreO += score;
        }
    }

    return scoreO - scoreX;
}