#include "widget_purecode.h"
#include "mybutton.h"
#include <QDebug>
#include <QString>
#include <string>
Widget_purecode::Widget_purecode(QWidget *parent)
    : QWidget(parent)
{
    //initialization
    /*
     * If a widget need to belong to another widget, we should specify the parent class for this widget
     */
    b2=new QPushButton("hello, Qt!",this);
    //b2->show(); //child widget can altomatically show when parent shows.
    b1.setParent(this);
    b1.setText("close");
    //change place
    b2->move(100,400);
    //x is right, y is down
    MyButton* btn=new MyButton(this);
    btn->setText("my button");
    btn->move(200,200);
    b1.resize(120,200);
    this->setWindowTitle("my widget");
    //this->resize(1000,1000);
    this->setFixedSize(1000,1000);
    //require:click b1 and close the whole widget
    connect(&b1,&QPushButton::clicked,this,&Widget_purecode::close);
    //2,4 parameter's syntax: "&" + the name of the function, meaning the pointer to a function
    l1=new QLabel("Text",this);
    l1->move(420,450);
    connect(b2,&QPushButton::clicked,this,&Widget_purecode::SetLabel);//the slot is defined manually
}

Widget_purecode::~Widget_purecode()
{
    //delete b2;
    //not necessary! Qt can manage it, but only apply to the class that inharit QObject and have parent.
}

void Widget_purecode::SetLabel()
{
    static int times=0;
    QString temp=QString::fromStdString(std::to_string(times));
    l1->setText("reset!"+temp);
    l1->resize(100,100);
    ++times;
    //qDebug()<<times;
}

