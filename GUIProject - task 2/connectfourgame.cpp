#include "connectfourgame.h"
#include "ui_connectfourgame.h"
#include "QDebug"
#include <QInputDialog>
#include <QMessageBox>

ConnectFourGame::ConnectFourGame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectFourGame)
{
    ui->setupUi(this);
    Player* players[2];
    Board* board;
    players[0] = new CollectFourPlayer (1, 'x');

    do{
    QMessageBox msBox;
    msBox.setText("choose the second player");
    msBox.addButton("Player 2", QMessageBox::AcceptRole);
    msBox.addButton("Random Player",QMessageBox::RejectRole);
    int choice = msBox.exec();

    if(choice == QMessageBox::AcceptRole){
        players[1] = new CollectFourPlayer(2,'O');
    }else if(choice == QMessageBox::RejectRole){
        players[1] = new RandomPlayer('O',7);
    }
    }while(players[1] == nullptr);
    board = new CollectFourBoard();
    GameManager collectFour(board, players);
    collectFour.run();
}

ConnectFourGame::~ConnectFourGame()
{
    delete ui;
}




void ConnectFourGame::on_MoveButton_clicked()
{
    bool okx;
    int x1 = QInputDialog::getInt(NULL,"Enter X","X:",0,INT_MIN,INT_MAX,1,&okx );
}

