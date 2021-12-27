#include <configcenter.h>
#include <scheduler.h>
#include <QApplication>
#include "datacallback.h"
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //widget t;
    //t.show();

    Scheduler s;
    s.startDDS(13);
    int udpPort = 5001;
    s.startUDP(udpPort);
    DataCallback data(&s);

    return a.exec();
}
