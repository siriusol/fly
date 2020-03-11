#ifndef ENEMYCHICKEN_H
#define ENEMYCHICKEN_H
#include "enemybullet.h"

class enemychicken
{
public:
    enemychicken();
    int cx;
    int cy;
    int cspeed;
    QPixmap cmap;
    ~enemychicken();
    enemybullet *eb[100];
};

#endif // ENEMYCHICKEN_H
