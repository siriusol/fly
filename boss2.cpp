#include "boss2.h"

boss2::boss2()
{
    this->bfatenum = 50;
    this->bossmap =  QPixmap("../project-final/boss2.png");
    this->bossspeed = 3;
    this->bossx = 440;
    this->bossy = 0;
    this->bossxian = false;
}
