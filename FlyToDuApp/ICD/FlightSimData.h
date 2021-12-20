#pragma once
#pragma  pack (1)
// DDS_TOPIC_HUD_PERIOD_SEND
struct FS_HudPeriod
{
	float SideslipAngle;//侧滑角 *100
	float AttackAngle;//攻角 *100
	float CurrentAirSpeed;//当前空速 *50
	float VacuoSpeed;//真空速 *50
	float CurrentMachNumber;//当前马赫数 *1000
	float PressueAltitude;//显示气压高度
	float AmbientTemperature;//机外温度
	float CurrentVerticalSpeed;//当前垂直速度
	float CourseBeaconDeviation;//航向信标偏离(LOC)
	float GlidePathDeviation;//下滑道偏离（GS)
	float RadioAltitude;//无线电高度
	float FrontWheelLoadSignal;//轮载信号（WOW）前轮有无轮载
	float LeftWheelLoadSignal;//轮载信号（WOW）左轮有无轮载
	float RightWheelLoadSignal;//轮载信号（WOW）右轮有无轮载
	float FrontUndercarriageCondition;//起落架状态 前轮收起/放下
	float LeftUndercarriageCondition;//起落架状态 左轮收起/放下
	float RightUndercarriageCondition;//起落架状态 右轮收起/放下
	float TheFlapsPosition;//襟翼位置
	float StallingSpeed;//失速速度
	float ChannelOff;//航道偏离
	float DecisionAltitude;//决断高度
	float TrueHeading;//真航向
	float PitchAngle;//俯仰角
	float RollAngle;//横滚角
	float GroundSpeed;//地速
	float WindSpeed;//风速		
	float WindDirection;//风向
};

// DDS_TOPIC_DU_SEND
struct FS_DU
{
	double GNSSLongtitude;//GNSS经度
	double GNSSLatitude;//GNSS纬度
	double GNSSAltitude;//GNSS高度
	float GNSSEastToSpeed;//GNSS东向速度
	float GNSSNorthToSpeed;//GNSS北向速度
	float GNSSHeavenToSpeed;//GNSS天向速度
	double Longtitude;//经度
	double Latitude;//纬度
	double Altitude;//高度
	float EastToSpeed;//东向速度

	float NorthToSpeed;//北向速度
	float HeavenToSpeed;//天向速度
	float AxialAcceleration;//轴向加速度
	float LateralAcceleration;//侧向加速度
	float NormalAcceleration;//法向加速度
	float YawAngle;//偏航角
	float PitchAngle;//俯仰角
	float RollAngle;//横滚角
	float YawRate;//偏航角速度
	float PitchRate;//俯仰角速度

	float RollRate;//滚转角速度
	float WindSpeed;//风速
	float WindDirection;//风向
	float GNSSGroundSpeed;//GNSS地速
	float GNSSTrackAngle;//GNSS航迹角
	float CourseErrorCorrection;//航向误差修正量	
	float PitchErrorCorrection;//俯仰误差修正量
	float RollErrorCorrection;//横滚误差修正量
	float SideslipAngleAOS;//侧滑角AOS
	float AttackAngleAOA;//攻角AOA

	float CalibratedAirspeedVc;//校准空速Vc
	float VacuoSpeedVt;//真空速Vt
	float MachNumberM;//马赫数M
	float BarometricHeightH;//显示气压高度H
	float StaticTempTs;//静温Ts
	float LiftingSpeedHPR;//升降速度HPR
	float TotalTempTt;//总温Tt
	float StandardPressureAltitudeHQNE;//标准气压高度HQNE
	float StandardPressurePs;//静压Ps	
	float TotalPressurePt;//全压Pt

	float DMECurrentChannelNumber;//DME当前波道号
	float DMEDistance;//DME距离
	float DMEGroundSpeed;//DME地速
	float DMEInTheTime;//DME到台时间
	float VORAzimuthAngle;//VOR方位角
	float LOCDiviation;//LOC偏差
	float GSDiviation;//GS偏差
	float RAAltitude;//RA高度
	float FrontWheelLoadSignal;//轮载信号（WOW）前轮有无轮载
	float LeftWheelLoadSignal;//轮载信号（WOW）左轮有无轮载

	float RightWheelLoadSignal;//轮载信号（WOW）右轮有无轮载
	float FrontUndercarriageCondition;//起落架状态 前轮收起/放下
	float LeftUndercarriageCondition;//起落架状态 左轮收起/放下
	float RightUndercarriageCondition;//起落架状态 右轮收起/放下
	float TheFlapsPosition;//襟翼位置	
	float AmbientTemperature;//机外温度OAT(Ch8 Temp)
	float N1;//N1(Ch 1 RPM)
	float PROP;//PROP(Ch 2 RPM)
	float RWing;//R Wing (Ch2 Fuel Level)
	float Elevator;//Elevator (Ch6 Pressure)	

	float PWR;//PWR (Ch14 Temp)
	float OILT;//OIL T (Ch2 Temp)
	float LWing;//L Wing (Ch1 Fuel Level)
	float Aileron;//Aileron (Ch5 Pressure)
	float EGT;//EGT(Ch1 Temp)
	float CENTER;//CENTER (Ch3 Fuel Level)
	float RUDDER;//RUDDER (Ch4 Pressure)
	float OILP;//OIL P (Ch3 Pressure)
	float FUELP;//FUEL P (Ch2 Pressure)
	float TORQ;//TORQ          (Ch1 Pressure)
	float FuelFlow;//Fuel Flow
};

//初始化HUD数据
struct ST_HUD_INIT_DATA
{
	unsigned char packageType;		//数据包类型
	unsigned char cycleCount;		//循环计数
	unsigned char dataValidity;		//数据有效性
	unsigned short VFE;				//最大襟翼操作速度
	unsigned short VMO;				//最大正常操作速度
	unsigned short VMax;			//最大演示操作速度
	unsigned short VS;				//失速速度Vs
	unsigned short minPressureAlt;	//最低气压高度
	unsigned short VSO;				//失速速度Vso
	unsigned short VD;				//最大俯冲速度Vd
	unsigned char checksum;			//校验和
};
#pragma  pack()
