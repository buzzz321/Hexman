#include "hexmanwindow.h"
#include "ui_hexmanwindow.h"
#include <iostream>

using namespace std; 

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

void HexmanWindow::on_loadButton_clicked()
{
  cout<<"load"<<endl;
}

void HexmanWindow::on_saveButton_clicked()
{
  cout<<"save"<<endl;
}
