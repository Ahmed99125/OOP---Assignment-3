#include "pyramidgame.h"
#include "ui_pyramidgame.h"

PyramidGame::PyramidGame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PyramidGame)
{
    ui->setupUi(this);
}

PyramidGame::~PyramidGame()
{
    delete ui;
}
