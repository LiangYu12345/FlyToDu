﻿#ifndef DATACALLBACK_H
#define DATACALLBACK_H

#include <scheduler.h>
#include <QElapsedTimer>
#include <QFile>
#include "ICD/FlightSimData.h"
#include "ICD/DuProtocolData.h"
#include <QPushButton>

class DataCallback : public Callback{
    Q_OBJECT
public:
    DataCallback(Scheduler *sched);
    ~DataCallback(){
        //delete SimThread::instance()->getOrCreate(1);
    }

    void sendState();

    //ushort getCrc16_DataCheck(unsigned char* data, unsigned int length);
private:
     virtual void apply(const DDSDatagram      &datagram); ///<DDS数据

    void dealFlyHudData(const FS_HudPeriod * structfly);
    void dealFlyDuData(const FS_DU * structfly);

private:

    int flag = 0;
    int DU_CIRCLE_COUNT = 0;

    QByteArray stPayload;
    QPushButton * m_sendBtn;
};

#endif // DATACALLBACK_H
