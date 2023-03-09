#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：采集软件 Data Acquisition Software （DAS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：手杆操控飞机指令数据包
TOPIC：DL-DAS-JOYSTICK-FLY-CMD   DAS-JOYSTICK-FLY-CMD
完整包结构：BasicPktHeader + JoyStickFly + BasicPktTail
*/
struct JoyStickFly
{
	Z_U8 seatID;        //席位ID	  uint8[0, 20]	无量纲数，LSB = 1
	Z_I16 aileronCmd;   //副翼控制指令	int16[-10000, 10000]	"无量纲数，LSB=1 左： - 1，右： + 1"
	Z_I16 elevatorCmd;  //升降舵控制指令	int16[-10000, 10000]	"无量纲数，LSB=1 低头： - 1，抬头： + 1"
	Z_U8 trimCmd;       //配平指令	uint8 / 1 - 上；2 - 下；3 - 左；4 - 右；其它 - 无效；
	Z_U8 trimZero;      //配平置零	uint8 / 1 - 置零；其它 - 无效；
	Z_U8 autoCtrlOff;   //AC切断	uint8 / 1 - 切断；其它 - 无效；
	Z_U8 reserve1;      //预留	uint8 / 置零
	Z_U8 reserve2;      //预留	uint8 / 置零
	Z_U8 reserve3;      //预留	uint8 / 置零

	CONSTRUCT(JoyStickFly);
};

/*
包名称：油门操控飞机指令数据包
TOPIC：DL-DAS-THROTTLE-FLY-CMD   DAS-THROTTLE-FLY-CMD
完整包结构：BasicPktHeader + ThrottleFly + BasicPktTail
*/
struct ThrottleFly
{
	Z_U8 seatID;            //席位ID	uint8[0, 20]	无量纲数，LSB = 1
	Z_I16 engine1Throttle;  //发动机1油门开度	int16[0, 10000]	无量纲数，LSB = 1
	Z_I16 engine2Throttle;  //发动机2油门开度	int16[0, 10000]	无量纲数，LSB = 1
	Z_U8 flapCmd;           //襟翼收起指令	uint8 / 1 - 收起；2 - 放下；其它 - 无效；
	Z_U8 reserve1;          //预留	uint8 / 置零
	Z_U8 reserve2;          //预留	uint8 / 置零
	Z_U8 reserve3;          //预留	uint8 / 置零
	Z_U8 reserve4;          //预留	uint8 / 置零
	Z_U8 reserve5;          //预留	uint8 / 置零

	CONSTRUCT(ThrottleFly);
};

/*
包名称：脚蹬操控飞机指令数据包
TOPIC：DL-DAS-RUDDERPEDAL-FLY-CMD   DAS-RUDDERPEDAL-FLY-CMD
完整包结构：BasicPktHeader + RudderpedalFly + BasicPktTail
*/
struct RudderpedalFly
{
	Z_U8 seatID;        //席位ID	uint8[0, 20]	无量纲数，LSB = 1
	Z_U8 leftBrake;     //左刹	uint8[0, 100]	无量纲数，LSB = 1
	Z_U8 rightBrake;    //右刹	uint8[0, 100]	无量纲数，LSB = 1
	Z_I16 rudderCmd;    //方向舵指令	int16[-10000, 10000]	无量纲数，LSB = 1
	Z_U8 reserve1;      //预留	uint8 / 置零
	Z_U8 reserve2;      //预留	uint8 / 置零

	CONSTRUCT(RudderpedalFly);
};

/*
包名称：手杆操控任务载荷指令数据包
TOPIC：DL-DAS-JOYSTICK-MIS-CMD   DAS-JOYSTICK-MIS-CMD
完整包结构：BasicPktHeader + JoyStickMIS + BasicPktTail
*/
struct JoyStickMIS
{
	Z_U8 seatID;            //席位ID	uint8[0, 20]	无量纲数，LSB = 1
	Z_I16 payloadHeading;   //载荷吊舱方位控制指令	int16[-10000, 10000]	无量纲数，LSB = 1
	Z_I16 payloadPitch;     //载荷吊舱俯仰控制指令	int16[-10000, 10000]	无量纲数，LSB = 1 
	Z_U8 targetLock;        //目标锁定指令	uint8 / 1 - 按下；其它 - 无效；
	Z_U8 missileEmit;       //MSL发射指令	uint8 / 1 - 发射；其它 - 无效；
	Z_U8 weaponSelect;      //武器SEL指令	uint8 / 1 - 上一个；2 - 下一个；其它 - 无效；
	Z_U8 sensorImageSelect; //传感器IMASEL	uint8 / 1 - 上一个；2 - 下一个；其它 - 无效；
	Z_U8 aerogunEmit;       //航炮发射指令	uint8 / 1 - 发射；其它 - 无效；
	Z_U8 laserMeasure;      //激光DM指令	uint8 / 1 - 按下；其它 - 无效；
	Z_U8 lockBoxMove;       //锁定框移动	uint8 / 1-上 2-下 3-左 4-右 其他-无效
	Z_U8 targetUnLock;      //解锁	uint8 / 1-解锁 其他-无效
	Z_U8 reserve3;          //预留	uint8 / 置零
	Z_U8 reserve4;          //预留	uint8 / 置零

	CONSTRUCT(JoyStickMIS);
};

/*
包名称：油门操控任务载荷指令数据包
TOPIC：DL-DAS-THROTTLE-MIS-CMD   DAS-THROTTLE-MIS-CMD
完整包结构：BasicPktHeader + ThrottleMIS + BasicPktTail
*/
struct ThrottleMIS
{
	Z_U8 seatID;            //席位ID	uint8[0, 20]	无量纲数，LSB = 1
	Z_I16 focusLengthCtrl;  //焦距控制指令	int16[0, 10000]	无量纲数，LSB = 1
	Z_U8 reserve1;          //预留	uint8 / 置零
	Z_U8 reserve2;          //预留	uint8 / 置零
	Z_U8 reserve3;          //预留	uint8 / 置零
	Z_U8 reserve4;          //预留	uint8 / 置零

	CONSTRUCT(ThrottleMIS);
};

/*
包名称：手杆操控地面目标
TOPIC：DAS-JOYSTICK-UGV-CMD
完整包结构：BasicPktHeader + JoyStickFly + BasicPktTail
*/
struct JoyStickUGV
{
	Z_U8 seatID;        //席位ID	  uint8[0, 20]	无量纲数，LSB = 1
	Z_I16 directCmd;	//方向控制指令	int16[-10000, 10000]	"无量纲数，LSB=1 左： - 1，右： + 1"
	Z_I16 reserve1;		//预留	int16 / 置零
	Z_U8 reserve2;      //预留	uint8 / 置零
	Z_U8 reserve3;      //预留	uint8 / 置零
	Z_U8 reserve4;		//预留	uint8 / 置零
	Z_U8 reserve5;      //预留	uint8 / 置零
	Z_U8 reserve6;      //预留	uint8 / 置零
	Z_U8 reserve7;      //预留	uint8 / 置零

	CONSTRUCT(JoyStickUGV)
};

/*
包名称：油门操控地面目标
TOPIC：DAS-THROTTLE-UGV-CMD
完整包结构：BasicPktHeader + ThrottleFly + BasicPktTail
*/
struct ThrottleUGV
{
	Z_U8 seatID;            //席位ID	uint8[0, 20]	无量纲数，LSB = 1
	Z_I16 engine1Throttle;  //油门开度	int16[0, 10000]	无量纲数，LSB = 1
	Z_I16 reserve1;			//发动机2油门开度	int16[0, 10000]	无量纲数，LSB = 1
	Z_U8 flapCmd;           //刹车指令	uint8 / 1 - 刹车；其它 - 无效；
	Z_U8 reserve2;          //预留	uint8 / 置零
	Z_U8 reserve3;          //预留	uint8 / 置零
	Z_U8 reserve4;          //预留	uint8 / 置零
	Z_U8 reserve5;          //预留	uint8 / 置零
	Z_U8 reserve6;          //预留	uint8 / 置零

	CONSTRUCT(ThrottleUGV)
};

/*
包名称：控制面板/周边键操控飞机指令数据包
TOPIC：DAS-PNLKEY-FLY-CMD
包名称：控制面板/周边键操控载荷指令数据包
TOPIC：DAS-PNLKEY-MIS-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + PanelKeyPublicSeg + PanelKeyArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct PanelKeyPublicSeg
{
	Z_U8 seatID;    //席位ID	uint8[0, 20]	公共数据块，无量纲数，LSB = 1
	Z_U8 ctrlType;  //操纵机构类型	uint8 / 1 - 控制面板；2 - 周边键；

	CONSTRUCT(PanelKeyPublicSeg);
};

struct PanelKeyArraySeg
{
	Z_U8 keyID;     //按钮ID	 uint8[0, 255]	周期数据块，无量纲数，LSB = 1
	Z_U8 keyState;  //按钮状态	uint8 / 周期数据块，0 - 弹起；1 - 按下；其它 - 无效；

	CONSTRUCT(PanelKeyArraySeg);
};

/*
包名称：天线杆操纵指令数据包
TOPIC：DAS-ANTENNA-DLM-CMD
完整包结构：BasicPktHeader + AntennaCtrl + BasicPktTail
*/
struct AntennaCtrl
{
	Z_U8 seatID;            //席位ID	uint8[0, 20]	无量纲数，LSB = 1
	Z_I16 azimuth;          //天线方位控制	int16	[-10000,10000]	无量纲数，LSB=1
	Z_I16 pitch;            //天线俯仰控制	int16	[-10000,10000]	无量纲数，LSB=1
	Z_U8 reserve1;          //预留	uint8 / 置零
	Z_U8 reserve2;          //预留	uint8 / 置零

	CONSTRUCT(AntennaCtrl);
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)