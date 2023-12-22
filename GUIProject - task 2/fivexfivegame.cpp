#include "fivexfivegame.h"
#include "qgridlayout.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "ui_fivexfivegame.h"
#include "AI_Player.h"

FiveXFiveGame::FiveXFiveGame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FiveXFiveGame)
{
    ui->setupUi(this);
    player1 = new FiveXFivePlayer('X');
    board = new FiveXFiveBoard();
    do{
        QMessageBox msBox;
        msBox.setText("choose the second player");
        msBox.addButton("Player 2", QMessageBox::AcceptRole);
        msBox.addButton("AI Player",QMessageBox::RejectRole);
        int choice = msBox.exec();

        if(choice == QMessageBox::AcceptRole){
            player2 = new FiveXFivePlayer('O');
        }else if(choice == QMessageBox::RejectRole){
            player2= new AI_Player('O', board);
            isRandomSecPlayer = true;
        }

    }while(player2 == nullptr);
    QGridLayout *gridLayout = new QGridLayout(this);
    buttons.resize(5, QVector<QPushButton *>(5, nullptr));//
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 5; ++col) {

            QPushButton *button = new QPushButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            gridLayout->addWidget(button,row, col);
            buttons[row][col] = button;
            //qDebug()<< "hi";

            connect(button, &QPushButton::clicked, [=](){
                move(col,row,button);
            });
        }
    }
}

FiveXFiveGame::~FiveXFiveGame()
{
    delete ui;
}

void FiveXFiveGame::move(int col, int row,QPushButton *button){

    //qDebug()<< col <<" "<< row<<" " <<symbol;

    if(board->update_board(row, col,IsPlayer1 ? 'X' :'O')){
        if(IsPlayer1){
            button->setText("X");
        }else{
            button->setText("O");
        }
        //board->display_board();
        if(board->game_is_over()){
            if(board->is_winner()){
                QMessageBox msBox;
                msBox.setText("Plyer1 won");
                msBox.exec();
                closeButtons();
            }else{
                QMessageBox msBox;
                if(isRandomSecPlayer){
                    msBox.setText("AI player won");
                }else{

                    msBox.setText("Plyer2 won");
                }
                msBox.exec();
                closeButtons();
            }
            return;
        }
       // cout<< "hi";
        if(board->is_draw()){
            QMessageBox msBox;
            msBox.setText("Draw");
            msBox.exec();
            closeButtons();
            return;
        }
        IsPlayer1 = !IsPlayer1;
        if(isRandomSecPlayer){
            int x,y;
            do{
                player2->get_move(x,y);
            }while(!board->update_board(x, y,IsPlayer1 ? 'X' :'O'));
            buttons[x][y]->setText("O");
            IsPlayer1 = !IsPlayer1;
            if(board->game_is_over()){
                if(board->is_winner()){
                    QMessageBox msBox;
                    msBox.setText("Plyer1 won");
                    msBox.exec();
                    closeButtons();
                    return;
                }else{
                    QMessageBox msBox;
                    msBox.setText("AI Player won");
                    msBox.exec();
                    closeButtons();
                    return;
                }
            }
            if(board->is_draw()){
                QMessageBox msBox;
                msBox.setText("Draw");
                msBox.exec();
                closeButtons();
                return;
            }
           // board->display_board();
        }
    }else{
        QMessageBox::warning(this, "Error", "Invaled move");
    }
}
void FiveXFiveGame::closeButtons(){
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 5; ++col) {
            buttons[row][col]->setEnabled(false);
        }
    }
}
