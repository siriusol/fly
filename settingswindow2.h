#ifndef SETTINGSWINDOW2_H
#define SETTINGSWINDOW2_H
#include <QWidget>
#include "mianwidget2.h"
#include "mianwidget.h"
#include <QPushButton>
#include <QLabel>


class settingswindow2
    :public QWidget
{
    Q_OBJECT
public slots:
    void settingsreturnslot();
    void modeslot();
public:
    settingswindow2(QWidget *parent = 0);
    QPushButton *settingsreturn;
    QLabel *shuoming;
    QLabel *neirong;
    QPushButton *modehuan;
};

#endif // SETTINGSWINDOW2_H
