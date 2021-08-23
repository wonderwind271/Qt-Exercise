#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menu_2->addAction("撤销");//add Chinese Character here.
    connect(ui->actionopen,&QAction::triggered,this,[=](){
        QString FileName= QFileDialog::getOpenFileName(this,"打开","D:/");
        qDebug()<<FileName.toUtf8().data();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

