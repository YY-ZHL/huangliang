#include "mythread.h"
#include<QElapsedTimer>
#include<QDebug>
MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    qDebug()<<"生成随机数的线程地址:"<<QThread::currentThread();
    QVector<int>list;
    QElapsedTimer timer;
    timer.start();
    for(int i=0;i<num;i++)
    {
        list.push_back(qrand()%10000);
    }
    qDebug()<<"生成随机数用时:"<<timer.nsecsElapsed()<<"微秒";
    emit emitData(list);
}

void MyThread::reciveNum(int num)
{
    this->num=num;
}

BubbleThread::BubbleThread(QObject *parent): QThread(parent)
{

}

void BubbleThread::run()
{
    //sleep(3);
    qDebug()<<"冒泡排序线程地址:"<<QThread::currentThread();
    QElapsedTimer timer;
    timer.start();
    bubbleSort(list,list.size());
    qDebug()<<"冒泡排序用时:"<<timer.elapsed()<<"毫秒";
    emitData(list);
}

void BubbleThread::reciveNum(QVector<int> list)
{
    this->list=list;
    qDebug()<<"接收到了数据:"<<"list.size():"<<this->list.size();
}

void BubbleThread::bubbleSort(QVector<int> &arr, int n)
{
    int i, j, temp;
        for (i = 0; i < n-1; i++) { // 外层循环，控制排序的轮数
            for (j = 0; j < n-i-1; j++) { // 内层循环，控制每轮比较的次数
                if (arr[j] > arr[j+1]) { // 如果当前元素大于下一个元素，则交换它们
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
}



QuickSortThread::QuickSortThread(QObject *parent): QThread(parent)
{

}

void QuickSortThread::run()
{
    qDebug()<<"快速排序线程地址:"<<QThread::currentThread();
    QElapsedTimer timer;
    timer.start();
    quickSort(list,0,list.size()-1);
    qDebug()<<"快速排序用时:"<<timer.elapsed()<<"毫秒";
    emitData(list);
}

void QuickSortThread::reciveNum(QVector<int> list)
{
    this->list=list;
}



void QuickSortThread::quickSort(QVector<int> &arr, int low, int high)
{
    if (low < high) {
        // pi 是分区后基准的索引位置
        int pi = partition(arr, low, high);

        // 分别对基准左右两边的子数组进行快速排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int QuickSortThread::partition(QVector<int> &arr, int low, int high)
{
    int pivot = arr[high];    // 选择最后一个元素作为基准
    int i = (low - 1);        // 较小元素的索引

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于pivot
        if (arr[j] <= pivot) {
            i++;    // 增加较小元素的索引



           int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            //swap(arr[i], arr[j]);
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    //swap(arr[i + 1], arr[high]);
    return (i + 1);
}
