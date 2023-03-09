#pragma once

#include <string.h>

#pragma pack(push)
#pragma pack(1)

#define ICD2002G_NAMESPACE_BEGIN namespace ICD2002G {
#define ICD2002G_NAMESPACE_END }

ICD2002G_NAMESPACE_BEGIN

#define Z_U8    unsigned char
#define Z_I8    signed char
#define Z_U16   unsigned short
#define Z_I16   short
#define Z_U32   unsigned int
#define Z_I32   int
#define Z_U64   unsigned long long
#define Z_I64   long long
#define Z_F32   float
#define Z_F64   double

#define POSLSB 0.0000001f

#define CONSTRUCT(_X) _X(){memset(this, 0, sizeof(_X));}

//类型
enum class OBJ_TYPE
{
    OBJ_AIR = 0,                //Air_obj
    OBJ_AIR_WC = 1,             //战斗机
    OBJ_AIR_WC_J8,              //J8
    OBJ_AIR_WC_J10,             //J10
    OBJ_AIR_WC_J11,             //J11
    OBJ_AIR_WC_J15,             //J15
    OBJ_AIR_WC_J20,             //J20
    OBJ_AIR_WC_J31,             //J31
    OBJ_AIR_WC_F18,             //F18
    OBJ_AIR_WC_F16,             //F16
    OBJ_AIR_WC_F22,             //F22
    OBJ_AIR_WC_F35,             //F35
    OBJ_AIR_WC_S27,             //S27
    OBJ_AIR_WC_S35,             //S35
    OBJ_AIR_WC_S57,             //S57

    OBJ_AIR_BB = 21,            //轰炸机
    OBJ_AIR_BB_H6K,             //轰6K
    OBJ_AIR_BB_B1,              //B1
    OBJ_AIR_BB_B2,              //B2
    OBJ_AIR_BB_T22,             //图22
    OBJ_AIR_BB_T160,            //图160

    OBJ_AIR_HC = 41,            //直升机
    OBJ_AIR_HC_Z9,              //直9
    OBJ_AIR_HC_WZ10,            //武装直升机10
    OBJ_AIR_HC_UH60,            //黑鹰直升机
    OBJ_AIR_HC_AH64,            //卡帕奇武装直升机
    OBJ_AIR_HC_RAH66,           //科曼奇武装直升机
    OBJ_AIR_HC_Mi24,            //雌鹿武装直升机

    OBJ_AIR_TR = 61,            //运输机
    OBJ_AIR_TR_Y9,              //运9
    OBJ_AIR_TR_Y20,             //运20
    OBJ_AIR_TR_C130,            //大力神运输机
    OBJ_AIR_TR_C17,             //环球霸王运输机

    OBJ_AIR_UAV = 81,           //无人机
    OBJ_AIR_UAV_YL1,            //Wing Loong1无人机
    OBJ_AIR_UAV_YL2,            //Wing Loong2无人机
    OBJ_AIR_UAV_CH4,            //CH-4无人机
    OBJ_AIR_UAV_YY,             //Cyunying无人机
    OBJ_AIR_UAV_LJ,             //Gongji无人机
    OBJ_AIR_UAV_XY,             //Soar Dragon无人机
    OBJ_AIR_UAV_MQ1,            //RQ-4无人机
    OBJ_AIR_UAV_MQ9,            //MQ-1无人机
    OBJ_AIR_UAV_X47b,           //X47b无人机
    OBJ_AIR_UAV_QF16,           //QF16无人机

    OBJ_AIR_MS = 101,           //MSL
    OBJ_AIR_MS_LJ7,             //蓝剑7MSL
    OBJ_AIR_MS_HQ16,            //红旗16MSL
    OBJ_AIR_MS_MISSILE_1,       //AG300MSL
    OBJ_AIR_MS_MISSILE_2,       //BA-7MSL
    OBJ_AIR_MS_MISSILE_3,       //BA-21MSL
    OBJ_AIR_MS_MISSILE_4,       //CM-502KGMSL
    OBJ_AIR_MS_MISSILE_5,       //CS/BBM2MSL
    OBJ_AIR_MS_MISSILE_6,       //CS/BBM3MSL
    OBJ_AIR_MS_MISSILE_7,       //GB4MSL
    OBJ_AIR_MS_MISSILE_8,       //LS-6/50MSL ->激光弹
    OBJ_AIR_MS_MISSILE_9,       //LS-6/100MSL
    OBJ_AIR_MS_MISSILE_10,      //YJ-9EMSL
	OBJ_AIR_MS_FT_7,			//滑翔弹

    OBJ_GRD = 200,              //Grd_obj
    OBJ_GRD_VEH = 201,          //车辆
    OBJ_GRD_VEH_JEEP,           //吉普车
    OBJ_GRD_VEH_FMTV,           //卡车
    OBJ_GRD_VEH_TRANSPORTCART,  //运输车
    OBJ_GRD_VEH_CAR001,         //txh 新增
    OBJ_GRD_VEH_CAR002,         //txh 新增
    OBJ_GRD_VEH_CAR003,         //txh 新增

    OBJ_GRD_TANK = 241,         //坦克
    OBJ_GRD_TANK_59,            //59式主战坦克
    OBJ_GRD_TANK_99,            //99式主战坦克
    OBJ_GRD_TANK_M1A2,          //M1A2主战坦克
    OBJ_GRD_TANK_T72,           //T72主战坦克
    OBJ_GRD_TANK_T90,           //T90主战坦克
    OBJ_GRD_TANK_ZTD05,         //ZTD05主战坦克   txh 新增
    OBJ_GRD_TANK_PLZ07,         //PLZ07主战坦克   txh 新增
    OBJ_GRD_TANK_PHL03,         //PHL03主战坦克   txh 新增
    OBJ_GRD_TANK_001,           //tank001主战坦克 txh 新增
	OBJ_GRD_AI ,				//人控车辆

    OBJ_GRD_FO = 261,           //固定目标
    OBJ_GRD_FO_RDR,             //地面雷达
    OBJ_GRD_FO_BUD,             //地面目标建筑
    OBJ_GRD_FO_BUD03,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD04,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD05,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD06,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD07,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD08,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD09,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD10,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD11,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD12,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD13,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD14,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD15,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD16,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD17,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD18,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD19,           //地面目标建筑  txh 新增
    OBJ_GRD_FO_BUD20,           //地面目标建筑  txh 新增

    OBJ_GRD_PERSON = 300,       //人物模型      txh 新增
    OBJ_GRD_PERSON_001,         //人物模型  001 txh 新增
    OBJ_GRD_PERSON_002,         //人物模型  002 txh 新增
    OBJ_GRD_PERSON_003,         //人物模型  003 txh 新增
    OBJ_GRD_PERSON_004,         //人物模型  004 txh 新增
    OBJ_GRD_PERSON_005,         //人物模型  005 txh 新增

    OBJ_SEA = 400,              //海上对象
    OBJ_SEA_WS = 401,           //军舰
    OBJ_SEA_WS_055,             //055型驱逐舰
    OBJ_SEA_WS_054a,            //054A型护卫舰
    OBJ_SEA_WS_001,             //辽宁舰
    OBJ_SEA_WS_Flight,          //"伯克"级MSL驱逐舰
    OBJ_SEA_WS_CVN68,           //“尼m兹”级航空母舰

    OBJ_SEA_SM = 441,           //潜艇
    OBJ_SEA_SM_094,             //094型核潜艇
    OBJ_SEA_SM_095,             //095型核潜艇
    OBJ_SEA_SM_SSN,             //“洛杉矶”级核潜艇
    OBJ_SEA_SM_SSGN,            //“俄亥俄”级核潜艇

    OBJ_SEA_CIV = 461,          //民用船

    OBJ_TA = 500,               //威胁区
    OBJ_TASK_REGION,            //任务区域
    OBJ_FORBID_REGION           //禁飞区域
};

//定长数据包、变长数据包公共包头
struct BasicPktHeader
{
    Z_U8  fixValue1;    //固定值 0xAA
    Z_U8  fixValue2;    //固定值 0x55
    Z_U16 pktLen;       //包长度 本数据帧的节数总字
    Z_U8  loopCount;    //循环计数器
    Z_U8  UAVID;        //无人机ID
    Z_U8  UAVType;      //无人机类型
    Z_U8  pktType;      //数据包类型 0-定长包 1-变长包

    BasicPktHeader()
    {
        memset(this, 0, sizeof(BasicPktHeader));
        fixValue1 = 0xAA;
        fixValue2 = 0x55;
    }
};

//变长数据包包头
struct ArrayPktHeader
{
    Z_U8 publicLen;                //公共数据块字节数
    Z_U8 oneArrayLen;              //单个周期数据块字节数
    Z_U8 arrayCountAll;            //周期数据块总数
    Z_U8 arrayCountInPkt;          //当次周期数据块个数
    Z_U8 startArrayIndexInPkt;     //当次起始周期数据块序号

    CONSTRUCT(ArrayPktHeader);
};

//包尾
struct BasicPktTail
{
    Z_U8 sum; //校验和 前面所有字节求和取256补码

    CONSTRUCT(BasicPktTail);
};

ICD2002G_NAMESPACE_END
#pragma pack(pop)
