#include "boss.h"

boss::boss()
{
    this->bfatenum = 50;
    this->bossmap =  QPixmap("../project-final/boss.png");
    this->bossspeed = 3;
    this->bossx = 440;
    this->bossy = 0;
    this->bossxian = false;
}
