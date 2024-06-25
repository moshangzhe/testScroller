#ifndef TOUCHSCROLLER_H
#define TOUCHSCROLLER_H

#include <QWidget>
#include <QScroller>
#include <QPropertyAnimation>

namespace Ui {
class TouchScroller;
}

class TouchScroller : public QWidget
{
    Q_OBJECT

public:
    explicit TouchScroller(QWidget *parent = nullptr);
    ~TouchScroller();
    void addWidget(QWidget *widget);


private:
    Ui::TouchScroller *ui;
    uint8_t page_num=0;
    int scroller_pos =0;
    int scroller_bar_pos =0;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPropertyAnimation *animation;
    int page_width=0;


};

#endif // TOUCHSCROLLER_H
