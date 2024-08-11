#include "userdefine.h"
#include "ui_userdefine.h"

UserDefine::UserDefine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserDefine)
{
    ui->setupUi(this);
    void (QSpinBox::*singal) (int)=QSpinBox::valueChanged;
    connect(ui->spinBox,singal,ui->horizontalSlider,&QSlider::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

UserDefine::~UserDefine()
{
    delete ui;
}
void UserDefine::reset()
{
    ui->spinBox->setValue(50);
    ui->horizontalSlider->setValue(50);
}
