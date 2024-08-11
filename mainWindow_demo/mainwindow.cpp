#include "mainwindow.h"
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QStatusBar>
#include<QLabel>
#include<QToolBar>
#include<QDockWidget>
#include<QTextEdit>
#include<QPixmap>
#include<QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800,600);
    //设置菜单栏
    QMenuBar *menuBar=this->menuBar();
    this->setMenuBar(menuBar);

    //设置菜单
    QMenu *menu1=new QMenu("菜单1");
    QMenu *menu2=new QMenu("菜单2");
    QMenu *menu3=new QMenu("菜单3");
    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);
    menuBar->addMenu(menu3);
    //设置子菜单
    QAction *action1=new QAction("子菜单1");
    QAction *action2=new QAction("子菜单2");
    QAction *action3=new QAction("子菜单3");
    menu1->addAction(action1);
    menu1->addAction(action2);
    menu1->addAction(action3);
    connect(action3,&QAction::triggered,this,&MainWindow::close);

    //设置状态栏
    QStatusBar *statusBar=this->statusBar();
    this->setStatusBar(statusBar);
    //临时信息
    //statusBar->showMessage("临时信息",3000);
    //正式信息
    QLabel *lable1=new QLabel("正式信息",this);
    statusBar->addWidget(lable1);
    //永久信息
    QLabel *lable2=new QLabel("永久信息",this);
    statusBar->addPermanentWidget(lable2);

    //设置工具栏
    QToolBar *toolBar=new QToolBar("工具栏");
    this->addToolBar(Qt::LeftToolBarArea,toolBar);

    QAction *action4=new QAction("工具1");
    QAction *action5=new QAction("工具2");
    QAction *action6=new QAction("工具3");
    toolBar->addAction(action4);
    toolBar->addAction(action5);
    toolBar->addAction(action6);

    QLabel *lable7=new QLabel("工具4",this);
    toolBar->addWidget(lable7);
    //可以停靠区域
    toolBar->setAllowedAreas(Qt::LeftToolBarArea);
    //是否可以移动
    toolBar->setMovable(false);
    //是否可以悬浮
    toolBar->setFloatable(false);



    //创建铆接部件
    QDockWidget *dockWidget=new QDockWidget("第一个铆接部件",this);
    this->addDockWidget(Qt::TopDockWidgetArea,dockWidget);
    dockWidget->setFloating(false);

    //创建中心部件
    QTextEdit *textEdit=new QTextEdit("中心部件",this);
    this->setCentralWidget(textEdit);




    //给子菜单添加图片
//    QPixmap *pix=new QPixmap("/yuanyuan");
//    action1->setIcon(pix);

    QPixmap pix;
    pix.load(":/image/yuanyuan.jpg");
    action1->setIcon(QIcon(pix));


}

MainWindow::~MainWindow()
{
}


