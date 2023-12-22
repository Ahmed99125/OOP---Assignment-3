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
        /*if(n_moves == 24) {
            for(int i=0; i<5; ++i) {
                for(int j=0; j<5; ++j) {
                    if(board[i][j] == 0) {
                        board[i][j] = toupper('x');
                        n_moves++;
                    }
                }
            }
        }*/
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

    if (countX != countO)
        return true;
    return false;
}
bool FiveXFiveBoard::is_draw()
{
    return (n_moves == 25 && !is_winner());
}

bool FiveXFiveBoard::game_is_over()
{
    return n_moves >= 25;
}
