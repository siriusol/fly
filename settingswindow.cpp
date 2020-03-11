#include "settingswindow.h"

settingswindow::settingswindow(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1080,720);
    this->setWindowTitle("设置及操作说明");
    this->setWindowIcon(QIcon("../project-final/icon.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("../project-final/settingsback.png").scaled(this->size())));
    this->setPalette(palette);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);

    settingsreturn = new QPushButton(this);
    //settingsreturn->setText("返回");
    settingsreturn->setGeometry(0,100,200,100);
    settingsreturn->setIcon(QPixmap("../project-final/return.png"));
    settingsreturn->setIconSize(QSize(200,100));
    settingsreturn->setFlat(true);
    QFont font;
    font.setPointSize(30);
    font.setBold(true);
    //settingsreturn->setFont(font);
    settingsreturn->setGeometry(0,0,200,50);
    connect(settingsreturn,SIGNAL(clicked(bool)),this,SLOT(settingsreturnslot()));
    shuoming = new QLabel(this);
    shuoming->setText("操作说明：");
    shuoming->setFont(font);
    shuoming->setGeometry(150,200,600,200);
    neirong = new QLabel(this);
    neirong->setText("WASD控制战机移动，K发射子弹");
    neirong->setFont(font);
    neirong->setGeometry(150,300,900,200);
    modehuan = new QPushButton(this);
    modehuan->setGeometry(300,500,500,100);
    modehuan->setText("切换模式(慎点!)");
    modehuan->setFont(font);
    connect(modehuan,SIGNAL(clicked(bool)),this,SLOT(modeslot()));
}

void settingswindow::settingsreturnslot()
{
    mianwidget *mianchuang = new mianwidget();
    this->close();
    mianchuang->show();
}

void settingswindow::modeslot()
{
    this->~settingswindow();
    mianwidget2 *p = new mianwidget2();
    p->show();
}
