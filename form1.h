#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include <QStylePainter>
#include <QStyleOption>

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~Form1();

private:
    Ui::Form1 *ui;
};

#endif // FORM1_H
