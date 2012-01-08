#include "hexmanwindow.h"
#include "ui_hexmanwindow.h"

HexmanWindow::HexmanWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HexmanWindow)
{
    ui->setupUi(this);
}

HexmanWindow::~HexmanWindow()
{
    delete ui;
}
