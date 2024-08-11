#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
   void  keyPressEvent(QKeyEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
    bool  event(QEvent *e);

   bool eventFilter(QObject *watched, QEvent *event);


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
