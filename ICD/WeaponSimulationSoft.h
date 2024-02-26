#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：武器仿真 Weapon Simulation Software （WSS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：MSL运动状态数据包
TOPIC：WSS-MISSILE-STA
完整包结构：BasicPktHeader + MissileMotionState + BasicPktTail
*/
struct MissileMotionState
{
    Z_U16 missileID;        //MSLID	uint16[256, 65535]	无量纲数，LSB = 1
    Z_U8 mountID;           //挂载点ID	uint8[0, 255]	无量纲数，LSB = 1
    Z_U8 missileType;       //MSL类型	uint8[0, 255]	无量纲数，LSB = 1
    Z_U16 lockedTargetID;   //锁定的目标ID	uint16[256, 65535]	无量纲数，LSB = 1
    Z_U16 targetIDInScene;  //目标在场景中的ID	uint16[256, 65535]	无量纲数，LSB = 1 
    Z_I32 longitude;        //经度	int32(-180, 180]	单位为度，LSB = 0.0000001°
    Z_I32 latitude;         //纬度	int32[-90, 90]	单位为度，LSB = 0.0000001°
    Z_F32 altitude;         //高度	float[-500, 20000]	单位为m
    Z_F32 heading;          //航向角	float[0, 360)	单位为度
    Z_F32 pitch;            //俯仰角	float(-90, 90)	单位为度
    Z_F32 roll;             //横滚角	float(-180, 180)	单位为度
    Z_U8 isExplosion;       //是否爆炸	uint8 / 0 - 未爆炸；1 - 爆炸；其它 - 无效；
    Z_U16 reserve1;         //预留	16位无符号数 / 置零

    CONSTRUCT(MissileMotionState);
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)