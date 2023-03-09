#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：飞机阶段状态软件 UAV Stage Software （USS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：阶段状态请求数据包
TOPIC：DL-USS-UAVSTAGE-CMD	USS-UAVSTAGE-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + UavStageCMD[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct UavStageCMD
{
	Z_I32 type;    ///<计算公式 0:飞前检查 1:MPS 2:放飞状态 3:放飞状态 4:Cruise状态 5:任务区 6:RTBGA
    Z_U8  seatId;   ///<席位ID

    CONSTRUCT(UavStageCMD);
};

/*
包名称：阶段状态回执数据包
TOPIC：DL-USS-UAVSTAGE-STATUS     USS-UAVSTAGE-STATUS
完整包结构：BasicPktHeader + ArrayPktHeader + UavStageStatus[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct UavStageStatus
{
    Z_U8  seatId;   ///<席位ID
	Z_I32 type;		///<计算公式 0:飞前检查 1:MPS 2:放飞状态 3:放飞状态 4:Cruise状态 5:任务区 6:RTBGA
	Z_I32 data1;	///<飞前检查百分比 DPI：100%
	Z_I32 data2;	///<MPS百分比 DPI：100%
	Z_I32 data3;	///<放飞状态百分比 DPI：100%
	Z_I32 data4;	///<Cruise状态百分比 DPI：100%
	Z_I32 data5;	///<任务区百分比 DPI：100%
	Z_I32 data6;	///<RTBGA百分比 DPI：100%

    CONSTRUCT(UavStageStatus);
};

ICD2002G_NAMESPACE_END
#pragma pack(pop)
