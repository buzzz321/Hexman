#ifndef HEXMANWINDOW_H
#define HEXMANWINDOW_H

#include <QMainWindow>

namespace Ui {
class HexmanWindow;
}

class HexmanWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit HexmanWindow(QWidget *parent = 0);
    ~HexmanWindow();
    
private:
    Ui::HexmanWindow *ui;
};

#endif // HEXMANWINDOW_H
