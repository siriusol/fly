#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include <QPixmap>

class enemybullet
{
public:
    enemybullet(int, int);
    int ebulletx;
    int ebullety;
    int speed;
    QPixmap ebulletmap;
};

#endif // ENEMYBULLET_H
