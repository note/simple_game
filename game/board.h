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
    ~Board(){
        deletePlayers();
    }

    bool isWinningMove(int row, int column) const;

    void move(int row, int column) throw(IncorrectMove);

    int getRowForColumn(int column);

    //returns pointer to Player that won or null pointer if there's no winner
    Player * winner();

    //stops timer for player on turn
    void playerStop();

    //starts timer for player on turn
    void playerStart();

    //starts game
    void start();

    void addPlayer(Player * player);

    //reset game and players
    void reset();

    void deletePlayers();

    //set turn on next active player (active player is player who does not lost
    void setTurnOnNextActive();

    //if board is full (no move possible) return true
    bool isFull() const;
};

#endif // BOARD_H
