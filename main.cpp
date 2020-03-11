#include "mianwidget.h"
#include "mianwidget2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mianwidget w;
    w.show();

    return a.exec();
}
