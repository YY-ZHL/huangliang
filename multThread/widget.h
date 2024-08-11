#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QVector>
#include<mythread.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    MyThread *generate;
    BubbleThread *bubble;
    QuickSortThread * quickSort;

public slots:
    void start();
    void handleRand(QVector<int> list);
    void handleBubble(QVector<int> list);
    void handleQuick(QVector<int> list);
signals:
    void emitNum(int num);

private slots:

};
#endif // WIDGET_H
