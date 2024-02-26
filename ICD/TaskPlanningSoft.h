#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：MPS软件 MPS Software （TPS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：无人机光电吊舱规划数据包
TOPIC：DL-TPS-EOPLAN-CMD     TPS-EOPLAN-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + EOPlanArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct EOPlanArraySeg
{
    Z_U8 routeID;           //航路ID	uint8[0, 255]	周期数据块，无量纲数，LSB = 1
    Z_U8 wptIDInRoute;      //航点导航ID（总航点ID）	uint8[0, 255]	周期数据块，无量纲数，LSB = 1
    Z_U16 distanceToWpt;    //到航路点距离	uint16[4500, 65535]	周期数据块，单位为m
    Z_F32 initAzimuth;      //初始方位角	float(-180, 180]	周期数据块，单位为度
    Z_F32 initPitch;        //初始俯仰角	float[0, 90]	周期数据块，单位为度
    Z_U8 EOPower;           //吊舱开关机控制	uint8 / "周期数据块，0 - 关机；1 - 开机；其它 - 无效；"
    Z_U8 VLPower;           //TV开关	uint8 / "周期数据块，0 - 关机；1 - 开机；其它 - 无效；"
    Z_U16 VLDuration;       //TV持续时间	uint16[0, 65535]	周期数据块，单位为秒
    Z_F32 hVLFOV;           //可将光水平视场角H	float[0, 180]	周期数据块，单位为度
    Z_F32 vVLFOV;           //可将光垂直视场角V	float[0, 180]	周期数据块，单位为度
    Z_U8 IRPower;           //IR开关	uint8 / "周期数据块，0 - 关机；1 - 开机；其它 - 无效；"
    Z_U16 IRDuration;       //IR持续时间	uint16[0, 65535]	周期数据块，单位为秒
    Z_F32 hIRFOV;           //IR水平视场角H	float[0, 180]	周期数据块，单位为度
    Z_F32 vIRFOV;           //IR垂直视场角V	float[0, 180]	周期数据块，单位为度
    Z_U8 reserve1;          //预留	uint8 / 周期数据块，预留置零

    CONSTRUCT(EOPlanArraySeg);
};

/*
包名称：无人机SAR雷达规划数据包
TOPIC：DL-TPS-SARPLAN-CMD    TPS-SARPLAN-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + SARPlanArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct SARPlanArraySeg
{
    Z_U8 routeID;               //航路ID	uint8[0, 255]	周期数据块，无量纲数，LSB = 1
    Z_U8 wptIDInRoute;          //航点导航ID（总航点ID）	uint8[0, 255]	周期数据块，无量纲数，LSB = 1
    Z_U16 distanceToWpt;        //到航路点距离	uint16[4500, 65535]	周期数据块，单位为m
    Z_U8 SARPower;              //SAR开关机控制	uint8 / "周期数据块，0 - 关机；1 - 开机；其它 - 无效；"
    Z_U16 SARDuration;          //SAR持续时间	uint16[0, 65535]	周期数据块，单位为秒
    Z_I32 stripeResolution;     //条带DPI	int32 / "周期数据块，0 - 3m；1 - 1m；2 - 0.5m；其它 - 无效；"
    Z_I32 stripeAzimuth;        //条带方位角	int[0, 1)	0-左侧视；1-右侧视；其他无效
    Z_U16 scanDistance;         //扫描距离	uint16[0, 20]	周期数据块，单位为千m
    Z_U16 reserve1;             //预留	uint16 / 周期数据块，预留置零
    Z_U8 reserve2;              //预留	uint8 / 周期数据块，预留置零

    CONSTRUCT(SARPlanArraySeg);
};

/*
包名称：数据链规划数据包
TOPIC：TPS-DLKPLAN-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + DataLinkPlanPublicSeg + DataLinkPlanArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct DataLinkPlanPublicSeg
{
    Z_U8 clientSelect;      //数据链端SEL	uint8 / "公共数据块，0 - 地面端；1 - 机载端；其它 - 无效；"
    Z_U8 dataLinkID;        //被控链ID	uint8[0, 255]	公共数据块，取值为无人机ID或地面端ID
    Z_U8 dataLinkType;      //数据链类型	uint8 / "公共数据块，0 - C链；1 - L链；2 - U链；3 - S链；4 - 卫通；其它 - 无效；"

    CONSTRUCT(DataLinkPlanPublicSeg);
};

struct DataLinkPlanArraySeg
{
    Z_U8 routeID;           //航路ID	uint8[0, 255]	周期数据块，无量纲数，LSB = 1
    Z_U8 wptIDInRoute;      //航点导航ID（总航点ID）	uint8[0, 255]	周期数据块，无量纲数，LSB = 1
    Z_U16 distanceToWpt;    //到航路点距离	uint16[4500, 65535]	周期数据块，单位为m
    Z_U8 cmdType;           //控制指令Label	uint8 / 指令类型Label，详见数据链控制指令定义
    Z_U8 cmdValue;          //指令定义说明	uint8 / 指令定义说明，详见数据链控制指令定义
    Z_I16 param1;           //指令参数1	int16 / 指令参数1，详见数据链控制指令定义
    Z_F32 param2;           //指令参数2	float / 预留，置零

    CONSTRUCT(DataLinkPlanArraySeg);
};

/*
包名称：无人机飞行Voyage-plan数据包
TOPIC：TPS-AIRWAYPLAN-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + RoutePlanPublicSeg + RoutePlanArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct RoutePlanPublicSeg
{
    Z_U8 routeID;       //航路ID	    uint8	[0, 255]
    Z_U8 subRouteCount; //子航线条数	uint8	[0,10]

    CONSTRUCT(RoutePlanPublicSeg);
};

struct RoutePlanArraySeg
{
    Z_U8 subRouteID;        // 航点所属子航线ID	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorR;    // 子航线R(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorG;    // 子航线G(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorB;    // 子航线B(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorA;    // 子航线A(透明度)	uint8[0, 100]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteType;      // 子航线类型	uint8 / "周期数据，1 - Take-off；2 - Climbing；3 - Cruise；4 - 下降；5 - GA；其它 - 无效；"
    Z_U8 wptIDInSubRoute;   // 航点在子航线里的ID	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 wptIDInRoute;      // 航点导航ID（总航点ID）	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_I32 longitude;        //int32	(-180, 180]	周期数据，单位为度，LSB=0.0000001°
    Z_I32 latitude;         //int32	[-90, 90]	周期数据，单位为度，LSB=0.0000001°
    Z_F32 altitude;         //float	[-500,20000]	周期数据，单位为m
    Z_F32 speed;            // 航点速度	float[0, 1200]	周期数据，单位为km / h 
    Z_U8 motionType;        // 航路点机动指令			周期数据，0 - 过点；1 - 压点；
    Z_U16 reserve1;         // 预留	uint16 / 周期数据，预留置零
    Z_U8 reserve2;          // 预留	uint8 / 周期数据，预留置零

    CONSTRUCT(RoutePlanArraySeg);
};

/*
包名称：无人机MSL规划数据包
TOPIC：DL-TPS-MISSILEPLAN-CMD    TPS-MISSILEPLAN-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + MissilePlanArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct MissilePlanArraySeg
{
    Z_U16 missileID;        //MSLID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
    Z_U8 mountID;           //挂载点ID	uint8	0~255	周期数据块，无量纲数，LSB = 1
    Z_U8 missileType;       //MSL类型	uint8	0~255	周期数据块，无量纲数，LSB = 1
    Z_U16 explosionRadius;  //爆炸半径	uint16(0, 1000]	周期数据块，单位为m，LSB = 1m
    Z_I16 reserve1;         //预留	int16 / 周期数据块，预留置零

    CONSTRUCT(MissilePlanArraySeg);
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)