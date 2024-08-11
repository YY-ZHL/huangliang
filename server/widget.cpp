#include "widget.h"
#include "ui_widget.h"
#include<QHostAddress>
#include<QTcpSocket>
#include<mythread.h>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server=new QTcpServer;
    server->listen(QHostAddress::AnyIPv4,8848);
    connect(server,&QTcpServer::newConnection,this,&Widget::handleConnect);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleConnect()
{
    QTcpSocket *soket=server->nextPendingConnection();
    QHostAddress address=soket->peerAddress();
    quint16  port=soket->peerPort();
    ui->lineEdit->setText(address.toString());
    ui->lineEdit_2->setText(QString::number(port));

//    connect(soket,&QTcpSocket::readyRead,this,[this](){
//        QTcpSocket *soket=( QTcpSocket *)sender();
//        QByteArray buff=soket->readAll();
//        ui->textEdit->append(QString(buff));
//    });


qDebug()<<"handleconnect线程："<<MyThread::currentThread();
    MyThread *myThread=new MyThread(soket);
    myThread->start();
    connect(myThread,&MyThread::emitBuff,this,&Widget::handleRead);

}

void Widget::handleRead(QByteArray buff)
{
    ui->textEdit->setText(QString(buff));
}

