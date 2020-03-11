#include "mianwidget2.h"
#include <QPixmap>
#include <QDebug>

mianwidget2::mianwidget2(QWidget *parent)
   : QWidget(parent)
{
    this->resize(1080,720);
    this->setWindowTitle("Fly");
    this->setWindowIcon(QIcon("../project-final/icon.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("../project-final/mianwindow2.png").scaled(this->size())));
    this->setPalette(palette);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);

    banner = new QLabel(this);
    banner->setPixmap(QPixmap("../project-final/banner.png"));
    banner->setGeometry(770,35,250,150);
    banner->show();

    startgame.setIcon(QPixmap("../project-final/startgame.png"));
    startgame.setIconSize(QSize(200,50));
    startgame.setGeometry(750,400,200,50);
    startgame.setParent(this);
    startgame.setFlat(true);
    startgame.show();

    settings.setIcon(QPixmap("../project-final/settings.png"));
    settings.setIconSize(QSize(200,50));
    settings.setGeometry(750,500,200,50);
    settings.setParent(this);
    settings.setFlat(true);
    settings.show();

    exitgame.setIcon(QPixmap("../project-final/exitgame.png"));
    exitgame.setIconSize(QSize(200,50));
    exitgame.setGeometry(750,600,200,50);
    exitgame.setParent(this);
    exitgame.setFlat(true);
    exitgame.show();

    connect(&startgame,SIGNAL(clicked()),this,SLOT(startslot()));
    connect(&settings,SIGNAL(clicked()),this,SLOT(settingsslot()));
    connect(&exitgame,SIGNAL(clicked()),this,SLOT(exitslot()));
}

void mianwidget2::startslot()
{
    gamewindow = new firstchapter2();
    gamewindow->show();
    this->hide();
}
void mianwidget2::settingsslot()
{
    settingswindow2 *settingschuang = new settingswindow2();
    this->hide();
    settingschuang->show();
}
void mianwidget2::exitslot()
{
    exitwindow *exitchuang = new exitwindow();
    this->hide();
    exitchuang->show();
}
