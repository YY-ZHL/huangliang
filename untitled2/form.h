#ifndef FORM_H
#define FORM_H

#include<QWidget>
#include <QTextEdit>
#include<QMouseEvent>
namespace Ui {
class Form;
}

class Form : public QTextEdit
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

     void mousePressEvent(QMouseEvent *e) ;


private:
    Ui::Form *ui;
};

#endif // FORM_H
