#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "map.h"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent * event);
    bool event(QEvent *event);
    void createMenus();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Map * map;
    QMenu * newMenu;
    QAction * newGame;
};

#endif // MAINWINDOW_H
