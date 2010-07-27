#ifndef NEWGAME_H
#define NEWGAME_H

#include <QMainWindow>
#include <QDialog>

namespace Ui {
    class NewGamePanel;
}

class NewGamePanel : public QDialog {
    Q_OBJECT
public:
    NewGamePanel(QWidget *parent = 0);
    ~NewGamePanel();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::NewGamePanel *ui;
    void createNewGame(int rows, int columns, int victory);

private slots:
    void on_pushButton_clicked();
};

#endif // NEWGAME_H
