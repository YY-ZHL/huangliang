#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include<QTcpSocket>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QTcpSocket *soket, QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    QTcpSocket *soket;
};

#endif // FORM_H
