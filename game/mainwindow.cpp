#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new Map(this);
    map->move(30, 30);
    createMenus();
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

void MainWindow::paintEvent(QPaintEvent * event){
   // QPainter paint( this );

   // QImage *img = new QImage(":red.png");
   // paint.drawImage(0, 0, *img, 0, 0, -1, -1);
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
    newMenu = new QMenu(tr("&New"), this);
    menuBar()->addMenu(newMenu);
    newGame = new QAction(tr("Game"), this);
    newGame->setShortcut(QKeySequence::New);
    newMenu->addAction(newGame);
}
