#ifndef MYBULLET_H
#define MYBULLET_H
#include <QPixmap>

class mybullet
{
public:
    int bulletx;
    int bullety;
    int bulletspeed;
    QPixmap bulletmap;
    mybullet(int, int);
};

#endif // MYBULLET_H
