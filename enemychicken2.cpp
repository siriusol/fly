#include "enemychicken2.h"
#include <QTime>
#include <QDebug>
#include <stdlib.h>
#include <ctime>

enemychicken2::enemychicken2()
{
    this->cx = 0;
    this->cy = -200;
    this->cspeed = 2;
    this->cmap = QPixmap("../project-final/chicken2.png");
}
enemychicken2::~enemychicken2()
{

}


