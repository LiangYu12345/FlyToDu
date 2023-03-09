#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：系统管理软件 System Management Software （SMS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：运行软件的生存状态数据包
TOPIC：SMS-SOFTWARE-STA
完整包结构：BasicPktHeader + ArrayPktHeader + SoftwareStatePublicSeg + SoftwareStateArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct SoftwareStatePublicSeg
{
    Z_U8 seatID; //席位ID	uint8	[0,20]	公共数据块，无量纲数，LSB=1

    CONSTRUCT(SoftwareStatePublicSeg);
};

struct SoftwareStateArraySeg
{
    Z_U8 softwareID;    //软件ID	uint8	[0,255]	周期数据块，无量纲数，LSB=1
    Z_U8 runState;      //软件运行状态	uint8	/	周期数据块，0-停止；1-运行；其它-无效

    CONSTRUCT(SoftwareStateArraySeg);
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)