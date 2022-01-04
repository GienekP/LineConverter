/*--------------------------------------------------------------------*/
/* LineConverter v0.5 - (c) GienekP                                   */
/*--------------------------------------------------------------------*/
#include "mainwindow.h"
#include <QApplication>
/*--------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":qtLineConverter.png"));
    MainWindow w;
    w.show();
    return a.exec();
}
/*--------------------------------------------------------------------*/
