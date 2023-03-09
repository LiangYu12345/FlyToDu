#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：飞行仿真 Flight Simulation Software （FSS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：无人机飞行状态数据包
TOPIC：DL-FSS-FLYSTATE-STA   FSS-FLYSTATE-STA
完整包结构：BasicPktHeader + UAVFlightState + BasicPktTail
*/
struct UAVFlightState
{
    Z_I32 longitude;        //经度	int32(-180, 180]	单位为度，LSB = 0.0000001°
    Z_I32 latitude;         //纬度	int32[-90, 90]	单位为度，LSB = 0.0000001°
    Z_F32 altitude;         //高度	float[-500, 20000]	单位为m
    Z_F32 trueHeading;      //真航向	float[0, 360)	单位为度
    Z_F32 pitch;            //俯仰角	float(-90, 90)	单位为度
    Z_F32 roll;             //横滚角	float(-180, 180)	单位为度
    Z_F32 vt;               //真空速Vt	float[0, 1200]	单位为km / h
    Z_I32 reserve1;         //预留	int32 / 置零
    Z_U8 reserve2;          //预留	uint8 / 置零

    CONSTRUCT(UAVFlightState);
};

/*
包名称：无人机舵面起落架位置数据包
TOPIC：DL-FSS-SURFACEPOS-STA     FSS-SURFACEPOS-STA
完整包结构：BasicPktHeader + UAVSurfacePosState + BasicPktTail
*/
struct UAVSurfacePosState
{
    Z_F32 landingGearPos;       //起落架位置	float[0, 1.0]	"无量纲数（0 - 放下，1 - 收起）"
    Z_U8 flapPosLeft;           //左襟翼位置	uint8[0, 40]	单位为度，LSB = 1°
    Z_U8 flapPosRight;          //右襟翼位置	uint8[0, 40]	单位为度，LSB = 1°
    Z_F32 aileronPosLeft;       //左副翼位置	float[-21.5, 21.5]	单位为度
    Z_F32 aileronPosRight;      //右副翼位置	float[-21.5, 21.5]	单位为度
    Z_I8 elevatorPos;           //升降舵位置	int8[-25, 25]	单位为度，LSB = 1°
    Z_I8 rudderPos;             //方向舵位置	int8[-30, 30]	单位为度，LSB = 1°

    Z_U8 flapComLeft;           //左襟翼命令
    Z_U8 flapComRight;          //右襟翼命令
    Z_F32 aileronComLeft;       //左副翼命令
    Z_F32 aileronComRight;      //右副翼命令
    Z_I8 elevatorComLeft;       //升降舵命令
    Z_I8 rudderCom;             //方向舵命令

    Z_I32 reserve1;             //预留	int32 / 置零
    Z_U8 reserve2;              //预留	uint8 / 置零

    CONSTRUCT(UAVSurfacePosState);
};

/*
包名称：无人机涡扇发动机系统状态数据包
TOPIC：DL-FSS-TFENGSYS-STA   FSS-TFENGSYS-STA
完整包结构：BasicPktHeader + UAVEngineState + BasicPktTail
*/
struct UAVEngineState
{
    Z_U8 engineID;              //发动机标识	uint8 / 1 - 1发；2 - 2发；3 - 3发；4 - 4发；其它 - 无效；
    Z_U16 highTurbineRPM;       //发动机高压涡轮转速 	uint16[0, 20000]	单位为RPM，LSB = 1
    Z_U8 highTurbineRPMPercent; //高压涡轮转速百分比	uint8[0, 130]	无量纲数，LSB = 1
    Z_U16 lowTurbineRPM;        //发动机低压涡轮转速 	uint16[0, 20000]	单位为RPM，LSB = 1RPM
    Z_U8 lowTurbineRPMPercent;  //低压涡轮转速百分比	uint8[0, 130]	无量纲数，LSB = 1
    Z_U8 throttleOpen;          //油门开度 	uint8[0, 100]	无量纲数，LSB = 1
    Z_U16 exhaustTemp;          //排气温度EGT  	uint16[0, 1000]	单位为℃，LSB = 1℃
    Z_F32 exhaustPress;         //排气压强	float[0, 1.0]	单位为Mpa
    Z_F32 intakePress;          //引气压力  	float[0, 1.0]	单位为Mpa
    Z_I16 intakeTotalTemp;      //进口总温  	int16[-70, 50]	单位为℃，LSB = 1℃
    Z_F32 intakeTotalPress;     //进口总压  	float[0, 1.0]	单位为Mpa
    Z_F32 lowTurbinePress;      //低压涡轮压强	float[0, 1.0]	单位为Mpa
    Z_U16 lowTurbineTemp;       //低压涡轮温度	uint16[0, 1000]	单位为℃，LSB = 1℃ 
    Z_F32 highTurbinePress;     //高压涡轮压强	float[0, 10.0]	单位为Mpa
    Z_U16 highTurbineTemp;      //高压涡轮温度	uint16[0, 1000]	单位为℃，LSB = 1℃
    Z_F32 lubePress;            //滑油压力Oil P  	float[0, 1.0]	单位为Mpa
    Z_I16 lubeTemp;             //滑油温度Oil T	int16[-50, 200]	单位为℃，LSB = 1℃
    Z_I32 reserve1;             //预留	int32 / 置零
    Z_U8 reserve2;              //预留	uint8 / 置零

    CONSTRUCT(UAVEngineState);
};

/*
包名称：无人机燃油系统状态数据包
TOPIC：DL-FSS-FUELSYS-STA    FSS-FUELSYS-STA
完整包结构：BasicPktHeader + UAVFuelState + BasicPktTail
*/
struct UAVFuelState
{
    Z_U16 fuelFlow;             //燃油流量FuelFlow	uint16[0, 11447]	单位为升 / 小时，LSB = 1L / h
    Z_U16 lessTotalFuel;        //全机余油量	uint16[0, 10000]	单位为升，LSB = 1L
    Z_U8 lessTotalFuelPer;      //油量百分比	uint8[0, 100]	无量纲数，LSB = 1
    Z_U16 lessFuel1;            //1号油泵油量	uint16[0, 10000]	单位为升，LSB = 1L
    Z_U16 lessFuel2;            //2号油泵油量	uint16[0, 10000]	单位为升，LSB = 1L
    Z_U16 lessFuel3;            //3号油泵油量	uint16[0, 10000]	单位为升，LSB = 1L
    Z_I16 fuelTemp;             //燃油温度Fuel T	int16[-50, 200]	单位为℃，LSB = 1℃
    Z_F32 fuelPress;            //燃油压力Fuel P	float[0, 1.0]	单位为Mpa
    Z_I32 reserve1;             //预留	int32 / 置零

    CONSTRUCT(UAVFuelState);
};

/*
包名称：无人机液压系统状态数据包
TOPIC：DL-FSS-HYDSYS-STA     FSS-HYDSYS-STA
完整包结构：BasicPktHeader + UAVHydraulicState + BasicPktTail
*/
struct UAVHydraulicState
{
    Z_F32 hydraulicPress;       //液压压力	float[0, 20.0]	单位为Mpa
    Z_F32 coolAirPress;         //冷气压力	float[0, 20.0]	单位为Mpa
    Z_F32 brakePressLeft;       //左刹车压力	float[0, 10.0]	单位为Mpa
    Z_F32 brakePressRight;      //右刹车压力	float[0, 10.0]	单位为Mpa
    Z_U8 leftBrakePercent;      //左刹车百分比	uint8	0~100	无量纲数，LSB = 1
    Z_U8 rightBrakePercent;     //右刹车百分比	uint8	0~100	无量纲数，LSB = 1
    Z_F32 emergencyBrakePress;  //应急刹车压力	float[0, 10.0]	单位为Mpa
    Z_I32 reserve1;             //预留	int32 / 置零
    Z_U8 reserve2;              //预留	uint8 / 置零

    CONSTRUCT(UAVHydraulicState);
};

/*
包名称：无人机起落架系统状态数据包
TOPIC：DL-FSS-LDGEARSYS-STA      FSS-LDGEARSYS-STA
完整包结构：BasicPktHeader + UAVLandingGearState + BasicPktTail
*/
struct UAVLandingGearState
{
    Z_U8 leftGearState;     //左起落架状态	uint8 / 0 - 放下，1 - 收起
    Z_U8 frontGearState;    //前起落架状态	uint8 / 0 - 放下，1 - 收起
    Z_U8 rightGearState;    //右起落架状态	uint8 / 0 - 放下，1 - 收起
    Z_U8 leftGearWheel;     //左起落架轮载WOW	uint8 / 0 - 接地，1 - 离地
    Z_U8 frontGearWheel;    //前起落架轮载WOW	uint8 / 0 - 接地，1 - 离地
    Z_U8 rightGearWheel;    //右起落架轮载WOW	uint8 / 0 - 接地，1 - 离地
    Z_U16 leftWheelSpeed;   //左机轮速度	uint16[0, 250]	单位为Km / h，LSB = 1Km / h
    Z_U16 rightWheelSpeed;  //右机轮速度	uint16[0, 250]	单位为Km / h，LSB = 1Km / h
    Z_I8 frontWheelAngle;   //前轮转弯角度	int8[-60, 60]	单位为度，LSB = 1°
    Z_I32 reserve1;         //预留	int32 / 置零

    CONSTRUCT(UAVLandingGearState);
};

/*
包名称：无人机电源系统状态数据包
TOPIC：DL-FSS-ELESYS-STA     FSS-ELESYS-STA
完整包结构：BasicPktHeader + UAVElectricitySystemState + BasicPktTail
*/
struct UAVElectricitySystemState
{
    Z_U8 busVoltage;        //总线电压	uint8[0, 35]	单位为V，LSB = 1V
    Z_U8 dynamoVoltage;     //发电机电压	uint8[0, 35]	单位为V，LSB = 1V
    Z_U8 dynamoCurrent;     //发电机电流	uint8[0, 30]	单位为A，LSB = 1A
    Z_U8 batteryVoltage;    //电池电压	uint8[0, 35]	单位为V，LSB = 1V
    Z_U8 batteryCapacity;   //电池余量	uint8[0, 60]	单位为Ah，LSB = 1Ah
    Z_U8 batteryLessTime;   //电池可使用时间	uint8[0, 30]	单位为分钟，LSB = 1min
    Z_U8 rudderCurrent;     //方向舵电流	uint8[0, 10]	单位为A，LSB = 1A
    Z_U8 elevatorCurrent;   //升降舵电流	uint8[0, 10]	单位为A，LSB = 1A
    Z_U8 aileronCurrent;    //副翼电流	uint8[0, 10]	单位为A，LSB = 1A
    Z_U8 flapCurrent;       //襟翼电流	uint8[0, 10]	单位为A，LSB = 1A
    Z_I32 reserve1;         //预留	int32 / 置零
    Z_U8 reserve2;          //预留	uint8 / 置零

    CONSTRUCT(UAVElectricitySystemState);
};

/*
包名称：无人机大气机状态数据包
TOPIC：DL-FSS-ADCDATA-STA    FSS-ADCDATA-STA
完整包结构：BasicPktHeader + UAVADCState + BasicPktTail
*/
struct UAVADCState
{
    Z_F32 density;      //大气密度	float(0, 1.5)	单位为kg / m3
    Z_I16 Ts;           //静温Ts	int16[-60, 80]	单位为℃，LSB = 1℃
    Z_I16 Tt;           //总温Tt	int16[-60, 99]	单位为℃，LSB = 1℃
    Z_F32 Ps;           //静压Ps 	float(35, 120)	单位为kPa
    Z_F32 Pt;           //总压Pt 	float(35, 120)	单位为kPa
    Z_F32 AOA;          //攻角AOA	float(-3, 30)	单位为度
    Z_F32 AOS;          //侧滑角AOS	float(-15, 15)	单位为度
    Z_F32 Vt;           //真空速Vt	float[0, 1200]	单位为km / h
    Z_F32 IAS;          //指示空速IAS	float[0, 1200]	单位为km / h
    Z_F32 M;            //马赫数M	float(0, 1.5)	无量纲数
    Z_F32 vSpeed;       //升降速度	float(-30, 30)	单位为m / s
    Z_F32 relativeHigh; //相对机场高度	float[-500, 20000]	单位为m
    Z_F32 Hqne;         //标准气压高度	float[-500, 20000]	单位为m
    Z_I16 reserve1;     //预留	int16 / 置零
    Z_U8 reserve2;      //预留	uint8 / 置零

    CONSTRUCT(UAVADCState);
};

/*
包名称：无人机惯导状态数据包
TOPIC：DL-FSS-INSDATA-STA    FSS-INSDATA-STA
完整包结构：BasicPktHeader + UAVINSState + BasicPktTail
*/
struct UAVINSState
{
    Z_I32 longitude;        //经度	int32(-180, 180]	单位为度，LSB = 0.0000001°
    Z_I32 latitude;         //纬度	int32[-90, 90]	单位为度，LSB = 0.0000001°
    Z_F32 altitude;         //高度	float[-500, 20000]	单位为m
    Z_F32 trueHeading;      //真航向	float[0, 360)	单位为度
    Z_F32 magHeading;       //磁航向	float[0, 360)	单位为度
    Z_F32 pitch;            //俯仰角	float(-90, 90)	单位为度
    Z_F32 roll;             //横滚角	float(-180, 180)	单位为度
    Z_F32 overloadG;        //过载G	float[0, 10.0)	单位为g
    Z_F32 GS;               //地速	float[0, 1500] 单位为Km/h
    Z_U8 reserve2;          //预留	uint8 / 置零

    CONSTRUCT(UAVINSState);
};

/*
包名称：无人机GPS状态数据包
TOPIC：DL-FSS-GPSDATA-STA    FSS-GPSDATA-STA
完整包结构：BasicPktHeader + UAVGPSState + BasicPktTail
*/
struct UAVGPSState
{
    Z_I32 longitude;        //经度	int32(-180, 180]	单位为度，LSB = 0.0000001°
    Z_I32 latitude;         //纬度	int32[-90, 90]	单位为度，LSB = 0.0000001°
    Z_F32 altitude;         //高度	float[-500, 20000]	单位为m
    Z_U32 date;             //日期	uint32	[0,20500000]	用整数表示的当天日期：年月日，如2020-8-30，整数为20200830
    Z_U32 time;             //时间	uint32	[0,235959999]	用整数表示的当前时间：时分秒毫秒，如16:54:46:200，整数为165446200
    Z_I16 reserve1;         //预留	int16 / 置零
    Z_U8 reserve2;          //预留	uint8 / 置零

    CONSTRUCT(UAVGPSState);
};

/*
包名称：无人机无线电高度表状态数据包
TOPIC：DL-FSS-RADATA-STA     FSS-RADATA-STA
完整包结构：BasicPktHeader + UAVRAState + BasicPktTail
*/
struct UAVRAState
{
    Z_F32 ra;           //RA高度	float[-500, 20000]	单位为m
    Z_I16 reserve1;     //预留	int16 / 置零
    Z_U8 reserve2;      //预留	uint8 / 置零

    CONSTRUCT(UAVRAState);
};

/*
包名称：无人机告警信息数据包
TOPIC：DL-FSS-ALARMSTATE-STA     FSS-ALARMSTATE-STA
完整包结构：BasicPktHeader + UAVAlarmState + BasicPktTail
*/
struct UAVAlarmState
{
    Z_U8 aoa;                   //攻角超限告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 overload;              //过载超限告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 lossSpeed;             //失速告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 overSpeed;             //超速告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 aos;                   //侧滑角告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 hydraulicLowPress;     //液压压力低告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 coolAirLowPress;       //冷气压力低告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 engineOverRPM;         //发动机超转告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 engineOverTemp;        //发动机超温告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 lubePress;             //滑油压力告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 remainFuel;            //余油量告警	uint8 / 0 - 正常，1 - 告警
    Z_U8 strike;                //近地防撞告警	uint8 / 0 - 正常，1 - 告警
    Z_I16 reserve1;             //预留	int16 / 置零
    Z_U8 reserve2;              //预留	uint8 / 置零

    CONSTRUCT(UAVAlarmState);
};

/*
包名称：无人机控制指令回传数据包
TOPIC：DL-FSS-CMDFEEDBACK-STA    FSS-CMDFEEDBACK-STA
完整包结构：BasicPktHeader + UAVCtrlCmdFeedback + BasicPktTail
*/
struct UAVCtrlCmdFeedback
{
    Z_U8 cmdType;       //回传控制指令Label	uint8 / 指令类型Label，详见无人机控制指令定义
    Z_U8 cmdValue;      //指令定义说明	uint8 / 指令定义说明，详见无人机控制指令定义
    Z_F32 param1;       //回传控制指令参数1	float / 指令参数1，详见无人机控制指令定义
    Z_I32 param2;       //回传控制指令参数2	int32 / 指令参数2，详见无人机控制指令定义
    Z_I32 param3;       //回传控制指令参数3	int32 / 指令参数3，详见无人机控制指令定义
    Z_U8 execState;     //指令执行状态	uint8 / 0 - 未执行；1 - 已执行；2 - 执行中；

    CONSTRUCT(UAVCtrlCmdFeedback);
};

/*
包名称：无人机飞控与导航状态信息数据包
TOPIC：DL-FSS-NAVCTRL-STA    FSS-NAVCTRL-STA
完整包结构：BasicPktHeader + UAVNavCtrlState + BasicPktTail
*/
struct UAVNavCtrlState
{
    Z_U8 ctrlMode;      //飞控模式	uint8 / "0-AC；1 - MC；其他 - 无效；"
    Z_U8 flightStage;   //飞行阶段	uint8 / "0-Tarmac-delay；1 - Take-off；2 - Climbing；3 - Cruise；4 - RTB；7 - GA；其他 - 无效；"
    Z_U8 curSubRouteID; //当前子航线ID	uint8[1, 255]	无量纲数，LSB = 1
    Z_U8 curWptID;              //当前航路点ID（子航线里的ID）	uint8[1, 255]	无量纲数，LSB = 1
    Z_F32 distanceToGo;         //待飞距离	float[0, 2000]	单位为Km
    Z_F32 crossTrackDistance;   //偏航距	float[-20, 20]	单位为Km
    Z_U32 flightTime;           //飞行时间	uint32	0~604800	单位为秒，LSB = 1s
    Z_F32 mcpHeading;             // [0,360) 航向 单位 度
	Z_F32 mcpHigh;             // [-500, 20000] 高度 单位 m
	Z_F32 mcpSpeed;             // [0,1200) 航向 单位 km/h
    Z_U8 reserve;              //预留	uint8 / 置零

    CONSTRUCT(UAVNavCtrlState);
};

/*
包名称：航向相对位置包
TOPIC：DL-FSS-ADD-STA    FSS-ADD-STA
完整包结构：BasicPktHeader + UAVSysState + BasicPktTail
*/
struct UAVAddData
{
	Z_F32 disFromAirport;      	 //距离机场直线距离
	Z_U8 backupPowerVoltage;     //备用电源电压	uint8[0, 35]	单位为V，LSB = 1V
	Z_U8 backupPowerCurrent;     //备用电源电流	uint8[0, 30]	单位为A，LSB = 1A

	Z_U8 showRunwayAid;		//控制DISP还是不DISP
	Z_F32 runwayMapX;		//俯视，偏离落地点的距离X ,单位m
	Z_F32 runwayMapY;		//俯视，偏离落地点的距离Y ,单位m
	Z_F32 runwayHeightX;	//剖视，偏离落地点的距离X ,单位m
	Z_F32 runwayHeightY;		//剖视，偏离落地点的高度Y ,单位m
	CONSTRUCT(UAVAddData);
};
ICD2002G_NAMESPACE_END
#pragma pack(pop)