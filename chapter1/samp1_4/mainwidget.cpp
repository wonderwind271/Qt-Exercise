#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    void (widget2::*send1)()=&widget2::SendSignal;
    //void (widget2::*send2)(int,QString)=&widget2::SendSignal;

    connect(&w2,send1,this,&MainWidget::reshow);
    //connect(&w2,send2,this,&MainWidget::SubMsg);
    //or:
    connect(&w2,SIGNAL(SendSignal(int,QString)),this,SLOT(SubMsg(int,QString)));
    connect(ui->pushButton_2,&QPushButton::clicked,ui->label,[=](){
        if(ui->label->text()!="change via lambda")
        ui->label->setText("change via lambda");
        else
        ui->label->setText("");
    });
}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::on_pushButton_clicked()
{
    this->hide();
    w2.show();
}

void MainWidget::reshow()
{
    show();
    w2.hide();
}

void MainWidget::SubMsg(int a, QString b)
{
    qDebug() <<a<<b<<endl;
}


