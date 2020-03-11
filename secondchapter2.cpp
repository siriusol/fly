#include "secondchapter2.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include "mianwidget2.h"
#include "widget2.h"

secondchapter2::secondchapter2(QWidget *parent)
   : QWidget(parent)
{
        this->resize(1080,720);
        this->setWindowTitle("第二关");
        this->setWindowIcon(QIcon("../project-final/icon.png"));
        setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);

        player = new QMediaPlayer();
        player->setMedia(QUrl::fromLocalFile("../project-final/2.mp3"));
        player->setVolume(20);
        player->play();
        secondmap = new QPixmap("../project-final/secondmap.png");
        warning = new QPixmap("../project-final/warning.png");
        gameovermap = new QPixmap("../project-final/window.png");

        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap("../project-final/secondback2.png").scaled(this->size())));
        this->setPalette(palette);
        killfen = 0;
        lifenum = 5;
        for(int i = 0; i < 10000; i++)//10000个菜鸡
        {
            chicken[i] = new enemychicken2();
        }
        for(int i = 0; i < 200; i++)//200个杂鱼及每个5个子弹
        {
             fish[i] = new enemyfish2();
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
                 fish[i]->eb[j] = new enemybullet2(fish[i]->fx + 20,fish[i]->fy + 80 + j * 100);
             }
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
        connect(timer, &QTimer::timeout, this, &secondchapter2::timerUpdate);
        timer->start(10);
}
secondchapter2::~secondchapter2()
{

}
void secondchapter2::paintEvent(QPaintEvent *)
{
    fen->setText(QString::number(killfen));
    lifenumlabel->setText(QString::number(lifenum));

    painter = new QPainter(this);
    painter->drawPixmap(0,300,1080,226,*secondmap);
    if (lifenum == 5)
        {
            painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,my.mymap);
        }
        else if (lifenum == 4)
        {
            painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane12"));
        }
        else if (lifenum == 3)
        {
            painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane22"));
        }
        else if (lifenum == 2)
        {
            painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane32"));
        }
        else if (lifenum == 1)
        {
            painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane42"));
        }
        else
        {
            painter->drawPixmap(my.myflyingx,my.myflyingy,80,80,QPixmap("../project-final/plane52"));
            painter->drawPixmap(0,300,1080,157,*gameovermap);
        }
    if (lifenum < 0)
    {
        painter->end();
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

void secondchapter2::keyPressEvent(QKeyEvent *event)
{
    int key1 = event->key();
    switch(key1)
    {
        case Qt::Key_W:pressW = true;break;
        case Qt::Key_A:pressA = true;break;
        case Qt::Key_S:pressS = true;break;
        case Qt::Key_D:pressD = true;break;
        default:
            break;
    }
    if (event->key() == Qt::Key_K)
        shoot();
}
void secondchapter2::keyReleaseEvent(QKeyEvent *event)
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

void secondchapter2::mymove()
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

void secondchapter2::shoot()
{
    my.mb[my.bulletcount] = new mybullet2(my.myflyingx,my.myflyingy);
    my.bulletcount++;
}

void secondchapter2::timerUpdate()
{
    gameover();
    mymove();
    bulletexist();     //自己的子弹死不死
    myexist();         //自己死不死
    ecexist();         //菜鸡死不死
    efexist();         //杂鱼死不死
    efbulletexist();   //杂鱼的子弹死不死
    secondmapexist();
    if (killfen > 8000)
        gameclear();
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

    this->update();
}

void secondchapter2::bulletexist() //自己的子弹死不死
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

void secondchapter2::ecexist() //菜鸡死不死
{
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

void secondchapter2::myexist()//自己死不死
{

            for (int j = 0; j < 200; j++)
            {
                if (chicken[j] == NULL)
                    continue;
                if ((my.myflyingx - chicken[j]->cx - 40) * (my.myflyingx - chicken[j]->cx - 40) +
                   (my.myflyingy - chicken[j]->cy - 40) * (my.myflyingy - chicken[j]->cy - 40) < 2000)
                {
                    if (!chickenpd[j])
                    {
                        lifenum--;
                        chickenpd[j] = true;
                    }
                }
            }
            for (int j = 0; j < 200; j++)
            {
                if (fish[j] == NULL)
                    continue;

                if ((my.myflyingx - fish[j]->fx - 40) * (my.myflyingx - fish[j]->fx - 40) +
                   (my.myflyingy - fish[j]->fy - 40) * (my.myflyingy - fish[j]->fy - 40) < 2000)
                {
                    if (fishpd[j] != 2)
                    {
                        lifenum--;
                    }

                }

                for (int k = 0; k < 3; k++)
                {
                    if (fish[j]->eb[k] == NULL)
                        continue;
                    if ((my.myflyingx - fish[j]->eb[k]->ebulletx) * (my.myflyingx - fish[j]->eb[k]->ebulletx) +
                       (my.myflyingx - fish[j]->eb[k]->ebullety) * (my.myflyingx - fish[j]->eb[k]->ebullety) < 2000)
                    {
                        lifenum--;
                    }
                }
            }
}

void secondchapter2::efexist() //杂鱼死不死
{
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
                        fish[i]->fmap = QPixmap("../project-final/efhalf2.png");
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

void secondchapter2::efbulletexist()//杂鱼的子弹死不死
{
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

void secondchapter2::explode(int x,int y)//显示"爆",菜鸡的死亡效果
{
    chickenbao[chickenlabelnum] = new QLabel(this);
    chickenbao[chickenlabelnum]->setPixmap(QPixmap("../project-final/explode2.png"));//应该持续2.5秒,还没实现
    chickenbao[chickenlabelnum]->setGeometry(x, y,60,60);
    chickenbao[chickenlabelnum]->setScaledContents(true);
    chickenbao[chickenlabelnum]->show();
    chickenlabelnum++;
}

void secondchapter2::secondmapexist()
{
    if (my.myflyingy < 500)
        secondmap->load("../project-final/window.png");
}

void secondchapter2::returnslot()
{
    this->hide();
    player->stop();
    mianwidget2 *mainchuang = new mianwidget2();
    mainchuang->show();
}

void secondchapter2::pauseslot()
{
    timer->stop();
    player->pause();
}

void secondchapter2::continueslot()
{
    timer->start(10);
    player->play();
}

void secondchapter2::gameover()
{
    if (lifenum < 1)
    {
        timer->stop();
        player->stop();
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

void secondchapter2::restartslot()
{
    secondchapter2 *rebootone = new secondchapter2();
    this->hide();
    rebootone->show();
}

void secondchapter2::nostartslot()
{
    mianwidget2 *remian = new mianwidget2();
    this->hide();
    remian->show();
}

void secondchapter2::gameclear()
{
    player->stop();
    thirdchapter2 *thirdguan = new thirdchapter2();
    this->~secondchapter2();
    thirdguan->show();
}
