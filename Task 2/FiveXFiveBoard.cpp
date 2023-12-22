#include <iostream>
#include "FiveXFiveBoard.h"
#include <iomanip>

FiveXFiveBoard::FiveXFiveBoard()
{
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool FiveXFiveBoard::update_board(int x, int y, char mark)
{
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
//        if(n_moves == 24) {
//            for(int i=0; i<5; ++i) {
//                for(int j=0; j<5; ++j) {
//                    if(board[i][j] == 0) {
//                        board[i][j] = toupper('x');
//                        n_moves++;
//                    }
//                }
//            }
//        }
        return true;
    }
    else
        return false;
}

void FiveXFiveBoard::display_board()
{
    for (int i : {0, 1, 2, 3, 4})
    {
        cout << "\n|";
        for (int j : {0, 1, 2, 3, 4})
        {
            if(board[i][j] == 0) {
                cout << setw(2) << "(" << i << "," << j << ")" << " |";
            } else {
                cout << setw(4) << board[i][j] << setw(4) << " |";
            }
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool FiveXFiveBoard::is_winner()
{
    int countX = 0;
    int countO = 0;

    // Rows and Columns wins counts.

    for (int i = 0; i < 5; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            char val = board[i][0];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
        if (board[i][1] == board[i][2] && board[i][2] == board[i][3])
        {
            char val = board[i][1];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
        if (board[i][2] == board[i][3] && board[i][3] == board[i][4])
        {
            char val = board[i][2];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            char val = board[0][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
        if (board[1][i] == board[2][i] && board[2][i] == board[3][i])
        {
            char val = board[1][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
        if (board[2][i] == board[3][i] && board[3][i] == board[4][i])
        {
            char val = board[2][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
    }

    // Diagonal wins counts

    for (int i = 0; i < 3; ++i)
    {
        if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2])
        {
            char val = board[i][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        if (board[i + 1][i] == board[i + 2][i + 1] && board[i + 2][i + 1] == board[i + 3][i + 2])
        {
            char val = board[i + 1][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
    }

    if (board[1][4] == board[2][3] && board[2][3] == board[3][2])
    {
        char val = board[1][4];
        if (val == 'X')
            countX++;
        else if (val == 'O')
            countO++;
    }

    if (board[2][3] == board[3][2] && board[3][2] == board[4][1])
    {
        char val = board[2][3];
        if (val == 'X')
            countX++;
        else if (val == 'O')
            countO++;
    }

    if (board[2][0] == board[3][1] && board[3][1] == board[4][2])
    {
        char val = board[2][0];
        if (val == 'X')
            countX++;
        else if (val == 'O')
            countO++;
    }

    if (board[0][2] == board[1][3] && board[1][3] == board[2][4])
    {
        char val = board[0][2];
        if (val == 'X')
            countX++;
        else if (val == 'O')
            countO++;
    }

    if (countX > countO)
        return true;
    return false;
}
bool FiveXFiveBoard::is_draw()
{
    int countX = 0;
    int countO = 0;

    // Rows and Columns wins counts.

    for (int i = 0; i < 5; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            char val = board[i][0];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
        if (board[i][1] == board[i][2] && board[i][2] == board[i][3])
        {
            char val = board[i][1];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
        if (board[i][2] == board[i][3] && board[i][3] == board[i][4])
        {
            char val = board[i][2];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            char val = board[0][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
        if (board[1][i] == board[2][i] && board[2][i] == board[3][i])
        {
            char val = board[1][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
        if (board[2][i] == board[3][i] && board[3][i] == board[4][i])
        {
            char val = board[2][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
    }

    // Diagonal wins counts

    for (int i = 0; i < 3; ++i)
    {
        if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2])
        {
            char val = board[i][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        if (board[i + 1][i] == board[i + 2][i + 1] && board[i + 2][i + 1] == board[i + 3][i + 2])
        {
            char val = board[i + 1][i];
            if (val == 'X')
                countX++;
            else if (val == 'O')
                countO++;
        }
    }

    if (board[1][4] == board[2][3] && board[2][3] == board[3][2])
    {
        char val = board[1][4];
        if (val == 'X')
            countX++;
        else if (val == 'O')
            countO++;
    }

    if (board[2][3] == board[3][2] && board[3][2] == board[4][1])
    {
        char val = board[2][3];
        if (val == 'X')
            countX++;
        else if (val == 'O')
            countO++;
    }

    if (board[2][0] == board[3][1] && board[3][1] == board[4][2])
    {
        char val = board[2][0];
        if (val == 'X')
            countX++;
        else if (val == 'O')
            countO++;
    }

    if (board[0][2] == board[1][3] && board[1][3] == board[2][4])
    {
        char val = board[0][2];
        if (val == 'X')
            countX++;
        else if (val == 'O')
            countO++;
    }

    if (countX == countO && countX > 0)
        return true;
    return false;
}

bool FiveXFiveBoard::game_is_over()
{
    return n_moves >= 24;
}



bool FiveXFiveBoard::undo_move(int x, int y) {
    if (x < 0 || x >= n_rows || y < 0 || y >= n_cols)
        return false;
    board[x][y] = 0;
    n_moves--;
    return true;
}

int FiveXFiveBoard::get_n_moves() const {
    return n_moves;
}

string FiveXFiveBoard::get_board() const {
    string ans = "";
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            ans += board[i][j];
        }
    }
    return ans;
}

int FiveXFiveBoard::get_n_rows() const {
    return n_rows;
}

int FiveXFiveBoard::get_n_cols() const {
    return n_cols;
}

int FiveXFiveBoard::eval_game(char curr_player, int depth) {
    if (game_is_over()){
        if (is_draw())
            return 0;
        if(is_winner())
            return (curr_player == 'X') ? -(1000+depth) : (1000+depth);
    }

    int scoreX = 0, scoreO = 0;

    auto check = [] (int i, int j, int limit) -> bool {
        return (i + j < 0 || i + j >= limit);
    };

    auto update = [&] (int i, int j, int i1, int j1, int i2, int j2) {
        if (check(i, i1, 5) || check(i, i2, 5) || check(j, j1, 5) || check(j, j2, 5))
            return 0;
        int ans = board[i][j] + board[i + i1][j + j1] + board[i + i2][j + j2];
        if (ans % board[i][j] == 0) {
            ans /= board[i][j];
            return (ans * ans);
        }
        return 0;
    };


    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            int score = 0;
            int arr[] = {-2, -1, 1, 2};
            if (board[i][j] != 0) {
                for (int k = 0; k < 3; k++) {
                    // horizontal
                    score += update(i, j, 0, arr[k], 0, arr[k+1]);
                    // vertical
                    score += 3 * update(i, j, arr[k], 0, arr[k+1], 0);
                    // diagonal
                    score += update(i, j, arr[k], arr[k], arr[k+1], arr[k+1]);
                    score += update(i, j, -arr[k], arr[k], -arr[k+1], arr[k+1]);
                }
            }

            if (board[i][j] == 'X')
                scoreX += score;
            else if (board[i][j] == 'O')
                scoreO += score;
        }
    }

    return (curr_player == 'X') ? (scoreX - scoreO) : -(scoreX - scoreO);
}