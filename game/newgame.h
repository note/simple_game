#ifndef NEWGAME_H
#define NEWGAME_H

#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include <QSignalMapper>

namespace Ui {
    class NewGamePanel;
}

class NewGamePanel : public QDialog {
    Q_OBJECT
public:
    NewGamePanel(QWidget *parent = 0);
    ~NewGamePanel();

private:
    Ui::NewGamePanel *ui;
    void setEnabledRow(bool enabled, int row);
    bool handleForm();
    void createNewGame();

    QSignalMapper * signalMapper;

private slots:
    //called after new game form was submitted
    void on_pushButton_clicked();
    void checkBoxChanged(int n);
};

#endif // NEWGAME_H
