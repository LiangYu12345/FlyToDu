#include <configcenter.h>
#include <scheduler.h>
#include <QApplication>
#include "datacallback.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Scheduler s;
    s.startDDS(ConfigCenter::ddsID());
    int udpPort = 6001;
    s.startUDP(udpPort);
    DataCallback data(&s);
    return a.exec();
}
