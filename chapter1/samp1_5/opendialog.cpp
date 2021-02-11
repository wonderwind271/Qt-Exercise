#include "opendialog.h"
#include <QLabel>
#include <QPushButton>

OpenDialog::OpenDialog()
{
    QLabel* l1=new QLabel("这是一个模态对话框",this);
    QPushButton* bt1=new QPushButton("close",this);
    l1->resize(300,50);
    l1->move(400,200);
    bt1->move(400,400);
    this->resize(900,500);
    connect(bt1,&QPushButton::clicked,this,&OpenDialog::close);
}
