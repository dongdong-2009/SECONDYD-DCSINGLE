#include "main_dialog.h"
#include <QtGui/QApplication>
#include <QtGui>
#include <QWSServer>
#include "globalhmi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_dialog w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    
    return a.exec();
}
