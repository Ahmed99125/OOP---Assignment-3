#include <iostream>
#include "CollectFourBoard.h"
#include "CollectFourPlayer.h"
#include "FiveXFiveBoard.h"
#include "FiveXFivePlayer.h"
#include "FiveXFive_GameManager.h"
#include "Pyramid_X_O_Board.h"
#include "Pyramid_X_O_Player.h"
#include "Pyramid_X_O_AI.h"

int main() {
int choice;
do {
    cout << "Welcome to FCAI X-O Games, please choose the game . :)\n"
         << "1- pyramid tic tac toe \n"
         << "2- connect four game\n"
         << "3- 5X5 tic tac toe\n";

    cin >> choice;
} while(choice != 1 &&choice !=2 && choice!=3);

    Player* players[2];
    Board* board;
    players[0] = new Player (1, 'x');

int choice1;
    switch (choice) {
        case 1: {
            board = new Pyramid_X_O_Board();
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice1;
            if (choice1 != 1) {
                players[1] = new Pyramid_X_O_Player(2, 'O');
            } else {
                //Player pointer points to child
                players[1] = new Pyramid_X_O_AI('O', board);
            }
            GameManager Pyramid_X_O (board, players);
            Pyramid_X_O.run();
        }
            break;
        case 2: {
            board = new CollectFourBoard();
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice1;
            if (choice1 != 1) {
                players[1] = new CollectFourPlayer(2, 'o');
            } else {
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 7);
            }
            GameManager collectFour(board, players);
            collectFour.run();
            break;
        }
        case 3: {
            board = new FiveXFiveBoard();
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice1;
            if (choice1 != 1)
                players[1] = new FiveXFivePlayer(2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 5);
            FiveXFive_GameManager FiveXFive (board, players);
            FiveXFive.run();
        }
            break;
        default:
            break;
    }


}
