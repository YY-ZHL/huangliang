#include "teacher.h"
#include<QDebug>
Teacher::Teacher(QObject *parent) : QObject(parent)
{

}




Teacher::~Teacher()
{
   qDebug()<<"teacher de xigouhanshu yi dioa yong";
}
