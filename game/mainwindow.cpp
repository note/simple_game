#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newgame.h"
#include <QPainter>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = 0;
    playersPanel = 0;
    newGamePanel = new NewGamePanel(this);
    createMenus();
    addEvents();
    createNewGame(7, 7, 4);
    addPlayer(1, "Peter", 3, 20);
    addPlayer(2, "Eric", 3, 0);

    showPlayersPanel(7);

    start();
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
    map = new Map(this, columns, rows, victory);;
    map->move(20, 35);
    map->show();
}

//it's first function called after emiting restart signal (eg. hitting ctrl+R)
void MainWindow::restart(){
    map->restart();
}

void MainWindow::addPlayer(short colorId, const QString &name, int minutes, int seconds){
    Player * player = new Player(colorId, name, minutes, seconds);
    map->board.addPlayer(player);
    player->showPanel(playersLayout, playersPanel);
    connect(playersPanel, SIGNAL(destroyed()), player, SLOT(disableDeletingQWidgets()));
    connect(player, SIGNAL(outOfTime()), map, SLOT(afterMove()));
}

void MainWindow::createNewGame(int rows, int columns, int victory){
    delete playersPanel;
    playersPanel = new QWidget(this);
    playersLayout = new QVBoxLayout();
    playersPanel->setLayout(playersLayout);
    drawMap(rows, columns, victory);
}

void MainWindow::start(){
    map->board.start();
}

void MainWindow::showPlayersPanel(int columns){
    playersPanel->move((Application::squareSize+2*Application::padding)*columns+100, 50);
    playersPanel->resize(playersLayout->closestAcceptableSize(playersPanel, QSize(100, 20)));
    playersPanel->show();
}
