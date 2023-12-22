#include "AI_Player.h"

AI_Player::AI_Player(char symbol, Board* board_ptr) : Player(symbol) {
    this->board = board_ptr;
    name = "Computer AI";
    int rows = board->get_n_rows(), cols = board->get_n_cols();
    int mid_rows = rows / 2, mid_cols = cols / 2;

    for (int i = 0; i <= mid_rows; i++) {
        int idx1 = mid_rows-i, idx2 = mid_rows+i;
        dimensionX.push_back(idx1);
        if (idx2 != idx1 && idx2 < rows)
            dimensionX.push_back(idx2);
    }

    for (int i = 0; i <= mid_cols; i++) {
        int idx1 = mid_cols-i, idx2 = mid_cols+i;
        dimensionY.push_back(idx1);
        if (idx2 != idx1 && idx2 < cols)
            dimensionY.push_back(idx2);
    }
}

int AI_Player::minimax(int depth, char curr_Player, int alpha, int beta) {
    is_pruned = false;
    if (!depth)
        return board->eval_game(curr_Player, depth);

    int best_moveX = 0, best_moveY = 0;
    char next_Player = (curr_Player == 'X') ? 'O' : 'X';

    // if curr player is X
    if (curr_Player == 'X') {
        int max_score = -INT_MAX, score = -INT_MAX;
        for (auto i : dimensionX) {
            for (auto j : dimensionY) {
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

                    if (!is_pruned)
                        dp[s_board] = max_score;
                    board->undo_move(i, j);

                    alpha = max(score, alpha);
                    if (beta <= alpha) {
                        is_pruned = true;
                        goto out1;
                    }
                }
            }
        }

        out1:;
        bestMove = {best_moveX, best_moveY};
        return max_score;
    }
    else {
        int min_score = INT_MAX, score = INT_MAX;
        for (auto i : dimensionX) {
            for (auto j : dimensionY) {
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

                    if (!is_pruned)
                        dp[s_board] = min_score;
                    board->undo_move(i, j);

                    beta = min(score, beta);
                    if (beta <= alpha) {
                        is_pruned = true;
                        goto out2;
                    }
                }
            }
        }

        out2:;
        bestMove = {best_moveX, best_moveY};
        return min_score;
    }
}

void AI_Player::get_move(int &x, int &y) {
    bestMove = {-1, -1};
    minimax(9, this->get_symbol(), -INT_MAX, INT_MAX);
    x = bestMove.first, y = bestMove.second;
}