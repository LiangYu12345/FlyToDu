#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：链路监控软件 DataLink Monitoring Software （DLM）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：数据链控制指令数据包
TOPIC：DLM-CTRL-CMD
完整包结构：BasicPktHeader + DataLinkCtrl + BasicPktTail
*/
struct DataLinkCtrl
{
    Z_U8 clientSelect;//数据链端SEL	uint8 / 0 - 地面端；1 - 机载端；其它 - 无效；
    Z_U8 dataLinkID;//被控链ID	uint8[0, 255]	取值为无人机ID或地面端ID
    Z_U8 dataLinkType;//数据链类型	uint8 / 0 - C链；1 - L链；2 - U链；3 - S链；10 - Ku链；11 - Ka链；其它 - 无效；；
    Z_U8 cmdType;//控制指令Label	uint8 / 指令类型Label，详见数据链控制指令定义
    Z_U8 cmdValue;//指令定义说明	uint8 / 指令定义说明，详见数据链控制指令定义
    Z_I16 param1;//指令参数1	int16 / 指令参数1，详见数据链控制指令定义
    Z_F32 param2;//指令参数2	float / 预留，置零

    CONSTRUCT(DataLinkCtrl);
};

enum class DataLinkCtrlCmdType
{
    //视距连指令相关
    DataLinkTypeChange = 1,     //1	链路类型切换指令	uint8 / "0-C链；1-L链；2-U链；3-S链；10 - Ku链；11 - Ka链；其它 - 无效；"
    UpModeCmd = 2,              //2	上行C、L、U、S链模式指令	uint8 / 0 - 工作；1 - 静默；其它 - 无效；
    DownModeCmd = 3,            //3	下行C、L、U、S链模式指令	uint8 / 0 - 工作；1 - 静默；其它 - 无效；
    UpChannelSelect = 4,        //4	上行频道通道SEL	uint8 / 1 - 有效；其它 - 无效；
                                    //频道SEL参数	频道通道SEL参数	int16[1, 10]	指令参数1，无量纲数
    DownChannelSelect = 5,      //5	下行频道通道SEL	uint8 / 1 - 有效；其它 - 无效；
                                    //频道SEL参数	频道通道SEL参数	int16[1, 10]	指令参数1，无量纲数
    UpPowerSelect = 6,          //6	上行功率SEL	uint8 / 0 - 小功率；1 - 大功率；2 - 静默 其它 - 无效；
    DownPowerSelect = 7,        //7	下行功率SEL	uint8 / 0 - 小功率；1 - 大功率；2 - 静默 其它 - 无效；
    EncodeSelect = 8,           //8	明文密文SEL	uint8 / 0 - 密文；1 - 明文；其它 - 无效；
    DownSpeedSelect = 9,        //9	下行速率SEL	uint8 / 0 - 2M-前视；1 - 4M-EO；2 - 4M-载荷；3 - 8M-复合；4-32M-复合；其它 - 无效；
    AntennaSelect = 10,         //10	天线SEL	uint8 / 1 - 地面全向；2 - 地面定向；3 - 全向机顶；4 - 全向机腹；5 - 定向机腹；其它 - 无效；
    StationChannelSelect = 11,  //11	站控通道SEL	uint8 / 0 - 网口站控；1 - 串口站控；其它 - 无效；
    RemoteChannelSelect = 12,   //12	遥控通道SEL	uint8 / 0 - 网口遥控；1 - 串口遥控；其它 - 无效；
    TimeCompare = 13,           //13	时间对比	uint8 / 0 - 关；1 - 开；其它 - 无效；
    PictureQualityChange = 14,  //14	画质切换	uint8 / 待定
    WaveSelect = 15,			//15    波形SEL 0 -直扩； 1 - 调频； 2 - 窄带
	TDSelect = 16 ,				//16    通道SEL 0 - 通道1 ；1 - 通道2 ； 2 - 通道3；3 - 通道4
    TZSelect = 17 ,				//17    调制SEL 0 - QPSK ； 1 - OFDM 
	//卫通链指令相关
    SpreadFreqSendSpeed = 41,   //41	扩频发数据速率指令	uint8 / 1 - 4kbps - BPSK - 卷；其它 - 无效；
    SpreadFreqRecvSpeed = 42,   //42	扩频收数据速率指令	uint8 / 1 - 4kbps - BPSK - 卷；其它 - 无效；
    NoneSpreadFreqSendSpeed = 43,   //43	非扩频发数据速率指令	uint8 / 1 - 4kbps - BPSK - 卷；其它 - 无效；
    NoneSpreadFreqRecvSpeed = 44,   //44	非扩频收数据速率指令	uint8 / 1 - 4kbps - BPSK - 卷；其它 - 无效；
    SendMediumFreq = 45,            //45	发中频频率	uint8 / 1 - 有效；其它 - 无效；
                                        //频率参数	发中频频率参数	int16[0, 4096]	指令参数1，单位为MHz
    SendMediumFreqLevel = 46,       //46	发中频电平	uint8 / 1 - 有效；其它 - 无效；
                                        //电平参数	发中频电平参数	int16[-50, 50]	指令参数1，单位为dBm
    SatcomUpChannelSelect = 47,     //47	上行频道通道SEL	uint8 / 1 - 有效；其它 - 无效；
                                        //频道SEL参数	上行频道通道SEL参数	int16[1, 10]	指令参数1，无量纲数
    SatcomDownChannelSelect = 48,   //48	下行频道通道SEL	uint8 / 1 - 有效；其它 - 无效；
                                        //频道SEL参数	下行频道通道SEL参数	int16[1, 10]	指令参数1，无量纲数
    SatcomUpPowerSelect = 49,       //49	上行功率SEL	uint8 / 0 - 小功率；1 - 大功率；其它 - 无效；
    SatcomDownPowerSelect = 50,     //50	下行功率SEL	uint8 / 0 - 小功率；1 - 大功率；其它 - 无效；
    SatcomEncodeSelect = 51,        //51	明文密文SEL	uint8 / 0 - 密文；1 - 明文；其它 - 无效；
    CarrierSwitch = 52,             //52	载波开关	uint8 / 0 - 关；1 - 开其；它 - 无效；
    PowerAmplifierSwitch = 53,       //53	功放开关	uint8 / 0 - 关；1 - 开；其它 - 无效；
	LDPCSwitch = 54,				//54   级联码SEL   0 - 级联码 ； 1 - LDPC码
    SAntennaSwitch = 55,			//55   天链/天通模式下发射天线SEL 0 - 发射天线工作 ; 1 - 发射天线校对 ；2 - 发射天线关
	RAntennaSwitch = 56,			//56   天链/天通模式下接收天线SEL 0 - 接收天线工作 ；1 - 接收天线校对
	RCarrierLoadType = 57			//57   天链/天通模式下反向传输功率SEL 0 - 反向3.2k  ; 1 - 反向 6.4k ； 2 - 反向12.8k	
};

/*
包名称：C链 数据链控制指令数据包
TOPIC：CDL-CTRL-CMD
完整包结构：BasicPktHeader + UavCDLDataCtrl + BasicPktTail
*/
struct UavCDLDataCtrl
{
	Z_U8 Id;				    //无人机编号
	Z_U8 mTsfDir;				//传输方向
	Z_U8 powerType;				//功率类型
	Z_U8 m_CId;					//频道 ID
	Z_U8 mTsfMode;				//传输方式
	Z_U8 mAntennaType;			//天线类型
	Z_U8 mBandWidth;			//传输带宽
	Z_U8 mTzType;				//调制类型
	Z_U8 enCode;				//编码 true 密码 false明码
	Z_U8 CalTime;				//校时 true 开，false 关
	CONSTRUCT(UavCDLDataCtrl);
};
/*
包名称：U链 数据链控制指令数据包
TOPIC：UDL-CTRL-CMD
完整包结构：BasicPktHeader + UavUDLDataCtrl + BasicPktTail
*/
struct UavUDLDataCtrl
{
	Z_U8 Id;				//无人机编号
	Z_U8 mTsfDir;			//传输方向
	Z_U8 powerType;			//功率类型
	Z_U8 m_CId;				//频道 ID
	Z_U8 m_TdId;			//通道 ID 
	Z_U8 m_waveType;		//波形类型	
	Z_U8 mTsfMode;			//传输方式
	Z_U8 mAntennaType;		//天线类型
	Z_U8 enCode;			//编码 true 密码 false明码
	Z_U8 CalTime;			//校时 true 开，false 关
	CONSTRUCT(UavUDLDataCtrl);
};
/*
包名称：Ku/ka链 数据链控制指令数据包
TOPIC：KDL-CTRL-CMD
完整包结构：BasicPktHeader + KDLDataCtrl + BasicPktTail
*/
struct KDLDataCtrl
{
	Z_U8 id;
	Z_U8 type;			//10:Ku频段 11:Ka频段
	Z_U8 gfPowerState;  // true:功放电源开，false:功放电源关
	Z_U8 code;			//1:级联码，2:LDPC	
	Z_U8 mBandWidth;		//反向速率：0:256kb,1:2Mb，2:4Mb，4:8Mb，5:16Mb -- 0:2M前视，1:4M视频,2:4M载荷,3:8M复合
	Z_U8 mAntennaWorkType; //天线工作方式: 0:工作，1：收藏，2：强制跟踪，3：校相，4：自检，5：待命，6：程序跟踪
	Z_U8 mJhMode;		   //天线极化模式: 0：东经-水平极化，1：东经-垂直极化，2：西经-水平极化，3:西经-垂直极化
	Z_F32 mJdValue;			//经度值

	Z_U8 mqsxl;				//前视速率: 0:2M, 1:4M
	Z_U8 meoxl;				//EO速率:	0:2M, 1:4M
	Z_U8 mqstype;			//前视类型:  0:模拟 ，1:数字
	Z_U8 meotype;			//EO类型:	 0:模拟，1:数字
	Z_U8 mxctype;			//下传类型: 前视(不)下传控制第一位， EO(不)下传控制第二位，载荷(不)下传控制第三位
	Z_U8 mtzType;			//调制方式：0:加调 ， 1:击调

	Z_F32 mplszKuFsValue;		//频率设置-Ku发射频率
	Z_F32 mplszKuJsValue;		//频率设置-Ku接收频率
	Z_F32 mplszKuBfFsValue;		//频率设置-Ku备份发射频率
	Z_F32 mplszKuBfJsValue;		//频率设置-Ku备份接收频率
	Z_F32 mplszKaFsValue;		//频率设置-Ka发射频率
	Z_F32 mplszKaJsValue;		//频率设置-Ka接收频率
	Z_F32 mplszKaBfFsValue;		//频率设置-Ka备份发射频率
	Z_F32 mplszKaBfJsValue;		//频率设置-Ka备份接收频率
	Z_F32 mplszKuXbValue;		//Ku信标频率
	Z_F32 mplszKaXbValue;		//Ka信标频率

	Z_U8 mxhszKu;			//星号设置:Ku星号 
	Z_U8 mxhszKuBf;			//星号设置:Ku备份星号
	Z_U8 mxhszKa;			//星号设置:Ka星号
	Z_U8 mxhszKaBf;			//星号设置:Ka备份星号
	Z_F32 mTzvalue;			//调制器电平
	Z_U8 mmjType;			//密码机控制：0:控制解锁，1:控制锁定,2:掉电毁钥，3:ADT毁钥
	Z_U8 enCode;			//编码 true 密码 false明码
	Z_U8 CalTime;			//校时 true 开，false 关
	CONSTRUCT(KDLDataCtrl);
};

/*
包名称：Ku/ka链 地面数据链控制指令数据包
TOPIC：KDL-DM-CTRL-CMD
完整包结构：BasicPktHeader + KDLDmDataCtrl + BasicPktTail
*/
struct KDLDmDataCtrl
{
	Z_U8 id;		//编号
	Z_U8 type;		//KU:Ku  KA:Ka
	Z_U8 tzjzType;  //0：A  1：B
	Z_U8 tzjzMode;  //0:Ku扩频调制非扩频调制 1:Ku扩频调制扩频调制 2:Ku非扩频调制非扩频调制 3:Ka 扩频调制非扩频调制 4:Ka扩频调制扩频调制 5:Ka非扩频调制非扩频调制
	Z_U8 tzjzkpSpeed;//0:收4kb 1:收8kb 2:收16kb
	Z_U8 tzjzKufkpfSpeed;//0:64kb-rs 1:256kb-rs  2:512kb-rs 3:2048kb-rs 4:256kb-LDPC 5:2048kb-LDPC 6:4096kb-LDPC 7:8192kb-LDPC
	Z_U8 tzjzKufkpsSpeed;//0:64kb-rs 1:256kb-rs  2:512kb-rs 3:2048kb-rs 4:256kb-LDPC 5:2048kb-LDPC 6:4096kb-LDPC 7:8192kb-LDPC
	Z_U8 tzjzKafkpfSpeed;//0:256kbps-OQPSK_LDPC  1:512kbps-OQPSK_LDPC  2:2048kbps-OQPSK_LDPC 3:4096kbps-OQPSK_LDPC 4:8192kbps-OQPSK_LDPC  5:16384kbps-OQPSK_LDPC
	Z_U8 tzjzKafkpsSpeed;//0:256kbps-OQPSK_LDPC  1:512kbps-OQPSK_LDPC  2:2048kbps-OQPSK_LDPC 3:4096kbps-OQPSK_LDPC 4:8192kbps-OQPSK_LDPC  5:16384kbps-OQPSK_LDPC
	Z_F32 tzjzKuFPl;	 //Ku 发射频率
	Z_F32 tzjzKuSPl;	 //Ku 收频率
	Z_F32 tzjzKaFPl;	 //Ka 发射频率
	Z_F32 tzjzKaSPl;	 //Ka 收频率
	Z_F32 tzjzDP;		 //发中频电平
	Z_U8 zbPower;		 //载波 1:开 0:关
	Z_U8 ppszxw;		 //频谱与时钟相位 0:调制频谱正相 1:调制频谱反相  2:解制频谱正相 3:解制频谱反相 4:收时钟正相 5:收时钟反相
	Z_U8 addrCode[2];	 //地址码 addrCode[0]: 0:Ku发地址码 1:Ku收地址码 2:Ka发地址码 3:Ka收地址码 addrCode[1]:地址码
	Z_U8 gfType;		 //KU: Ku功放 KA: Ka功放
	Z_U8 fsjId;			 //0: A   1:B
	Z_U8 jltdPower;		 //1:开 0:关
	Z_F32 sjValue;		 //衰减值
};
/*
包名称：U链 数据链控制指令数据包
TOPIC：SDL-CTRL-CMD
完整包结构：BasicPktHeader + SDLDataCtrl + BasicPktTail
*/
struct SDLDataCtrl
{
	Z_U8 id;
	Z_U8 type;				//S:天联模式，L:天通模式
	Z_U8 tzPower;			//0:关 1:开	
	Z_U8 sAntennaType;		//1:发射天线工作，2:发射天线校相，3:发射天线关
	Z_U8 rAntennaType;		//1:接收天线工作，2:接收天线校相
	Z_U8 preType;			//1:前向3.2k ，2:前向6.4k，3:前向12.8k
	Z_U8 rType;				//1:反向3.2k ，2:反向6.4k，3:反向12.8k
	Z_F32 sPlCtrl[2];		//频率控制 ： sPlCtrl[0] ： 0:天链发射频率 1:天链接收频率 2:天通发射频率 3:天通接收频率 sPlCtrl[1]:值
	Z_F32 dpValue;			//电平值
	Z_U8 enCode;			//编码 true 密码 false明码
	Z_U8 CalTime;			//校时 true 开，false 关
	CONSTRUCT(SDLDataCtrl);
};


/*
包名称：天线控制指令数据包
TOPIC：AD-CTRL-CMD
完整包结构：BasicPktHeader + AntennaDataCtrl + BasicPktTail
*/
struct AntennaDataCtrl
{
	Z_U8 id;			    //编号
	Z_U8 m_AntennaAmuizth;  //方位控制
	Z_U8 m_AntennaPitch;    //俯仰控制
	Z_U8 m_CtrlImage;	    //图像控制	
	Z_U8 m_AntennaTd;	    //天线通道模式
	CONSTRUCT(AntennaDataCtrl);
};

/*
包名称：天线控制指令数据包
TOPIC：ASTAR-CTRL-CMD
完整包结构：BasicPktHeader + AStarRDataCtrl + BasicPktTail
*/
struct AStarRDataCtrl
{
	Z_U32 id;			//编号	
	Z_F64 lon;		//位置lon
	Z_F64 lat;		//位置lat
	Z_F64 alt;		//位置alt
	Z_F64 yaw;		//偏航
	Z_F64 pitch;	//俯仰	
	Z_F64 roll;		//滚转
	CONSTRUCT(AStarRDataCtrl);
};


/*
包名称：干扰因子
TOPIC：DISTURBITEM-CTRL-CMD
完整包结构：BasicPktHeader + DisturbItemCtrl + BasicPktTail
*/

 struct DisturbItemCtrl
{
	 Z_U8 id;		//编号
	 Z_U8 enable;	//开启/关闭
	 Z_F64 lon;		//位置lon
	 Z_F64 lat;		//位置lat
	 Z_F64 alt;		//位置alt
	 Z_F64 yaw;		//偏航
	 Z_F64 pitch;	//俯仰	
	 Z_F64 roll;		//滚转
	 Z_U8  type;		//干扰方式 0压制 1欺骗
	 Z_F64 frequency;	//频率
	 Z_F64 fpower;		//功率
	 Z_F64 dir;			//发射方向
	 Z_U32 time;		//发射时间
	 Z_F64 dutyradio;	//占空比
	 CONSTRUCT(DisturbItemCtrl);
};
 /*
包名称：系统标校
TOPIC：SYSCALIB-CTRL-CMD
完整包结构：BasicPktHeader + SysCalibDataCtrl + BasicPktTail
*/
 struct SysCalibDataCtrl
 {
	 //地面站
	 //手动输入站
	 Z_F64 	  	m_ManualDmzPos_lon;	
	 Z_F64		m_ManualDmzPos_lat;
	 Z_F64		m_ManualDmzPos_alt;
	 //自动采集站
	 Z_F64		m_AutoDmzPos_lon;
	 Z_F64		m_AutoDmzPos_lat;
	 Z_F64		m_AutoDmzPos_alt;
	 Z_F64	m_DmzWcBc;	//俯仰 误差补偿
	 Z_F64	m_DmzWcSr;	//俯仰 输入补偿
	 //飞机方位定标
	 Z_U8	m_uavid;				//飞机ID
	 Z_F64		m_PlanePos_lon;		//飞机经纬度
	 Z_F64		m_PlanePos_lat;		//飞机经纬度
	 Z_F64		m_PlaneDb_lon;		//近距定标
	 Z_F64		m_PlaneDb_lat;		//近距定标
	 Z_F64	m_Dbresult;	//定标结果
	 //俯仰补偿	
	 Z_F64 m_pitchWcBc;	//误差补偿
	 Z_F64 m_pitchSrBc;	//输入补偿
	 //DM定标
	 Z_F64 m_wbjwxdcj;	//未标胶的无线电DM
	 Z_F64 m_xxsldw;	//下行速率档位
	 Z_F64 m_dqsldwcjwc;//当前速率档位保存的DM误差
	 Z_F64 m_bjwxdcj;	//标胶后的无线电DM
	 Z_F64 m_gpsDis;	//GPS距离
	 Z_F64 m_srDis;		//输入距离
 };

 /*
包名称：系统标校
TOPIC：RAINDECLINE-CTRL-CMD
完整包结构：BasicPktHeader + DRainDeclineCtrl + BasicPktTail
*/

 struct DRainDeclineCtrl
 {
	 Z_F32 attenuationValueC;		//链路C衰减值 dB/Km
	 Z_F32 attenuationValueU;		//链路U衰减值 dB/Km
	 Z_F32 attenuationValueKu;		//链路Ku衰减值 dB/Km
	 Z_F32 attenuationValueKa;		//链路Ka衰减值 dB/Km
	 Z_F32 attenuationValueS;		//链路S衰减值 dB/Km
	 Z_F32 zeroTempertureHeightC;	//零度等温高度C
	 Z_F32 zeroTempertureHeightU;	//零度等温高度U
	 Z_F32 zeroTempertureHeightKu;	//零度等温高度Ku
	 Z_F32 zeroTempertureHeightKa;	//零度等温高度Ka	
	 Z_F32 zeroTempertureHeightS;	//零度等温高度S
 };
ICD2002G_NAMESPACE_END
#pragma pack(pop)