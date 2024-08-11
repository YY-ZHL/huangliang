#include "student.h"
#include<QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::chiFanH()
{
 qDebug()<<"触发了";
}
void Student:: chiFanH(QString food)
{
    qDebug()<<"吃饭"<<food;
}
