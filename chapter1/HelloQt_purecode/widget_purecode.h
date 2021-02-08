#ifndef WIDGET_PURECODE_H
#define WIDGET_PURECODE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class Widget_purecode : public QWidget
{
    Q_OBJECT //use signal and slot
private:
    QPushButton b1;
    QPushButton* b2;
    QLabel* l1;


public:
    Widget_purecode(QWidget *parent = nullptr);
    ~Widget_purecode();
    void SetLabel();
};
#endif // WIDGET_PURECODE_H
