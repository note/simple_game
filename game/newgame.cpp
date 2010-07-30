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

std::vector<QString> NewGamePanel::handleForm(){
    short enabled = 0;
    std::vector<QString> errors;
    for(int i=0; i<Application::maxPlayers; i++){
        if(qobject_cast<QCheckBox *>(ui->gridLayout->itemAtPosition(i, 0)->widget())->isChecked()){
            enabled++;
            QString s;
            s.setNum(i+1);
            if(qobject_cast<QLineEdit *>(ui->gridLayout->itemAtPosition(i, 3)->widget())->text().length() == 0)
                errors.push_back("You don't provide name for player number " + s);
            if(qobject_cast<QLineEdit *>(ui->gridLayout->itemAtPosition(i, 3)->widget())->text().length() > 60)
                errors.push_back("Name provided for player number " + s + " is longer than 60 characters.");
            if(qobject_cast<QSpinBox *>(ui->gridLayout->itemAtPosition(i, 5)->widget())->value() == 0 &&
               qobject_cast<QSpinBox *>(ui->gridLayout->itemAtPosition(i, 7)->widget())->value() == 0)
                errors.push_back("You provide 0 minutes and 0 seconds for player number " + s);
        }
    }
    if(enabled<2)
        errors.push_back("You must enable at least 2 players.");
    return errors;
}

void NewGamePanel::createNewGame(){
    MainWindow * mainWindow = qobject_cast<MainWindow *>(parentWidget());
    mainWindow->createNewGame(ui->rowsInput->value(), ui->columnsInput->value(), ui->victoryInput->value());
    for(int i=0; i<Application::maxPlayers; i++){
    if(qobject_cast<QCheckBox *>(ui->gridLayout->itemAtPosition(i, 0)->widget())->isChecked())
    mainWindow->addPlayer(i+1, qobject_cast<QLineEdit *>(ui->gridLayout->itemAtPosition(i, 3)->widget())->text(),
                                         qobject_cast<QSpinBox *>(ui->gridLayout->itemAtPosition(i, 5)->widget())->value(),
                                         qobject_cast<QSpinBox *>(ui->gridLayout->itemAtPosition(i, 7)->widget())->value());
    }
    mainWindow->showPlayersPanel(ui->columnsInput->value());
    hide();
    mainWindow->start();
}

void NewGamePanel::printErrors(std::vector<QString>errors){
    QString s;
    for(std::vector<QString>::iterator b = errors.begin(), e = errors.end(); b!=e; b++)
        s += *b + "\n";
    QMessageBox::information(this, "Correct form", s);
}

//called after new game form was submitted
void NewGamePanel::on_pushButton_clicked()
{
    //TODO: validation
    std::vector<QString> errors = handleForm();
    if(errors.empty())
        createNewGame();
    else
        printErrors(errors);
}

//called when checkbox for player was clicked
void NewGamePanel::checkBoxChanged(int row){
    if(qobject_cast<QCheckBox *>(ui->gridLayout->itemAtPosition(row, 0)->widget())->isChecked())
        setEnabledRow(true, row);
    else
        setEnabledRow(false, row);
}

void NewGamePanel::setEnabledRow(bool enabled, int row){
    for(int i=2; i<8; i++)
        ui->gridLayout->itemAtPosition(row, i)->widget()->setEnabled(enabled);
}
