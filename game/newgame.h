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
    std::vector<QString> handleForm();
    void createNewGame();
    void printErrors(std::vector<QString> errors);

    QSignalMapper * signalMapper;

private slots:
    //called after new game form was submitted
    void on_pushButton_clicked();
    void checkBoxChanged(int n);
};

#endif // NEWGAME_H
