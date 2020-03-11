#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
#include <QWidget>
#include "mianwidget.h"
#include "mianwidget2.h"
#include <QPushButton>
#include <QLabel>


class settingswindow
    :public QWidget
{
    Q_OBJECT
public slots:
    void settingsreturnslot();
    void modeslot();
public:
    settingswindow(QWidget *parent = 0);
    QPushButton *settingsreturn;
    QLabel *shuoming;
    QLabel *neirong;
    QPushButton *modehuan;
};

#endif // SETTINGSWINDOW_H
