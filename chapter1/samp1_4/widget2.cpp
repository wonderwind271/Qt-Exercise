#include "widget2.h"

widget2::widget2(QWidget *parent) : QWidget(parent)
{

    b1=new QPushButton("show mainwidget",this);
    b1->resize(200,100);
    b1->move(25,125);
    b1->setText("show mainwidget");
    //b1->show();
    resize(800,600);
    connect(b1,&QPushButton::clicked,this,&widget2::SendSignalSlot);
}

void widget2::SendSignalSlot()
{
    static int i=1;
    emit SendSignal();
    emit SendSignal(i,"times!");
    ++i;
}
