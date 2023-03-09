#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：综合控制软件 IntegratedCtrl Software （ICS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：编队飞行Voyage-plan数据包
TOPIC：ICS-TEAMAIRWAYPLAN-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + TeamRoutePlanArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/

struct TeamRoutePlanArraySeg
{
    Z_U8 routeID;           // 航点所属航线ID	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorR;    // 子航线R(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorG;    // 子航线G(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorB;    // 子航线B(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorA;    // 子航线A(透明度)	uint8[0, 100]	周期数据，无量纲数，LSB = 1
    Z_U8 wptIDInRoute;      // 航点导航ID（总航点ID）	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_I32 longitude;        //int32	(-180, 180]	周期数据，单位为度，LSB=0.0000001°
    Z_I32 latitude;         //int32	[-90, 90]	周期数据，单位为度，LSB=0.0000001°
    Z_F32 altitude;         //float	[-500,20000]	周期数据，单位为m
    Z_F32 speed;            // 航点速度	float[0, 1200]	周期数据，单位为km / h 
    Z_U8 motionType;        // 航路点机动指令			周期数据，0 - 过点；1 - 压点；
    Z_U16 reserve1;         // 预留	uint16 / 周期数据，预留置零
    Z_U8 reserve2;          // 预留	uint8 / 周期数据，预留置零

    CONSTRUCT(TeamRoutePlanArraySeg);
};

/*
包名称：编队飞行RP规划数据包
TOPIC：DL-ICS-RALLYPOINT-CMD    ICS-RALLYPOINT-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + RallyPointArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct RallyPointArraySeg
{
    Z_U8  rptID;            // RP的ID	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8  rpt;              // RP的类型	uint8[0, 255]	周期数据，0 - Take-offRP；1 - 降落RP；
    Z_I32 longitude;        //int32	(-180, 180]	周期数据，单位为度，LSB=0.0000001°
    Z_I32 latitude;         //int32	[-90, 90]	周期数据，单位为度，LSB=0.0000001°
    Z_F32 altitude;         //float	[-500,20000]	周期数据，单位为m
    Z_F32 speed;            // 航点速度	float[0, 1200]	周期数据，单位为km / h 
    Z_U8 motionType;        // 航路点机动指令			周期数据，0 - 过点；1 - 压点；
    Z_U16 reserve1;         // 预留	uint16 / 周期数据，预留置零
    Z_U8 reserve2;          // 预留	uint8 / 周期数据，预留置零

    CONSTRUCT(RallyPointArraySeg);
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)
