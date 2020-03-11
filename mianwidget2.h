#ifndef MIANWIDGET2_H
#define MIANWIDGET2_H

#include <QWidget>
#include <QPushButton>
#include "widget2.h"
#include "exitwindow.h"
#include "settingswindow2.h"
#include "firstchapter2.h"
#include "secondchapter2.h"
#include "thirdchapter2.h"
#include "widget2.h"
#include <QIcon>
#include <QLabel>


class mianwidget2
    :public QWidget
{
    Q_OBJECT
public:
    explicit mianwidget2(QWidget *parent = 0);
    QPushButton startgame;
    QPushButton settings;
    QPushButton exitgame;
    firstchapter2 *gamewindow;
    QLabel *banner;
public slots:
    void startslot();
    void settingsslot();
    void exitslot();
};

#endif // MIANWIDGET2_H
