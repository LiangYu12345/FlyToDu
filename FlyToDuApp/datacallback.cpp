#include "datacallback.h"
#include <packetutility.h>

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
        PacketDecoder decoder(datagram.data());
        const FS_HudPeriod * structfly = decoder.popStruct<FS_HudPeriod>();

        flag ^= 0x01;

        dealFlyHudData(structfly);
    }
    else if(datagram.topic() == "DDS_TOPIC_DU_SEND"){
        PacketDecoder decoder(datagram.data());
        const FS_DU * structfly = decoder.popStruct<FS_DU>();

        flag ^= 0x02;

        dealFlyDuData(structfly);
    }

    sendState();
}

void DataCallback::sendState(){

    if(flag == 0x03)
    {
        scheduler()->getUDPNetwork()->writeDatagram(stPayload, QHostAddress("192.168.3.200"), 5001);
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
            wow += 0x02;
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
            land += 0x02;
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
        st->insGnss1.gnssSysState = 0;
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
        st->insGnss2.gnssSysState = 0;
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
        st->adc1.baroSet = 0 / 0.01;
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
        st->adc2.baroSet = 0 / 0.01;
        st->adc2.baroStd = 0x00;
    }

    {
        st->cns.moduleState = 0xff;
         //VHF         (待处理)
        st->cns.vhf1.state = 0;
        st->cns.vhf1.frequency = 0 / 0.001;
        st->cns.vhf1.selcal = 0;
        st->cns.vhf2.state = 0;
        st->cns.vhf2.frequency = 0 / 0.001;
        st->cns.vhf2.selcal = 0;

        st->cns.dme.state = 0;
        st->cns.dme.channel = structfly->DMECurrentChannelNumber;
        st->cns.dme.distance = structfly->DMEDistance / 0.01;
        st->cns.dme.groundSpeed = structfly->DMEGroundSpeed;
        st->cns.dme.time = structfly->DMEInTheTime;
        //DME站台识别码  (待处理)
        st->cns.dme.code = 0;

        st->cns.mmr.state = 0xff;
        //MMR当前频率  (待处理)
        st->cns.mmr.frequency = 0 / 0.01;
        st->cns.mmr.vorAzimuth = structfly->VORAzimuthAngle / 0.04395;
        st->cns.mmr.locDeviation = structfly->LOCDiviation / 0.4 * 2e-12;
        st->cns.mmr.gsDeviation = structfly->GSDiviation / 0.8 * 2e-12;
        //MMR台站识别码  (待处理)
        st->cns.mmr.code = 0;

        st->cns.xpdr.state = 0xff;
        //SSR编码  (待处理)
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
        st->dec.FuelFlow = 0 ;  //单位   / (1/64)
        st->dec.EngineFailure = 0x02;
        st->dec.EngineOilPressure = 0 ;   //    / (1/1024)
        st->dec.EngineOilTemp = 0;     //    / (1/128)
        st->dec.ExhaustGasTemp = 0;    //    / (1/16)
        st->dec.GasGeneratorSpeed = 0;  //    / (1/226)
        st->dec.OilChipDetection = 0X02;
        st->dec.OilFilterClogged = 0X02;
        st->dec.PROP = 0;    //    / (1/8)
        st->dec.TORQ = 0;   // / 0.00667%
        st->dec.POWERSET = 0;   //    / (1/256)
        st->dec.EnginePower = 0;  //    / (1/16)
        st->dec.ManCtrl = 0X02;
        st->dec.VibrDng = 0X02;
        st->dec.Aileron = 0;
        st->dec.RHPUMPON = 0X02;
        st->dec.PWR_RETARD = 0X02;
        st->dec.RUN = 0X02;
        st->dec.PL = 0;
        st->dec.CHIPT = 0X02;
        st->dec.REVERSE = 0X02;
        st->dec.EventReg = 0X02;
        st->dec.FailReg = 0X02;
        st->dec.MaintLvl_1 = 0X02;
        st->dec.MaintLvl_2 = 0X02;
        st->dec.MaintLvl_3 = 0X02;
        st->dec.VibrHigh = 0X02;
        st->dec.PwrLimit = 0X02;
    }

    {
        st->bat1.Battery1_voltage = 0;  //    /  0.001953125
        st->bat1.Battery1_current = 0;   //    /  0.125
        st->bat1.Bat1_Failure = 0;
        st->bat1.Bat1_Charge = 0;    //   /  0.0625
    }

    {
        st->bat2.Battery2_voltage = 0;   //    /  0.001953125
        st->bat2.Battery2_current = 0;    //    /  0.125
        st->bat2.Bat2_Failure = 0;
        st->bat2.Bat2_Charge = 0;     //   / 0.0625
    }

    {
        st->dcu1.FPUMPB = 0x02;
        st->dcu1.EsntlBusV = 0;     //  / 0.1
        st->dcu1.FPRESS = 0x02;
        st->dcu1.FXFERLH = 0x02;
        st->dcu1.AUXPON = 0x02;
        st->dcu1.Gen_1_Load = 0;
        st->dcu1.PropPitch = 0x02;
        st->dcu1.HiLoadBus = 0x02;
        st->dcu1.LWing = 0;  //  / 0.1  99.9=Disconnected
        st->dcu1.GEN1V = 0;   //  /0.1
        st->dcu1.BusTies = 0x02;
        st->dcu1.CENTER = 0;   //  / 0.1    29.9=Disconnected
        st->dcu1.FUEL_P = 0;   //   / 0.001
        st->dcu1.FXFERRH = 0x02;
        st->dcu1.RWing = 0;   //   /0.1   99.9=Disconnected
        st->dcu1.FuelFilt = 0x02;
        st->dcu1.ExtPwr = 0x02;
        st->dcu1.F_Temp = 182;  // 285：Full Down   182：Center    49：Full Up
        st->dcu1.N_EsntlBus = 0x02;
        st->dcu1.Elevator = 0;
        st->dcu1.F_Punp_A = 0x02;
        st->dcu1.Aero_F_Low = 0x02;
        st->dcu1.Canopy = 0x02;
        st->dcu1.RefDiode = 0;
        int8_t wow = 0;
        if(structfly->FrontWheelLoadSignal)
            wow += 0x01;
        if(structfly->LeftWheelLoadSignal)
            wow += 0x02;
        if(structfly->RightWheelLoadSignal)
            wow += 0x04;
        st->dcu1.wowState = wow;
        st->dcu1.wingAngle = structfly->TheFlapsPosition;
        st->dcu1.FUELLOW  = 0x02;
    }

    {
        st->dcu2.Bat_2_Fail = 0x02;
        st->dcu2.Bat_1_Maint = 0x02;
        st->dcu2.N_Esntl_Bus_V = 0;   //  / 0.1
        st->dcu2.Gen_2_Fail = 0x02;
        st->dcu2.Gen_1_Off = 0x02;
        st->dcu2.Gen_2_L = 0;
        st->dcu2.Eng_Boost = 0x02;
        st->dcu2.Gen_2_Off = 0x02;
        st->dcu2.PropInlet = 0x02;
        st->dcu2.AvBus = 0x02;
        st->dcu2.Inert_P_Sep = 0x02;
        st->dcu2.Gen_1_Fail = 0x02;
        st->dcu2.DeIce = 0x02;
        st->dcu2.Bat_2_Maint = 0x02;
        st->dcu2.Gen_2_V = 0;      //     / 0.1
        st->dcu2.PitotHt = 0x02;
        st->dcu2.RUDDER = 108;        //55：Full Left  108：Neutral     160：Full Right
        st->dcu2.Bat_1_Heater = 0x02;
        st->dcu2.Starter = 0x02;
        st->dcu2.Eject_S_R = 0x02;
        st->dcu2.RefDiode = 0;
        st->dcu2.Bat_1_Fail = 0x02;
        st->dcu2.Eject_S_F = 0x02;
        st->dcu2.RefDiode = 0;
        int8_t land = 0;
        if(structfly->LeftUndercarriageCondition)
            land += 0x01;
        else
            land += 0x02;
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

    st->crc16 = 0;
}
