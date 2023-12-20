#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"connectfourgame.h"
#include"pyramidgame.h"
#include "fivexfivegame.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FiveXFiveGameBtn_clicked()
{
    FiveXFiveGame fiveXFiveGame;
    fiveXFiveGame.setWindowTitle("5 X 5 game");
    fiveXFiveGame.setModal(true);
    fiveXFiveGame.exec();
}


void MainWindow::on_conncetFourGameBtn_clicked()
{
    ConnectFourGame connectFourGame;
    connectFourGame.setWindowTitle("Connect Four Game");
    connectFourGame.setModal(true);
    connectFourGame.exec();
}


void MainWindow::on_pyramicGameBtn_clicked()
{
    PyramidGame pyramidGame;
    pyramidGame.setWindowTitle("Pyramid Game");
    pyramidGame.setModal(false);
    pyramidGame.show();
}

