#ifndef BOARD_H
#define BOARD_H
#include "two_dim.h"
#include "application.h"
#include "player.h"

class Board : public TwoDim<short>{
    const int victory;
    Player * _winner;
    Player * headPlayer;

    bool isWinningRow(int row, int column) const;
    bool isWinningColumn(int row, int column) const;
    bool isWinningDiagonal(int row, int column) const;

public:
    Player * player; //whose turn is now

    Board(int columns, int rows, int victory);

    bool isWinningMove(int row, int column) const;

    void move(int row, int column) throw(IncorrectMove);

    int getRowForColumn(int column);

    Player * winner() const{
        return _winner;
    }

    void addPlayer(Player * player);

    void restart();
};

#endif // BOARD_H
