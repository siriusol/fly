#ifndef ENEMYFISH2_H
#define ENEMYFISH2_H
#include "enemybullet2.h"

class enemyfish2
{
public:
    enemyfish2();
    int fx;
    int fy;
    int fspeed;
    QPixmap fmap;
    enemybullet2 *eb[5];
};

#endif // ENEMYFISH2_H
