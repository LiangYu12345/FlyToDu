#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：LDS Image仿真 Load Image Simulation Software
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：无人机LDS Image仿真经纬高数据包
TOPIC：DL-LIS-DATA-STA    LIS-DATA-STA
完整包结构：BasicPktHeader + UAVloadImageDataState + BasicPktTail
*/
struct UAVloadImageDataState
{
	Z_U8  isEffect;  	//有效性 0-无效 1-有效
    Z_F32 ALT;       	//高度	float 
    Z_I32 LON;       	//经度	int32 LSB = 0.0000001
    Z_I32 LAN;       	//纬度	int32 LSB = 0.0000001
	Z_U32 reserve1;     //预留1
	Z_U32 reserve2;     //预留2

    CONSTRUCT(UAVloadImageDataState);
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)