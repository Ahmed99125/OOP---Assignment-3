
#include "pyramidgame.h"
#include "qgridlayout.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "ui_pyramidgame.h"
#include "AI_Player.h"

PyramidGame::PyramidGame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PyramidGame)
{
    ui->setupUi(this);

    player1 = new Pyramid_X_O_Player('X');
    board = new Pyramid_X_O_Board();
    do{
        QMessageBox msBox;
        msBox.setText("choose the second player");
        msBox.addButton("Player 2", QMessageBox::AcceptRole);
        msBox.addButton("AI Player",QMessageBox::RejectRole);
        int choice = msBox.exec();

        if(choice == QMessageBox::AcceptRole){
            player2 = new Pyramid_X_O_Player('O');
        }else if(choice == QMessageBox::RejectRole){
            player2 = new AI_Player('O', board, 0);
            isRandomSecPlayer = true;
        }

    }while(player2 == nullptr);

    QGridLayout *gridLayout = new QGridLayout(this);
    buttons.resize(3, QVector<QPushButton *>(5, nullptr));//
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 5; ++col) {
            //qDebug()<< "hi";
            if(((row == 0 )&&(col==0 || col==1 || col == 3|| col== 4)) || (row ==1)&&(col==0|| col==4)){
                continue;
            }
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
    //qDebug()<< "hi1";

}

PyramidGame::~PyramidGame()
{
    delete ui;
}

void PyramidGame::move(int col, int row,QPushButton *button){

    //qDebug()<< col <<" "<< row<<" " <<symbol;

    if(board->update_board(row, col,IsPlayer1 ? 'X' :'O')){
        if(IsPlayer1){
            button->setText("X");
        }else{
            button->setText("O");
        }
        //board->display_board();
        if(board->is_winner()){
            QMessageBox msBox;
            if(IsPlayer1)msBox.setText("Plyer1 won");
            else msBox.setText("Plyer2 won");
            msBox.exec();
            closeButtons();
            return;
        }
        //cout<< "hi";
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
                qDebug()<<"hi";
            }while(!board->update_board(x, y,IsPlayer1 ? 'X' :'O'));
            buttons[x][y]->setText("O");
            IsPlayer1 = !IsPlayer1;
            if(board->is_winner()){
                QMessageBox msBox;
                msBox.setText("AI Player won");
                msBox.exec();
                closeButtons();
                return;
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
void PyramidGame::closeButtons(){
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 5; ++col) {
            if(((row == 0 )&&(col==0 || col==1 || col == 3|| col== 4)) || (row ==1)&&(col==0|| col==4)){
                continue;
            }
            buttons[row][col]->setEnabled(false);
        }
    }
}
