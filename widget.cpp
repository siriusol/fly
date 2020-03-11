#include "Widget.h"
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include "mianwidget.h"
#include <QPalette>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
    this->resize(1080,720);
    this->setWindowTitle("第四关");
    this->setWindowIcon(QIcon("../project-final/icon.png"));
    setStyleSheet("color:blue;");
    //setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);

    player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("../project-final/4.mp3"));
    player->setVolume(20);
    player->play();
    fourmap = new QPixmap("../project-final/fourmap.png");
    warning = new QPixmap("../project-final/warning.png");
    gameovermap = new QPixmap("../project-final/window.png");
    gameclearmap = new QPixmap("../project-final/window.png");

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("../project-final/fourback.png").scaled(this->size())));
    this->setPalette(palette);
    killfen = 0;
    lifenum = 5;
    for(int i = 0; i < 10000; i++)//10000个菜鸡
    {
        chicken[i] = new enemychicken();
    }
    for(int i = 0; i < 200; i++)//200个杂鱼及每个5个子弹
    {
         fish[i] = new enemyfish();
    }
    for (int i = 0; i < 100; i++)//10000个菜鸡布局
    {
        if (i == 0)
        {
            //默认this->cx = 0;
            //默认this->cy = 0;
        }
        else
        {
            if (i < 10)
            {
                chicken[i]->cx = chicken[i - 1]->cx + 100;
            }
            else if (i % 4 == 0)
            {
                chicken[i]->cx = chicken[4]->cx;
            }
            else if (i % 5 == 0)
            {
                chicken[i]->cx = chicken[5]->cx;
            }
            else if (i % 6 == 0)
            {
                chicken[i]->cx = chicken[6]->cx;
            }
            else if (i % 7 == 0)
            {
                chicken[i]->cx = chicken[7]->cx;
            }
            else if (i % 8 == 0)
            {
                chicken[i]->cx = chicken[8]->cx;
            }
            else if (i % 9 == 0)
            {
                chicken[i]->cx = chicken[9]->cx;
            }
            else
            {
                chicken[i]->cx = chicken[i % 9]->cx;
                if (chicken[i]->cx == chicken[i - 1]->cx + 100 &&
                    chicken[i - 1]->cx == chicken[i - 2]->cx + 100)
                    chicken[i]->cx = chicken[i % 5 + 1]->cx;
            }
        }
        chicken[i]->cy = chicken[i - 1]->cy - 100;
    }
    for(int i = 0; i < 200; i++)//200个杂鱼布局
    {
        //默认this->fx = 100;
        //默认this->fy = 0;

        //y布局
        if (i != 0)
        {
            fish[i]->fy = fish[i - 1]->fy - 100;
        }
        //x布局
        if (i % 5 == 0 && i != 0)
        {
            fish[i]->fx = fish[i - 1]->fx;
        }
        else if (i != 0)
        {
            fish[i]->fx = fish[i - 1]->fx + 100 + (i % 7) * 100;
            if (fish[i]->fx > 720)
                fish[i]->fx  = fish[i % 7]->fx;
        }
    }
    for (int i = 0 ; i < 200; i++)//fishpd及fishpd2初始化为0
    {
        fishpd[i] = 0;
        fishpd2[i] = 0;
    }
    for(int i = 0; i < 200; i++)//200个杂鱼及每个5个子弹布局
    {
         for (int j = 0; j < 5; j++)
         {
             fish[i]->eb[j] = new enemybullet(fish[i]->fx + 20,fish[i]->fy + 80 + j * 80);
         }
    }

    boss1 = new boss();
    boss1->bossmap =  QPixmap("../project-final/boss2.png");
    for (int i = 0; i < 1000; i++)//boss1的1000个子弹初始布局
    {
        boss1->boss1bullet1[i] = new enemybullet(boss1->bossx,boss1->bossy);
        boss1->boss1bullet2[i] = new enemybullet(boss1->bossx,boss1->bossy);
        boss1->boss1bullet3[i] = new enemybullet(boss1->bossx,boss1->bossy);
        boss1->boss1bullet1[i]->ebulletmap.load("../project-final/bossbullet4.png");
        boss1->boss1bullet2[i]->ebulletmap.load("../project-final/bossbullet5.png");
        boss1->boss1bullet3[i]->ebulletmap.load("../project-final/bossbullet6.png");
        if (i % 19 < 10)
           boss1->boss1bullet3[i]->ebulletx = (i % 9) * 145;
        else
           boss1->boss1bullet3[i]->ebulletx = 720 - (i % 9) * 145;
    }

    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::blue);

    fenzi = new QLabel(this);
    QFont font1;
    font1.setPointSize(15);
    fenzi->setFont(font1);
    fenzi->setText("积分：");
    fenzi->setGeometry(QRect(0, 0, 300, 30));
    fenzi->setPalette(pa);
    fenzi->show();

    fen = new QLabel(this);
    QFont font2;
    font2.setPointSize(25);
    fen->setFont(font2);
    fen->setText("0");
    fen->setGeometry(QRect(0, 30, 300, 50));
    fen->setPalette(pa);
    fen->show();

    lifelabel = new QLabel(this);
    lifelabel->setFont(font1);
    lifelabel->setText("生命：");
    lifelabel->setGeometry(QRect(0, 80, 300, 30));
    lifelabel->setPalette(pa);
    lifelabel->show();

    lifenumlabel = new QLabel(this);
    lifenumlabel->setFont(font2);
    lifenumlabel->setText("5");
    lifenumlabel->setGeometry(QRect(0, 110, 300, 50));
    lifenumlabel->setPalette(pa);
    lifenumlabel->show();

    returnbutton = new QPushButton(this);
    returnbutton->setGeometry(0,200,70,40);
    returnbutton->setIcon(QPixmap("../project-final/return.png"));
    returnbutton->setIconSize(QSize(70,40));
    returnbutton->setFlat(true);
    returnbutton->show();

    pausebutton = new QPushButton(this);
    pausebutton->setGeometry(0,250,70,40);
    pausebutton->setIcon(QPixmap("../project-final/pause.png"));
    pausebutton->setIconSize(QSize(70,40));
    pausebutton->setFlat(true);
    pausebutton->show();

    continuebutton = new QPushButton(this);
    continuebutton->setGeometry(0,300,70,40);
    continuebutton->setIcon(QPixmap("../project-final/continue.png"));
    continuebutton->setIconSize(QSize(70,40));
    continuebutton->setFlat(true);
    continuebutton->show();

    connect(returnbutton,SIGNAL(clicked(bool)),this,SLOT(returnslot()));
    connect(pausebutton,SIGNAL(clicked(bool)),this,SLOT(pauseslot()));
    connect(continuebutton,SIGNAL(clicked(bool)),this,SLOT(continueslot()));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::timerUpdate);
    timer->start(10);

}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *)
{
    fen->setText(QString::number(killfen));
    lifenumlabel->setText(QString::number(lifenum));

    painter = new QPainter(this);
    painter->drawPixmap(0,300,1080,226,*fourmap);
    if (lifenum == 5)
    {
        painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,my.mymap);
    }
    else if (lifenum == 4)
    {
        painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane1"));
    }
    else if (lifenum == 3)
    {
        painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane2"));
    }
    else if (lifenum == 2)
    {
        painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane3"));
    }
    else if (lifenum == 1)
    {
        painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane4"));
    }
    else
    {
        painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane5"));
        painter->drawPixmap(0,300,1080,157,*gameovermap);
    }


    if (killfen >= 7500 && !boss1pd)
        painter->drawPixmap(0,300,1080,226,*warning);
    if (killfen >= 8000)//boss出现的判断
    {
        painter->end();
        boss1pd = true;
        for (int i = 0; i < chickenlabelnum; i++)
        {
            //chickenbao[i]->setPixmap(QPixmap("../project-final/window.png"));
            delete chickenbao[i];
            chickenbao[i] = NULL;
        }
        //delete chickenbao;
    }
    if (boss1->bfatenum < 40)
    {
        painter2->end();
        gameclear();
        return;
    }
    if (killfen <= 1400 && boss1pd)
        warning->load("../project-final/window.png");

    if (!boss1pd)
    {
        for (int i = 0; i < 100; i++)
        {
            boss1->boss1bullet1[i]->ebullety = 0;
            boss1->boss1bullet2[i]->ebullety = 0;
            boss1->boss1bullet3[i]->ebullety = 0;
        }
    }

    if (boss1pd)
    {
        painter2 = new QPainter(this);
        painter2->drawPixmap(boss1->bossx,boss1->bossy,300,300,boss1->bossmap);
        painter2->drawPixmap(0,300,1800,157,*gameclearmap);

        for (int i = 0;i < my.bulletcount;i++)//绘制自己的子弹
        {
            if (my.mb[i] != NULL)
                painter2->drawPixmap(my.mb[i]->bulletx + 25,my.mb[i]->bullety,27,70,my.mb[i]->bulletmap);
        }

        for (int i = 0; i < 300; i++)//绘制boss的子弹类型1
        {
            if (boss1->boss1bullet1[i] == NULL || boss1->boss1bullet1[i - 1] == NULL)
                continue;
            boss1->boss1bullet1[i]->ebulletx = boss1->bossx - (i % 20) * 50;
            if (i != 0)
            {
                boss1->boss1bullet1[i]->ebullety = boss1->boss1bullet1[i - 1]->ebullety  - 50;
            }
            if (boss1->boss1bullet1[i] != NULL)
            {
                painter2->drawPixmap(boss1->boss1bullet1[i]->ebulletx,
                                     boss1->boss1bullet1[i]->ebullety,
                                     40,80,boss1->boss1bullet1[i]->ebulletmap);
            }
        }


        for (int i = 0; i < 300; i++)//绘制boss的子弹类型2
        {
            if (boss1->boss1bullet2[i] == NULL || boss1->boss1bullet2[i - 1] == NULL)
                continue;
            boss1->boss1bullet2[i]->ebulletx = boss1->bossx + (i % 20) * 50;
            if (i != 0)
            {
                boss1->boss1bullet2[i]->ebullety = boss1->boss1bullet2[i - 1]->ebullety - 50;
            }
            if (boss1->boss1bullet2[i] != NULL)
            {
                painter2->drawPixmap(boss1->boss1bullet2[i]->ebulletx,
                                     boss1->boss1bullet2[i]->ebullety,
                                     40,80,boss1->boss1bullet2[i]->ebulletmap);
            }

        }
        for (int i = 0; i < 300; i++)//绘制boss的子弹类型3
        {
            if (boss1->boss1bullet3[i] == NULL || boss1->boss1bullet3[i - 1] == NULL)
                continue;
            if (i != 0)
            {
                boss1->boss1bullet3[i]->ebullety = boss1->boss1bullet3[i - 1]->ebullety - 75;
            }
            painter2->drawPixmap(boss1->boss1bullet3[i]->ebulletx,
                                 boss1->boss1bullet3[i]->ebullety,
                                 60,60,boss1->boss1bullet3[i]->ebulletmap);
        }

    }

    for(int i = 0; i < 100; i++)//绘制100个菜鸡
    {
        if (chicken[i] != NULL)
            painter->drawPixmap(chicken[i]->cx,chicken[i]->cy,80,80,chicken[i]->cmap);
    }

    for(int i = 0;i < my.bulletcount;i++)//绘制自己的子弹
    {
        if (my.mb[i] != NULL)
            painter->drawPixmap(my.mb[i]->bulletx + 25,my.mb[i]->bullety,27,70,my.mb[i]->bulletmap);
    }

    for(int i = 0; i < 200; i++)//绘制200个杂鱼
    {
        if (fish[i] != NULL)
        {
            painter->drawPixmap(fish[i]->fx,fish[i]->fy,80,80,fish[i]->fmap);
            for (int j = 0; j < 3; j++)
            {
                if (fish[i]->eb[j] != NULL)
                {
                    painter->drawPixmap(fish[i]->eb[j]->ebulletx,
                        fish[i]->eb[j]->ebullety,40,80,fish[i]->eb[j]->ebulletmap);
                }
            }
        }
    }   

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int key1 = event->key();
    switch(key1)
    {
        case Qt::Key_W:pressW = true;break;
        case Qt::Key_A:pressA = true;break;
        case Qt::Key_S:pressS = true;break;
        case Qt::Key_D:pressD = true;break;
        //case Qt::Key_K:pressK = true;break;
        default:
            break;
    }
    if (event->key() == Qt::Key_K)
        shoot();
}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    int key2 = event->key();
    switch(key2)
    {
        case Qt::Key_W:pressW = false;break;
        case Qt::Key_A:pressA = false;break;
        case Qt::Key_S:pressS = false;break;
        case Qt::Key_D:pressD = false;break;
        case Qt::Key_K:pressK = false;break;
        default:
            break;
    }
}

void Widget::mymove()
{
    if (pressW)
    {
        if(my.myflyingy < 0)
            return;
        my.myflyingy -= 5;
    }
    if (pressS)
    {
        if (my.myflyingy > 640)
            return;
        my.myflyingy += 5;
    }
    if (pressA)
    {
        if(my.myflyingx < 0)
            return;
        my.myflyingx -= 5;
    }
    if (pressD)
    {
        if (my.myflyingx > 1000)
            return;
        my.myflyingx += 5;
    }
}

void Widget::shoot()
{
    my.mb[my.bulletcount] = new mybullet(my.myflyingx,my.myflyingy);
    my.bulletcount++;
}

void Widget::timerUpdate()
{
    gameover();
    mymove();
    bulletexist();     //自己的子弹死不死
    myexist();         //自己死不死
    myexistboss();     //自己死不死
    ecexist();         //菜鸡死不死
    efexist();         //杂鱼死不死
    efbulletexist();   //杂鱼的子弹死不死
    boss1bulletexist();//boss的子弹死不死
    bossexist();
    fourmapexist();
    qDebug() << boss1->bfatenum;
    if (boss1->bfatenum < 0)
    {
        gameclear();
    }
    for(int i = 0; i < my.bulletcount;i++)
    {
        if (my.mb[i] != NULL)
        {
            my.mb[i]->bullety -= my.mb[i]->bulletspeed;
        }
    }

    for(int i = 0; i < 200;i++)
    {
        if (fish[i] == NULL)
            continue;

        if (fish[i]->fy > -50 && fish[i]->fy < 750)
        {
            for (int j = 0; j < 3; j++)
            {
                if (fish[i]->eb[j] != NULL)
                {
                    fish[i]->eb[j]->speed = 3;
                    fish[i]->eb[j]->ebullety += fish[i]->eb[j]->speed;
                }
            }
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                if (fish[i]->eb[j] != NULL)
                {
                    fish[i]->eb[j]->ebullety += fish[i]->eb[j]->speed;
                }
            }
        }

    }
    for(int i = 0; i < 100;i++)
    {
        if(chicken[i] != NULL)
            chicken[i]->cy += chicken[i]->cspeed;
    }
    for(int i = 0; i < 200;i++)
    {
        if (fish[i] != NULL)
            fish[i]->fy += fish[i]->fspeed;
    }


    if (boss1->bossx > 880 || boss1->bossx < 0)
    {
        boss1->bossspeed = -boss1->bossspeed;
    }
    boss1->bossx += boss1->bossspeed;

    for (int i = 0; i < 1000; i++)
    {
        if (boss1->boss1bullet1[i] == NULL)
            continue;
/*
        if (boss1->boss1bullet1[i]->ebulletx < 0 ||
             boss1->boss1bullet1[i]->ebulletx > 1100)
        {
            boss1->boss1bullet1[i]->speed = -boss1->boss1bullet1[i]->speed;
        }
*/
        boss1->boss1bullet1[i]->ebullety += boss1->boss1bullet1[i]->speed;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (boss1->boss1bullet2[i] == NULL)
            continue;
        boss1->boss1bullet2[i]->ebullety += boss1->boss1bullet2[i]->speed;
    }
    for (int i = 0; i < 100; i++)
    {
        if (boss1->boss1bullet3[i] == NULL)
            continue;
        boss1->boss1bullet3[i]->ebullety += boss1->boss1bullet3[i]->speed;
    }

    this->update();
}

void Widget::bulletexist() //自己的子弹死不死
{
    for(int i = 0;i < my.bulletcount;i++)
    {
        if((my.mb[i] != NULL) && (my.mb[i]->bullety < 0))
        {
            delete my.mb[i];
            my.mb[i] = NULL;
        }
    }
}

void Widget::ecexist() //菜鸡死不死
{
    if (boss1pd)
        return;
    for(int i = 0;i < my.bulletcount;i++)
    {
        for (int j = 0;j < 100; j++)
        {
            if (chicken[j] == NULL || my.mb[i] == NULL)
                continue;
            if ((my.mb[i]->bulletx - chicken[j]->cx - 40) * (my.mb[i]->bulletx - chicken[j]->cx - 40) +
               (my.mb[i]->bullety - chicken[j]->cy - 40) * (my.mb[i]->bullety - chicken[j]->cy - 40) < 3000)
            {
                if (chicken[j] != NULL)
                {
                    chicken[j]->cmap = QPixmap("../project-final/window.png");
                    killfen += 100;
                    //qDebug() << killfen;
                    if (!chickenpd[j])
                    {
                        explode(chicken[j]->cx,chicken[j]->cy);
                        delete my.mb[i];
                        my.mb[i] = NULL;
                    }
                    delete chicken[j];
                    chicken[j] = NULL;
                    chickenpd[j] = true;
                }
            }
        }
    }
}

void Widget::myexist()//自己死不死
{

            for (int j = 0; j < 200; j++)
            {
                if (boss1pd)
                    return;
                if (chicken[j] == NULL)
                    continue;
                if ((my.myflyingx - chicken[j]->cx - 40) * (my.myflyingx - chicken[j]->cx - 40) +
                   (my.myflyingy - chicken[j]->cy - 40) * (my.myflyingy - chicken[j]->cy - 40) < 2000)
                {
                    if (!chickenpd[j])
                    {
                        //my.mymap = QPixmap("../project-final/ecexist.png");
                        lifenum--;
                        chickenpd[j] = true;
                        delete chicken[j];
                        chicken[j] = NULL;
                    }
                }
            }
            for (int j = 0; j < 200; j++)
            {
                if (boss1pd)
                    return;
                if (fish[j] == NULL)
                    continue;

                if ((my.myflyingx - fish[j]->fx - 40) * (my.myflyingx - fish[j]->fx - 40) +
                   (my.myflyingy - fish[j]->fy - 40) * (my.myflyingy - fish[j]->fy - 40) < 2000)
                {
                    if (fishpd[j] != 2)
                    {
                        //my.mymap = QPixmap("../project-final/ecexist.png");
                        lifenum--;
                        delete fish[j];
                        fish[j] = NULL;
                    }

                }

                for (int k = 0; k < 3; k++)
                {
                    if (fish[j] == NULL || fish[j]->eb[k] == NULL)
                        continue;
                    if ((my.myflyingx - fish[j]->eb[k]->ebulletx) * (my.myflyingx - fish[j]->eb[k]->ebulletx) +
                       (my.myflyingx - fish[j]->eb[k]->ebullety) * (my.myflyingx - fish[j]->eb[k]->ebullety) < 2000)
                    {
                        //my.mymap = QPixmap("../project-final/ecexist.png");
                        lifenum--;
                        delete fish[j]->eb[k];
                        fish[j]->eb[k] = NULL;
                    }
                }
            }
}

void Widget::myexistboss()//自己死不死boss
{
    if (!boss1pd)
        return;
    for (int j = 0; j < 100; j++)
    {
        if (!boss1pd)
            return;
        if (boss1->boss1bullet1[j] == NULL)
            continue;
        if ((my.myflyingx - boss1->boss1bullet1[j]->ebulletx - 20) * (my.myflyingx - boss1->boss1bullet1[j]->ebulletx - 20) +
           (my.myflyingy - boss1->boss1bullet1[j]->ebullety - 20) * (my.myflyingy - boss1->boss1bullet1[j]->ebullety - 20) < 2000)
        {
            lifenum--;
            delete boss1->boss1bullet1[j];
            boss1->boss1bullet1[j] = NULL;
        }
    }
    for (int j = 0; j < 100; j++)
    {
        if (!boss1pd)
            return;
        if (boss1->boss1bullet2[j] == NULL)
            continue;
        if ((my.myflyingx - boss1->boss1bullet2[j]->ebulletx - 20) * (my.myflyingx - boss1->boss1bullet2[j]->ebulletx - 20) +
           (my.myflyingy - boss1->boss1bullet2[j]->ebullety - 20) * (my.myflyingy - boss1->boss1bullet2[j]->ebullety - 20) < 2000)
        {
            lifenum--;
            delete boss1->boss1bullet2[j];
            boss1->boss1bullet2[j] = NULL;
        }
    }
    for (int j = 0; j < 100; j++)
    {
        if (!boss1pd)
            return;
        if (boss1->boss1bullet3[j] == NULL)
            continue;
        if ((my.myflyingx - boss1->boss1bullet3[j]->ebulletx) * (my.myflyingx - boss1->boss1bullet3[j]->ebulletx) +
           (my.myflyingy - boss1->boss1bullet3[j]->ebullety) * (my.myflyingy - boss1->boss1bullet3[j]->ebullety) < 1000)
        {
            lifenum--;
            delete boss1->boss1bullet3[j];
            boss1->boss1bullet3[j] = NULL;
        }
    }
}

void Widget::efexist() //杂鱼死不死
{
    if (boss1pd)
        return;
    for (int i = 0; i < 200; i++)
    {
        if (fish[i] != NULL && fish[i]->fy > 1000 && i > 11)
        {
            delete fish[i];
            fish[i] = NULL;
        }
        if (fish[i] != NULL)
        {
            for (int j = 0; j < my.bulletcount; j++)
            {
                if (my.mb[j] == NULL || fish[i] == NULL)
                    continue;
                if ((my.mb[j]->bulletx - fish[i]->fx) * (my.mb[j]->bulletx - fish[i]->fx) +
                   (my.mb[j]->bullety - fish[i]->fy) * (my.mb[j]->bullety - fish[i]->fy) < 2000)
                {

                    //fish[i]->fmap = QPixmap("../project-final/efhalf.png");
                    //写了也没用
                    /*
                    delete fish[i];
                    fish[i] = NULL;
                    killfen += 200;
                    delete my.mb[j];
                    my.mb[j] = NULL;
                    */
                    delete my.mb[j];
                    my.mb[j] = NULL;
                    if (fishpd[i] == 2)
                    {
                        fish[i]->fmap = QPixmap("../project-final/window.png");
                        fishpd[i]++;
                        delete fish[i];
                        fish[i] = NULL;
                        killfen += 200;
                    }
                    if (fishpd[i] == 0)
                    {
                        fish[i]->fmap = QPixmap("../project-final/efhalf.png");
                        fishpd[i]++;
                        killfen += 100;
                    }

                }
                if (fishpd[i] == 1)
                {
                    fishpd2[i]++;
                    if (fishpd2[i] % 100 == 0)
                    {
                        if (fishpd[i] == 1)
                            fishpd[i]++;
                    }
                }
            }
        }
    }
}

void Widget::efbulletexist()//杂鱼的子弹死不死
{
    if (boss1pd)
        return;
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < my.bulletcount;k++)
            {
                if (fish[i] != NULL && my.mb[k] != NULL && fish[i]->eb[j] != NULL)
                {
                    if ((my.mb[k]->bulletx - fish[i]->eb[j]->ebulletx) * (my.mb[k]->bulletx - fish[i]->eb[j]->ebulletx) +
                       (my.mb[k]->bullety - fish[i]->eb[j]->ebullety) * (my.mb[k]->bullety - fish[i]->eb[j]->ebullety) < 4000)
                    {
                        delete fish[i]->eb[j];
                        fish[i]->eb[j] = NULL;
                        killfen += 50;
                        delete my.mb[k];
                        my.mb[k] = NULL;
                    }
                }
            }
        }
    }
}

void Widget::explode(int x,int y)//显示"爆",菜鸡的死亡效果
{
    if (boss1pd)
        return;
    chickenbao[chickenlabelnum] = new QLabel(this);
    chickenbao[chickenlabelnum]->setPixmap(QPixmap("../project-final/explode.png"));//应该持续2.5秒,还没实现
    chickenbao[chickenlabelnum]->setGeometry(x, y,60,60);
    chickenbao[chickenlabelnum]->setScaledContents(true);
    chickenbao[chickenlabelnum]->show();
    chickenlabelnum++;
}

void Widget::boss1bulletexist()//boss的子弹类型1和类型2死不死
{
    if (!boss1pd)
        return;
    for (int k = 0; k < my.bulletcount;k++)
    {
        for (int j = 0; j < 300; j++)
        {
            if (my.mb[k] != NULL && boss1->boss1bullet1[j] != NULL)
            {

               if ((my.mb[k]->bulletx - boss1->boss1bullet1[j]->ebulletx) * (my.mb[k]->bulletx - boss1->boss1bullet1[j]->ebulletx) +
               (my.mb[k]->bullety - boss1->boss1bullet1[j]->ebullety) * (my.mb[k]->bullety - boss1->boss1bullet1[j]->ebullety) < 2000)
               {
                   //if (j > 21)
                   //{
                       delete boss1->boss1bullet1[j];
                       boss1->boss1bullet1[j] = NULL;
                   //}

                   killfen += 50;
                   delete my.mb[k];
                   my.mb[k] = NULL;
               }            
            }
            if (my.mb[k] != NULL && boss1->boss1bullet2[j] != NULL)
            {
                if ((my.mb[k]->bulletx - boss1->boss1bullet2[j]->ebulletx) * (my.mb[k]->bulletx - boss1->boss1bullet2[j]->ebulletx) +
                (my.mb[k]->bullety - boss1->boss1bullet2[j]->ebullety) * (my.mb[k]->bullety - boss1->boss1bullet2[j]->ebullety) < 2000)
                {
                    //if (j > 21)
                    //{
                        delete boss1->boss1bullet2[j];
                        boss1->boss1bullet2[j] = NULL;
                    //}
                    killfen += 50;
                    delete my.mb[k];
                    my.mb[k] = NULL;
                }
            }
        }
    }
}

void Widget::bossexist()
{
    if (!boss1pd)
        return;
    for (int i = 0; i < my.bulletcount; i++)
    {
        if (my.mb[i] == NULL)
            continue;
        if ((my.mb[i]->bulletx - boss1->bossx) * (my.mb[i]->bulletx - boss1->bossx) +
             (my.mb[i]->bullety - boss1->bossy) * (my.mb[i]->bullety - boss1->bossy) < 2000)
        {
            boss1->bfatenum--;
            /*
            if (boss1->bfatenum < 30)
                boss1->bossmap = QPixmap("../project-final/efhalf.png");
            if (boss1->bfatenum < 40)
            {
                boss1->bossmap = QPixmap("../project-final/explode.png");
                player->pause();
            }
            if (boss1->bfatenum < -10)
            {
                player->play();
            }
            */
            delete my.mb[i];
            my.mb[i] = NULL;
        }
    }
}

void Widget::fourmapexist()
{
    if (my.myflyingy < 500)
        fourmap->load("../project-final/window.png");
}

void Widget::returnslot()
{
    this->hide();
    player->stop();
    mianwidget *mainchuang = new mianwidget();
    mainchuang->show();
}

void Widget::pauseslot()
{
    timer->stop();
    player->pause();
}

void Widget::continueslot()
{
    timer->start(10);
    player->play();
}

void Widget::gameover()
{
    if (lifenum < 1)
    {
        timer->stop();
        player->stop();
        //painter->end();
        //painter2->end();
        pausebutton->setEnabled(false);
        continuebutton->setEnabled(false);
        gameovermap->load("../project-final/gameover.png");

        QFont fontwenzi;
        fontwenzi.setPointSize(30);
        QLabel *startwenzi = new QLabel(this);
        startwenzi->setText("游戏结束，是否重新开始?");
        startwenzi->setGeometry(250,300,800,100);
        startwenzi->setFont(fontwenzi);
        startwenzi->show();

        restartbutton = new QPushButton(this);
        restartbutton->setText("继续(Y)");
        restartbutton->setFont(fontwenzi);
        restartbutton->setGeometry(250,500,300,100);
        nostartbutton = new QPushButton(this);
        nostartbutton->setText("算了(N)");
        nostartbutton->setFont(fontwenzi);
        nostartbutton->setGeometry(550,500,300,100);
        connect(restartbutton,SIGNAL(clicked(bool)),this,SLOT(restartslot()));
        connect(nostartbutton,SIGNAL(clicked(bool)),this,SLOT(nostartslot()));
        restartbutton->show();
        nostartbutton->show();
    }

}


void Widget::restartslot()
{
    firstchapter *rebootone = new firstchapter();
    this->hide();
    rebootone->show();
}

void Widget::nostartslot()
{
    mianwidget *remian = new mianwidget();
    this->hide();
    remian->show();
}

void Widget::gameclear()
{
    timer->stop();
    player->stop();
    pausebutton->setEnabled(false);
    continuebutton->setEnabled(false);
    gameclearmap->load("../project-final/gameclear.png");

    QFont fontwenzi;
    fontwenzi.setPointSize(30);
    QLabel *startwenzi = new QLabel(this);
    startwenzi->setText("游戏通关！是否重新开始?");
    startwenzi->setGeometry(250,300,800,100);
    startwenzi->setFont(fontwenzi);
    startwenzi->show();

    restartbutton = new QPushButton(this);
    restartbutton->setText("可以(Y)");
    restartbutton->setFont(fontwenzi);
    restartbutton->setGeometry(250,500,300,100);
    nostartbutton = new QPushButton(this);
    nostartbutton->setText("算了(N)");
    nostartbutton->setFont(fontwenzi);
    nostartbutton->setGeometry(550,500,300,100);
    connect(restartbutton,SIGNAL(clicked(bool)),this,SLOT(restartslot()));
    connect(nostartbutton,SIGNAL(clicked(bool)),this,SLOT(nostartslot()));
    restartbutton->show();
    nostartbutton->show();
}
