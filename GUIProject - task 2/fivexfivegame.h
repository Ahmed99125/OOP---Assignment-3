#ifndef FIVEXFIVEGAME_H
#define FIVEXFIVEGAME_H

#include "boardgame_classes.h"
#include "fivexfiveboard.h"
#include "fivexfiveplayer.h"
#include <QDialog>

namespace Ui {
class FiveXFiveGame;
}

class FiveXFiveGame : public QDialog
{
    Q_OBJECT

public:
    explicit FiveXFiveGame(QWidget *parent = nullptr);
    ~FiveXFiveGame();

private:
    Ui::FiveXFiveGame *ui;
    void move(int col, int row,QPushButton *button);
    Player *player1;
    Player *player2;
    Board *board;
    bool IsPlayer1= true;
    bool isRandomSecPlayer =false;
    QVector<QVector<QPushButton *>> buttons;
    void closeButtons();
};

#endif // FIVEXFIVEGAME_H
