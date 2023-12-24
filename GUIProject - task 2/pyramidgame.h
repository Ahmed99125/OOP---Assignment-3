#ifndef PYRAMIDGAME_H
#define PYRAMIDGAME_H

#include <QDialog>
#include "pyramid_x_o_board.h"
#include "pyramid_x_o_player.h"
#include "BoardGame_Classes.hpp"

namespace Ui {
class PyramidGame;
}

class PyramidGame : public QDialog
{
    Q_OBJECT

public:
    explicit PyramidGame(QWidget *parent = nullptr);
    ~PyramidGame();

private:
    Ui::PyramidGame *ui;
    void move(int col, int row,QPushButton *button);
    Player *player1;
    Player *player2;
    Board *board;
    bool IsPlayer1= true;
    bool isRandomSecPlayer =false;
    QVector<QVector<QPushButton *>> buttons;
    void closeButtons();
    void openButtons();
};

#endif // PYRAMIDGAME_H
