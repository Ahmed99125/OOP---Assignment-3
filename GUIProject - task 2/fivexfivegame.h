#ifndef FIVEXFIVEGAME_H
#define FIVEXFIVEGAME_H

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
};

#endif // FIVEXFIVEGAME_H
