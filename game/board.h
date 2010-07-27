#ifndef BOARD_H
#define BOARD_H
#include "two_dim.h"

class Board : public TwoDim<short>{
    const int victory;
    short _winner;

    bool isWinningRow(int row, int column);
    bool isWinningColumn(int row, int column);
    bool isWinningDiagonal(int row, int column);

public:
    short player; //whose turn is now

    Board(int columns, int rows, int victory);

    bool isWinningMove(int row, int column);

    //return row occupied by added piece
    int move(int column) throw(IncorrectMove);

    short winner(){
        return _winner;
    }
};

#endif // BOARD_H
