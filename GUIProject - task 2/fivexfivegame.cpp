#include "fivexfivegame.h"
#include "ui_fivexfivegame.h"

FiveXFiveGame::FiveXFiveGame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FiveXFiveGame)
{
    ui->setupUi(this);
}

FiveXFiveGame::~FiveXFiveGame()
{
    delete ui;
}
