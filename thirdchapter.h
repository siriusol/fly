#ifndef THIRDCHAPTER_H
#define THIRDCHAPTER_H


#include <QWidget>
#include "myflying.h"
#include <QTimer>
#include <QTime>
#include "enemychicken.h"
#include "enemyfish.h"
#include "boss.h"
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>
#include <QDialog>
#include <QPixmap>
#include "firstchapter.h"
#include "widget.h"



class thirdchapter : public QWidget
{
    Q_OBJECT

public slots:
    void returnslot();
    void pauseslot();
    void continueslot();
    void restartslot();
    void nostartslot();
public:
    explicit thirdchapter(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void shoot();
    void bulletexist();
    ~thirdchapter();
    void timerUpdate();
    void ecexist();
    void myexist();
    void myexistboss();
    void efexist();
    void efbulletexist();
    void explode(int, int);
    void boss1bulletexist();
    void bossexist();
    void thirdmapexist();
    void warningexist();
    void mymove();
    void gameover();
    void gameclear();

private:
    myflying my;
    enemychicken *chicken[10000];//10000个菜鸡，不会发子弹
    QLabel *chickenbao[10000];
    int chickenlabelnum = 0;
    boss *boss1;
    bool chickenpd[10000];
    int fishpd[500];
    int fishpd2[500];
    enemyfish *fish[500];//500个杂鱼，会发子弹
    QTimer *timer;
    int killfen; // 菜鸡100分，杂鱼300分(打残100，打死200)
    QPainter *painter;
    QPainter *painter2;
    int lifenum;
    QLabel *fen;
    QLabel *fenzi;
    QLabel *lifelabel;
    QLabel *lifenumlabel;
    QPushButton *returnbutton;
    QPushButton *pausebutton;
    QPushButton *continuebutton;
    QPushButton *restartbutton;
    QPushButton *nostartbutton;
    bool boss1pd = false;
    QMediaPlayer *player;
    QPixmap *thirdmap;
    QPixmap *warning;
    QPixmap *gameovermap;
    QPixmap *gameclearmap;
    bool pressW;
    bool pressA;
    bool pressS;
    bool pressD;
    bool pressK;
};


#endif // THIRDCHAPTER_H
