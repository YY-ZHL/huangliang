#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->mianWidget=new Form;
    this->test=new Form3;
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        this->hide();
        mianWidget->show();
    });
    connect(this->mianWidget,&Form::back,this,[=](){
        mianWidget->hide();
        this->show();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        this->hide();
        test->show();
    });
    connect(this->test,&Form3::back,this,[=](){
        test->hide();
        this->show();
    });

}

Widget::~Widget()
{
    delete ui;
    //delete mianWidget;
}

