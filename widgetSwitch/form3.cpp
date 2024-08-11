#include "form3.h"
#include "ui_form3.h"

Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&Form3::back);
}

Form3::~Form3()
{
    delete ui;
}
