#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDesktopWidget>

/*
  Class with useful functions.
 */
class QHelper{
public:
    void static centerAndResize(QWidget & widget, QApplication & a, const int w, const int h){
        QDesktopWidget * desktop = a.desktop();
        int width, height;
        width = desktop->width();
        height = desktop->height();
        widget.move((width-w)/2, (height-h)/2);
        widget.resize(w, h);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QHelper::centerAndResize(w, a, 600, 600);
    return a.exec();
}
