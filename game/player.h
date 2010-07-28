#ifndef PLAYER_H
#define PLAYER_H
#include <QTime>
#include <QLayout>
#include <QLabel>

class Player{
    QTime * elapsed;
    QLayout * layout;
    int timeLeft;
    QLabel * nameLabel;
    QLabel * timeLabel;
public:
    //This class is very simple and I predict that no extra actions would be performed in accessors so it's more convenient to make all those properties public
    short color;
    QString name;
    Player * next;

    Player(short color, const QString & name, int minutes, int seconds);

    //return value in range 0 to 59
    int minutes(){
        return timeLeft/(60*1000);
    }

    //return value in range 0 to 59
    int seconds(){
        return (timeLeft/1000)%60;
    }

    QString getMinutes();

    QString getSeconds();

    void start(){
        elapsed->start();
    }

    void stop(){
        timeLeft -= elapsed->elapsed();
    }

    void showPanel(QLayout * layout, QWidget * parent);

    void update(){

    }

    void activate(bool active){

    }
};

#endif // PLAYER_H
