#include "form1.h"
#include "ui_form1.h"

Form1::Form1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form1)
{
    ui->setupUi(this);
}

Form1::~Form1()
{
    delete ui;
}

void Form1::paintEvent(QPaintEvent *event)
{
    QStylePainter painter(this);
    QStyleOption opt;
    opt.initFrom(this);
    opt.rect = rect();
    painter.drawPrimitive(QStyle::PE_Widget, opt);

    QWidget::paintEvent(event);
}


