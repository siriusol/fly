#include "enemybullet.h"
#include <QDebug>
enemybullet::enemybullet(int x, int y)
{
    this->ebulletx = x;
    this->ebullety = y;
    this->speed = 2;
    this->ebulletmap = QPixmap("../project-final/efbullet.png");
    //qDebug() << this->ebulletx;
}

