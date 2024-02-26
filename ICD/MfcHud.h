#pragma once
#pragma pack(push)
#pragma pack(1)

#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

// 任务遥测参数
struct missionTelemety{
	Z_U8 head1;         //头字 05
	Z_U8 head2;         //头字 0F
	Z_U8 flyCommand;    //飞控指令编码 00~FF
	Z_U8 weaponCommand; //武器指令编码 00~FF
	Z_U8 scoutCommand;  //侦察指令编码 00~FF
	Z_U8 missionInject; //任务注入数据类型 00~FF
	Z_U8 injectData;    //注入数据包号 00~FF
	Z_U8 injectDataCheck;  //注入数据校验和 00~FF
	Z_U16 missionCheck;  //任务总线设备自检状态 0000~FFFF
	Z_U16 missionStatu1;  //任务总线设备状态字1 0000~FFFF
	Z_U16 missionStatu2;  //任务总线设备状态字2 0000~FFFF
	Z_U16 missionStatu3;  //任务总线设备状态字3 0000~FFFF
	Z_U16 missionRes1;  //遥控指令执行结果字1 0000~FFFF
	Z_U16 missionRes2;  //遥控指令执行结果字2 0000~FFFF
	Z_U16 missionRes3;  //遥控指令执行结果字3 0000~FFFF
	Z_U16 missionRes4;  //遥控指令执行结果字4 0000~FFFF
	Z_U16 missionRes5;  //遥控指令执行结果字5 0000~FFFF
	Z_U16 weaponStatu1;  //武器1状态码 0000~FFFF
	Z_U16 weaponStatu2;  //武器2状态码 0000~FFFF
	Z_U16 avionicsErr1;  //航电错误码1 0000~FFFF
	Z_U16 avionicsErr2;  //航电错误码2 0000~FFFF
	Z_U16 missionRes6;  //遥控指令执行结果字6 0000~FFFF
    Z_U16 checksum;  //校验和 00~FF
	
	CONSTRUCT(missionTelemety);
};

// 飞控遥测参数
struct flyTelemety{
	Z_U8 head1;         //头字 6A
	Z_U8 head2;         //头字 01
	Z_U32 systemTime;    //系统时间(s) 0~86400
	Z_I16 lateralDeviation; //横偏差（m） -32000～32000
	Z_U16 indicatedAirspeed;  //滤波后指示空速(m/s) 0~340
	Z_I16 pressureAltitude; //组合气压高度(m) -400~20000
	Z_I32 lon;    	//组合经度（°） -180~180
	Z_I32 lat;  	//组合纬度（°） -90~90
	Z_I16 alt;		//组合卫星高度(m) -400~25000
	Z_U16 rarAltitude;  //组合无线电高度(m) 0~6000
	Z_I16 verticalAcc;  //垂向加速度(m/s^2) -200~200
	Z_I16 groundSpeed;  //组合地速（低通滤波后）(m/s)-320~320
	Z_U16 yaw;  //真航向角（°）0~360
	Z_I16 pitch;  //俯仰角（°）-90~90
	Z_I16 roll;  //滚动角（°）-180~180
	Z_U8 leftBrake;  //左刹车量 0～100
	Z_U8 rightBrake;  //右刹车量 0~100
	Z_U16 flightControlStatu;  //飞控系统状态字 0000~FFFF
	Z_U16 lowPressureRotor;  //低压转子转速N1（rpm）0 ~19000
	Z_U16 highPressureRotor;  //高压转子转速N2（rpm）0 ~45320
	Z_U16 ittTemperature;  //ITT温度（℃）-65~1100
	Z_U8 flightControlCode;  //飞控指令编码 00~FF
	Z_U8 flightControlCmd1;  //飞控指令参数1 00~FF
	Z_U8 flightControlCmd2;	//飞控指令参数2 00~FF
	Z_U8 injectDataType;	//注入数据类型 00~FF
	Z_U8 undercart;	//起落架下到位综合 00~FF
	Z_U8 packetSequence ;	//包序包号 00~FF
	Z_U8 busbarVoltage;	//母线电压（V）0~48
	Z_U8 engineVoltage;	//发动机电压（V）0~48
	Z_U8 cellVoltage2;	//电池2电压（V）0~30
	Z_U8 cellVoltage1;	//电池1电压（V）0~30
	Z_U16 remainL;	//剩余油量（kg）0~3000
	Z_U16 flyStatu;	//无人机飞行状态字 0000~FFFF
	Z_U16 sysWorkStatu;	//惯导/航姿系统工作状态字 0000~FFFF
	Z_U16 navWorkStatu;	//惯导/航姿导航方式状态字 0000~FFFF
	Z_U16 checksum;  //校验和 0000~FFFF
	
	CONSTRUCT(flyTelemety);
};

/*
测控遥测
*/
struct measureControl{
    Z_U8 reserve[34];
	
	CONSTRUCT(measureControl);
};

/*
包名称：小遥测数据包
*/
struct MayData
{
    Z_U8	fix1 = 0x55;
    Z_U8    fix2 = 0xAA;
    Z_U8	fix3 = 0x88;
    struct missionTelemety mT;
    struct flyTelemety fT;
    struct measureControl mC;
	Z_U8   checksum;
    CONSTRUCT(MayData);
};


/*
包名称：飞控大遥测数据
*/
struct flyBigTelemety
{
    Z_U8  fixValue1 = 0x55;    //固定值 55
    Z_U8  fixValue2 = 0xAA;    //固定值 AA
	Z_U8  fixValue3 = 0x84;    //固定值 84
	Z_U8 type = 0x22;  		//数据类型	22
	Z_I16 rollingVelocity;  //滚动角速度程序信号（°/s）-50~50
	Z_U8 wrollingVelocity;           //W滚动角速度程序信号（°/s）
	Z_I16 northboundVelocity;		//组合北向速度(m/s) [-320,320]
    Z_U8 wnorthboundVelocity;           //W组合北向速度(m/s)
	Z_I16 eastboundVelocity;		//组合东向速度(m/s)[-320,320]
	Z_U8 weastboundVelocity;           //W组合东向速度(m/s)
	Z_I16 yOverride;		//沿机体系Y向过载 [-10,10]
	Z_U8 wyOverride;           //W沿机体系Y向过载
	Z_I16 xOverride;		//沿机体系X向过载 [-10,10]
	Z_U8 wxOverride;           //W沿机体系X向过载
	Z_I16 zOverride;		//沿机体系Z向过载 [-10,10]
	Z_U8 wzOverride;           //W沿机体系Z向过载
	Z_U16 indicatedAirspeed;		//指示空速（主大气静压修正后）(m/s)0~340
	Z_U8 windicatedAirspeed;           //W指示空速（主大气静压修正后）(m/s)
	Z_U16 mach;		//马赫数（主大气静压修正后）0.0~1.0
	Z_U8 wmach;     //W马赫数（主大气静压修正后）
    Z_U16 throttleVoltage;		//油门电压(V)1~8
    Z_U8 wthrottleVoltage;     //W油门电压(V)
	Z_I8 elevatorPressure;		//升降舵综合舵控电压(V)[-10，+10]
	Z_U8 welevatorPressure;     //W升降舵综合舵控电压
	Z_I8 rudderPressure;		//方向舵综合舵控电压(V)[-10，+10]
	Z_U8 wrudderPressure;       //W方向舵综合舵控电压
	Z_I8 aileronPressure;		//副翼综合舵控电压(V)[-10，+10]
	Z_U8 waileronPressure;      //W副翼综合舵控电压
	Z_U16 redundancy; 			//当前使用余度设备 0000~FFFF
	Z_U8 wredundancy; 			//w当前使用余度设备
	Z_I16 barometricRate;		//组合气压升降速率(m/s) -300~300
	Z_U8 wbarometricRate;       //W组合气压升降速率(m/s)
	Z_I16 radioRate;		//组合无线电升降速率(m/s)-300~300
	Z_U8 wradioRate;       //W组合无线电升降速率(m/s)
	Z_U8 expectedSpeed;		//期望速度(m/s)0~255
	Z_U8 wexpectedSpeed;       //W期望速度(m/s)
	Z_U8 curWaypointNum;		//当前航线编号 00~FF
	Z_U8 wcurWaypointNum;       //W当前航线编号
	Z_U8 curNavpointNum;		//当前导航点序号 0~255
	Z_U8 wcurNavpointNum;       //W当前导航点序号
	Z_I16 disNextNavpoint;		//距下一导航点距离(km)-1000~1000
	Z_U8 wdisNextNavpoint;       //W距下一导航点距离(km)
	Z_U16 expectedyaw;		//期望航向（°）[0,360）
	Z_U8 wexpectedyaw;       //W期望航向（°）
	Z_I16 expectedAlt;		//期望高度(m)-400~20000
	Z_U8 wexpectedAlt;       //W期望高度
	Z_I16 altitudeIntercept;		//高度差(m)-1000~1000
	Z_U8 waltitudeIntercept;       //W高度差
	Z_U16 yawTrail;		//航迹方位角(°)[0,360）
	Z_U8 wyawTrail;       //W航迹方位角
	Z_U16 turningDistance;		//提前转弯距离(km) 0~40
	Z_U8 wturningDistance;       //W提前转弯距离(km)
	Z_U16 crudingRange;		//三维航程(km)0~20000
	Z_U8 wcrudingRange;       //W三维航程(km)
	Z_U16 checkResHigh;		//飞控自检结果字（高字）0000~FFFFH
	Z_U16 checkResLow;       //飞控自检结果字（低字）0000~FFFFH
	Z_U16 wcheckResHigh;		//W飞控自检结果字高
	Z_U16 wcheckResLow;       //W飞控自检结果字低
    Z_I16 pitch;		//俯仰角程序信号（°）-15~25
    Z_U8 wpitch;       //W俯仰角程序信号（°）
    Z_I16 rool;		//滚动角程序信号（°）-35~35
    Z_U8 wrool;       //W滚动角程序信号（°）
    Z_U16 cmdRes;		//遥控指令执行结果字0000~FFFF
    Z_U16 workStatu;       //工作流程状态字0000~FFFF
    Z_U16 communicationError;		//通信故障字 0000~FFFFH
    Z_I8 flapPressure;       //襟翼综合舵控电压(V)-10~10
    Z_I8 wflapPressure;		//W襟翼综合舵控电压
    Z_U8 leftPressure;       //正常左压力0~100
    Z_U8 wleftPressure;		 //W正常左压力
    Z_U8 rightPressure;      //正常右压力0~100
    Z_U8 wrightPressure;	 //W正常右压力
    Z_I8 rudderControl1;       //1舵控电压 -10~10
    Z_I8 rudderControl2;       //2舵控电压 -10~10
    Z_I8 rudderControl3;       //3舵控电压 -10~10
    Z_I8 rudderControl4;       //4舵控电压 -10~10
    Z_I8 rudderControl5;       //5舵控电压 -10~10
    Z_I8 rudderControl6;       //6舵控电压 -10~10
    Z_I8 rudderControl7;       //7舵控电压 -10~10
    Z_I8 rudderControl8;       //8舵控电压 -10~10
    Z_I8 feedbackPressure1;       //1舵反馈电压 -12~12
    Z_I8 feedbackPressure2;       //2舵反馈电压 -12~12
    Z_I8 feedbackPressure3;       //3舵反馈电压 -12~12
    Z_I8 feedbackPressure4;       //4舵反馈电压 -12~12
    Z_I8 feedbackPressure5;       //5舵反馈电压 -12~12
    Z_I8 feedbackPressure6;       //6舵反馈电压 -12~12
    Z_I8 feedbackPressure7;       //7舵反馈电压 -12~12
    Z_I8 feedbackPressure8;       //8舵反馈电压 -12~12
    Z_I16 relativeAltitude;       //卫星相对高度 -400-20000
    Z_I16 attackAngle;       //攻角（°） -30~30
    Z_I16 sideslipAngle;       //侧滑角（°） -30~30
	
    Z_U8 reserve1[25];      //备用 23	uint8 / 置零
    Z_U8 checkSum;          //

    CONSTRUCT(flyBigTelemety);
};

/*
包名称：任务大遥数据
*/
struct RudderFly
{
	Z_U8  fixValue1 = 0x55;    //固定值 55
    Z_U8  fixValue2 = 0xAA;    //固定值 AA
	Z_U8  fixValue3 = 0x52;    //固定值 52
	Z_U8 type = 0x33;  		//数据类型	33
	
	Z_U16 modelA;        //本机A模式代码
	Z_U8 wmodelA;        //W本机A模式代码
	Z_U8 modelS1;        //本机S模式地址1
	Z_U8 modelS2;        //本机S模式地址2
	Z_U8 modelS3;        //本机S模式地址3
	Z_U8 wmodelS;        //W本机S模式地址
	Z_U8 identity1;        //本机身份字符1
	Z_U8 identity2;        //本机身份字符2
	Z_U8 identity3;        //本机身份字符3
	Z_U8 identity4;        //本机身份字符4
	Z_U8 identity5;        //本机身份字符5
	Z_U8 identity6;        //本机身份字符6
	Z_U8 identity7;        //本机身份字符7
	Z_U8 identity8;        //本机身份字符8
	Z_U8 widentity;        //W本机身份字符
	Z_U8 workStatu1;        //应答机工作状态字1
	Z_U8 wworkStatu1;        //w应答机工作状态字1
	Z_U8 workStatu2;        //应答机工作状态字2
	Z_U8 wworkStatu2;        //w应答机工作状态字2
	Z_U8 workStatu3;        //应答机工作状态字3
	Z_U8 wworkStatu3;        //w应答机工作状态字3
	Z_U16 leftMisEror1;        //左1导弹故障信息
	Z_U8 wleftMisEror1;        //w左1导弹故障信息
	Z_U16 rightMisEror1;        //右1导弹故障信息
	Z_U8 wrightMisEror1;        //w右1导弹故障信息
	Z_U16 leftMisEror2;        //左2导弹故障信息
	Z_U8 wleftMisEror2;        //w左2导弹故障信息
	Z_U16 rightMisEror2;        //右2导弹故障信息
	Z_U8 wrightMisEror2;        //w右2导弹故障信息
	Z_U16 misfire1;        //左1/右1导弹发射标志字
	Z_U8 wmisfire1;        //W左1/右1导弹发射标志字
	Z_U16 misfire2;        //左2/右2导弹发射标志字
	Z_U8 wmisfire2;        //w左2/右2导弹发射标志字

	Z_U8 weaponCtl1;        //武器/中继载荷控制指令1
	Z_U8 weaponCtl2;        //武器/中继载荷控制指令2
	Z_U8 weaponCtl3;        //武器/中继载荷控制指令3
	Z_U8 injectType;        //注入数据类型
	Z_U8 packageSequence;        //包序及包号定义
	Z_U16 leftMisEror1Mes;        //左1导弹故障信息 00~FFFFH
	Z_U16 rightMisEror1Mes;        //右1导弹故障信息 00~FFFFH
	Z_U16 leftMisEror2Mes;        //左2导弹故障信息 00~FFFFH
	Z_U16 rightMisEror2Mes;        //右2导弹故障信息 00~FFFFH
	Z_U8 SSPC9;        //二次配电装置II的SSPC9 00~FFH
	Z_U8 SSPC10;        //二次配电装置II的SSPC10 00~FFH
	Z_U8 SSPC11;        //二次配电装置II的SSPC11 00~FFH
	Z_U8 SSPC12;        //二次配电装置II的SSPC12 00~FFH
	Z_U16 SSPC13;
	Z_U16 SSPC14;
	
    Z_U8 reserve1[20];      //备用 20	uint8 / 置零
	Z_U8 checkSum;          //
    CONSTRUCT(RudderFly);
};

/*
包名称：专业数据遥测数据
*/
struct ProfessionalData
{
	Z_U8  fixValue1 = 0x55;    //固定值 55
    Z_U8  fixValue2 = 0xAA;    //固定值 AA
	Z_U8  fixValue3 = 0x2F;    //固定值 2F
	Z_U8 type = 0x44;  		//数据类型	44
	Z_I16 celestialVelocity;        //组合天向速度m/s[-300.00, 300.00]
	Z_U8 wcelestialVelocity; // W组合天向速度m/s
    Z_I32 diffAlt;        //差分组合高度m [-300,30000]
	Z_U8 wdiffAlt; 			// W差分组合高度m
	Z_U16 staticPressure;        //静压kpa 1.7~110
	Z_U8 wstaticPressure; 		// W静压
	Z_U16 fullPressure;        	//全压kpa 1.7~250
	Z_U8 wfullPressure; 		// W全压kpa
	Z_U16 turbineTemperature;   	 //涡轮级间温度ITT(℃) -65~1100
	Z_U8 wturbineTemperature; 		// W涡轮级间温度ITT(℃)
	Z_U16 inletAirTemperature;        //进口气流总温TT2(℃) -65~94
	Z_U8 winletAirTemperature; 		// W进口气流总温TT2(℃)
	Z_U16 fuelFlowCtrl;        			//燃油流量控制信号Uy(V) 0~8
	Z_U8 wfuelFlowCtrl; 				// W燃油流量控制信号Uy(V)
	Z_U16 dutyCycleVoltage;        //占空比电压U8t(V) -6.0~6.0
	Z_U8 wdutyCycleVoltage; 		// W占空比电压U8t(V)
	Z_U16 fuelFlowOrder;        //燃油流量指令(kg/h) 20 ~700
	Z_U8 wfuelFlowOrder; 		// W燃油流量指令(kg/h)
	Z_U16 u5tucmd;        //U5tu-cmd -6.5~6.5
	Z_U8 wu5tucmd; 		// WU5tu-cmd
	Z_U16 uq;        //uq  -1.0~1.0
	Z_U8 wuq; 		// Wuq
	Z_U16 generatorSpeed;        //起发电机转速N(rpm)	0~12000
	Z_U8 wgeneratorSpeed; 		// W起发电机转速N(rpm)
	Z_U16 inletAirPressure;        //进口气流总压Pt2(kPa)  5 ~170
	Z_U8 winletAirPressure; 		// W进口气流总压Pt2(kPa)
	Z_U16 N1u;        //N1u	 0~65535
	Z_U8 wN1u; 		// WN1u
	Z_U16 U5T;        //U5T	 -6.5~6.5	
	Z_U8 wU5T; 		// WU5T
	Z_U16 ECU1WorkStatu;        //ECU1_发动机工作状态字1 0000~FFFFH
	Z_U8 lowOilSwitch; 		// 低滑油液位开关 0~45
	Z_I16 ftmpTemperature;        //燃油温度(℃) -55~80
	Z_U8 wftmpTemperature; 		// W燃油温度
	Z_I16 oilPitchAngle;        //油面俯仰角(°) -90~90
	Z_U8 woilPitchAngle; 		// W油面俯仰角(°)
	Z_I16 oilRollAngle;        //油面滚转角（°）	-180~180
	Z_U8 woilRollAngle; 		// W油面滚转角（°）
	Z_U16 fuelDensity;        //燃油密度（kg/m3）	700~900
	Z_U8 wfuelDensity; 		// W燃油密度（kg/m3）
	Z_U16 fudswitchStatus;        //前起上下位行程开关状态	0000~FFFF
	Z_U8 wfudswitchStatus; 		// W前起上下位行程开关状态
	Z_U16 ludswitchStatus;        //左主起上下位行程开关状态 0000~FFFF
	Z_U8 wludswitchStatus; 		// W左主起上下位行程开关状态
	Z_U16 rudswitchStatus;        //右主起上下位行程开关状态 0000~FFFF
	Z_U8 wrudswitchStatus; 		// W右主起上下位行程开关状态
	Z_U16 fludcabinswitchStatus;        //前起左舱门上下位行程开关状态 0000~FFFFH
	Z_U8 wfludcabinswitchStatus; 		// W前起左舱门上下位行程开关状态
	Z_U16 frudcabinswitchStatus;        //前起右舱门上下位行程开关状态 0000~FFFFH
	Z_U8 wfrudcabinswitchStatus; 		// W前起右舱门上下位行程开关状态
	Z_U16 ludcabinswitchStatus;        //左主起舱门上下位行程开关状态 0000~FFFFH
	Z_U8 wludcabinswitchStatus; 		// W左主起舱门上下位行程开关状态
	Z_U16 rudcabinswitchStatus;        //右主起舱门上下位行程开关状态 0000~FFFFH
	Z_U8 wrudcabinswitchStatus; 		// W右主起舱门上下位行程开关状态
	Z_F32 integratedNavigation;        //组合导航UTC天秒(s) [0,4294967.296]
	Z_U8 wintegratedNavigation; 		// W组合导航UTC天秒
	Z_I16 northSpeed;        //惯性/差分组合北速(m/s) [-350,350]
	Z_U8 wnorthSpeed; 		// W惯性/差分组合北速(m/s)
	Z_I16 eastSpeed;        //惯性/差分组合东速(m/s) [-350,350]
	Z_U8 weastSpeed; 		// 惯性/差分组合东速(m/s)
	Z_U16 yaw;        //惯性/差分航向角(°) [0,360）
	Z_U8 wyaw; 		// 惯性/差分航向角(°)
	Z_I16 pitch;        //惯性/差分俯仰角（°） [-90,90]
	Z_U8 wpitch; 		// 惯性/差分俯仰角（°）
	Z_I16 roll;        //惯性/差分滚动角（°） （-180,180]
	Z_U8 wroll; 		// W惯性/差分滚动角（°）
	Z_U16 outletPressure;        //高压压气机出口总压Pt3(kPa) 10 ~2500
	Z_U8 woutletPressure; 		// W高压压气机出口总压Pt3(kPa)
	Z_U16 flyingBusbar;        //接触器K1\K2\K3\K4\K5\K6动作信号	00~FFH 1-接通 0-断开 Bit6~Bit15飞行汇流条电流（A）
	Z_U8 wflyingBusbar;			//W飞行汇流条电流
	Z_U8 batteryVoltage;			//蓄电池电压（V） 0~36V
	Z_U8 generatorVoltage;			//发电机电压（V） 0~36V
	Z_U8 wbatteryVoltage;			//W蓄电池电压
	Z_U8 wgeneratorVoltage;			//W发电机电压
	Z_U8 flyingVelocity;			//飞行汇流条电压（V） 0~36V
	Z_U8 missionVelocity;			//任务汇流条电压（V） 0~36V
	Z_U8 wflyingVelocity;			//W飞行汇流条电压（V）
	Z_U8 wmissionVelocity;			//W任务汇流条电压（V）
	Z_U8 rarHeightVoltage;			//无线电高度表电压（V） 0~36V
	Z_U8 rarHeightCurrent;			//无线电高度表电流（A）
	Z_U8 wrarHeightVoltage;			//W无线电高度表电压（V） 0~40A
	Z_U8 wrarHeightCurrent;			//W无线电高度表电流（A）
	Z_U8 brakeCtrolVoltage1;			//刹车控制盒1电压（V） 0~36V
	Z_U8 brakeCtrolCurrent1;			//刹车控制盒1电流（A） 0~200A
	Z_U8 wbrakeCtrolVoltage1;			//W刹车控制盒1电压（V）
	Z_U8 wbrakeCtrolCurrent1;			//W刹车控制盒1电流（A）
	Z_U8 brakeCtrolVoltage2;			//刹车控制盒2电压（V） 0~36V
	Z_U8 brakeCtrolCurrent2;			//刹车控制盒2电流（A） 0~200A
	Z_U8 wbrakeCtrolVoltage2;			//W刹车控制盒2电压（V）
	Z_U8 wbrakeCtrolCurrent2;			//W刹车控制盒2电流（A）
	Z_U8 iceDetectVoltage;			//结冰探测器电压（V）   0~36V
	Z_U8 iceDetectCurrent;			//结冰探测器电流（A）   0~100A
	Z_U8 wiceDetectVoltage;			//W结冰探测器电压（V）
	Z_U8 wiceDetectCurrent;			//W结冰探测器电流（A）
	Z_U8 heatingVoltage;			//空速管加温电压（V）   0~36V
	Z_U8 heatingCurrent;			//空速管加温电流（A）   0~40A
	Z_U8 wheatingVoltage;			//W空速管加温电压（V）
	Z_U8 wheatingCurrent;			//W空速管加温电流（A）
	Z_U8 openVoltage;			//燃油切断阀打开电压（V）   0~36V
	Z_U8 openCurrent;			//燃油切断阀打开电流（A）   0~40A
	Z_U8 wopenVoltage;			//W燃油切断阀打开电压（V）
	Z_U8 wopenCurrent;			//W燃油切断阀打开电流（A）
	Z_U8 closeVoltage;			//燃油切断阀关闭电压（V）   0~36V
	Z_U8 closeCurrent;			//燃油切断阀关闭电流（A）   0~40A
	Z_U8 wcloseVoltage;			//W燃油切断阀关闭电压（V）
	Z_U8 wcloseCurrent;			//W燃油切断阀关闭电流（A）
	Z_U8 deicingVelocity;			//除冰装置电压状态   0~36V
	Z_U8 deicingCurrent;			//除冰装置电流（A）   0~320A
	Z_U8 wdeicingVelocity;			//W除冰装置电压状态
	Z_U8 wdeicingCurrent;			//W除冰装置电流（A）
	Z_U8 BTVelocity;			//温度变换器等传感器电压（V）   0~36V
	Z_U8 BTCurrent;			//温度变换器等传感器电流（A）   0~24A
	Z_U8 wBTVelocity;			//W温度变换器等传感器电压（V）
	Z_U8 wBTCurrent;			//W温度变换器等传感器电流（A）
	Z_U8 fuelPumpVelocity1;			//燃油泵1供电电压（V）   0~36V
	Z_U8 fuelPumpCurrent1;			//燃油泵1供电电流（A）   0~200A
	Z_U8 wfuelPumpVelocity1;			//W燃油泵1供电电压（V）
	Z_U8 wfuelPumpCurrent1;			//W燃油泵1供电电流（A）
	Z_U8 fuelPumpVelocity2;			//燃油泵2供电电压（V）   0~36V
	Z_U8 fuelPumpCurrent2;			//燃油泵2供电电流（A）   0~200A
    Z_U8 wfuelPumpVelocity2;			//W燃油泵2供电电压（V）
	Z_U8 wfuelPumpCurrent2;			//W燃油泵2供电电流（A）
	Z_U8 navLightVelocity;			//航灯电压（V）   0~36V
	Z_U8 navLightCurrent;			//航灯电流（A）   0~8A
	Z_U8 wnavLightVelocity;			//W航灯电压（V）
	Z_U8 wnavLightCurrent;			//W航灯电流（A）
	Z_U8 resSystemVelocity;			//航管应答系统电压（V）   0~36V
	Z_U8 resSystemCurrent;			//航管应答系统电流（A）   0~24A
	Z_U8 wresSystemVelocity;			//W航管应答系统电压（V）
	Z_U8 wresSystemCurrent;			//W航管应答系统电流（A）
	Z_U8 cSystemVelocity;			//C系统电压（V）   0~36V
	Z_U8 cSystemCurrent;			//C系统电流（A）   0~100A
	Z_U8 wBTCurrentcSystemVelocity;			//WC系统电压（V）
	Z_U8 wcSystemCurrent;			//WC系统电流（A）
	Z_U8 uSystemVelocity;			//U系统电压（V）   0~36V
	Z_U8 uSystemCurrent;			//U系统电流（A）   0~60A
	Z_U8 wuSystemVelocity;			//WU系统电压（V）
	Z_U8 wuSystemCurrent;			//WU系统电流（A）
	Z_U8 vitonVelocity;			//卫通电压（V）   0~36V
	Z_U8 vitonCurrent;			//卫通电流（A）   0~200A
	Z_U8 wvitonVelocity;			//W卫通电压（V）
	Z_U8 wvitonCurrent;			//W卫通电流（A）
	Z_U8 emergPermisVelocity;			//应急允许电压（V）   0~36V
	Z_U8 emergPermisCurrent;			//应急允许电流（A）   0~60A
	Z_U8 wemergPermisVelocity;			//W应急允许电压（V）
	Z_U8 wemergPermisCurrent;			//W应急允许电流（A）
	Z_U8 emergRealxVelocity;			//起落架应急放电压（V）   0~36V
	Z_U8 emergRealxCurrent;			//起落架应急放电流（A）   0~24A
	Z_U8 wemergRealxVelocity;			//W起落架应急放电压（V）
	Z_U8 wemergRealxCurrent;			//W起落架应急放电流（A）
	Z_U8 emergBrakeVelocity;			//应急刹车电压（V）   0~36V
    Z_U8 emergBrakeCurrent;			//应急刹车电流（A）   0~24A
    Z_U8 wemergBrakeVelocity;			//W应急刹车电压（V）
    Z_U8 wemergBrakeCurrent;			//W应急刹车电流（A）
	Z_U8 realxBrakeVelocity;			//起落架解抱闸电压（V）   0~36V
	Z_U8 realxBrakeCurrent;			//起落架解抱闸电流（A）   0~16A
	Z_U8 wrealxBrakeVelocity;			//W起落架解抱闸电压（V）
	Z_U8 wrealxBrakeCurrent;			//W起落架解抱闸电流（A）
	Z_U8 exportOilPressure;			//换热器出口滑油压力   0～1500
	Z_U8 wexportOilPressure;			//w换热器出口滑油压力
	Z_U8 exportOilTemperature;			//换热器出口滑油温度（℃） 0～150
	Z_U8 wexportOilTemperature;			//W换热器出口滑油温度（℃）
	Z_U8 exportOilVelocity;			//燃油调节器出口燃油压力（kPa）   0～4500
	Z_U8 wexportOilVelocity;			//w燃油调节器出口燃油压力（kPa）
	Z_U8 oilSupplyVelocity;			//供油压力传感器（kpa） -50~300
	Z_U8 woilSupplyVelocity;			//W供油压力传感器（kpa）
	Z_U8 fwSwitch;			//前起轮载开关信号1（V）  0~35V
	Z_U8 wfwSwitch;			//w前起轮载开关信号1（V）
	Z_U8 lwSwitch;			//左主起轮载开关信号1（V） 0~35V
	Z_U8 wlwSwitch;			//W左主起轮载开关信号1（V）
	Z_U8 rwSwitch;			//右主起轮载开关信号1（V） 0~35V
	Z_U8 wrwSwitch;			//w右主起轮载开关信号1（V）
	Z_U8 fTemperature;			//前机身设备舱温度（℃） -60~150
	Z_U8 wfTemperature;			//W前机身设备舱温度（℃）
	Z_U8 mTemperature;			//中机身设备舱温度（℃） -60~150
	Z_U8 wmTemperature;			//W中机身设备舱温度（℃）
	Z_U8 ufTemp;			//发动机舱上前部温度（℃） -60~150
	Z_U8 wufTemp;			//W发动机舱上前部温度（℃）
	Z_U8 fTemp;			//发动机舱后上部温度（℃） -60~150
	Z_U8 buTemp;			//W发动机舱后上部温度（℃）
	Z_U8 gasTemp1;			//气体温度传感器1（°C） -55~200
	Z_U8 wgasTemp1;			//W气体温度传感器1（°C）
	Z_U8 gasTemp2;			//气体温度传感器2（°C） -55~200
	Z_U8 wgasTemp2;			//W气体温度传感器2（°C）
	Z_U8 freezeStatus;			//结冰探测器结冰状态字 0~255
	Z_U8 lowOilPressure;			//低滑油压力告警 0~45
	Z_F32 comNavStatu;			//组合导航修正方式状态字 00000000~FFFFFFFFH
	Z_U16 navStatu;			//导航方式状态字	0000~FFFFH
	Z_U8 resSymVelocity;			//航管应答系统电压（V）	0~36V
	Z_U16 xOil;			//燃油总重心_X纵向	0~10000
	Z_I16 zOil;			//燃油总重心_Z横向	-5000~5000
	Z_U8 wtotalOil;			//W燃油总重心告警
	Z_U16 ECU1WorkStatu2;			//ECU1_发动机工作状态字2	0000~FFFFH
	Z_U8 backupsVelocity;			//备份发电机电压(V)	0~36V
	Z_U8 wbackupsVelocity;			//W备份发电机电压
	Z_U16 mOilQuantity;			//机身中油箱油量（kg）	0~1000
	Z_U16 fOilQuantity;			//机身前油箱油量（kg）	0~1000
	Z_U16 bOilQuantity;			//机身后油箱油量（kg）	0~1000
	Z_U16 lOilQuantity;			//左机翼油箱油量（kg）	0~1000
	Z_U16 rOilQuantity;			//右机翼油箱油量（kg）	0~1000
	Z_U16 tOilQuantity;			//总油量（kg）	0~5000 
	Z_U8 wOilQuantity;			//W燃油油量告警  Bit0：机身中告警；Bit1：机身前告警；Bit2：机身后告警；Biit3：左机翼告警；Bit4：右机翼告警；Bit5：总油量告警
	Z_U16 status;			//状态字	0000~FFFFH
	
	Z_I16 rudderCurrent1;			//1舵电流(A)	-30~30
	Z_I16 rudderCurrent2;			//2舵电流(A)	-30~30
	Z_I16 rudderCurrent3;			//3舵电流(A)	-30~30
	Z_I16 rudderCurrent4;			//4舵电流(A)	-30~30
	Z_I16 rudderCurrent5;			//5舵电流(A)	-30~30
	Z_I16 rudderCurrent6;			//6舵电流(A)	-30~30
	Z_I16 rudderCurrent7;			//7舵电流(A)	-30~30
	Z_I16 rudderCurrent8;			//8舵电流(A)	-30~30
	Z_U16 radderCheckStatu1;			//舵系统自检状态字1	0000~FFFFH
	Z_U16 radderCheckStatu2;			//舵系统自检状态字2	0000~FFFFH
	Z_U8 batteryHeat1;			//电池1加温好（V）	0~45
	Z_U8 batteryHeat2;			//电池2加温好（V）	0~45
	
	Z_U16 ECU2WorkStatu1;			//ECU2_发动机工作状态字1	0000~FFFFH
	Z_U16 ECU2WorkStatu2;			//ECU2_发动机工作状态字2	0000~FFFFH
	Z_U8 NysWorkState_High;
	Z_U8 NysWorkState_Low;
	Z_U8 NysPosWorkState_High;
	Z_U8 NysPosWorkState_Low;
	Z_U8 NysPosWorkState_high_high_4_Bit;
    Z_U8 reserve1[36];      //备用 16	uint8 / 置零
	Z_U8 checkSum;      

	CONSTRUCT(ProfessionalData);
};

// 操控杆(MFD接收硬件串口数据， 发送给HUD)
struct HOTAS
{
    Z_U8 head1;
    Z_U8 head2;
    Z_U8 devNum;
    Z_U8 switchCmd1;
    Z_U8 switchCmd2;
    Z_I16 axisX;    // 右手杆X轴位移量
    Z_I16 axisY;    // 右手杆Y轴位移量
    Z_I16 axisZ;
    Z_U8 selfCheck;
    Z_U8 reserve;
    Z_U8 counter;
    Z_U8 checkVal;
    Z_U8 tail;
};

// 脚舵
struct RudderPedal
{
    Z_U8 head1;
    Z_U8 head2;
    Z_U16 length;
    Z_U8 counter;
    Z_U8 devId;
    Z_U16 leftBreak;
    Z_U16 rightBreak;
    Z_U16 yaw;  // 脚蹬偏航位移量
    Z_U8 reserve1;
    Z_U8 reserve2;
    Z_U8 reserve3;
    Z_U8 selfCheck;
    Z_U8 tail;
};

// 手动和随动状态（MFD发送给HUD）
struct DeviceControlMode
{
    Z_U8 head1;
    Z_U8 head2;
    Z_U8 length;
    Z_U8 attState; // 姿态是否为随动模式(操控杆)
    Z_U8 yawState; // 偏航是否为随动模式(操控杆)
    Z_U8 breakState; // 刹车是否为随动模式
    Z_U8 ThroState; // 油门台是否为随动模式
    Z_U8 reserve1;
};

// 时间信息（MFD发送给HUD）
struct TimeInfo
{
    Z_U8 head1;
    Z_U8 head2;
    Z_U16 length;
    Z_U32 localTime;    // 本地时间
    Z_U32 ntpTime;  // NTP时间
    Z_U32 reserve1;
};

ICD2002G_NAMESPACE_END
#pragma pack(pop)
