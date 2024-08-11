#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include<QString>
class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    void chiFanH();

    void chiFanH(QString food);

};

#endif // STUDENT_H
