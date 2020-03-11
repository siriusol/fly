#ifndef ENEMYCHICKEN2_H
#define ENEMYCHICKEN2_H
#include "enemybullet2.h"

class enemychicken2
{
public:
    enemychicken2();
    int cx;
    int cy;
    int cspeed;
    QPixmap cmap;
    ~enemychicken2();
    enemybullet2 *eb[100];
};

#endif // ENEMYCHICKEN2_H
