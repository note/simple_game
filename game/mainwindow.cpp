#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newgame.h"
#include <QPainter>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new Map(this, 7, 7, 4);
    map->move(20, 20);
    newGamePanel = new NewGamePanel();
    createMenus();
    addEvents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//that method is essential to prevent from disappearing Map after minimising window
bool MainWindow::event(QEvent *event){
    if(event->type() == QEvent::WindowStateChange){
        if(windowState() == Qt::WindowNoState){ //if it's in normal state then redraw Map
            map->redraw();
        }
    }
    return QMainWindow::event(event);
}

void MainWindow::createMenus(){
    newMenu = new QMenu(tr("&Game"), this);
    menuBar()->addMenu(newMenu);
    newGameAction = new QAction(tr("New game"), this);
    newGameAction->setShortcut(QKeySequence::New);
    restartAction = new QAction(tr("Restart"), this);
    restartAction->setShortcut(Qt::CTRL + Qt::Key_R);
    newMenu->addAction(newGameAction);
    newMenu->addAction(restartAction);
}

void MainWindow::addEvents(){
    connect(newGameAction, SIGNAL(triggered()), this, SLOT(createGamePanel()));
    connect(restartAction, SIGNAL(triggered()), this, SLOT(restart()));
}

void MainWindow::createGamePanel(){
    newGamePanel->move(x()+30, y()+30);
    newGamePanel->show();
}

void MainWindow::drawMap(int rows, int columns, int victory){
    if(map != 0){
        delete map;
    }
    map = new Map(this, columns, rows, victory);
    map->move(20, 20);
    map->show();
}

void MainWindow::restart(){
    map->restart();
}
