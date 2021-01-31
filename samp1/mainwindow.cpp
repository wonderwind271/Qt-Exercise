#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->radioButton_1,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_1_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
}

void MainWindow::on_checkBox_2_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
}

void MainWindow::on_checkBox_3_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);
}

void MainWindow::setTextFontColor()
{
    QPalette plet=ui->textEdit->palette();
        if (ui->radioButton_1->isChecked())
            plet.setColor(QPalette::Text,Qt::black);
        else if (ui->radioButton_2->isChecked())
           plet.setColor(QPalette::Text,Qt::red);
        else if (ui->radioButton_3->isChecked())
            plet.setColor(QPalette::Text,Qt::blue);
        else
           plet.setColor(QPalette::Text,Qt::black);
        ui->textEdit->setPalette(plet);
}


