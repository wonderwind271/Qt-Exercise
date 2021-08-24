#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x=100;
    y=100;
    state=0;
    timer=new QTimer(this);
    block=new QLabel(this);
    block->setGeometry(x,y,40,40);
    //block->setText("target");
    QPalette pal(block->palette());
    pal.setColor(QPalette::Background, Qt::gray);
    block->setAutoFillBackground(true);
    block->setPalette(pal);
    block->show();
    connect(timer,&QTimer::timeout,this,[&](){
        switch(state)
        {
        case 1:
            --x;break;
        case 2:
            ++x;break;
        case 3:
            --y;break;
        case 4:
            ++y;break;

        }
        if(state==1||state==2||state==3||state==4)
        {
            //qDebug()<<"x="<<x<<", y="<<y<<endl;
            block->setGeometry(x,y,40,40);
        }

    });
    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //version 1:
    //switch (event->key())
    //{
    //    case Qt::Key_Escape:
    //        qDebug()<<"ESC"<<endl;break;
    //    case Qt::Key_0:
    //        qDebug()<<"0"<<endl;break;
    //}
    //++times;
    //qDebug()<<times<<endl;

    switch (event->key())
    {
    case Qt::Key_W:
        state=3;break;
    case Qt::Key_S:
        state=4;break;
    case Qt::Key_A:
        state=1;break;
    case Qt::Key_D:
        state=2;break;
    default:
        state=0;break;
    }


}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    //version 1:
    //qDebug()<<"released"<<endl;
    //++times;
    //qDebug()<<times<<endl;
    state=0;
}

