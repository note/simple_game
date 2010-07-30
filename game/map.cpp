#include "map.h"
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>

Map::Map(QWidget * parent, int columns, int rows, int victory, int squareSize, int padding) :
QWidget(parent), board(columns, rows, victory), columns(columns), rows(rows), squareSize(squareSize), victory(victory), padding(padding){
    QWidget::resize((squareSize+padding*2)*columns, (squareSize+padding*2)*rows);
    action = 1;
}

void Map::paintEvent(QPaintEvent * event){
    QPainter painter(this);
    if(action & 1){ //drawing/redrawing board
        QColor color(0, 0, 0);
        painter.setBrush(color);
        painter.setPen(color);
        painter.setRenderHint(QPainter::Antialiasing, true);
        for(int i=0; i<columns; i++)
            for(int j=0; j<rows; j++){
                QRect rect(i*(squareSize+2*padding)+padding, j*(squareSize+2*padding)+padding, squareSize, squareSize);
                if(board[j][i] == 0)
                    painter.drawEllipse(rect);
                else{
                    QRect source(0, 0, 40, 40);
                    QString whichFile;
                    whichFile.setNum(board[j][i]);
                    QImage image(":"+whichFile+".png");
                    painter.drawImage(rect, image, source);
                }
            }
    }
    if((action >> 1) & 1){ //draw new piece
        QRect target(event->rect());
        QRect source(0, 0, 40, 40);
        QString whichFile;
        whichFile.setNum((whoseMove()->color));
        QImage image(":"+whichFile+".png");
        painter.drawImage(target, image, source);
        action = 1;
    }
}

void Map::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        int column = event->x() / (squareSize+2*padding);
        try{
            //make move
            int row = board.getRowForColumn(column);
            if(row>=0){ //otherwise row<0, then this column is full, nothing to do
                board.playerStop();
                board.move(row, column);
                QRect rect(QRect(column*(squareSize+2*padding)+padding, row*(squareSize+2*padding)+padding, squareSize, squareSize));
                action = 2;
                repaint(rect); //important!! it can't be update cause update doesn't call paintEvent immediately
                afterMove();
            }
        }catch(IncorrectMove &e){
            QMessageBox::information(this, "Error", "Icorrect move");
        }catch(OutOfRange &e){
            QMessageBox::information(this, "Error", "Out of range error.");
        }
    }
}

void Map::redraw(){
    action = 1;
    update();
}

void Map::restart(){
    int ret = QMessageBox::AcceptRole;
    if(board.winner() == 0){ //current game still lasts
        QMessageBox box;
        box.setText("Current game still lasts.");
        box.setInformativeText("Do you want to restart?");
        box.addButton("Yes", QMessageBox::AcceptRole);
        box.addButton("No", QMessageBox::RejectRole);
        ret = box.exec();
    }
    if(ret==QMessageBox::AcceptRole){ //if confirmation was accepted
        board.reset();
        action = 1;
        update();
        board.start();
    }
}

Player * Map::whoseMove(){
    return board.player;
}

void Map::afterMove(){
    board.setTurnOnNextActive();
    if(board.winner() || board.isFull()){
        endOfGame();
    }else
        board.playerStart();
}

void Map::endOfGame(){
    QString message;
    if(board.winner())
        message = "Player " + board.winner()->name + " has won!";
    else
        message = "You all are winners!";

    //MessageBox::information forces some updates, that strange repetition makes it all works
    action = 1;
    QMessageBox::information(this, "End of game", message);
    action=1;
}
