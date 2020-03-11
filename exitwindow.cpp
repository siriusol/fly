#include "exitwindow.h"

exitwindow::exitwindow(QWidget *parent)
    : QWidget(parent)
{
    this->resize(400,400);
    this->setFixedSize(400,400);
    this->setWindowTitle("退学警告！！！");
    this->setWindowIcon(QIcon("../project-final/icon.png"));
    QFont font;
    font.setPointSize(15);
    wenzi = new QLabel(this);
    wenzi2 = new QLabel(this);
    tuichu = new QPushButton(this);
    fanhui = new QPushButton(this);
    connect(tuichu,SIGNAL(clicked(bool)),this,SLOT(fanhuislot()));
    connect(fanhui,SIGNAL(clicked(bool)),this,SLOT(tuichuslot()));
    wenzi->setFont(font);
    wenzi->setText("逻辑问题：");
    wenzi2->setFont(font);
    wenzi2->setText("请不要放弃点击你不想点击的按钮：");
    tuichu->setText("退出");
    //tuichu->setFlat(true);
    fanhui->setText("刚才点错了");
    //fanhui->setFlat(true);
    wenzi->setGeometry(10,15,400,50);
    wenzi2->setGeometry(10,75,400,50);
    tuichu->setGeometry(100,200,200,50);
    fanhui->setGeometry(100,300,200,50);
}

void exitwindow::tuichuslot()
{
    this->close();
}

void exitwindow::fanhuislot()
{
    mianwidget *mianchuang = new mianwidget();
    this->close();
    mianchuang->show();
}
