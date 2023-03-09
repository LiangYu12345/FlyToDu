#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：场景仿真 Scenario Simulation Software （SSS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：场景中目标信息数据包
TOPIC：DL-SSS-TARGET-INFO-STA    SSS-TARGET-INFO-STA
完整包结构：BasicPktHeader + ArrayPktHeader + SceneTargetInfoArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct SceneTargetInfoArraySeg
{
    Z_U16 targetID;         //目标ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
    Z_U16 targetType;       //Type	uint16[0, 65535]	周期数据块，详见场景中Type定义
    Z_I32 longitude;        //经度	int32(-180, 180]	周期数据块，单位为度，LSB = 0.0000001°
    Z_I32 latitude;         //纬度	int32[-90, 90]	周期数据块，单位为度，LSB = 0.0000001°
    Z_F32 altitude;         //高度	float[-500, 20000]	周期数据块，单位为m
    Z_F32 heading;          //航向角	float[0, 360)	周期数据块，单位为度
    Z_F32 pitch;            //俯仰角	float(-90, 90)	周期数据块，单位为度
    Z_F32 roll;             //横滚角	float(-180, 180)	周期数据块，单位为度
    Z_F32 groundSpeed;      //地速	float[0, 1200]	周期数据块，单位为km / h
    Z_U16 missileObjId;	    //MSL从属的无人机ID
    Z_U8  missileLaunchID;  //MSL在无人机上的位置(机翼从左至右，依次编号0-n)
    Z_F32 influenceRadius;  //影响半径	float[0, 100]	周期数据块，单位为km / h
    Z_U16 raderScanSpeed;   //雷达扫描速率	uint16[0, 36000]	周期数据块，单位为度 / 秒，LSB = 1° / s
    Z_U8 raderWorkState;    //雷达开关状态	uint8 / "周期数据块，0 - 已关机；1 - 开机引导；2 - 已开机；3 - 关机中；其它 - 无效；"
    Z_U8 dangerFactor;      //危险因子	uint8[0, 100]	周期数据块，无量纲数，LSB = 1
    Z_U8 isStaticTarget;    //是否定点目标	uint8 / 周期数据块，0 - 非定点；1 - 定点；其它 - 无效；
    Z_U8 groupType;         //目标敌我属性	uint8 / 周期数据块，1 - 敌方；2 - 友方；3 - 中立；其它 - 未知；
    Z_I16 reserve1;         //预留	int16 / 周期数据块，预留置零

    CONSTRUCT(SceneTargetInfoArraySeg);
};

/*
包名称：场景中目标生存状态数据包
TOPIC：DL-SSS-TARGET-LIFE-STA    SSS-TARGET-LIFE-STA
完整包结构：BasicPktHeader + ArrayPktHeader + SceneLivingStateArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct SceneLivingStateArraySeg
{
    Z_U16 targetID;     //目标ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
    Z_U16 targetType;   //Type	uint16[0, 65535]	周期数据块，详见场景中Type定义
    Z_U8 livingState;   //目标生存状态	uint8 / 周期数据块，0 - 生存；1 - 毁灭；2 - 毁伤；其它 - 无效；

    CONSTRUCT(SceneLivingStateArraySeg);
};

/*
包名称：气象信息数据包
TOPIC：SSS-WEATHER-STA
完整包结构：BasicPktHeader + SceneWeatherInfo + BasicPktTail
*/
struct SceneWeatherInfo
{
    Z_U8 weatherType;       //天气类型	uint8 / 0 - 晴；1 - 雨；2 - 雪；其它 - 无效；
    Z_U8 weatherDensity;    //天气剧烈程度	uint8[0, 100]	无量纲数，LSB = 1
    Z_U16 visiableDis;      //能见度距离	uint16(0, 10000]	单位为m，LSB = 1m
    Z_F32 windSpeed;        //风速	float[0, 40]	单位为m / s
    Z_F32 windDirection;    //风向	float[0, 360)	单位为度
    Z_U8 onflowState;       //湍流开关	uint8 / 0 - 关；1 - 开；其它 - 无效；
    Z_U8 gustState;         //阵风开关	uint8 / 0 - 关；1 - 开；其它 - 无效；
    Z_U8 windShearState;    //风切变开关	uint8 / 0 - 关；1 - 开；其它 - 无效；
    Z_U32 date;             //日期	uint32	[0,20500000]	用整数表示的当天日期：年月日，如2020-8-30，整数为20200830
    Z_U32 time;             //时间	uint32	[0,235959999]	用整数表示的当前时间：时分秒毫秒，如16:54:46:200，整数为165446200
    Z_F32 seaTemperature;   //海平面温度	float	(-50,100)	单位为摄氏度

    CONSTRUCT(SceneWeatherInfo);
};

ICD2002G_NAMESPACE_END
#pragma pack(pop)
