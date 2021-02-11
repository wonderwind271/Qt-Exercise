#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //find QAction
    ui->actionnew->setDisabled(true);
    connect(ui->actiontest,&QAction::triggered,this,[=](){
        ui->label_3->setText("open test");
        DOpen =new OpenDialog;
        DOpen->exec();
    });
    connect(ui->actionopen,&QAction::triggered,this,[=](){

        QString fileName= QFileDialog::getOpenFileName(this,"open","D:/","*.zip");
        qDebug()<<fileName;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

