#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include<QThread>
#include<QVector>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);


    void run();

signals:
    void emitData(QVector<int> list);
public slots:
    void reciveNum(int num);
private:
    int num;


};

class BubbleThread : public QThread
{
    Q_OBJECT
public:
    explicit BubbleThread(QObject *parent = nullptr);


    void run();

signals:
    void emitData(QVector<int> list);
public slots:
    void reciveNum(QVector<int> list);
private:
    QVector<int> list;
    void bubbleSort(QVector<int>& arr, int n);

};

class QuickSortThread : public QThread
{
    Q_OBJECT
public:
    explicit QuickSortThread(QObject *parent = nullptr);


    void run();

signals:
    void emitData(QVector<int> list);
public slots:
    void reciveNum(QVector<int> list);
private:
    QVector<int> list;
    void quickSort(QVector<int>& arr, int low, int high);
    int partition(QVector<int>& arr, int low, int high) ;


};

#endif // MYTHREAD_H
