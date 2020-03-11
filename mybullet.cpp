#include "mybullet.h"

mybullet::mybullet(int nx,int ny)
{
    this->bulletx = nx;
    this->bullety = ny;
    this->bulletspeed= 5;
    this->bulletmap = QPixmap("../project-final/bullet.png");//放普通子弹的图片
}
