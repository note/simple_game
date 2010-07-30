#ifndef PLAYER_H
#define PLAYER_H
#include <QTime>
#include <QLayout>
#include <QLabel>
#include <QBasicTimer>

class Player : public QObject{
    Q_OBJECT
    QTime * elapsed;
    int timeLeft, displayedTime;
    const int initialTime; //initialTime useful when restarting game
    QLabel * nameLabel; //important! nameLabel and time label must not be deleted in destructor cause they're QWidgets with parent
    QLabel * timeLabel;
    QBasicTimer timer;
    bool active; //if it's true then player still plays, otherwise he's already lost

public:
    //This class is very simple and I predict that no extra actions would be performed in accessors so it's more convenient to make all those properties public
    short color;
    QString name;
    Player * next;

    Player(short color, const QString & name, int minutes, int seconds);
    ~Player();

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

    void stop();

    void showPanel(QLayout * layout, QWidget * parent);

    void update();
    void update(int time);
    void restart();

    void activate(bool active){

    }

    bool isActive(){
        return active;
    }

    Player * getNextActive();
public slots:
    //it's called by parent of nameLabel and timeLabel
    void disableDeletingQWidgets(){
        nameLabel = 0; //set to 0 to distinguish that has been deleted
        timeLabel = 0; //set to 0 to distinguish that has been deleted
    }

protected:
    void timerEvent(QTimerEvent * event){
        displayedTime -= 1000;
        update();
    }
};

#endif // PLAYER_H
