#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：ALC软件 Load Control Software （LCS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：语音识别成功数据包
TOPIC：SRS-CTRL-CMD
完整包结构：BasicPktHeader + SRCtrlCmd + BasicPktTail
*/
struct SRCtrlCmd
{
    Z_U8 seatId;   		//席位编号
    Z_U8 seatType;      //席位类型
    Z_U8 cmdValue[128]; //命令值
    Z_F32 param1;       //保留


    CONSTRUCT(SRCtrlCmd);
};

/*
包名称：语音识别软件接受控制包
TOPIC：SRS-CTRLED
完整包结构：BasicPktHeader + SRCtrled + BasicPktTail
*/
struct SRCtrled
{
	Z_U8 seatId;   		//席位编号
	Z_U8 seatType;      //席位类型
	Z_U8 cmd;			//命令			//0Hidden界面, 1DISP界面｛cmdValue:提示字符串｝
	Z_U8 cmdValue[128]; //命令值
	Z_F32 reserve;      //保留
	
	CONSTRUCT(SRCtrled)
};

ICD2002G_NAMESPACE_END
#pragma pack(pop)