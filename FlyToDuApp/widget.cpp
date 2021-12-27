#include "widget.h"

#include <QFile>
#include "ICD/DuProtocolData.h"

#include <QTimer>

widget::widget(QWidget *parent) : QWidget(parent)
{
    this->resize(600,400);

    //
    stPayload.resize(sizeof (DiuCircleData));
    QFile file("data");
    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<"can't open";
        return;
    }
    else
    {
        stPayload = file.readAll();
        file.close();
    }

    QTimer * m_time;
    m_time = new QTimer();
    connect(m_time,&QTimer::timeout,this,&widget::slottimeout);
  //  m_time->start(20);

}

void widget::slottimeout()
{
    int temp = udp.writeDatagram(stPayload, QHostAddress("192.168.3.200"), 5001);
    qDebug()<<"send"<<temp;
}
