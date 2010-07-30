#include "board.h"
#include <QMessageBox>

bool Board::isWinningRow(int row, int column) const{
    int res = 1, i=column-1;
    while(res<victory && i>=0)
        if((*this)[row][i] == (*this)[row][column])
            res++, i--;
        else
            break;
    i = column+1;
    while(res<victory && i<columns)
        if((*this)[row][column] == (*this)[row][i])
            res++, i++;
        else
            break;
    return res == victory;
}

bool Board::isWinningColumn(int row, int column) const{
    int res=1, i=row+1; //there's no point in going up (in this case up means from greater to smaller index) because [row][column] is last added piece so no piece can be above that
    while(res<victory && i<rows)
        if((*this)[i][column] == (*this)[row][column])
            res++, i++;
        else
            break;
    return res == victory;
}

bool Board::isWinningDiagonal(int row, int column) const{
    //diagonal from top-left to bottom-right
    int res=1, i=row-1, j=column-1;
    //top-left direction
    while(res<victory && i>=0 && j>=0)
        if((*this)[i][j] == (*this)[row][column])
            res++, i--, j--;
        else
            break;
    //bottom-right direction
    i = row+1, j=column+1;
    while(res<victory && i<rows && j<columns)
        if((*this)[i][j] == (*this)[row][column])
            res++, i++, j++;
        else
            break;
    if(res == victory)
        return true;

    //diagonal from top-right to bottom-left
    res = 1, i = row-1, j = column+1;
    //top-right direction
    while(res<victory && i>=0 && j<columns)
        if((*this)[i][j] == (*this)[row][column])
            res++, i--, j++;
        else
            break;
    //bottom-left direction
    i = row+1, j=column-1;
    while(res<victory && i<rows && j>=0)
        if((*this)[i][j] == (*this)[row][column])
            res++, i++, j--;
        else
            break;
    return res == victory;
}

Board::Board(int columns, int rows, int victory) : TwoDim<short>(columns, rows), victory(victory){
   // QMessageBox::information(this, "koniec", "BOARD()");
    headPlayer = 0;
    reset();
}

bool Board::isWinningMove(int row, int column) const{
    if(isWinningRow(row, column))
        return true;
    if(isWinningColumn(row, column))
        return true;
    if(isWinningDiagonal(row, column))
        return true;

    return false;
}

//get first empty row in given column
int Board::getRowForColumn(int column){
    int i=rows-1;
    for(; i>=0; i--)
        if((*this)[i][column]==0){ //if empty
            break;
        }
    return i;
}

//return row occupied by added piece
void Board::move(int row, int column) throw(IncorrectMove){
    if(!_winner){
        (*this)[row][column] = player->color; //todo: out of range, end of game
        _winner = (isWinningMove(row, column)) ? player : 0;
    }else
        throw IncorrectMove();
}

void Board::reset(){
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            (*this)[i][j] = 0; //0 means that no piece occupy that field, 1 means that piece of player #1 occupy that field, 2...
    Player * tmp = headPlayer;
    if(tmp){
        do{
            tmp->restart();
            tmp = tmp->next;
        }while(tmp && tmp != headPlayer);
     }
}

void Board::addPlayer(Player *player){
    if(!headPlayer){
        headPlayer = player;
        headPlayer->next = player; //it's closed list
    }else{
        Player * tmp = headPlayer;
        while(tmp->next != headPlayer)
            tmp = tmp->next;
        tmp->next = player;
        player->next = headPlayer;
    }
    player->setBoard(this);
}

void Board::playerStop(){
    player->stop();
}

void Board::playerStart(){
    player->start();
}

void Board::start(){
    player = headPlayer;
    _winner = 0;
    playerStart();
}

void Board::deletePlayers(){
    Player *toDel = 0, *it=headPlayer, *head=headPlayer;
    if(it){
        while((it->next) && it->next != head){ //last player attribute next points to headPlayer. Since it might has been already deleted we need temporary pointer head
            toDel = it;
            it = toDel->next;
            delete toDel;
            toDel = 0;
        }
        delete it;
        it = 0;
    }
}

//important! it must be at least one active player
void Board::setTurnOnNextActive(){
    if(!player)
        throw IncorrectMethodUse();
    Player * next = player->getNextActive();
    if(next == player) //it means that player is the winner
        _winner = next;

    player = next;
}
