#include "mythread.h"
#include<QByteArray>
#include<QDebug>
MyThread::MyThread(QTcpSocket *soket)
{
    this->soket=soket;

    qDebug()<<"构造函数调用";
}

void MyThread::run()
{
      //qDebug()<<"running";

      connect(soket,&QTcpSocket::readyRead,this,&MyThread::clientInfoSlot);
      qDebug()<<"run线程："<<MyThread::currentThread();
}

void MyThread::clientInfoSlot()
{
    QByteArray buff=soket->readAll();
    emit emitBuff(buff);
    qDebug()<<"clientInfoSlot线程："<<MyThread::currentThread();

}
