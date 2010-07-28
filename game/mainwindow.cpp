#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newgame.h"
#include <QPainter>
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new Map(this, 7, 7, 4);
    map->move(20, 20);
    newGamePanel = new NewGamePanel(this);
    createMenus();
    addEvents();
    //TODO:
    //players[0] = new Player("Bob", 3, 0);
   // players[1] = new Player("Alice", 3, 0);
   // players[2] = 0;
   // players[3] = 0;

    playersPanel = new QWidget(this);
    playersLayout = new QVBoxLayout();
    playersPanel->move(500, 200);
    playersPanel->setLayout(playersLayout);
    /*QString qs;
    players[0]->setLayout();*/
}

MainWindow::~MainWindow()
{
    //TODO:
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

   // ui->
}

void MainWindow::restart(){
    map->restart();
}

void MainWindow::addPlayer(short colorId, const QString &name, int minutes, int seconds){
    //(players[id] != 0)
       // delete players[id];
    QMessageBox::information(this, "a", "AFDG");
    Player * player = new Player(colorId, name, minutes, seconds);
    map->board.addPlayer(player);
   // QVBoxLayout * layout = new QVBoxLayout(this); //TODO: who will destroy it
  //  playersLayout->addLayout(layout);
    player->showPanel(playersLayout, playersPanel);
    playersPanel->resize(300, 300);
    playersPanel->show();
}
