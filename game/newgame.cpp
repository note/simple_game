#include "newgame.h"
#include "ui_newgame.h"
#include "map.h"
#include "mainwindow.h"
#include <QSignalMapper>

NewGamePanel::NewGamePanel(QWidget * parent) : QDialog(parent), ui(new Ui::NewGamePanel)
{
    ui->setupUi(this);
    signalMapper = new QSignalMapper(this);
    for(int i=0; i<Application::maxPlayers; i++){
        signalMapper->setMapping(ui->gridLayout->itemAtPosition(i, 0)->widget(), i);
        connect(ui->gridLayout->itemAtPosition(i, 0)->widget(), SIGNAL(stateChanged(int)), signalMapper, SLOT(map()));
    }
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(checkBoxChanged(int)));
}

NewGamePanel::~NewGamePanel()
{
    delete ui;
}

bool NewGamePanel::handleForm(){
    return true; //TODO
}

void NewGamePanel::createNewGame(){
    MainWindow * mainWindow = qobject_cast<MainWindow *>(parentWidget());
   // mainWindow->deletePlayers();
    //mainWindow->drawMap(ui->rowsInput->value(), ui->columnsInput->value(), ui->victoryInput->value());
    mainWindow->createNewGame(ui->rowsInput->value(), ui->columnsInput->value(), ui->victoryInput->value());
    for(int i=0; i<Application::maxPlayers; i++){
        if(qobject_cast<QCheckBox *>(ui->gridLayout->itemAtPosition(i, 0)->widget())->isChecked())
            mainWindow->addPlayer(i+1, qobject_cast<QLineEdit *>(ui->gridLayout->itemAtPosition(i, 2)->widget())->text(),
                                 qobject_cast<QSpinBox *>(ui->gridLayout->itemAtPosition(i, 4)->widget())->value(),
                                 qobject_cast<QSpinBox *>(ui->gridLayout->itemAtPosition(i, 6)->widget())->value());
    }
    hide();
    mainWindow->start();
}

//called after new game form was submitted
void NewGamePanel::on_pushButton_clicked()
{
    //TODO: validation
    if(handleForm())
        createNewGame();
}

//called when checkbox for player was clicked
void NewGamePanel::checkBoxChanged(int row){
    if(qobject_cast<QCheckBox *>(ui->gridLayout->itemAtPosition(row, 0)->widget())->isChecked())
        setEnabledRow(true, row);
    else
        setEnabledRow(false, row);
}

void NewGamePanel::setEnabledRow(bool enabled, int row){
    for(int i=2; i<7; i++)
        ui->gridLayout->itemAtPosition(row, i)->widget()->setEnabled(enabled);
}
