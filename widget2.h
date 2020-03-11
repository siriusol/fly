#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include "myflying2.h"
#include <QTimer>
#include <QTime>
#include "enemychicken2.h"
#include "enemyfish2.h"
#include "boss2.h"
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>
#include <QDialog>
#include <QPixmap>
#include "firstchapter2.h"

namespace Ui {
class Widget2;
}

class Widget2 : public QWidget
{
    Q_OBJECT

public slots:
    void returnslot();
    void pauseslot();
    void continueslot();
    void restartslot();
    void nostartslot();
public:
    explicit Widget2(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void shoot();
    void bulletexist();
    ~Widget2();
    void timerUpdate();
    void ecexist();
    void myexist();
    void myexistboss();
    void efexist();
    void efbulletexist();
    void explode(int, int);
    void boss1bulletexist();
    void bossexist();
    void fourmapexist();
    void warningexist();
    void mymove();
    void gameover();
    void gameclear();

private:
    Ui::Widget2 *ui;
    myflying2 my;
    enemychicken2 *chicken[10000];//10000个菜鸡，不会发子弹
    QLabel *chickenbao[10000];
    int chickenlabelnum = 0;
    boss2 *boss1;
    bool chickenpd[10000];
    int fishpd[500];
    int fishpd2[500];
    enemyfish2 *fish[500];//500个杂鱼，会发子弹
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
    QPixmap *fourmap;
    QPixmap *warning;
    QPixmap *gameovermap;
    QPixmap *gameclearmap;
    bool pressW;
    bool pressA;
    bool pressS;
    bool pressD;
    bool pressK;
};

#endif // WIDGET2_H
