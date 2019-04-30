#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <mywidget.h>
#include <QThread>
#include <QTime>
#include <QTimer>

#include <QDir>

void sleep(unsigned int msec)
{
QTime dieTime = QTime::currentTime().addMSecs(msec);
while( QTime::currentTime() < dieTime )
QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyWidget w;
    w.show();
    sleep(5000);
    w.close();
    Widget w1;
    w1.show();

    return a.exec();
}
