#include "player.h"
#include <QMessageBox>

Player::Player(short color, const QString & name, int minutes, int seconds) : initialTime(minutes*60*1000 + seconds*1000){
    this->color = color;
    this->name = name;
    displayedTime = initialTime;
    timeLeft = initialTime;
    elapsed = new QTime(0, 0, 0, 0);
    next = 0;
}

void Player::showPanel(QLayout * layout, QWidget * parent){
    //setting nameLabel
    //this->layout = layout;
    nameLabel = new QLabel(name, parent);
    QFont font;
    font.setBold(true);
    nameLabel->setFont(font);
    layout->addWidget(nameLabel);

    //setting timeLabel
    timeLabel = new QLabel(getMinutes() + ":" + getSeconds(), parent);
    layout->addWidget(timeLabel);
}

QString Player::getMinutes(){
    return getMinutes(timeLeft);
}

QString Player::getMinutes(int time){
    QString s;
    s.setNum(minutes(time));
    return s;
}

QString Player::getSeconds(){
    return getSeconds(timeLeft);
}

QString Player::getSeconds(int time){
    QString s;
    s.setNum(seconds(time));
    s = (seconds(time)<10) ? "0"+s : s;
    return s;
}

void Player::update(){
    update(displayedTime);
}

void Player::update(int time){
    if(time>0)
        timeLabel->setText(getMinutes(time) + ":" + getSeconds(time));
    else
        QMessageBox::information(timeLabel, "koniec", "koniec");
}

void Player::restart(){
    stop();
    timeLeft = initialTime;
    displayedTime = initialTime;
    update(initialTime);
}
