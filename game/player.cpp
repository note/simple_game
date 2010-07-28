#include "player.h"

Player::Player(short color, const QString & name, int minutes, int seconds){
    this->color = color;
    this->name = name;
    timeLeft = minutes*60*1000 + seconds*1000;
    elapsed = new QTime();
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
    QString s;
    s.setNum(minutes());
    return s;
}

QString Player::getSeconds(){
    QString s;
    s.setNum(seconds());
    s = (seconds()<10) ? "0"+s : s;
    return s;
}
