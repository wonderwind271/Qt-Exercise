#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowTitle("type game");
    score=0;
    ui->setupUi(this);
    ui->label_score_num->setNum(score);
    connect(ui->pushButtonStart,&QPushButton::pressed,ui->label_score_num,[&](){
        score++;
        ui->label_score_num->setNum((score));

    });
    test_label=new QLabel(this);
    //test_label->setMargin(1);
    test_label->setGeometry(200,200,70,30);
    test_label->setText("A");
    //test_label->setAlignment();
    QPalette pal(test_label->palette());
    pal.setColor(QPalette::Background, Qt::gray);
    test_label->setAutoFillBackground(true);
    test_label->setPalette(pal);
    test_label->show();
    //animation test
    test_animation = new QPropertyAnimation(test_label,"geometry");
    /*
      QPropertyAnimation *animation = new QPropertyAnimation(myWidget, "geometry");
      animation->setDuration(10000);
      animation->setStartValue(QRect(0, 0, 100, 30));
      animation->setEndValue(QRect(250, 250, 100, 30));
      animation->start();
     */
    test_animation->setDuration(10000);
    test_animation->setKeyValueAt(0, QRect(70, 0, 100, 30));
    test_animation->setKeyValueAt(0.8, QRect(250, 250, 100, 30));
    test_animation->setKeyValueAt(1, QRect(0, 0, 100, 30));
    test_animation->start();

    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,ui->label_score_num,[&](){
        score++;
        ui->label_score_num->setNum((score));

    });
    timer->start(500);


    //qDebug()<<"I'm here!"<<endl;



}

MainWindow::~MainWindow()
{
    delete ui;
}

