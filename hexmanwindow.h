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
    
private slots:
    void on_loadButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::HexmanWindow *ui;
};

#endif // HEXMANWINDOW_H
