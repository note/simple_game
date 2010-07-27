#include "newgame.h"
#include "ui_newgame.h"
#include "map.h"
#include "mainwindow.h"

NewGamePanel::NewGamePanel(QWidget * parent) : QDialog(parent), ui(new Ui::NewGamePanel)
{
    ui->setupUi(this);
}

NewGamePanel::~NewGamePanel()
{
    delete ui;
}

void NewGamePanel::changeEvent(QEvent *e)
{
    //dunno if it's neccessary
   /* QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }*/
}

void NewGamePanel::createNewGame(int rows, int columns, int victory){
    qobject_cast<MainWindow *>(parentWidget())->drawMap(rows, columns, victory);
}

void NewGamePanel::on_pushButton_clicked()
{
    //TODO: validation
    createNewGame(ui->rowsInput->value(), ui->columnsInput->value(), ui->victoryInput->value());
    hide();
}
