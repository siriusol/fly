#ifndef BOSS2_H
#define BOSS2_H
#include "enemybullet2.h"
#include <QPixmap>

class boss2
{
public:
    boss2();
    void bossfull();//掉血，进度条
    int bfatenum;//生命值而不是生命数
    int bossx;
    int bossy;
    int bossspeed;
    QPixmap bossmap;
    bool bossxian;
    enemybullet2 *boss1bullet1[1000];
    enemybullet2 *boss1bullet2[1000];
    enemybullet2 *boss1bullet3[1000];
};

#endif // BOSS2_H
