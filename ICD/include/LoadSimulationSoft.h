#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：载荷仿真 Load Simulation Software （LSS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：传感器探测目标数据包
TOPIC：DL-LSS-DETECTTARGET-STA   LSS-DETECTTARGET-STA
完整包结构：BasicPktHeader + ArrayPktHeader  + SensorDetectArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct SensorDetectArraySeg
{ 
	enum SensorType
	{
		SensorType_None = 0,								//无
		SensorType_TV = 1,									//TV
		SensorType_IR = SensorType_TV << 1,					//IR
		SensorType_Stripmap = SensorType_IR << 1,			//条带
		SensorType_Spotlight = SensorType_Stripmap << 1,	//聚术
		SensorType_GMTI = SensorType_Spotlight << 1			//GMTI
	};

	Z_U8 sensorType;            //探测传感器类型	uint8 / "公共数据，按位OPER，详见SensorType"
	Z_U16 IDInSensor;           //传感器认定的目标ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
    Z_U16 IDinScene;            //目标在场景中的ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
    Z_U16 targetType;           //Type	uint16 / 周期数据块，详见Type定义
    Z_U8 isRealTimeTarget;      //是否实时目标	uint8 / "周期数据块，1 - 实时目标；0 - 非实时目标；
								//从低位开始，第1位代表TV是否实时，第2位IR，第3位条带，第4位聚术，第5位GMTI"

    Z_U8 recognition;           //目标识别度	uint8[0, 100]	周期数据块，无量纲数，LSB = 1
    Z_U8 reserve1;              //预留	uint8 / 周期数据块，预留置零
    Z_I32 longitude;            //目标经度	int32(-180, 180]	周期数据块，单位为度，LSB = 0.0000001°
    Z_I32 latitude;             //目标纬度	int32[-90, 90]	周期数据块，单位为度，LSB = 0.0000001°
    Z_F32 altitude;             //目标高度	float[-500, 20000]	周期数据块，单位为m
    Z_F32 azimuthToAircraft;    //目标相对飞机的方位	float[0, 360)	周期数据块，单位为度
    Z_F32 disToAircraft;        //目标到飞机的距离（水平投影地面距离）	float[0, 100]	周期数据块，单位为km
    Z_F32 groundSpeed;          //目标地速（仅GMTI使用）	float[0, 1200]	周期数据块，单位为km / h
    Z_U16 reserve2;              //预留	uint8 / 周期数据块，预留置零

    CONSTRUCT(SensorDetectArraySeg);
};

/*
包名称：无人机光电吊舱状态数据包
TOPIC：DL-LSS-EO-STA     LSS-EO-STA
完整包结构：BasicPktHeader + UAVEOState + BasicPktTail
*/
struct UAVEOState
{
    Z_U8 workState;         //开关状态	uint8 / "0-已关机；1 - 开机引导；2 - 已开机；3 - 关机中；其它 - 无效；"
    Z_F32 azimuth;          //视线方位（机体坐标系）	float(-180, 180]	单位为度
    Z_F32 pitch;            //视线俯仰（机体坐标系）	float(-90, 90)	单位为度
    Z_U8 isLockedTarget;    //是否锁定目标	uint8 / 0 - 不锁定；1 - 锁定
    Z_I32 lockedLongitude;  //锁定目标经度	int32(-180, 180]	单位为度，LSB = 0.0000001°
    Z_I32 lockedLatitude;   //锁定目标纬度	int32[-90, 90]	单位为度，LSB = 0.0000001°
    Z_F32 lockedAltitude;   //锁定目标高度	float[-500, 20000]	单位为m
    Z_I16 reserve1;         //预留	int16 / 置零
    Z_U8 reserve2;          //预留	uint8 / 置零

    CONSTRUCT(UAVEOState);
};

/*
包名称：无人机光电传感器状态数据包
TOPIC：DL-LSS-EOSENSOR-STA       LSS-EOSENSOR-STA
完整包结构：BasicPktHeader + UAVEOSensorState + BasicPktTail
*/
struct UAVEOSensorState
{
    Z_U8 sensorMode;        //传感器模式	uint8 / "0-TV；1 - IR； 其它 - 无效；"
    Z_U8 workState;         //开关状态	uint8 / "0-已关机；1 - 开机引导；2 - 已开机；3 - 关机中； 其它 - 无效；"
    Z_U16 focalLength;      //焦距	uint16(0, 300)	单位为毫m
    Z_F32 hFOV;             //水平视场角H	float(0, 180)	单位为度
    Z_F32 vFOV;             //垂直视场角V	float(0, 180)	单位为度 
    Z_I16 reserve1;         //预留	int16 / 置零
    Z_U8 reserve2;          //预留	uint8 / 置零

    CONSTRUCT(UAVEOSensorState);
};

/*
包名称：无人机SAR雷达状态数据包
TOPIC：DL-LSS-SAR-STA    LSS-SAR-STA
完整包结构：BasicPktHeader + UAVSARState + BasicPktTail
*/
struct UAVSARState
{
    Z_U8 sarWorkMode;           //SAR工作模式	uint8 / "0-条带；1 - 聚束；2 - GMTI；3 - MMTI；其它 - 无效；"
    Z_U8 workState;             //开关状态	uint8 / "0-已关机；1 - 开机引导；2 - 已开机；3 - 关机中；其它 - 无效；"
    Z_I32 stripeResolution;     //条带DPI	int32 / "0-3m；1 - 1m；2 - 0.5m；其它 - 无效；"
    Z_F32 beamAzimuth;          //波束方位	float[0, 360)	单位为度
    Z_F32 beamPitch;            //波束俯仰	float(-90, 90)	单位为度
    Z_F32 beamAngle;            //波束角	float(-90, 90)	单位为度
    Z_F32 groundSwath;          //刈幅Ground swath	float[0, 100]	单位为km
    Z_F32 workDistance;         //工作距离（对地）	float[0, 100]	单位为km
    Z_I32 beamLongitude;        //聚束经度	int32(-180, 180]	单位为度，LSB = 0.0000001°
    Z_I32 beamLatitude;         //聚束纬度	int32[-90, 90]	单位为度，LSB = 0.0000001°
    Z_F32 beamAltitude;         //聚束高度	float[-500, 20000]	单位为m
    Z_F32 GMTIScanDis;          //GMTI扫描距离	float[0, 100]	单位为km
    Z_F32 GMTICenter;           //GMTI方位中心	float(-90, 90)	单位为度
    Z_F32 GMTIRange;            //GMTIAzi	float(0, 90)	单位为度
    Z_U8 sarMainMode;           //SAR主模式	uint8 / 0-空对地 ；1-空对海

    CONSTRUCT(UAVSARState);
};



/*
包名称：传感器首次探测目标数据包
TOPIC：LSS-FIRSTDETECTTARGET-STA
完整包结构：BasicPktHeader + ArrayPktHeader  + FirstSensorDetectArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct FirstSensorDetectArraySeg
{
	Z_U16 IDinScene;            //目标在场景中的ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
	Z_U16 IDInSensor;           //传感器认定的目标ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
	
	Z_U32 detectTime;           //探测时间	uint32	0~4,294,967,296	单位为秒，LSB = 1s
	Z_U8  reserve1;              //预留	uint8 / 周期数据块，预留置零
	Z_U8  reserve2;              //预留	uint8 / 周期数据块，预留置零

	CONSTRUCT(FirstSensorDetectArraySeg);
};


/*
包名称：锁定目标时间包
TOPIC：LSS-LOCKTARGETTIME-STA
完整包结构：BasicPktHeader + LockTargetTime + BasicPktTail
*/
struct LockTargetTime
{
	Z_I16 IDinScene;            //目标在场景中的ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1 负值无效
	Z_I16 IDInSensor;           //传感器认定的目标ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1 负值无效
	
	Z_I32 longitude;            //目标经度	int32(-180, 180]	周期数据块，单位为度，LSB = 0.0000001°
	Z_I32 latitude;             //目标纬度	int32[-90, 90]	周期数据块，单位为度，LSB = 0.0000001°
	Z_F32 altitude;             //目标高度	float[-500, 20000]	周期数据块，单位为m

	Z_U32 lockTime;           //探测时间	uint32	0~604800	单位为秒，LSB = 1s
	Z_U8  reserve1;              //预留	uint8 / 周期数据块，预留置零
	Z_U8  reserve2;              //预留	uint8 / 周期数据块，预留置零

	CONSTRUCT(LockTargetTime);
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)