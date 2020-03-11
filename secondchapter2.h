#ifndef SECONDCHAPTER2_H
#define SECONDCHAPTER2_H

#include <QWidget>
#include "myflying2.h"
#include <QTimer>
#include <QTime>
#include "enemychicken2.h"
#include "enemyfish2.h"
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>
#include <QDialog>
#include "thirdchapter2.h"


class secondchapter2
    :public QWidget
{
    Q_OBJECT
public slots:
    void returnslot();
    void pauseslot();
    void continueslot();
    void restartslot();
    void nostartslot();
public:
    explicit secondchapter2(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void shoot();
    void bulletexist();
    ~secondchapter2();
    void timerUpdate();
    void ecexist();
    void myexist();
    void efexist();
    void efbulletexist();
    void explode(int, int);
    void secondmapexist();
    void warningexist();
    void mymove();
    void gameover();
    void gameclear();
private:
    myflying2 my;
    enemychicken2 *chicken[10000];//10000个菜鸡，不会发子弹
    QLabel *chickenbao[10000];
    int chickenlabelnum = 0;
    bool chickenpd[10000];
    int fishpd[500];
    int fishpd2[500];
    enemyfish2 *fish[500];//500个杂鱼，会发子弹
    QTimer *timer;
    int killfen; // 菜鸡100分，杂鱼300分(打残100，打死200)
    QPainter *painter;
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
    QMediaPlayer *player;
    QPixmap *secondmap;
    QPixmap *warning;
    QPixmap *gameovermap;
    bool pressW;
    bool pressA;
    bool pressS;
    bool pressD;
    bool pressK;
};

#endif // SECONDCHAPTER2_H
