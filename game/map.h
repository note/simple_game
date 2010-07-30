#ifndef MAP_H
#define MAP_H
#include <QWidget>
#include "application.h"
#include "board.h"

class Map : public QWidget {
    Q_OBJECT
public:
    Board board;
    Map(QWidget * parent=0, int columns=7, int rows=7, int victory=4, int squareSize=Application::squareSize, int padding=Application::padding);
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void redraw();
    Player * whoseMove();
    void restart();

private:
    const int columns, rows, squareSize, victory, padding;
    int action; //flag, youngest bit means drawing board, next bit means draw piece
    void endOfGame();

public slots:
    void afterMove();
};

#endif // MAP_H
