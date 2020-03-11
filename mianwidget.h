#ifndef MIANWIDGET_H
#define MIANWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "widget.h"
#include "exitwindow.h"
#include "settingswindow.h"
#include "firstchapter.h"
#include "secondchapter.h"
#include "thirdchapter.h"
#include "widget.h"
#include <QIcon>
#include <QLabel>


class mianwidget
    :public QWidget
{
    Q_OBJECT
public:
    explicit mianwidget(QWidget *parent = 0);
    QPushButton startgame;
    QPushButton settings;
    QPushButton exitgame;
    firstchapter *gamewindow;
    QLabel *banner;
public slots:
    void startslot();
    void settingsslot();
    void exitslot();
};

#endif // MIANWIDGET_H
