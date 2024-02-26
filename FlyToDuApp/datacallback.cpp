#include "datacallback.h"
#include <QFile>
#include <packetutilityv2.h>
#include "ICDCommonData.h"
#include "common.h"


unsigned short getCrc_DataCheck(unsigned char* data, unsigned int length)
{
    unsigned short crc = 0;
    unsigned int value = 0;

    while(length-- != 0)
    {
        value += *data++;
    }
    crc = value & 0xFF;
    return crc;
}

DataCallback::DataCallback(Scheduler *sched) : Callback(sched)
{
    setObjectName("DataCallback");
    registerDDS("FSS-FLYSTATE-STA");
    registerDDS("FSS-SURFACEPOS-STA");
    registerDDS("FSS-TFENGSYS-STA");
    registerDDS("FSS-FUELSYS-STA");
    registerDDS("FSS-HYDSYS-STA");
    registerDDS("FSS-LDGEARSYS-STA");
    registerDDS("FSS-ELESYS-STA");
    registerDDS("FSS-ADCDATA-STA");
    registerDDS("FSS-INSDATA-STA");
    registerDDS("FSS-GPSDATA-STA");
    registerDDS("FSS-RADATA-STA");
    registerDDS("FSS-ALARMSTATE-STA");
    registerDDS("FSS-CMDFEEDBACK-STA");
    registerDDS("FSS-NAVCTRL-STA");
    registerDDS("FSS-ADD-STA");

    registerDDS("DAS-JOYSTICK-FLY-CMD");
    registerDDS("DAS-THROTTLE-FLY-CMD");
    registerDDS("DAS-RUDDERPEDAL-FLY-CMD");


    m_mayDataSockect = new QUdpSocket;
    m_mayDataSockect->bind(QHostAddress::AnyIPv4,5555,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    m_mayDataSockect->joinMulticastGroup(QHostAddress("224.0.2.1"));


    m_fbTelemetySockect = new QUdpSocket;
    m_fbTelemetySockect->bind(QHostAddress::AnyIPv4,6666,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    m_fbTelemetySockect->joinMulticastGroup(QHostAddress("224.0.2.1"));

    m_rudderPedalSockect = new QUdpSocket;
    m_rudderPedalSockect->bind(QHostAddress::AnyIPv4,7777,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    m_rudderPedalSockect->joinMulticastGroup(QHostAddress("224.0.2.1"));

    m_professionSockect = new QUdpSocket;
    m_professionSockect->bind(QHostAddress::AnyIPv4,32769,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    m_professionSockect->joinMulticastGroup(QHostAddress("224.0.2.1"));

    m_joySockect = new QUdpSocket;
    m_joySockect->bind(QHostAddress::AnyIPv4,7778,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    m_joySockect->joinMulticastGroup(QHostAddress("224.0.2.1"));

    m_rudderSockect = new QUdpSocket;
    m_rudderSockect->bind(QHostAddress::AnyIPv4,7779,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    m_rudderSockect->joinMulticastGroup(QHostAddress("224.0.2.1"));

    m_throttleSockect = new QUdpSocket;
    m_throttleSockect->bind(QHostAddress::AnyIPv4,7780,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    m_throttleSockect->joinMulticastGroup(QHostAddress("224.0.2.1"));
    m_mayData.fix1 = 0x55;
    m_mayData.fix2 = 0xAA;
    m_mayData.fix3 = 0x88;

    m_mayData.mT.head1 = 0x05;
    m_mayData.mT.head2 = 0x0F;

    m_mayData.fT.head1 = 0x6A;
    m_mayData.fT.head2 = 0x01;

    m_fbTelemety.fixValue1 = 0x55;
    m_fbTelemety.fixValue2 = 0xAA;
    m_fbTelemety.fixValue3 = 0x84;
    m_fbTelemety.type = 0x22;

    m_rudpedal.fixValue1 = 0x55;
    m_rudpedal.fixValue2 = 0xAA;
    m_rudpedal.fixValue3 = 0x52;
    m_rudpedal.type = 0x22;

    m_profession.fixValue1 = 0x55;    //固定值 55
    m_profession.fixValue2 = 0xAA;    //固定值 AA
    m_profession.fixValue3 = 0x2F;    //固定值 2F
    m_profession.type = 0x44;  		//数据类型	44

    m_joy.head1 = 0x55;
    m_joy.head2 = 0xAA;
    m_joy.devNum = 0x26;

    m_rudder.head1 = 0x55;
    m_rudder.head2 = 0xAA;

    m_throttle.head1 = 0x55;
    m_throttle.head2 = 0xAA;
}

void DataCallback::apply(const DDSDatagram &datagram)
{
    if(datagram.topic() == "FSS-FLYSTATE-STA")
    {
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVFlightState>();
        dealFlyStateData(structfly);
    }
    else if(datagram.topic() == "FSS-SURFACEPOS-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVSurfacePosState>();
        dealSurfacePosData(structfly);
    }
    else if(datagram.topic() == "FSS-TFENGSYS-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVEngineState>();
        dealEngineStateData(structfly);
    }
    else if(datagram.topic() == "FSS-FUELSYS-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVFuelState>();
        dealFuelStateData(structfly);
    }
    else if(datagram.topic() == "FSS-HYDSYS-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVHydraulicState>();
        dealHydraulicStateData(structfly);
    }
    else if(datagram.topic() == "FSS-LDGEARSYS-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVLandingGearState>();
        dealLandingGearStateData(structfly);
    }
    else if(datagram.topic() == "FSS-ELESYS-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVElectricitySystemState>();
        dealElectricitySystemStateData(structfly);
    }
    else if(datagram.topic() == "FSS-ADCDATA-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVADCState>();
        dealADCStateData(structfly);
    }
    else if(datagram.topic() == "FSS-INSDATA-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVINSState>();
        dealINSStateData(structfly);
    }
    else if(datagram.topic() == "FSS-GPSDATA-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVGPSState>();
        dealGPSStateData(structfly);
    }
    else if(datagram.topic() == "FSS-RADATA-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVRAState>();
        dealRAStateData(structfly);
    }
    else if(datagram.topic() == "FSS-ALARMSTATE-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVAlarmState>();
        dealAlarmStateData(structfly);
    }
    else if(datagram.topic() == "FSS-CMDFEEDBACK-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVCtrlCmdFeedback>();
        dealCtrlCmdFeedbackData(structfly);
    }
    else if(datagram.topic() == "FSS-NAVCTRL-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVNavCtrlState>();
        dealNavCtrlStateData(structfly);
    }
    else if(datagram.topic() == "FSS-ADD-STA"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::UAVAddData>();
        dealAddData(structfly);
    }

    else if(datagram.topic() == "DAS-JOYSTICK-FLY-CMD"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::JoyStickFly>();
        dealJOYSTICKData(structfly);
    }
    else if(datagram.topic() == "DAS-THROTTLE-FLY-CMD"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::ThrottleFly>();
        dealTHROTTLEData(structfly);
    }
    else if(datagram.topic() == "DAS-RUDDERPEDAL-FLY-CMD"){
        PacketDecoderFixed decoder(datagram.data());
        auto structfly = decoder.getFixed<const ICD2002G::RudderpedalFly>();
        dealRUDDERPEDALData(structfly);
    }
    sendState();
}

void DataCallback::sendState(){

    QByteArray st;
    st.append((char*)&m_mayData, sizeof (ICD2002G::MayData) - 1);
    auto crc = getCrc_DataCheck((unsigned char *)st.data(), st.size() - 1);
    st.append(crc);
    m_mayDataSockect->writeDatagram(st, st.size(), QHostAddress("224.0.2.1"), 5555);

    QByteArray stPay;
    stPay.append((char*)&m_fbTelemety, sizeof (ICD2002G::flyBigTelemety));
    m_fbTelemetySockect->writeDatagram(stPay, stPay.size(), QHostAddress("224.0.2.1"), 6666);

    QByteArray stPayl;
    stPayl.append((char*)&m_rudpedal, sizeof (ICD2002G::RudderFly));
    m_rudderPedalSockect->writeDatagram(stPayl, stPayl.size(), QHostAddress("224.0.2.1"), 7777);

    QByteArray stPayload;
    stPayload.append((char*)&m_profession, sizeof (ICD2002G::ProfessionalData));
    m_professionSockect->writeDatagram(stPayload, stPayload.size(), QHostAddress("224.0.2.1"), 32769);

    QByteArray stPaylj;
    stPaylj.append((char*)&m_joy, sizeof (ICD2002G::HOTAS));
    m_joySockect->writeDatagram(stPaylj, stPaylj.size(), QHostAddress("224.0.2.1"), 7778);

    QByteArray stPaylr;
    stPaylr.append((char*)&m_rudder, sizeof (ICD2002G::RudderPedal));
    m_rudderSockect->writeDatagram(stPaylr, stPaylr.size(), QHostAddress("224.0.2.1"), 7779);

    QByteArray stPaylt;
    stPaylt.append((char*)&m_throttle, sizeof (ICD2002G::DeviceControlMode));
    m_throttleSockect->writeDatagram(stPaylt, stPaylt.size(), QHostAddress("224.0.2.1"), 7780);
}

void DataCallback::dealFlyStateData(const ICD2002G::UAVFlightState* structfly)
{
    m_mayData.fT.lon = BigLittleSwap32(structfly->longitude);
    m_mayData.fT.lat = BigLittleSwap32(structfly->latitude);

    m_mayData.fT.yaw = BigLittleSwap16((unsigned short)(structfly->trueHeading * 100));
    m_mayData.fT.pitch = BigLittleSwap16((short)(structfly->pitch * 100));
    m_mayData.fT.roll = BigLittleSwap16((short)(structfly->roll * 100));

    m_fbTelemety.expectedyaw = BigLittleSwap16((unsigned short)(structfly->trueHeading * 100));
    m_fbTelemety.pitch = BigLittleSwap16((short)(structfly->pitch * 100));
    m_fbTelemety.rool = BigLittleSwap16((short)(structfly->roll * 100));

    m_fbTelemety.indicatedAirspeed = BigLittleSwap16((unsigned short)(structfly->vt * 100));

    m_profession.yaw = BigLittleSwap16((unsigned short)(structfly->trueHeading / 0.00549324788));
    m_profession.pitch = BigLittleSwap16((short)(structfly->pitch / 0.0027466658528));
    m_profession.roll = BigLittleSwap16((short)(structfly->roll / 0.005493331705679));
    m_profession.diffAlt = BigLittleSwap32((int)(structfly->altitude / 0.01));
}

void DataCallback::dealSurfacePosData(const ICD2002G::UAVSurfacePosState *structfly)
{

}

void DataCallback::dealEngineStateData(const ICD2002G::UAVEngineState *structfly)
{
    m_mayData.fT.highPressureRotor =  BigLittleSwap16(structfly->highTurbineRPM);
    m_mayData.fT.lowPressureRotor = BigLittleSwap16(structfly->lowTurbineRPM);

    m_profession.turbineTemperature =  BigLittleSwap16(ceil((structfly->highTurbineTemp + 65) / 0.018310826276));

    m_profession.inletAirTemperature = BigLittleSwap16((unsigned short)structfly->intakeTotalTemp);
    m_profession.inletAirPressure = BigLittleSwap16((unsigned short)structfly->intakeTotalPress);

    m_profession.outletPressure = BigLittleSwap32((unsigned short)(structfly->highTurbinePress * 1000));

    m_profession.exportOilPressure = (unsigned char)(ceil((structfly->lubePress  + 144.4426173) / 8.060977 ));
    m_profession.exportOilTemperature = (unsigned char)(ceil((structfly->lubeTemp + 56.08242773) / 1.005118064));

    m_profession.outletPressure = BigLittleSwap16((unsigned short)((structfly->highTurbinePress / 0.0381475547417)));
}

void DataCallback::dealFuelStateData(const ICD2002G::UAVFuelState *structfly)
{
//    m_mayData.fT.remainL = BigLittleSwap16(structfly->lessTotalFuel * 10);

    m_profession.tOilQuantity = BigLittleSwap16(structfly->lessTotalFuel);
    m_profession.ftmpTemperature =  BigLittleSwap16(structfly->fuelTemp);
    m_profession.exportOilVelocity =  (unsigned char)ceil((structfly->fuelPress + 477.8239054) / 24.40097565);
    m_profession.fuelFlowOrder = BigLittleSwap16(structfly->fuelFlow / 0.010681315);
}

void DataCallback::dealHydraulicStateData(const ICD2002G::UAVHydraulicState *structfly)
{
    m_fbTelemety.leftPressure = (unsigned char)(structfly->brakePressLeft);
    m_fbTelemety.rightPressure = (unsigned char)(structfly->brakePressRight);
}

void DataCallback::dealLandingGearStateData(const ICD2002G::UAVLandingGearState *structfly)
{
    if(structfly->frontGearState > 0.95)
    {
        m_profession.fudswitchStatus = BigLittleSwap16(16);
    }
    else if(structfly->frontGearState < 0.05)
    {
        m_profession.fudswitchStatus = BigLittleSwap16(1);
    }
    else
    {
        m_profession.fudswitchStatus = 0;
    }

    if(structfly->leftGearState > 0.95)
    {
        m_profession.ludswitchStatus = BigLittleSwap16(16);
    }
    else if(structfly->leftGearState < 0.05)
    {
        m_profession.ludswitchStatus = BigLittleSwap16(1);
    }
    else
    {
        m_profession.fudswitchStatus = 0;
    }

    if(structfly->rightGearState > 0.95)
    {
        m_profession.rudswitchStatus = BigLittleSwap16(16);
    }
    else if(structfly->rightGearState < 0.05)
    {
        m_profession.rudswitchStatus = BigLittleSwap16(1);
    }
    else
    {
        m_profession.rudswitchStatus = 0;
    }

    if(structfly->frontGearWheel > 0.95)
    {
        m_profession.fwSwitch = 16;
    }
    else if(structfly->frontGearWheel < 0.05)
    {
        m_profession.fwSwitch = 1;
    }
    else
    {
        m_profession.fwSwitch = 0;
    }

    if(structfly->leftGearWheel > 0.95)
    {
        m_profession.lwSwitch = 16;
    }
    else if(structfly->leftGearWheel < 0.05)
    {
        m_profession.lwSwitch = 1;
    }
    else
    {
        m_profession.lwSwitch = 0;
    }

    if(structfly->rightGearWheel > 0.95)
    {
        m_profession.rwSwitch = 16;
    }
    else if(structfly->rightGearWheel < 0.05)
    {
        m_profession.rwSwitch = 1;
    }
    else
    {
        m_profession.rwSwitch = 0;
    }
}

void DataCallback::dealElectricitySystemStateData(const ICD2002G::UAVElectricitySystemState *structfly)
{
    m_mayData.fT.engineVoltage = BigLittleSwap16(structfly->dynamoVoltage);
    m_mayData.fT.cellVoltage1 = (unsigned char)((structfly->batteryVoltage - 18) * 10);

    m_profession.generatorVoltage = (unsigned char)(structfly->dynamoVoltage / 0.14117670588);
    m_fbTelemety.throttleVoltage = BigLittleSwap16((unsigned short)(structfly->busVoltage / 0.01));
}

void DataCallback::dealADCStateData(const ICD2002G::UAVADCState *structfly)
{
    m_mayData.fT.indicatedAirspeed = BigLittleSwap16((unsigned short)(structfly->IAS * 10));
    m_mayData.fT.pressureAltitude = BigLittleSwap16((short)(structfly->Hqne / 0.610370189519943));

    m_fbTelemety.mach = BigLittleSwap16((unsigned short)(structfly->M * 1000));
    m_fbTelemety.attackAngle = BigLittleSwap16((short)(structfly->AOA / 0.002));
    m_fbTelemety.sideslipAngle = BigLittleSwap16((short)(structfly->AOS / 0.002));

    m_fbTelemety.barometricRate = BigLittleSwap16((short)(structfly->vSpeed * 100));
    m_fbTelemety.radioRate = m_fbTelemety.barometricRate;
    m_profession.staticPressure = BigLittleSwap16((unsigned short)structfly->Ps);
    m_profession.fullPressure = BigLittleSwap16((unsigned short)structfly->Pt);
    m_fbTelemety.relativeAltitude = BigLittleSwap16((short)structfly->relativeHigh);
    m_mayData.fT.rarAltitude = BigLittleSwap16((short)structfly->relativeHigh);
}

void DataCallback::dealINSStateData(const ICD2002G::UAVINSState *structfly)
{
    m_mayData.fT.groundSpeed = BigLittleSwap16((short)(structfly->GS));
    m_mayData.fT.remainL = BigLittleSwap16(structfly->overloadG);
}

void DataCallback::dealGPSStateData(const ICD2002G::UAVGPSState *structfly)
{
    m_profession.diffAlt = BigLittleSwap32((int)(structfly->altitude * 100));
    m_mayData.fT.alt = BigLittleSwap16((short)(structfly->altitude / 0.7629627368999298));
    m_alt = structfly->altitude;
}

void DataCallback::dealRAStateData(const ICD2002G::UAVRAState *structfly)
{
//    m_mayData.fT.rarAltitude = BigLittleSwap16((unsigned short)(structfly->ra * 10));
}

void DataCallback::dealAlarmStateData(const ICD2002G::UAVAlarmState *structfly)
{
    m_profession.wOilQuantity = BigLittleSwap16(structfly->remainFuel);
    m_profession.lowOilPressure = BigLittleSwap16(structfly->lubePress);
}

void DataCallback::dealCtrlCmdFeedbackData(const ICD2002G::UAVCtrlCmdFeedback *structfly)
{
    if(structfly->cmdType == 6 && structfly->cmdValue == 1)
        m_fbTelemety.expectedSpeed = BigLittleSwap16((unsigned char)structfly->param1);
    if(structfly->cmdType == 5 && structfly->cmdValue == 1){
        m_fbTelemety.expectedAlt = BigLittleSwap16((short)structfly->param1);
        m_expectedAlt = m_fbTelemety.expectedAlt;
        m_fbTelemety.altitudeIntercept = BigLittleSwap16((short)m_expectedAlt - m_alt);
    }
}

void DataCallback::dealNavCtrlStateData(const ICD2002G::UAVNavCtrlState *structfly)
{
//
    m_fbTelemety.curWaypointNum = BigLittleSwap16(structfly->curSubRouteID);
    m_fbTelemety.curNavpointNum = BigLittleSwap16(structfly->curWptID);
    m_fbTelemety.disNextNavpoint = BigLittleSwap16((short)structfly->distanceToGo);
    m_fbTelemety.expectedyaw = BigLittleSwap16((unsigned short)structfly->mcpHeading);
    m_fbTelemety.expectedAlt = BigLittleSwap16((short)structfly->mcpHigh);
    m_fbTelemety.expectedSpeed = BigLittleSwap16((unsigned char)(structfly->mcpSpeed * 10));
    m_mayData.fT.lateralDeviation = BigLittleSwap16((short)(structfly->crossTrackDistance));

    m_mayData.fT.systemTime = BigLittleSwap32((unsigned int)(structfly->flightTime / 0.001));

    m_mayData.fT.flyStatu = BigLittleSwap16((short)(1 << structfly->flightStage));
}

void DataCallback::dealAddData(const ICD2002G::UAVAddData *structfly)
{

}

void DataCallback::dealJOYSTICKData(const ICD2002G::JoyStickFly *structfly)
{
    m_joy.axisX = structfly->aileronCmd;
    m_joy.axisY = structfly->elevatorCmd;
}

void DataCallback::dealTHROTTLEData(const ICD2002G::ThrottleFly *structfly)
{

}

void DataCallback::dealRUDDERPEDALData(const ICD2002G::RudderpedalFly *structfly)
{
    m_mayData.fT.leftBrake = (structfly->leftBrake);
    m_mayData.fT.rightBrake = (structfly->rightBrake);
    m_rudder.yaw = structfly->rudderCmd;
}




