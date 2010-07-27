#include "board.h"

bool Board::isWinningRow(int row, int column){
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

bool Board::isWinningColumn(int row, int column){
    int res=1, i=row+1; //there's no point in going up (in this case up means from greater to smaller index) because [row][column] is last added piece so no piece can be above that
    while(res<victory && i<rows)
        if((*this)[i][column] == (*this)[row][column])
            res++, i++;
        else
            break;
    return res == victory;
}

bool Board::isWinningDiagonal(int row, int column){
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
    restart();
}

bool Board::isWinningMove(int row, int column){
    if(isWinningRow(row, column))
        return true;
    if(isWinningColumn(row, column))
        return true;
    if(isWinningDiagonal(row, column))
        return true;

    return false;
}

//return row occupied by added piece
int Board::move(int column) throw(IncorrectMove){
    if(!_winner){
        int i=rows-1;
        for(; i>=0; i--)
            if((*this)[i][column]==0){
                (*this)[i][column] = player; //todo: out of range, end of game
                break;
            }

        _winner = (isWinningMove(i, column)) ? player : 0;
        player = (player==2) ? 1 : 2;
        return i;
    }else
        throw IncorrectMove();
}

void Board::restart(){
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            (*this)[i][j] = 0; //0 means that no piece occupy that field, 1 means that piece of player #1 occupy that field, 2...
    player = 1;
    _winner = 0;
}
