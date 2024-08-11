#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<QCloseEvent>
#include<QResizeEvent>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    ui->textEdit->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button =QMessageBox::question(this,"question","是否确定关闭窗口");
    if(button==QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"窗口大小发生变化"<<"--"<<event->size();

}

void Widget::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Enter)
    {
        qDebug()<<"按下enter";
    }
    else
    {
        qDebug()<<event->key();
    }

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标移动了"<<"--"<<"x:"<<event->globalX()<<"Y:"<<event->globalY();
}

bool Widget::event(QEvent *e)
{
    if(e->type()==QEvent::KeyPress)
    {
        QKeyEvent *keyEvent=static_cast<QKeyEvent *>(e);
        if(keyEvent->key()==Qt::Key_Tab)
        {
            qDebug()<<"tab被按下";
            return true;
        }


    }
    return QWidget::event(e);
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->textEdit)
    {
        if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent *keyEvent=static_cast<QKeyEvent *>(event);
                    if(keyEvent->key()==Qt::Key_F2)
                    {
                        ui->textEdit->append("F2被按下");
                        qDebug()<<"F2被按下";
                        return true;
                    }

        }
        return false;
    }
    else
    {
        return QWidget::eventFilter(watched, event);
    }
}

