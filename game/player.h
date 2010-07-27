#ifndef PLAYER_H
#define PLAYER_H
#include <QTime>

class Player{
    QTime * elapsed;
    int timeLeft;
public:
    //This class is very simple and I predict that no extra actions would be performed in accessors so it's more convenient to make all those properties public
   // short id;
    QString name;

    Player(const QString & name, int minutes, int seconds){
        this->name = name;
        timeLeft = minutes*60*1000 + seconds*1000;
        elapsed = new QTime();
    }

    //return value in range 0 to 59
    int minutes(){
        return timeLeft/(60*1000);
    }

    //return value in range 0 to 59
    int seconds(){
        return (timeLeft/1000)%60;
    }

    void start(){
        elapsed->start();
    }

    void stop(){
        timeLeft -= elapsed->elapsed();
    }
};

#endif // PLAYER_H
