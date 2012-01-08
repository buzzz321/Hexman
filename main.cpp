#include <QtGui/QApplication>
#include "hexmanwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HexmanWindow w;
    w.show();

    return a.exec();
}
