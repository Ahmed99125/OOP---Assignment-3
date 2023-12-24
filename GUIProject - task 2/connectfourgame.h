#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H

#include "collectfourboard.h"
#include "collectfourplayer.h"
#include "BoardGame_Classes.hpp"
#include "QDebug"
#include <QDialog>

namespace Ui {
class ConnectFourGame;
}

class ConnectFourGame : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectFourGame(QWidget *parent = nullptr);
    ~ConnectFourGame();

private slots:




private:
    Ui::ConnectFourGame *ui;
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

#endif // CONNECTFOURGAME_H
