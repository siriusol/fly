#include "enemychicken.h"
#include <QTime>
#include <QDebug>
#include <stdlib.h>
#include <ctime>

enemychicken::enemychicken()
{
    this->cx = 0;
    this->cy = -200;
    this->cspeed = 2;
    this->cmap = QPixmap("../project-final/chicken.png");
}
enemychicken::~enemychicken()
{

}


