#ifndef NORMALGAME_H
#define NORMALGAME_H

#include <QDialog>
#include "BoardGame_Classes.hpp"

namespace Ui {
class NormalGame;
}

class NormalGame : public QDialog
{
    Q_OBJECT

public:
    explicit NormalGame(QWidget *parent = nullptr);
    ~NormalGame();

private:
    Ui::NormalGame *ui;
    void move(int col, int row,QPushButton *button);
    Player *player1;
    Player *player2;
    Board *board;
    bool IsPlayer1= true;
    bool isRandomSecPlayer =false;
    QVector<QVector<QPushButton *>> buttons;
    void closeButtons();
};

#endif // NORMALGAME_H
