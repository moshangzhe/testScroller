#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScroller>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ts = new TouchScroller(ui->widget_4);
    f1 = new Form1();
    f2 = new Form2();
    f3 = new Form1();
    Form2 *f4 = new Form2();
    ts->addWidget(f1);
    ts->addWidget(f2);
    ts->addWidget(f3);
    ts->addWidget(f4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

