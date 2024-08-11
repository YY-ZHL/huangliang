#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
#define MyTime 1000


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    virtual void timerEvent(QTimerEvent *event);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Widget *ui;
    int TimerId;
    int ImageId;

    QTimer *timer;
    int ImageId_2;
};
#endif // WIDGET_H
