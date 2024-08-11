#include "widget.h"
#include "ui_widget.h"
#include<QVector>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"主线程的线程地址："<<QThread::currentThread();
    generate=new MyThread;
    bubble=new BubbleThread;
    quickSort=new QuickSortThread;


    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::start);

    connect(generate,&MyThread::emitData,this,&Widget::handleRand);
    connect(this,&Widget::emitNum,generate,&MyThread::reciveNum);


    connect(generate,&MyThread::emitData,bubble,&BubbleThread::reciveNum);
    connect(bubble,&BubbleThread::emitData,this,&Widget::handleBubble);

    connect(generate,&MyThread::emitData,quickSort,&QuickSortThread::reciveNum);
    connect(quickSort,&QuickSortThread::emitData,this,&Widget::handleQuick);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::start()
{
    emitNum(10000);
    generate->start();

}

void Widget::handleRand(QVector<int> list)
{

    for(int i=0;i<list.size();i++)
    {
        ui->shuijishu->addItem(QString::number(list.at(i)));
    }
     bubble->start();
     quickSort->start();

}

void Widget::handleBubble(QVector<int> list)
{

    for(int i=0;i<list.size();i++)
    {
        ui->maopao->addItem(QString::number(list.at(i)));
    }
}

void Widget::handleQuick(QVector<int> list)
{
    for(int i=0;i<list.size();i++)
    {
        ui->kaishu->addItem(QString::number(list.at(i)));
    }
}


