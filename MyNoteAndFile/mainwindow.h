#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void keyPressEvent(QKeyEvent *event);

public slots:
    void newActionSlot();
    void openActionSlot();
    void saveActionSlot();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
