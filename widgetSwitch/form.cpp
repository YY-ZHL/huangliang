#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&Form::back);
}

Form::~Form()
{
    delete ui;
}
