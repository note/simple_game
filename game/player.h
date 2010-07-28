#ifndef PLAYER_H
#define PLAYER_H
#include <QTime>
#include <QLayout>
#include <QLabel>
#include <QBasicTimer>

class Player : QObject{
    Q_OBJECT
    QTime * elapsed;
    QLayout * layout;
    int timeLeft, displayedTime, initialTime; //initialTime useful when restarting game
    QLabel * nameLabel;
    QLabel * timeLabel;
    QBasicTimer timer;
public:
    //This class is very simple and I predict that no extra actions would be performed in accessors so it's more convenient to make all those properties public
    short color;
    QString name;
    Player * next;

    Player(short color, const QString & name, int minutes, int seconds);

    //return value in range 0 to 59
    int minutes(){
        return minutes(timeLeft);
    }

    int minutes(int time){
        return time/(60*1000);
    }

    //return value in range 0 to 59
    int seconds(){
        return seconds(timeLeft);
    }

    int seconds(int time){
        return (time/1000)%60;
    }

    QString getMinutes();
    QString getMinutes(int time);

    QString getSeconds();
    QString getSeconds(int time);

    void start(){
        elapsed->start();
        timer.start(1000, this);
    }

    void stop(){
        timer.stop();
        timeLeft -= elapsed->elapsed();
        displayedTime = timeLeft;
        update();
    }

    void showPanel(QLayout * layout, QWidget * parent);

    void update();
    void update(int time);
    void restart();

    void activate(bool active){

    }
protected:
    void timerEvent(QTimerEvent * event){
        displayedTime -= 1000;
        update();
    }
};

#endif // PLAYER_H
