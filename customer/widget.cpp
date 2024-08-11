#include "widget.h"
#include "ui_widget.h"
#include<QString>
#include<QMessageBox>
#include<QHostAddress>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    soket=new QTcpSocket();
    chat=new Form(soket);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    this->close();
}
void Widget::on_pushButton_clicked()
{
    QString ip=ui->lineEdit->text();
    QString port=ui->lineEdit_2->text();

    qDebug()<<ip;
    qDebug()<<port;

    soket->connectToHost(QHostAddress(ip),port.toShort());

    qDebug()<<"here";

    connect(soket,&QTcpSocket::connected,this,[this](){
       // QMessageBox::information(this,"信息","连接成功");
        this->hide();
        chat->show();

    });
    connect(soket,&QTcpSocket::disconnected,this,[this](){
        QMessageBox::information(this,"信息","断开连接");
    });
}
