#ifndef DATACALLBACK_H
#define DATACALLBACK_H

#include <scheduler.h>
#include <QElapsedTimer>
#include <QFile>
#include <QPushButton>
#include <MfcHud.h>
#include <FlightSimulationSoft.h>
#include "DataAcquisitionSoft.h"

class DataCallback : public Callback{
    Q_OBJECT
public:
    DataCallback(Scheduler *sched);
    ~DataCallback(){
        //delete SimThread::instance()->getOrCreate(1);
    }

    void sendState();

private:
     virtual void apply(const DDSDatagram      &datagram); ///<DDS数据

    // 飞行状态
    void dealFlyStateData(const ICD2002G::UAVFlightState* structfly);
    // 无人机舵面起落架位置
    void dealSurfacePosData(const ICD2002G::UAVSurfacePosState* structfly);
    // 无人机涡扇发动机系统状态
    void dealEngineStateData(const ICD2002G::UAVEngineState* structfly);
    // 无人机燃油系统状态
    void dealFuelStateData(const ICD2002G::UAVFuelState* structfly);
    // 无人机液压系统状态
    void dealHydraulicStateData(const ICD2002G::UAVHydraulicState* structfly);
    // 无人机起落架系统状态
    void dealLandingGearStateData(const ICD2002G::UAVLandingGearState* structfly);
    // 无人机电源系统状态
    void dealElectricitySystemStateData(const ICD2002G::UAVElectricitySystemState* structfly);
    // 无人机大气机状态
    void dealADCStateData(const ICD2002G::UAVADCState* structfly);
    // 无人机惯导状态
    void dealINSStateData(const ICD2002G::UAVINSState* structfly);
    // 无人机GPS状态
    void dealGPSStateData(const ICD2002G::UAVGPSState* structfly);
    // 无人机无线电高度表状态
    void dealRAStateData(const ICD2002G::UAVRAState* structfly);
    // 无人机告警信息
    void dealAlarmStateData(const ICD2002G::UAVAlarmState* structfly);
    // 无人机控制指令回传
    void dealCtrlCmdFeedbackData(const ICD2002G::UAVCtrlCmdFeedback* structfly);
    // 无人机飞控与导航状态信息
    void dealNavCtrlStateData(const ICD2002G::UAVNavCtrlState* structfly);
    // 航向相对位置
    void dealAddData(const ICD2002G::UAVAddData* structfly);

    void dealJOYSTICKData(const ICD2002G::JoyStickFly* structfly);

    void dealTHROTTLEData(const ICD2002G::ThrottleFly* structfly);

    void dealRUDDERPEDALData(const ICD2002G::RudderpedalFly* structfly);
private:
    QByteArray stPayload;

    ICD2002G::MayData m_mayData;
    ICD2002G::flyBigTelemety m_fbTelemety;
    ICD2002G::RudderFly m_rudpedal;
    ICD2002G::ProfessionalData m_profession;

    ICD2002G::HOTAS m_joy;
    ICD2002G::RudderPedal m_rudder;
    ICD2002G::DeviceControlMode m_throttle;

    QUdpSocket  *m_mayDataSockect;
    QUdpSocket  *m_fbTelemetySockect;
    QUdpSocket  *m_rudderPedalSockect;
    QUdpSocket  *m_professionSockect;

    QUdpSocket  *m_joySockect;
    QUdpSocket  *m_rudderSockect;
    QUdpSocket  *m_throttleSockect;
    Z_F32   m_alt;
    Z_I16   m_expectedAlt;
};

#endif // DATACALLBACK_H
