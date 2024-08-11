#ifndef USERDEFINE_H
#define USERDEFINE_H

#include <QWidget>

namespace Ui {
class UserDefine;
}

class UserDefine : public QWidget
{
    Q_OBJECT

public:
    explicit UserDefine(QWidget *parent = nullptr);
    ~UserDefine();

private:
    Ui::UserDefine *ui;
public slots:
    void reset();
};

#endif // USERDEFINE_H
