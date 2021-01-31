#include "qwdialog.h"
#include "ui_qwdialog.h"

QWDialog::QWDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QWDialog)
{
    ui->setupUi(this);
    connect(ui->radioButtonBe,SIGNAL(clicked()),this,SLOT(setTextFontColor()));//connect the signal with the slot.
    connect(ui->radioButtonBk,SIGNAL(clicked()),this,SLOT(setTextFontColor()));//which is not set in qwdialog.ui
    connect(ui->radioButtonRd,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

QWDialog::~QWDialog()
{
    delete ui;
}


void QWDialog::on_checkBoxU_clicked(bool checked)
{
    QFont font=ui->textEdit->font();//Font means the shape of the text
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
}

void QWDialog::on_checkBoxI_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
}

void QWDialog::on_checkBoxB_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);
}

//notice that the process of setting something includes three process:
//get the origin element, change it and give it back.

void QWDialog::setTextFontColor()
{
    QPalette plet=ui->textEdit->palette();//Palette means the color changer
        if (ui->radioButtonBe->isChecked())
            plet.setColor(QPalette::Text,Qt::blue);
        else if (ui->radioButtonRd->isChecked())
           plet.setColor(QPalette::Text,Qt::red);
        else if (ui->radioButtonBk->isChecked())
            plet.setColor(QPalette::Text,Qt::black);
        else
           plet.setColor(QPalette::Text,Qt::black);
        ui->textEdit->setPalette(plet);
}

