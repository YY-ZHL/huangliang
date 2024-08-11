#include "form.h"
#include "ui_form.h"
#include<QByteArray>
#include<QTextEdit>
Form::Form(QTcpSocket *soket,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->soket=soket;
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}

void Form::on_pushButton_clicked()
{
    QByteArray buff;
    buff.append(ui->textEdit->toPlainText());
    soket->write(buff);
    ui->textEdit->clear();
}
