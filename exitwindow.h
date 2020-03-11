#ifndef EXITWINDOW_H
#define EXITWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "mianwidget.h"


class exitwindow
    :public QWidget
{
    Q_OBJECT
public slots:
    void fanhuislot();
    void tuichuslot();
public:
    exitwindow(QWidget *parent = 0);
    QLabel *wenzi;
    QLabel *wenzi2;
    QPushButton *tuichu;
    QPushButton *fanhui;
};

#endif // EXITWINDOW_H
