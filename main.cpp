#include <QtGui/QApplication>
#include "hexmanwindow.h"
#include "FileBuffer.h"
using namespace Program;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HexmanWindow w;
    w.show();
    FileBuffer fb(80);

    return a.exec();
}
