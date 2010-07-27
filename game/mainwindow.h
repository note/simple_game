#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "map.h"
#include "newgame.h"
#include <QMainWindow>
#include "player.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool event(QEvent *event);
    void createMenus();
    void addEvents();
    void drawMap(int rows, int columns, int victory);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Map * map;
    QMenu * newMenu;
    QAction *newGameAction, *restartAction;
    NewGamePanel * newGamePanel;
    Player * players[Application::maxPlayers];

private slots:
    void createGamePanel();
    void restart();
};

#endif // MAINWINDOW_H
