#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "touchscroller.h"
#include "form1.h"
#include "form2.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    TouchScroller *ts;
    Form1 *f1;
    Form2 *f2;
    Form1 *f3;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
