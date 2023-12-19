#include "Pyramid_X_O_AI.h"

Pyramid_X_O_AI::Pyramid_X_O_AI(char symbol, Board* board_ptr) : Player(symbol) {
    this->board = board_ptr;
    name = "Computer AI";
}

int Pyramid_X_O_AI::minimax(int depth, char curr_Player, int alpha, int beta) {
    if (board->is_winner()) {
        return (curr_Player == 'X') ? -depth : depth;
    }
    if (board->is_draw())
        return 0;

    int best_moveX = 0, best_moveY = 0;
    char next_Player = (curr_Player == 'X') ? 'O' : 'X';

    // if curr player is X
    if (curr_Player == 'X') {
        int max_score = -INT_MAX, score = -INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (board->update_board(i, j, curr_Player)) {
                    string s_board = board->get_board();

                    if (dp.count(s_board))
                        score = dp[s_board];
                    else
                        score = minimax(depth-1, next_Player, alpha, beta);

                    if (max_score < score) {
                        best_moveX = i, best_moveY = j;
                        max_score = score;
                    }

                    dp[s_board] = max_score;
                    board->undo_move(i, j);

                    alpha = max(score, alpha);
                    if (beta <= alpha)
                        goto out1;
                }
            }
        }
        out1:;
        bestMove = {best_moveX, best_moveY};
        return max_score;
    }
    else {
        int min_score = INT_MAX, score = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (board->update_board(i, j, curr_Player)) {
                    string s_board = board->get_board();

                    if (dp.count(s_board))
                        score = dp[s_board];
                    else
                        score = minimax(depth-1, next_Player, alpha, beta);
                    if (min_score > score) {
                        best_moveX = i, best_moveY = j;
                        min_score = score;
                    }

                    dp[s_board] = min_score;
                    board->undo_move(i, j);

                    beta = min(score, beta);
                    if (beta <= alpha)
                        goto out2;
                }
            }
        }

        out2:;
        bestMove = {best_moveX, best_moveY};
        return min_score;
    }
}

void Pyramid_X_O_AI::get_move(int &x, int &y) {
    bestMove = {0, 0};
    minimax(10-board->get_n_moves(), this->get_symbol(), -INT_MAX, INT_MAX);
    x = bestMove.first, y = bestMove.second;
    cout << x << ' ' << y << endl;
}