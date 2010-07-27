#ifndef APPLICATION_H
#define APPLICATION_H
#include <QApplication>

class Application : public QApplication{
public:
    Application(int argc, char *argv[]) : QApplication(argc, argv){}

    //important constants
    static const int maxPlayers = 4;
    static const int squareSize = 40; //size of square in pix
    static const int padding = 2; //paddig of square, analogical to css padding attribute
};

#endif // APPLICATION_H
