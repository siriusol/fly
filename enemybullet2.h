#ifndef ENEMYBULLET2_H
#define ENEMYBULLET2_H
#include <QPixmap>

class enemybullet2
{
public:
    enemybullet2(int, int);
    int ebulletx;
    int ebullety;
    int speed;
    QPixmap ebulletmap;
};

#endif // ENEMYBULLET2_H
