#include "mybullet2.h"

mybullet2::mybullet2(int nx,int ny)
{
    this->bulletx = nx;
    this->bullety = ny;
    this->bulletspeed= 5;
    this->bulletmap = QPixmap("../project-final/bullet2.png");//放普通子弹的图片
}
