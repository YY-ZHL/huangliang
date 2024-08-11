#include "form.h"
#include "ui_form.h"
#include<QDebug>

Form::Form(QWidget *parent) :
    QTextEdit(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<"text-anxia";
    this->append("anxai");
}
