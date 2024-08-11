#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pix(":/image1/1.png");
    ui->label->setPixmap(pix);
    ui->label_2->setPixmap(pix);
    ImageId=2;
    ImageId_2=1;



    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,ui->label_2,[=](){
        ImageId_2++;
        QString path(":/image1/");
        path+=QString::number(ImageId_2);
        path+=".png";

        ui->label_2->setPixmap(path);

        if(ImageId_2>=4)
            ImageId_2=0;
    });

}


Widget::~Widget()
{

    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
   if(event->timerId()==TimerId)
   {
       QString path(":/image1/");
       path+=QString::number(ImageId);
       path+=".png";
       ImageId++;

       QPixmap pix(path);
       ui->label->setPixmap(pix);
       if(ImageId==5)
       {
           ImageId=1;
       }
   }
}


void Widget::on_pushButton_clicked()
{
    TimerId=this->startTimer(MyTime);
}

void Widget::on_pushButton_2_clicked()
{
    this->killTimer(TimerId);
}

void Widget::on_pushButton_3_clicked()
{
    timer->start(MyTime);
}

void Widget::on_pushButton_4_clicked()
{
    timer->stop();
}

void Widget::on_pushButton_5_clicked()
{
    QTimer::singleShot(1000,this,[this](){
        ImageId_2++;
        QString path(":/image1/");
        path+=QString::number(ImageId_2);
        path+=".png";

        ui->label_2->setPixmap(path);

        if(ImageId_2>=4)
            ImageId_2=0;
    });
}
