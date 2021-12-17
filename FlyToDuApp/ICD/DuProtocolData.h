#pragma once

#pragma pack(1)
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned char uchar;


struct InsGnssNet					//					89
{
	uint sysTime;					//系统时间			4
	ushort gpsWeek;					//GPSWeek			2
	uint gpsTime;					//GPS时间			4
	int gnssLon;					//GNSS经度			4
	int gnssLat;					//GNSS纬度			4
	int gnssAlt;					//GNSS高度			4
	short gnssEastSpeed;			//GNSS东向速度		2
	short gnssNorthSpeed;			//GNSS北向速度		2
	short gnssSkySpeed;				//GNSS天向速度		2
	ushort vdop;					//VDOP精度因子		2
	ushort hdop;					//HDOP精度因子		2
	uchar gpsCount;					//GPS定位星数		1
	uchar bdCount;					//北斗定位星数		1
	int lon;						//经度				4
	int lat;						//纬度				4
	int alt;						//高度				4
	short eastSpeed;				//东向速度			2
	short northSpeed;				//北向速度			2
	short skySpeed;					//天向速度			2
	short axialAccSpeed;			//轴向加速度		2
	short lateralAccSpeed;			//侧向加速度		2
	short normalAccSpeed;			//法向加速度		2
	ushort yaw;						//偏航角			2
	short pitch;					//俯仰角			2
	short roll;						//横滚角			2
	short yawSpeed;					//航向角速度		2
	short pitchSpeed;				//俯仰角速度		2
	short rollSpeed;				//滚转角速度		2
	ushort windSpeed;				//风速				2
	ushort windDirection;			//风向				2
	ushort gnssGroundSpeed;			//GNSS地速			2
	ushort gnssTrackAngle;			//GNSS航迹角		2
	short yawErrorCorrection;		//航向误差修正量	2
	short pitchErrorCorrection;	//俯仰误差修正量	2
	short rollErrorCorrection;		//横滚误差修正量	2
	ushort gnssSysState;			//系统状态字		2
	ushort gnssSysError;			//系统故障字		2
	uchar gnssVersion;				//软件版本			1
};

struct AdcNet						//					32
{
	short aos;						//侧滑角AOS			2
	short aoa;						//攻角AOA			2
	ushort vc;						//校准空速			2
	ushort vt;						//真空速			2
	ushort mach;					//马赫数			2
	short h;						//显示气压高度		2
	short ts;						//静温				2
	short hpr;						//升降速度HPR		2
	short tt;						//总温				2
	short hqne;						//标准气压高度Hqne	2
	ushort ps;						//静压				2
	ushort pt;						//全压pt			2
	ushort dataValid;				//数据有效性		2
	ushort sysError;				//系统故障字		2
	uchar version;					//软件版本			1
	ushort baroSet;					//气压基准设定		2
	uchar baroStd;					//气压基准			1
};

struct VhfNet
{
	uchar state;					//VHF状态字			1
	uint frequency;					//当前频率			4
	ushort selcal;					//选呼码			2
};

struct AdfNet						//					9
{
	uchar state;					//ADF状态字			1
	ushort frequency;				//ADF当前频率		2
	ushort azimuth;					//方位角			2
	uint code;						//站台识别码		4
};

struct DmeNet						//					13
{
	uchar state;					//DME状态字			1
	ushort channel;				//DME当前频率		2
	ushort distance;				//DME距离			2
	ushort groundSpeed;				//地速				2
	ushort time;					//到台时间			2
	uint code;						//DME站台识别码		4
};

struct MmrNet						//					13
{
	uchar state;					//MMR状态字			1
	ushort frequency;				//MMR当前频率		2
	short vorAzimuth;				//vor方位角			2
	short locDeviation;				//loc偏差			2
	short gsDeviation;				//gs偏差			2
	uint code;						//MMR站台识别码		4
};

struct XpdrNet						//					3
{
	uchar state;					//XPDR状态字		1
	ushort ssrCode;					//SSR编码			2
};

struct RaNet						//RA高度			3
{
	uchar state;					//RA状态字			1
	ushort raHeight;				//RA高度			2
};

struct CnsNet						//					62
{
	uchar moduleState;				//模块在线状态		1
	VhfNet vhf1;					//VHF1				7
	VhfNet vhf2;					//VHF2				7
	AdfNet adf;						//ADF				9
	DmeNet dme;						//DME				13
	MmrNet mmr;						//MMR(Vor/Ils)		13
	XpdrNet xpdr;					//XPDR				3
	RaNet ra;						//无线电高度		3
	uchar moduleError;				//模块故障状态      1
	uchar reserve;					//预留				1
};

struct RaBakNet					//RA高度备份		4
{
	RaBakNet()
	{
		state = 0;
		raHeight = 0;
		reserve = 0;
	}

	uchar state;					//RA状态字			1
	ushort raHeight;				//RA高度			2
	uchar reserve;					//预留				1
};

struct DiuNet						//					6
{
	uint diuError;					//DIU故障状态		4      pos:311~314
	uchar diuVersion;				//DIU版本			1      pos:315
	uchar fpgaVersion;				//FPGA版本			1      pos:316
};

struct EngineWarnNet
{
	uchar warnCode;			//告警码  317
	uchar space;			//预留    318
};

struct DecNet
{
	int FuelFlow;                    //0.0~260.0	gallons/h   1/64                                    燃烧流量        
	int EngineFailure;               //0x01：不显示;0x02: 显示：ENGINE（Engine Failure）                发动机故障
	int EngineOilPressure;           //0.0~5.0	BAR	 1/1024   Engine Oil Pressure (OIL PRESS)           机油压力       
	int EngineOilTemp;               //-65~150   1/128   Engine Oil Temperature (OIL TEMP)              机油温度       
	int ExhaustGasTemp;              //-70~+1100   1/16   Exhaust Gas Temperature (EGT)                 废气温度        
	int GasGeneratorSpeed;           //0~120    1/266  %  Gas Generator Speed (NG)                      气体发生器速度  
	int OilChipDetection;            //0X01：不显示;0X02：显示：CHIP；（OIL CHIP）                      石油芯片检测
	int OilFilterClogged;            //0X01：不显示 0X02：显示：OIL FILT；（Oil Filter Clogged）        油过滤器堵塞
	int PROP;                        //0~2800	rpm	1/8   Propeller (-Shaft) Speed (PROP)               螺旋桨轴转速   
	int TORQ;                        //0.0~110.0  %	0.00667%   Propeller (-Shaft) Torque (TORQ)         螺旋桨轴扭矩   
	int POWERSET;                    //0~100	%	1/256  Position of Metering Element (POWER SET)     计量元件位置  
	int EnginePower;                 //0.0~850.0	hp   1/16    Engine Power (ENGINE POWER)            发动机功率   
	unsigned int ManCtrl;            //手动控制 0x01:不显示  0x02:显示黄色警告MAN CTRL
	unsigned int VibrDng;            //震动警告  0x01:不显示 0x02:显示红色警告（VIBR DNG)
	unsigned int Aileron;            //             °       Aileron           (Ch5 Pressure)           副翼（CH5 压力）
	unsigned int RHPUMPON;           // 0x01:正常不显示; 0x02:显示"Righthand feeder pump on"                           
	unsigned int PWR_RETARD;         // 0x01:正常不显示; 0x02:显示"Throttle self retarding"                           
	unsigned int RUN;                // 0x01:正常不显示; 0x02:显示"Engine is running"                                 
	unsigned int PL;                 //           °     PL(CH4 Fuel Level)                                            
	unsigned int CHIPT;              // 0x01:正常不显示; 0x02:显示"Chips/Oil overheating in tyrbine bearing suppots" 
	unsigned int REVERSE;            // 0x01:正常不显示; 0x02:显示"Reverse lock open" 
	unsigned int EventReg;           // 0X01：正常不显示；0X02：显示“EVENT REG"
	unsigned int FailReg;            // 0X01：正常不显示；0X02：显示“FAIL REG"
	unsigned int MaintLvl_1;         // 0X01：正常不显示；0X02：显示“MAINT LVL 1"
	unsigned int MaintLvl_2;         // 0X01：正常不显示；0X02：显示“MAINT LVL 2"
	unsigned int MaintLvl_3;         // 0X01：正常不显示；0X02：显示“MAINT LVL 3"
	unsigned int VibrHigh;           // 0X01：正常不显示；0X02：显示“VIBR HIGH"
	unsigned int PwrLimit;           // 0x01:正常不显示；0x02：显示"PWR LIMIT"
};

struct Bat1Net
{
	int Battery1_voltage;            //       V  LSB:0.001953
	int Battery1_current;            //       A  LSB:0.125
	int Bat1_Failure;                //0x01：正常不显示；0x02：显示：BAT 1 FAIL(Battery 1 Failure)
	int Bat1_Charge;                 // 单位为:%  LSB：0.0625
};

struct Bat2Net
{
	int Battery2_voltage;            //       V  LSB:0.001953
	int Battery2_current;            //       A  LSB:0.125
	int Bat2_Failure;                //0x01：正常不显示；0x02：显示：BAT 2 FAIL(Battery 2 Failure)
	int Bat2_Charge;                 // 单位为:%  LSB：0.0625
};

struct Dcu1Net
{
	unsigned int FPUMPB;             //0x01：正常不显示；0x02：显示：F PUMP B（Main Fuel Pump B Failure）                                   
	unsigned int EsntlBusV;          //0~40.0      ESNTL BUS V    LSB为0.1V                       ESNTL总线电压    
	unsigned int FPRESS;             // 0x01:正常不显示; 0x02:显示"FUEL PRESS"（Fuel Pressure Low）                                
	unsigned int FXFERLH;            // 0x01:正常不显示; 0x02:显示"XFER FUEL L"（Fuel XFER Left Wing Tank Off / Disabled）                                      
	unsigned int AUXPON;             // 0x01:正常不显示; 0x02:显示"AUX F PUMP"（The auxiliary fuel pump is operating）                                      
	unsigned int Gen_1_Load;         //0.0~600       LSB:1A                                                              
	unsigned int PropPitch;          //0x01:正常不显示; 0x02:显示"BETA"（Propeller Pitch Low）   螺旋桨间距
	unsigned int HiLoadBus;          //0x01:正常不显示; 0x02:显示"HI LOAD BUS"（High Load Bus Offline / Failure）                                     
	unsigned int LWing;              //  LSB:0.1Gal    L Wing   输出99.9Gal时，显示：disconnected left wing probe                              
	unsigned int GEN1V;              //0~40.0    LSB:0.1V                                                
	unsigned int BusTies;            // 0x01:正常不显示; 0x02:显示"BUS TIES"（the bus ties for essential systems only are open）                     
	unsigned int CENTER;             //  LSB:1Gal   输出49.9Gal时，显示：disconnected center wing probe                         
	unsigned int FUEL_P;             //  0.0-6.990Bar                         
	unsigned int FXFERRH;            // 0x01:正常不显示; 0x02:显示"XFER FUEL R"（Fuel XFER Right Wing Tank Off / Disabled）                  
	unsigned int RWing;              // LSB:0.1Gal  输出99.9Gal时，显示：disconnected Right wing probe                               
	unsigned int FuelFilt;           // 0x01:正常不显示; 0x02:显示"FUEL FILT"（Fuel Filter Clogged）                      
	unsigned int ExtPwr;             // 0x01:正常不显示; 0x01:显示"EXT PWR"（the external power plug is connected to the aircraft.）                 
	int F_Temp;                      //-60-370℃        LSB:1℃                                        
	unsigned int N_EsntlBus;         // 0x01:正常不显示; 0x02:显示"N ESNTL BUS"（Non-Essential Bus Offline / Failure）             
	unsigned int Elevator;           // 44：Full Down   167：Neutral    289：Full Up
	unsigned int F_Punp_A;           // 0x01:正常不显示; 0x02:显示"F PUMP A"（Main Fuel Pump A Failure）                
	unsigned int Aero_F_Low;         // 0x01:正常不显示; 0x02:显示"AERO F LOW"（Aerobatic Fuel Level Low）                         
	unsigned int Canopy;             // 0x01:正常不显示; 0x02:显示"CANOPY"（Canopy Open）                         
	unsigned int RefDiode;           //                                                                 
	unsigned char wowState;          //轮载信号状态 D0:0-前轮无轮载；1-前轮有轮载
									 //             D1:0-左轮无轮载；1-左轮有轮载
									 //             D2:0-右轮无轮载；1-右轮有轮载      D3-D7:置零；     
	unsigned short wingAngle;        //襟翼位置     D0:0-襟翼处于UP状态；1-襟翼UP状态结束
									 //             D1：0-襟翼处于T/O状态；1-襟翼T/O状态结束
									 //             D2：0-襟翼处于LND状态；1-襟翼LND状态结束     
	unsigned int FUELLOW;            // 0x01:正常不显示; 0x02:显示"Fuel Low"                          
};

struct Dcu2Net
{
	unsigned int Bat_2_Fail;         // 0x01:正常不显示; 0x02:显示"BAT 2 FAIL"（Battery 2 Failure）                
	unsigned int Bat_1_Maint;        // 0x01:正常不显示; 0x02:显示"BAT 1 MAINT"（Battery 1 Maintenance Status）                 
	unsigned int N_Esntl_Bus_V;      //  0.0-40.0V  LSB:0.1V                                      
	unsigned int Gen_2_Fail;         // 0x01:正常不显示; 0x02:显示"GEN 2 FAIL"（Generator 2 Failure）                  
	unsigned int Gen_1_Off;          // 0x01:正常不显示; 0x02:显示"GEN 1 OFF" （Generator 1 Offline）                  
	unsigned int Gen_2_L;            // 0.0~70    LSB:1A                                            
	unsigned int Eng_Boost;          // 0x01:正常不显示; 0x02:显示"ENG BOOST Enabled"                   
	unsigned int Gen_2_Off;          // 0x01:正常不显示; 0x02:显示"Generator 2 Offline"                    
	unsigned int PropInlet;          // 0x01:正常不显示; 0x02:显示"Propeller/Intake De-Ice" （propeller and intake de-ice and heating system are active）                 
	unsigned int AvBus;              // 0x01:正常不显示; 0x02:显示"AV BUS"(Avionics Bus Offline / Failure)                        
	unsigned int Inert_P_Sep;        // 0x01:正常不显示; 0x02：显示: Inertia Particle Separator (OPEN)                    
	unsigned int Gen_1_Fail;         // 0x01:正常不显示; 0x02:显示"GEN 1 FAIL"（Generator 1 Failure）                      
	unsigned int DeIce;              // 0x01:正常不显示; 0x02:显示"De-Ice Collective" （the ice protection system is active）                          
	unsigned int Bat_2_Maint;        // 0x01:正常不显示; 0x02:显示"BAT 2 MAINT" （Battery 2 Maintenance Status）                     
	unsigned int Gen_2_V;            //0.0~40.0  LSB:0.1V                                                    
	unsigned int PitotHt;            // 0x01:正常不显示; 0x02:显示"PROBES HT"（LH/RH Probes Heat）                        
	unsigned int RUDDER;             // 55：Full Left   108：Neutral    160：Full Right
	unsigned int Bat_1_Heater;       // 0x01:正常不显示; 0x02:显示"BAT 1 HEATER"（Battery 1 Heater Status）                    
	unsigned int Starter;             // 0x01:正常不显示; 0x02:显示"STARTER" （Starter Fail）                          
	unsigned int Eject_S_R;          // 0x01:正常不显示; 0x02:显示"EJECT S R"（Rear Ejection Seat Not Armed）                         
	unsigned int RefDiode;           //                                                               
	unsigned int Bat_1_Fail;         // 0x01:正常不显示; 0x02:显示"BAT 1 FAIL"（Battery 1 Failure）                         
	unsigned int Eject_S_F;          // 0x01:正常不显示; 0x02:显示"EJECT S F"（Front Ejection Seat Not Armed）                          
	unsigned char LandingGearStatus; // 起落架状态 D0:左侧起落架放下：0不在位，1放下并锁定
									 //            D1:左侧起落架收起：0不在位，1收起并锁定
									 //            D2:前起落架放下：0不在位，1放下并锁定
									 //            D3:前起落架收起：0不在位，1收起并锁定
									 //            D4:右侧起落架放下：0不在位，1放下并锁定
									 //            D5:右侧起落架收起：0不在位，1收起并锁定      D6~D7 预留         
};

struct HudNet					//				8
{
	uint hudError1;
	uint hudError2;
};

struct VersionNet					//				2
{
	ushort duVersion;
	uint decVersion;
	uint bat1Version;
	uint bat2Version;
	uint dcu1Version;
	uint dcu2Version;
};

struct DiuCircleData
{
	DiuCircleData()
	{

	}
	ushort frameID;                 //帧头FA5F
	ushort length;					//数据长度				2
	uchar dataType;					//数据类型				1
	uchar count;					//循环计数				1
	ushort dataValid;				//数据有效性			2
	InsGnssNet insGnss1;			//惯导卫星导航数据1		89
	InsGnssNet insGnss2;			//惯导卫星导航数据2		89
	AdcNet adc1;					//大气数据1				32
	AdcNet adc2;					//大气数据2				32
	CnsNet cns;						//无线电数据			58
	RaBakNet raBak;			  		//无线电高度备份数据	4        pos:312
	DiuNet diu;						//DIU					6        pos:313~318
	EngineWarnNet engineWarn;       //发动机告警            2        pos:319~320
	DecNet dec;                     //DEC数字发动机控制     76       pos:321~429
	Bat1Net bat1;                   //BAT1                  12       pos:430~448
	Bat2Net bat2;                   //BAT2                  12       pos:449~464
	Dcu1Net dcu1;                   //DCU1                  103      pos:465~567
	Dcu2Net dcu2;                   //DCU2                  93       pos:568~660
	HudNet hud;						//HUD					8        pos:661~668
	VersionNet version;			    //version					2    pos:669~690
	ushort crc16;					//校验和				2        pos:691~692
};

struct DuFaultData //故障注入数据
{
	uchar length;
	uchar dataType;
	uchar count;
	uchar dataValid;
	uint fault;
	ushort crc16;
};

struct VhfWorkMode //VHF工作模式 
{
	uchar vhf1Channel : 1;
	uchar vhf2Channel : 1;
	uchar interCom : 1;
	uchar vhf1Selcal : 1;
	uchar vhf2Selcal : 1;
	uchar space : 3;
};

struct VolumeData //音量数据
{
	uchar vhf1Volume : 4;
	uchar vhf2Volume : 4;
	uchar adfVolume : 4;
	uchar interComVolume : 4;
	uchar warnVolume : 4;
	uchar mbVolume : 4;
	uchar dmeVolume : 4;
	uchar ilsVolume : 4;
};

struct MovalToDUData
{
	ushort head;	//头 0xAA55
	uchar length;	//长度 0x12
	uchar fid;		//帧标识 0x05
	uchar did;		//设备标识 0x05
	uchar count;	//帧计数 0~255
	uchar src;		//指令源 0
	uchar code;		//指令码 0x0A前舱 0x0B后舱
	VhfWorkMode workMode;
	VolumeData volumeData;
	uchar noiseLeavel;	//内话静噪等级
	ushort crc;		//校验和
	ushort end;		//帧尾 0xEDED
};


struct BitSoftversionData
{
	uchar length;	//数据长度 0x34
	uchar dataType;	//数据类型 0x02
	uchar count;	//帧计数
	uchar bitOrSoftversion;	//0x01自检结果 0x02软件版本
	union{
		struct{
			/*D1-D0*/
			uint VHF1: 2; 		/*VHF1自检结果,00:正常，01：主收故障，10：未定义，11：发射单元故障*/
			/*D3-D2*/
			uint VHF2 : 2; 		/*VHF1自检结果,00:正常，01：主收故障，10：未定义，11：发射单元故障*/
			/*D6-D4*/
			uint ADF : 3; 		/*ADF自检结果,000:正常，001：SinMod故障，010：CosMod故障，011：通道故障,100：电源故障,101：频合出错*/
			/*D9-D7*/
			uint DME : 3;		/* DME自检结果,000:正常，001：接收机故障，010：发射机故障，011：频合电源分机故障，100：信号处理单元故障，其他：未定义*/
			/*D12-D10*/
			uint MMR : 3;		/* MMR自检结果,000：正常,001：接收机故障,010：信号处理机故障,其他：未定义*/
			/*D14-D13*/
			uint XPDR : 2;		/*XPDR自检结果,00：正常,01：发射机故障,10：接收机故障,11：通信故障*/
			/*D16-D15*/
			uint RA : 2;		/*RA自检结果,00：正常,01：锯齿波故障,10：FLASH存储错误,11：未定义*/
			/*D20-D17*/
			uint MAVOL : 4;		/*机通自检结果,0000：正常,0001：前舱音频通信故障,0010：后舱音频通信故障,0011：预留,0100：预留,0101：电台1音频通信故障,0110：电台2音频通信故障,0111：罗盘音频通信故障,1000：DME音频通信故障,1001：VOR/ILS音频通信故障,1010：信标音频故障,1011：模拟供电故障,1100：数字供电故障,其他：未定义*/
			/*D21*/
			uint VHF1_COM : 1;	/*VHF1通信状态,0:正常，1：故障*/
			/*D22*/
			uint VHF2_COM : 1;	/*VHF2通信状态，0：正常，1：故障*/
			/*D23*/
			uint ADF_COM : 1;	/*ADF通信状态，0：正常，1：故障*/
			/*D24*/
			uint DME_COM : 1;	/*DME通信状态，0：正常，1：故障*/
			/*D25*/
			uint MMR_COM : 1;	/*MMR通信状态，0：正常，1：故障*/
			/*D26*/
			uint XPDR_COM : 1;	/*XPDR通信状态，0：正常，1：故障*/
			/*D27*/
			uint RA_COM : 1;	/*RA通信状态，0：正常，1：故障*/
			/*D28*/
			uint MAVOL_COM : 1;	/*机通通信状态，0：正常，1：故障*/
			/*D31-D29*/
			uint resever : 3;	/*预留*/
		}bBit_Result;
		uint Bit_Result;		/*自检结果*/
	};
	unsigned char Spare;/*预留*/
	uint Vfh1SoftVersion; /*VHF1软件版本*//*sprintf(Vfh1SoftVersion, "%s.%s.%s", x1x2, x3x4,x5x6); */
	uint Vfh2SoftVersion; /*VHF2软件版本*/
	uint AdfSoftVersion; /*ADF软件版本*/
	uint DmeSoftVersion; /*DME软件版本*/
	uint MmrSoftVersion; /*MMR软件版本*/
	uint XpdrSoftVersion; /*XPDR软件版本*/
	uint RaSoftVersion; /*RA软件版本*/
	uint CompSoftVersion; /*机通软件版本*/
	uint ProcessSofVersion;/*处理机软件版本*/
	uint Spare1;		//预留
	uchar Spare2;		//预留
	ushort crc;			//CRC16
};
#pragma pack()
