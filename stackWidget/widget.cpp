#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,ui->stackedWidget,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pushButton_2,&QPushButton::clicked,ui->stackedWidget,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_3,&QPushButton::clicked,ui->stackedWidget,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
}

Widget::~Widget()
{
    delete ui;
}

