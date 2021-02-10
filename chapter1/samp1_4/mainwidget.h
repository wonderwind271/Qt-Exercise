#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <widget2.h>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    //void HideMe();

private slots:
    void on_pushButton_clicked();
    void reshow();
    void SubMsg(int, QString);

private:
    Ui::MainWidget *ui;
    widget2 w2;
};
#endif // MAINWIDGET_H
