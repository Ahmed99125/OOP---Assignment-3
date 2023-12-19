//
// Created by at991 on 12/15/2023.
//

#include <iostream>
#include <iomanip>
#include "Pyramid_X_O_Board.h"

using namespace std;

Pyramid_X_O_Board::Pyramid_X_O_Board() {
    // make n_cols = 5 and then mark only the allowed cells
    n_rows = 3, n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char [n_cols];
        // the start and number of cols allowed in this row
        int start = n_rows - i - 1, cols = 1 + 2 * i;
        for (int j = 0; j < n_cols; j++) {
            board[i][j] = -1;
            //mark only the allowed cells with 0
            if (j >= start && j < start + cols)
                board[i][j] = 0;
        }
    }
}

bool Pyramid_X_O_Board::update_board(int x, int y, char mark) {
    if (x < 0 || x >= n_rows || y < 0 || y >= n_cols || board[x][y] != 0)
        return false;
    board[x][y] = toupper(mark);
    n_moves++;
    return true;
}

bool Pyramid_X_O_Board::undo_move(int x, int y) {
    if (x < 0 || x >= n_rows || y < 0 || y >= n_cols)
        return false;
    board[x][y] = 0;
    n_moves--;
    return true;
}

void Pyramid_X_O_Board::display_board() {
    for (int i = 0; i < n_rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; j++) {
            // if there is no cell just print space
            if (board[i][j] == -1) {
                cout << setw(10) << " |";
                continue;
            }
            cout << " (" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool Pyramid_X_O_Board::is_winner() {
    // hard coding winning possibilities
    char row_win[4], col_win, diag_win[2];
    diag_win[0] = board[0][2] & board[1][1] & board[2][0];
    diag_win[1] = board[0][2] & board[1][3] & board[2][4];
    col_win = board[0][2] & board[1][2] & board[2][2];
    row_win[0] = board[1][1] & board[1][2] & board[1][3];
    for (int i = 0; i < 3; i++) {
        row_win[1+i] = board[2][i] & board[2][i+1] & board[2][i+2];
    }

    if ((diag_win[0] && diag_win[0] == board[0][2]) ||
        (diag_win[1] && diag_win[1] == board[0][2]) ||
        (col_win && col_win == board[0][2]) ||
        (row_win[0] && row_win[0] == board[1][1])){
        return true;
    }
    for (int i = 0; i < 3; i++) {
        if (row_win[1+i] && row_win[1+i] == board[2][i]) {
            return true;
        }
    }

    return false;
}

// Return true if 9 moves are done and no winner
bool Pyramid_X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramid_X_O_Board::game_is_over() {
    return n_moves >= 9;
}

int Pyramid_X_O_Board::get_n_moves() const {
    return n_moves;
}

string Pyramid_X_O_Board::get_board() const {
    string ans = "";
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            ans += board[i][j];
        }
    }
    return ans;
}