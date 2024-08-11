#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include<QThread>
#include<QTcpSocket>
#include<QByteArray>


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QTcpSocket *soket);

     void run();


signals:
     void emitBuff(QByteArray buff);


private slots:
    void clientInfoSlot();

private:

    QTcpSocket *soket;

};

#endif // MYTHREAD_H
