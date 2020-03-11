#ifndef MYFLYING_H
#define MYFLYING_H
#include "mybullet.h"

class myflying
{
public:
    myflying();
    int myflyingx;
    int myflyingy;
    int myspeed;
    mybullet *mb[10000];
    int screencount;
    int lastnum;
    int bulletcount;//子弹数量
    QPixmap mymap;
};

#endif // MYFLYING_H
