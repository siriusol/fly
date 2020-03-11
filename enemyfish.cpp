#include "enemyfish.h"

enemyfish::enemyfish()
{
    this->fspeed = 2;
    this->fx = 100;
    this->fy = -330;
    this->fmap = QPixmap("../project-final/fish.png");
}

