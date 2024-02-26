#include <configcenter.h>
#include <scheduler.h>
#include <QApplication>
#include "datacallback.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Scheduler s;
    s.startDDS(1);

    DataCallback data(&s);

    return a.exec();
}
