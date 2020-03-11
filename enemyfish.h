#ifndef ENEMYFISH_H
#define ENEMYFISH_H
#include "enemybullet.h"

class enemyfish
{
public:
    enemyfish();
    int fx;
    int fy;
    int fspeed;
    QPixmap fmap;
    enemybullet *eb[5];
};

#endif // ENEMYFISH_H
