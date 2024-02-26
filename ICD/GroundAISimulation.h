#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：地面AI仿真 Ground AI Simulation （AIS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：地面AI运动状态数据包
TOPIC：AIS-AI-INFO-STA
完整包结构：BasicPktHeader + GroundAIMotionState + BasicPktTail
*/
struct GroundAIMotionState
{
    Z_U16 targetID;         //目标ID	uint16[256, 65535]	无量纲数，LSB = 1
    Z_U16 targetType;       //Type	uint16[0, 65535]	详见场景中Type定义
    Z_I32 longitude;        //经度	int32(-180, 180]	周期数据块，单位为度，LSB = 0.0000001°
    Z_I32 latitude;         //纬度	int32[-90, 90]	周期数据块，单位为度，LSB = 0.0000001°
    Z_F32 altitude;         //高度	float[-500, 20000]	周期数据块，单位为m
    Z_F32 heading;          //航向角	float[0, 360)	周期数据块，单位为度
    Z_F32 pitch;            //俯仰角	float(-90, 90)	周期数据块，单位为度
    Z_F32 roll;             //横滚角	float(-180, 180)	周期数据块，单位为度
    Z_F32 groundSpeed;      //地速	float[0, 1200]	单位为km / h
    Z_I16 reserve1;         //预留	int16 / 置零
    Z_U8 reserve2;          //预留	uint8 / 置零

    CONSTRUCT(GroundAIMotionState);
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)