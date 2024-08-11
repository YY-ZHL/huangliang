#include "widget.h"
#include "ui_widget.h"
#include<QDialog>
#include<QFileDialog>
#include<QDebug>
#include<QString>
#include<QTextEdit>
#include<QColorDialog>
#include<QFontDialog>
#include<QMessageBox>
#include<QInputDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QDialog dialog;
//    dialog.setWindowTitle("hell");
//    dialog.show();


//    QDialog *dialog=new QDialog();
//    dialog->setWindowTitle("hello huangliang");
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
//    dialog->setFixedSize(800,600);
//    dialog->show();

//    QWidget *widget1=new QWidget();
//    widget1->setWindowTitle("widget");
//    widget1->show();


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                     "D:",
                                                     tr("Images (*.png *.xpm *.jpg);; "));
    if(!fileName.isEmpty())
    {
    ui->textBrowser->append(fileName);
    }

}

void Widget::on_pushButton_2_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
                              this,
                              "打开多个文件",
                              "C:/",
                              "Images (*.png *.xpm *.jpg);;");
    for(int i=0;i<files.count();i++)
    {
        ui->textEdit->append(files.at(i));
    }
}

void Widget::on_pushButton_3_clicked()
{
    QPalette palette;

    QColor color=QColorDialog::getColor(Qt::white,this,"得到颜色");
    if(color.isValid())
    {
        palette.setColor(QPalette::Text,color);
        ui->textEdit->setPalette(palette);
    }

}

void Widget::on_pushButton_4_clicked()
{

    QFont font=ui->textEdit->font();
    bool ok;
    QFont font1 = QFontDialog::getFont(&ok, font,  this);
    if (ok) {
        ui->textEdit->setFont(font1);
    } else {
        qDebug()<<"获取失败";
    }
}

void Widget::on_pushButton_5_clicked()
{

    QMessageBox::StandardButtons button;
   button=QMessageBox::critical(this,"错误","出现了问题",QMessageBox::Yes|QMessageBox::No|QMessageBox::Close|QMessageBox::Ok);
   if(button==QMessageBox::Ok)
       qDebug()<<"OK";
}

void Widget::on_pushButton_8_clicked()
{
    QMessageBox::warning(this,"warning","警告");
}

void Widget::on_pushButton_7_clicked()
{
    QMessageBox::information(this,"information","提示信息");
}

void Widget::on_pushButton_6_clicked()
{
    QMessageBox::StandardButton button;
   button= QMessageBox::question(this,"question","喜欢我的大Qt吗？",QMessageBox::Yes|QMessageBox::No|QMessageBox::Close);
   if(button==QMessageBox::Yes)
   {
       qDebug()<<"喜欢";
   }
   else
   {
       qDebug()<<"非常喜欢";
   }
}

void Widget::on_pushButton_9_clicked()
{

    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog"),
                                         tr("输入你的名字"), QLineEdit::Normal,
                                        "黄亮", &ok);
    if (ok && !text.isEmpty())
       ui->textBrowser->append(text);

}
