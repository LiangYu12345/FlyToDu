#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：数据链仿真 DataLink Simulation Software（DLS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：仿真数据链状态数据包
TOPIC：DLS-DLK-STA
完整包结构：BasicPktHeader + ArrayPktHeader + DataLinkStatePublicSeg + DataLinkStateArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct DataLinkStatePublicSeg
{
    Z_U8 curClient;         //当前数据链端	uint8 / "公共数据块，0 - 地面端；1 - 机载端；其它 - 无效；"
    Z_U8 curdataLinkID;     //当前数据链ID	uint8[0, 255]	公共数据块，取值为无人机ID或地面端ID
    Z_U8 curdataLinkType;   //当前数据链类型	uint8 / "公共数据块，0 - C链；1 - L链；2 - U链；3 - S链；4 - 卫通；其它 - 无效；"

    CONSTRUCT(DataLinkStatePublicSeg);
};

struct DataLinkStateArraySeg
{
    Z_U8 cmdType;       //链路状态回传Label	uint8 / 指令类型Label，详见数据链控制指令定义
    Z_U8 cmdValue;      //链路状态定义说明	uint8 / 指令定义说明，详见数据链控制指令定义
    Z_I16 param1;       //链路状态参数1	int16 / 指令参数1，详见数据链控制指令定义
    Z_F32 param2;       //链路状态参数2	float / 预留，置零

    CONSTRUCT(DataLinkStateArraySeg);
};

/*
包名称：仿真数据链状态数据包
TOPIC：DL-DLS-DLK-STA
完整包结构：BasicPktHeader + ArrayPktHeader + DataLinkSimStateArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct DataLinkSimStateArraySeg
{
    Z_U8 UAVID;             //无人机ID
    Z_U8 dataLinkType;      //当前数据链类型 Type_C = 0,Type_L = 1,Type_U = 2,Type_S = 3,Type_Ku = 10,Type_Ka = 11

    Z_F64 packetLossRatio;  //丢包率
    Z_F64 delayMilli;       //延时

    Z_U64 packetRecvCount;  //收包数
    Z_U64 packetLossCount;  //丢包数
    Z_U64 packetSendCount;  //发包数

    DataLinkSimStateArraySeg()
    {
        memset(this, 0, sizeof(DataLinkSimStateArraySeg));
    }
};

/*
包名称：仿真数据链状态数据包
TOPIC：DLS-DLK-SIM-STA
完整包结构：BasicPktHeader + DataLinkSimStateSeg + BasicPktTail
*/
struct DataLinkSimStateSeg
{
	Z_U8 UAVID;             //无人机ID
	Z_U8 dataLinkType;      //当前数据链类型 Type_C = 0,Type_L = 1,Type_U = 2,Type_S = 3,Type_Ku = 10,Type_Ka = 11

	Z_F64 packetLossRatio;  //丢包率
	Z_F64 delayMilli;       //延时
	Z_F64 errorRatio;		//误码率

	Z_U8  iTsfDir;			//传输方向：0 - 上行 ；1-下行
	Z_U8  bState;			//上行连接状态	
	Z_U8  powerType;		//功率   大功率、小功率、静默
	Z_U8  iChannelId;		//频道ID  1-10 
	Z_U8  iTzType;			//调制类型 0 - QPSK ； 1 - OFDM
	Z_F64 fChannelValue;	//频道值 12.8kpbs 
	Z_U8  iTDId;			//0 - 通道1 ；1 - 通道2 ； 2 - 通道3；3 - 通道4
	Z_U8  iAntennaType;		//天线状态
	Z_U8  iWaveType;        //波形  0 -直扩； 1 - 调频； 2 - 窄带
	Z_F64 fWaveValue;		// 信道值
	Z_F64 fJkValue;			// 解扩值
	Z_F64 fSignal;			//信号值	
	Z_U64 packetRecvCount;  //收包数
	Z_U64 packetLossCount;  //丢包数
	Z_U64 packetSendCount;  //发包数

	DataLinkSimStateSeg()
	{
		memset(this, 0, sizeof(DataLinkSimStateSeg));
	}
};
ICD2002G_NAMESPACE_END
#pragma pack(pop)