#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：火控仿真 Fire Control Simulation （FCS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：武器发射指令数据包
TOPIC：DL-FCS-WEAPONLAUNCH-CMD   FCS-WEAPONLAUNCH-CMD
完整包结构：BasicPktHeader + WeaponLaunchCmd + BasicPktTail
*/
struct WeaponLaunchCmd
{
    Z_U16 missileID;    //发射MSLID	uint16[256, 65535]	无量纲数，LSB = 1
    Z_U8 mountID;       //挂载点ID	uint8[1, 255]	无量纲数，LSB = 1
    Z_U8 missileType;   //MSL类型	uint8[0, 255]	常见MSL类型
    Z_U8 attackType;    //攻击目标方式	uint8 / 1 - 攻击目标ID有效；2 - 攻击点位置有效；其它 - 无效；
    Z_U8 targetID;      //锁定的目标ID	uint8[256, 65535]	无量纲数，LSB = 1 
    Z_F32 altitude;     //攻击点高度	float[-500, 20000]	指令参数1，单位为m
    Z_I32 longitude;    //攻击点经度	int32(-180, 180]	指令参数2，单位为度，LSB = 0.0000001°
    Z_I32 latitude;     //攻击点纬度	int32[-90, 90]	指令参数3，单位为度，LSB = 0.0000001°

    CONSTRUCT(WeaponLaunchCmd);
};

/*
包名称：火控解算结果数据包
TOPIC：DL-FCS-FIRECALC-STA   FCS-FIRECALC-STA
完整包结构：BasicPktHeader + FireControlCalcResult + BasicPktTail
*/
struct FireControlCalcResult
{
    Z_U8 attackAzimuth;         //攻击方位角解算	uint8 / 0 - 不满足，1 - 满足
    Z_U8 aircraftPitch;         //飞机俯仰角解算	uint8 / 0 - 不满足，1 - 满足
    Z_U8 aircraftRoll;          //飞机横滚角解算	uint8 / 0 - 不满足，1 - 满足
    Z_U8 aircraftAltitude;      //飞机海拔解算	uint8 / 0 - 不满足，1 - 满足
    Z_U8 targetAltitude;        //目标高度解算	uint8 / 0 - 不满足，1 - 满足
    Z_U8 attackDis;             //攻击距离解算	uint8 / 0 - 不满足，1 - 满足
    Z_U8 flySpeed;              //飞行速度解算	uint8 / 0 - 不满足，1 - 满足
    Z_U8 laser;                 //激光条件解算	uint8 / 0 - 不满足，1 - 满足
    Z_U8 reserve1;              //预留	uint8 / 置零
    Z_F32 attackDisUpEdge;      //攻击距离上边界	float[0, 100]	单位为Km
    Z_F32 attackDisDownEdge;    //攻击距离下边界	float[0, 100]	单位为Km
    Z_I32 reserve2;             //预留	int32 / 置零

    CONSTRUCT(FireControlCalcResult);
};

/*
包名称：剩余弹量数据包
TOPIC：DL-FCS-MISSILECOUNT-STA   FCS-MISSILECOUNT-STA
完整包结构：BasicPktHeader + ArrayPktHeader + MissileCountArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct MissileCountArraySeg
{
    Z_U8 missileType;   //MSL类型	uint8[0, 255]	周期数据块，无量纲数，LSB = 1
    Z_U8 mountID;       //所在挂载点ID	uint8[0, 255]	周期数据块，无量纲数，LSB = 1

    CONSTRUCT(MissileCountArraySeg);
};

ICD2002G_NAMESPACE_END
#pragma pack(pop)