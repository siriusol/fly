#ifndef MYFLYING2_H
#define MYFLYING2_H
#include "mybullet2.h"

class myflying2
{
public:
    myflying2();
    int myflyingx;
    int myflyingy;
    int myspeed;
    mybullet2 *mb[10000];
    int screencount;
    int lastnum;
    int bulletcount;//子弹数量
    QPixmap mymap;
};

#endif // MYFLYING2_H
