#ifndef BOSS_H
#define BOSS_H
#include "enemybullet.h"
#include <QPixmap>

class boss
{
public:
    boss();
    void bossfull();//掉血，进度条
    int bfatenum;//生命值而不是生命数
    int bossx;
    int bossy;
    int bossspeed;
    QPixmap bossmap;
    bool bossxian;
    enemybullet *boss1bullet1[1000];
    enemybullet *boss1bullet2[1000];
    enemybullet *boss1bullet3[1000];
};

#endif // BOSS_H
