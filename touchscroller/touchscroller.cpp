#include "touchscroller.h"
#include "ui_touchscroller.h"
#include <QMouseEvent>
#include <QScrollBar>
#define THRESHOLD 10 // 翻页阈值百分比

TouchScroller::TouchScroller(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TouchScroller)
{
    ui->setupUi(this);
    animation = new QPropertyAnimation(ui->scrollArea->horizontalScrollBar(), "value");
    // QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);
    int width = parent->width();
    int height = parent->height();
    this->setMinimumSize(width, height);
    this->setMaximumSize(width, height);
    this->setFixedSize(width, height);
    ui->scrollArea->setMinimumSize(width, height);
    ui->scrollArea->setMaximumSize(width, height);
    ui->scrollArea->setFixedSize(width, height);
    ui->scrollAreaWidgetContents->setMinimumSize(width, height);
    ui->scrollAreaWidgetContents->setFixedSize(width, height);
    page_width = width;
}

void TouchScroller::addWidget(QWidget *widget)
{
    page_num ++;
    ui->scrollAreaWidgetContents->setMinimumWidth(page_width*page_num);
    ui->horizontalLayout->addWidget(widget);

}

TouchScroller::~TouchScroller()
{
    delete ui;
}

void TouchScroller::mousePressEvent(QMouseEvent *event)
{
    scroller_pos = event->pos().x();
    scroller_bar_pos = ui->scrollArea->horizontalScrollBar()->value();
}

void TouchScroller::mouseMoveEvent(QMouseEvent *event)
{
    ui->scrollArea->horizontalScrollBar()->setValue(scroller_bar_pos - (event->pos().x() - scroller_pos));
    animation->stop();
}

void TouchScroller::mouseReleaseEvent(QMouseEvent *event)
{
    int value = ui->scrollArea->horizontalScrollBar()->value();
    int dis = value - scroller_bar_pos;
    int width = page_width *THRESHOLD /100;
    if((dis >width) || (dis > -width && dis < 0))
    {
        animation->setDuration(300);
        animation->setStartValue(value);
        animation->setEndValue((value/page_width + 1)*page_width);
        animation->setEasingCurve(QEasingCurve::OutQuad);
        animation->start();
    }
    else if(dis < -width || (dis < width && dis > 0))
    {
        animation->setDuration(300);
        animation->setStartValue(value);
        animation->setEndValue((value/page_width)*page_width);
        animation->setEasingCurve(QEasingCurve::OutQuad);
        animation->start();
    }
}






