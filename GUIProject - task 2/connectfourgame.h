#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H

#include "collectfourboard.h"
#include "collectfourplayer.h"
#include "boardgame_classes.h"
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


    void on_MoveButton_clicked();

private:
    Ui::ConnectFourGame *ui;


};

#endif // CONNECTFOURGAME_H
