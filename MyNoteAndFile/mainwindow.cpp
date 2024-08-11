#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QString>
#include<QFileDialog>
#include<QMessageBox>
#include<QKeyEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action,&QAction::triggered,this,newActionSlot);
    connect(ui->action_2,&QAction::triggered,this,openActionSlot);
    connect(ui->action_3,&QAction::triggered,this,saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_S&&event->modifiers()==Qt::ControlModifier)
        saveActionSlot();
}

void MainWindow::newActionSlot()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本.txt");
}

void MainWindow::openActionSlot()
{
    QString fileName=QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                  "./",
                                                  tr("Images (*.png *.xpm *.jpg);;*.cpp;;*"));
    if(fileName.isEmpty())
    {

        QMessageBox::warning(this,"警告","文件无效");

    }
    else
    {
         QFile file(fileName);
         file.open(QIODevice::ReadOnly);
         QByteArray buff=file.readAll();
         ui->textEdit->setText(QString(buff));
         file.close();

    }

}

void MainWindow::saveActionSlot()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("保存文件"),
                                                  "./",
                                                  tr("*.cpp"));
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","文件无效");
    }
    else
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QByteArray buff;
        buff.append(ui->textEdit->toPlainText());
        file.write(buff);
        file.close();

    }

}

