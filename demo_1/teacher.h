#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include<QString>
class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);


    ~Teacher();

signals:
    void xiaKeH();
    void xiaKeH(QString food);

};

#endif // TEACHER_H
