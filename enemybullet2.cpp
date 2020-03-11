#include "enemybullet2.h"
#include <QDebug>
enemybullet2::enemybullet2(int x, int y)
{
    this->ebulletx = x;
    this->ebullety = y;
    this->speed = 2;
    this->ebulletmap = QPixmap("../project-final/efbullet2.png");
}
