#include "myflying.h"

myflying::myflying()
{
    this->myflyingx = 540;//应该有个固定的出生点及重生点
    this->myflyingy = 600;
    this->myspeed= 5;//自己的初始速度
    this->mymap = QPixmap("../project-final/my.png");//己机图片
    this->bulletcount = 0;
    this->lastnum = 0;
    this->screencount = 0;
}
