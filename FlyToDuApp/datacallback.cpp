#include "datacallback.h"
#include <QFile>

ushort crcTable[256]=
{
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
    0x1231, 0x0110, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
    0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
    0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
    0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
    0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
    0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
    0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
    0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
    0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
    0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
    0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
    0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
    0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
    0x01b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
    0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
    0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
    0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
    0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
    0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
    0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
    0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
    0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

unsigned short getCrc16_DataCheck(unsigned char* data, unsigned int length)
{
    unsigned short crc = 0;
    unsigned short crc1= 0;
    unsigned int high;

    while(length-- != 0)
    {
        high = crc >> 8; //取CRC锟斤拷位
        crc <<= 8;
        crc ^= crcTable[high^*data];
        data++;
    }
    crc1	= crc << 8;
    crc1	|= (crc >> 8) & 0xFF;
    return crc1;
}

DataCallback::DataCallback(Scheduler *sched) : Callback(sched)
{
    setObjectName("DataCallback");
    registerDDS("DDS_TOPIC_HUD_PERIOD_SEND");
    registerDDS("DDS_TOPIC_DU_SEND");

}

void DataCallback::apply(const DDSDatagram &datagram)
{
    if(datagram.topic() == "DDS_TOPIC_HUD_PERIOD_SEND")
    {
        const FS_HudPeriod * structfly = reinterpret_cast<const FS_HudPeriod*>(datagram.data().data());

        flag ^= 0x01;

        dealFlyHudData(structfly);
    }
    else if(datagram.topic() == "DDS_TOPIC_DU_SEND"){
        const FS_DU * structfly = reinterpret_cast<const FS_DU*>(datagram.data().data());


        flag ^= 0x01;

        dealFlyDuData(structfly);
    }

    sendState();
}

void DataCallback::sendState(){

    if(flag == 0x03)
    {
        auto st = reinterpret_cast<DiuCircleData *>(stPayload.data());
        st->crc16 = getCrc16_DataCheck((unsigned char *)st,stPayload.size()-2);

        scheduler()->getUDPNetwork()->writeDatagram(stPayload, QHostAddress("192.168.3.200"), 5001);


       // scheduler()->getUDPNetwork()->writeDatagram(stPayload, QHostAddress("192.168.3.201"), 5501);
        flag = 0;
    }
}

void DataCallback::dealFlyHudData(const FS_HudPeriod *structfly)
{

    stPayload.resize(sizeof (DiuCircleData));

    auto st = reinterpret_cast<DiuCircleData*>(stPayload.data());
    st->frameID = 0xFA5F;
    {
        st->adc1.aos = structfly->SideslipAngle / 0.01;
        st->adc1.aoa = structfly->AttackAngle / 0.01;
        st->adc1.vc = structfly->CurrentAirSpeed / 0.02;
        st->adc1.vt = structfly->VacuoSpeed / 0.02;
        st->adc1.mach = structfly->CurrentMachNumber / 0.001;
        st->adc1.h = structfly->PressueAltitude / 0.5;
    }

    {
        st->adc2.aos = structfly->SideslipAngle / 0.01;
        st->adc2.aoa = structfly->AttackAngle / 0.01;
        st->adc2.vc = structfly->CurrentAirSpeed / 0.02;
        st->adc2.vt = structfly->VacuoSpeed / 0.02;
        st->adc2.mach = structfly->CurrentMachNumber / 0.001;
        st->adc2.h = structfly->PressueAltitude / 0.5;
    }

    {
        st->cns.mmr.locDeviation = structfly->CourseBeaconDeviation / 0.4*2e-12;
        st->cns.mmr.gsDeviation = structfly->GlidePathDeviation / 0.8*2e-12;
        st->cns.ra.raHeight = structfly->RadioAltitude / 0.1;
        st->cns.dme.groundSpeed = structfly->GroundSpeed / 0.02;
    }

    {
        int8_t wow = 0;
        if(structfly->FrontWheelLoadSignal)
            wow += 0x01;
        if(structfly->LeftWheelLoadSignal)
            wow += 0x01;
        if(structfly->RightWheelLoadSignal)
            wow += 0x04;
        st->dcu1.wowState = wow;
        st->dcu1.wingAngle = structfly->TheFlapsPosition;
    }

    {
        int8_t land = 0;
        if(structfly->LeftUndercarriageCondition)
            land += 0x01;
        else
            land += 0x01;
        if(structfly->FrontUndercarriageCondition)
            land += 0x04;
        else
            land += 0x08;
        if(structfly->RightUndercarriageCondition)
            land += 0x16;
        else
            land += 0x32;
        st->dcu2.LandingGearStatus = land;
    }

    {
        st->insGnss1.pitch = structfly->PitchAngle / 0.01;
        st->insGnss1.roll = structfly->RollAngle / 0.01;
        st->insGnss1.windSpeed = structfly->WindSpeed / 0.02;
        st->insGnss1.windDirection = structfly->WindDirection / 0.01;
    }

    {
        st->insGnss2.pitch = structfly->PitchAngle / 0.01;
        st->insGnss2.roll = structfly->RollAngle / 0.01;
        st->insGnss2.windSpeed = structfly->WindSpeed / 0.02;
        st->insGnss2.windDirection = structfly->WindDirection / 0.01;
    }
}

void DataCallback::dealFlyDuData(const FS_DU * structfly)
{
    stPayload.resize(sizeof (DiuCircleData));

    auto st = reinterpret_cast<DiuCircleData*>(stPayload.data());
    st->frameID = 0xFA5F;
    st->length = 0x2B4;
    st->dataType = 0x01;
    if (DU_CIRCLE_COUNT == 256)
    {
        DU_CIRCLE_COUNT = 0;
    }
    st->count = (uchar)DU_CIRCLE_COUNT++;
    st->dataValid = 0x0fff;

    {
        st->insGnss1.gnssLon = structfly->GNSSLongtitude / 0.000003;
        st->insGnss1.gnssLat = structfly->GNSSLatitude / 0.000003;
        st->insGnss1.gnssAlt = structfly->GNSSAltitude / 0.01;
        st->insGnss1.gnssEastSpeed = structfly->GNSSEastToSpeed / 0.01;
        st->insGnss1.gnssNorthSpeed = structfly->GNSSNorthToSpeed / 0.01;
        st->insGnss1.gnssSkySpeed = structfly->GNSSHeavenToSpeed / 0.01;
        st->insGnss1.lon = structfly->Longtitude / 0.000003;
        st->insGnss1.lat = structfly->Latitude / 0.000003;
        st->insGnss1.alt = structfly->Altitude / 0.01;
        st->insGnss1.eastSpeed = structfly->EastToSpeed / 0.01;
        st->insGnss1.northSpeed = structfly->NorthToSpeed / 0.01;
        st->insGnss1.skySpeed = structfly->HeavenToSpeed / 0.01;
        st->insGnss1.axialAccSpeed = structfly->AxialAcceleration / 0.01;
        st->insGnss1.lateralAccSpeed = structfly->LateralAcceleration / 0.01;
        st->insGnss1.normalAccSpeed = structfly->NormalAcceleration / 0.01;
        st->insGnss1.yaw = structfly->YawAngle / 0.01;
        st->insGnss1.pitch = structfly->PitchAngle / 0.01;
        st->insGnss1.roll = structfly->RollAngle / 0.01;
        st->insGnss1.yawSpeed = structfly->YawRate / 0.02;
        st->insGnss1.pitchSpeed = structfly->PitchRate / 0.02;
        st->insGnss1.rollSpeed = structfly->RollRate / 0.02;
        st->insGnss1.windSpeed = structfly->WindSpeed / 0.02;
        st->insGnss1.windDirection = structfly->WindDirection / 0.01;
        st->insGnss1.gnssGroundSpeed = structfly->GNSSGroundSpeed / 0.02;
        st->insGnss1.gnssTrackAngle = structfly->GNSSTrackAngle / 0.01;
        st->insGnss1.yawErrorCorrection = structfly->CourseErrorCorrection / 0.01;
        st->insGnss1.pitchErrorCorrection = structfly->PitchErrorCorrection / 0.01;
        st->insGnss1.rollErrorCorrection = structfly->RollErrorCorrection / 0.01;
        //系统状态字    (待处理)
        st->insGnss1.gnssSysState = 0x7f3b;   //0x7f3b
        st->insGnss1.gnssSysError = 0;
        //系统版本      (待处理)
        st->insGnss1.gnssVersion = 0;
    }

    {
        st->insGnss2.gnssLon = structfly->GNSSLongtitude / 0.000003;
        st->insGnss2.gnssLat = structfly->GNSSLatitude / 0.000003;
        st->insGnss2.gnssAlt = structfly->GNSSAltitude / 0.01;
        st->insGnss2.gnssEastSpeed = structfly->GNSSEastToSpeed / 0.01;
        st->insGnss2.gnssNorthSpeed = structfly->GNSSNorthToSpeed / 0.01;
        st->insGnss2.gnssSkySpeed = structfly->GNSSHeavenToSpeed / 0.01;
        st->insGnss2.lon = structfly->Longtitude / 0.000003;
        st->insGnss2.lat = structfly->Latitude / 0.000003;
        st->insGnss2.alt = structfly->Altitude / 0.01;
        st->insGnss2.eastSpeed = structfly->EastToSpeed / 0.01;
        st->insGnss2.northSpeed = structfly->NorthToSpeed / 0.01;
        st->insGnss2.skySpeed = structfly->HeavenToSpeed / 0.01;
        st->insGnss2.axialAccSpeed = structfly->AxialAcceleration / 0.01;
        st->insGnss2.lateralAccSpeed = structfly->LateralAcceleration / 0.01;
        st->insGnss2.normalAccSpeed = structfly->NormalAcceleration / 0.01;
        st->insGnss2.yaw = structfly->YawAngle / 0.01;
        st->insGnss2.pitch = structfly->PitchAngle / 0.01;
        st->insGnss2.roll = structfly->RollAngle / 0.01;
        st->insGnss2.yawSpeed = structfly->YawRate / 0.02;
        st->insGnss2.pitchSpeed = structfly->PitchRate / 0.02;
        st->insGnss2.rollSpeed = structfly->RollRate / 0.02;
        st->insGnss2.windSpeed = structfly->WindSpeed / 0.02;
        st->insGnss2.windDirection = structfly->WindDirection / 0.01;
        st->insGnss2.gnssGroundSpeed = structfly->GNSSGroundSpeed / 0.02;
        st->insGnss2.gnssTrackAngle = structfly->GNSSTrackAngle / 0.01;
        st->insGnss2.yawErrorCorrection = structfly->CourseErrorCorrection / 0.01;
        st->insGnss2.pitchErrorCorrection = structfly->PitchErrorCorrection / 0.01;
        st->insGnss2.rollErrorCorrection = structfly->RollErrorCorrection / 0.01;
        //系统状态字    (待处理)
        st->insGnss2.gnssSysState = 0x7f3b;
        st->insGnss2.gnssSysError = 0;
        //系统版本     (待处理)
        st->insGnss2.gnssVersion = 0;
    }

    {
        st->adc1.aos = structfly->SideslipAngleAOS / 0.01;
        st->adc1.aoa = structfly->AttackAngleAOA / 0.01;
        st->adc1.vc = structfly->CalibratedAirspeedVc / 0.02;
        st->adc1.vt = structfly->VacuoSpeedVt / 0.02;
        st->adc1.mach = structfly->MachNumberM / 0.001;
        st->adc1.h = structfly->BarometricHeightH / 0.5;
        st->adc1.ts = structfly->StaticTempTs / 0.01;
        st->adc1.hpr = structfly->LiftingSpeedHPR / 0.01;
        st->adc1.tt = structfly->TotalTempTt / 0.01;
        st->adc1.hqne = structfly->StandardPressureAltitudeHQNE / 0.5;
        st->adc1.ps = structfly->StandardPressurePs / 0.002;
        st->adc1.pt = structfly->TotalPressurePt / 0.002;
        st->adc1.dataValid = 0x1fff;
        st->adc1.sysError = 0;
        //系统版本     (待处理)
        st->adc1.version = 0;
        //气压基准设定  (待处理)
        st->adc1.baroSet = 0;    //    / 0.01
        st->adc1.baroStd = 0x00;
    }

    {
        st->adc2.aos = structfly->SideslipAngleAOS / 0.01;
        st->adc2.aoa = structfly->AttackAngleAOA / 0.01;
        st->adc2.vc = structfly->CalibratedAirspeedVc / 0.02;
        st->adc2.vt = structfly->VacuoSpeedVt / 0.02;
        st->adc2.mach = structfly->MachNumberM / 0.001;
        st->adc2.h = structfly->BarometricHeightH / 0.5;
        st->adc2.ts = structfly->StaticTempTs / 0.01;
        st->adc2.hpr = structfly->LiftingSpeedHPR / 0.01;
        st->adc2.tt = structfly->TotalTempTt / 0.01;
        st->adc2.hqne = structfly->StandardPressureAltitudeHQNE / 0.5;
        st->adc2.ps = structfly->StandardPressurePs / 0.002;
        st->adc2.pt = structfly->TotalPressurePt / 0.002;
        st->adc2.dataValid = 0x1fff;
        st->adc2.sysError = 0;
        //系统版本     (待处理)
        st->adc2.version = 0;
        //气压基准设定  (待处理)
        st->adc2.baroSet = 0;  //   / 0.01
        st->adc2.baroStd = 0x00;
    }

    {
        st->cns.moduleState = 0xff;
         //VHF 状态        (待处理)
        st->cns.vhf1.state = 0xc0;    //
        st->cns.vhf1.frequency = 0;   //   / 0.001
        // 选呼码
        st->cns.vhf1.selcal = 0;
        // ADF状态
        st->cns.vhf2.state = 0xc0;
        st->cns.vhf2.frequency = 0;    //   / 0.001
        st->cns.vhf2.selcal = 0;

        st->cns.dme.state = 0xff;
        st->cns.dme.channel = structfly->DMECurrentChannelNumber;
        st->cns.dme.distance = structfly->DMEDistance / 0.01;
        st->cns.dme.groundSpeed = structfly->DMEGroundSpeed;
        st->cns.dme.time = structfly->DMEInTheTime;
        //DME站台识别码  (待处理)
        st->cns.dme.code = 0;

        st->cns.mmr.state = 0xff;
        //MMR当前频率  (待处理)
        st->cns.mmr.frequency = 0;   //   / 0.01
        st->cns.mmr.vorAzimuth = structfly->VORAzimuthAngle / 0.04395;
        st->cns.mmr.locDeviation = structfly->LOCDiviation / 0.4 * 2e-12;
        st->cns.mmr.gsDeviation = structfly->GSDiviation / 0.8 * 2e-12;
        //MMR台站识别码  (待处理)
        st->cns.mmr.code = 0;

        st->cns.xpdr.state = 0xfe;
        //SSR回传编码  (待处理)
        st->cns.xpdr.ssrCode = 0;

        st->cns.ra.state = 0x03;
        st->cns.ra.raHeight = structfly->RAAltitude / 0.1;

        st->cns.moduleError = 0;
        st->cns.reserve = 0;
    }

    {
        st->raBak.state = 0x03;
        st->raBak.raHeight = 0 / 0.1;
        st->raBak.reserve = 0;
    }

    {
        st->diu.diuError = 0;
        //DIU版本  (待处理)
        st->diu.diuVersion = 0;
        st->diu.fpgaVersion = 0;
    }

    {
        st->engineWarn.warnCode = 0xff;
        st->engineWarn.space = 0;
    }

    {
        st->dec.FuelFlow = 0;  //单位   / (1/64)
        st->dec.EngineFailure = 0x01;
        st->dec.EngineOilPressure = 0 ;   //    / (1/1024)
        st->dec.EngineOilTemp = 0;     //    / (1/128)
        st->dec.ExhaustGasTemp = 0;    //    / (1/16)
        st->dec.GasGeneratorSpeed = 0;  //    / (1/226)
        st->dec.OilChipDetection = 0X01;
        st->dec.OilFilterClogged = 0X01;
        st->dec.PROP = 0;    //    / (1/8)
        st->dec.TORQ = 0;   // / 0.00667%
        st->dec.POWERSET = 0;   //    / (1/256)
        st->dec.EnginePower = 0;  //    / (1/16)
        st->dec.ManCtrl = 0X01;
        st->dec.VibrDng = 0X01;
        st->dec.Aileron = 0;
        st->dec.RHPUMPON = 0X01;
        st->dec.PWR_RETARD = 0X01;
        st->dec.RUN = 0X01;
        st->dec.PL = 0;
        st->dec.CHIPT = 0X01;
        st->dec.REVERSE = 0X01;
        st->dec.EventReg = 0X01;
        st->dec.FailReg = 0X01;
        st->dec.MaintLvl_1 = 0X01;
        st->dec.MaintLvl_2 = 0X01;
        st->dec.MaintLvl_3 = 0X01;
        st->dec.VibrHigh = 0X01;
        st->dec.PwrLimit = 0X01;
    }

    {
        st->bat1.Battery1_voltage = 6000;  //    /  0.001953125
        st->bat1.Battery1_current = 200;   //    /  0.125
        st->bat1.Bat1_Failure = 0;
        st->bat1.Bat1_Charge = 0;    //   /  0.0625
    }

    {
        st->bat2.Battery2_voltage = 5000;   //    /  0.001953125
        st->bat2.Battery2_current = 200;    //    /  0.125
        st->bat2.Bat2_Failure = 0;
        st->bat2.Bat2_Charge = 0;     //   / 0.0625
    }

    {
        st->dcu1.FPUMPB = 0x01;
        st->dcu1.EsntlBusV = 0;     //  / 0.1
        st->dcu1.FPRESS = 0x01;
        st->dcu1.FXFERLH = 0x01;
        st->dcu1.AUXPON = 0x01;
        st->dcu1.Gen_1_Load = 0;
        st->dcu1.PropPitch = 0x01;
        st->dcu1.HiLoadBus = 0x01;
        st->dcu1.LWing = 0;  //  / 0.1  99.9=Disconnected
        st->dcu1.GEN1V = 0;   //  /0.1
        st->dcu1.BusTies = 0x01;
        st->dcu1.CENTER = 0;   //  / 0.1    29.9=Disconnected
        st->dcu1.FUEL_P = 0;   //   / 0.001
        st->dcu1.FXFERRH = 0x01;
        st->dcu1.RWing = 0;   //   /0.1   99.9=Disconnected
        st->dcu1.FuelFilt = 0x01;
        st->dcu1.ExtPwr = 0x01;
        st->dcu1.F_Temp = 182;  // 285：Full Down   182：Center    49：Full Up
        st->dcu1.N_EsntlBus = 0x01;
        st->dcu1.Elevator = 0;
        st->dcu1.F_Punp_A = 0x01;
        st->dcu1.Aero_F_Low = 0x01;
        st->dcu1.Canopy = 0x01;
        st->dcu1.RefDiode = 0;
        int8_t wow = 0;
        if(structfly->FrontWheelLoadSignal)
            wow += 0x01;
        if(structfly->LeftWheelLoadSignal)
            wow += 0x01;
        if(structfly->RightWheelLoadSignal)
            wow += 0x04;
        st->dcu1.wowState = wow;
        st->dcu1.wingAngle = structfly->TheFlapsPosition;
        st->dcu1.FUELLOW  = 0x01;
    }

    {
        st->dcu2.Bat_2_Fail = 0x01;
        st->dcu2.Bat_1_Maint = 0x01;
        st->dcu2.N_Esntl_Bus_V = 0;   //  / 0.1
        st->dcu2.Gen_2_Fail = 0x01;
        st->dcu2.Gen_1_Off = 0x01;
        st->dcu2.Gen_2_L = 0;
        st->dcu2.Eng_Boost = 0x01;
        st->dcu2.Gen_2_Off = 0x01;
        st->dcu2.PropInlet = 0x01;
        st->dcu2.AvBus = 0x01;
        st->dcu2.Inert_P_Sep = 0x01;
        st->dcu2.Gen_1_Fail = 0x01;
        st->dcu2.DeIce = 0x01;
        st->dcu2.Bat_2_Maint = 0x01;
        st->dcu2.Gen_2_V = 0;      //     / 0.1
        st->dcu2.PitotHt = 0x01;
        st->dcu2.RUDDER = 108;        //55：Full Left  108：Neutral     160：Full Right
        st->dcu2.Bat_1_Heater = 0x01;
        st->dcu2.Starter = 0x01;
        st->dcu2.Eject_S_R = 0x01;
        st->dcu2.RefDiode = 0;
        st->dcu2.Bat_1_Fail = 0x01;
        st->dcu2.Eject_S_F = 0x01;
        st->dcu2.RefDiode = 0;
        int8_t land = 0;
        if(structfly->LeftUndercarriageCondition)
            land += 0x01;
        else
            land += 0x01;
        if(structfly->FrontUndercarriageCondition)
            land += 0x04;
        else
            land += 0x08;
        if(structfly->RightUndercarriageCondition)
            land += 0x16;
        else
            land += 0x32;
        st->dcu2.LandingGearStatus = land;
    }

    {
        st->hud.hudError1 = 0;
        st->hud.hudError2 = 0;
    }
    //(待处理)
    {

        st->version.duVersion = 0;
        st->version.decVersion = 0;
        st->version.bat1Version = 0;
        st->version.bat2Version = 0;
        st->version.dcu1Version = 0;
        st->version.dcu2Version = 0;
    }
}


