#include "widget.h"
#include"teacher.h"
#include"student.h"
#include<QPushButton>
#include<QDebug>
#include<QString>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button=new QPushButton(this);
    this->resize(800,500);
    button->resize(200,100);
    button->move(0,0);
    button->setText("button1");

    Teacher *tea=new Teacher(this);
    Student *stu=new Student(this);

    void (Teacher::*teasingal)(QString)=&Teacher::xiaKeH;
    void (Student::*stuSlots)(QString)=&Student::chiFanH;



    connect(tea,teasingal,stu,stuSlots);
    // connect(button,&QPushButton::clicked,tea,teasingal);


    tea->xiaKeH("1111");
    //    this->chuFa();
    //    emit tea->xiaKeH();
}

Widget::~Widget()
{

    qDebug()<<"Qwidget";
}
//void Widget::chuFa()
//{
//    emit tea->xiaKeH();
//}
