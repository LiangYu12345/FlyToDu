#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：飞控与导航软件 Flight Control and Navigation （FCN）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：无人机控制指令数据包
TOPIC：	   FCN-CTRL-CMD
完整包结构：BasicPktHeader + FlightContrlCMD + BasicPktTail
*/
struct FlightContrlCMD
{
    Z_U8 cmdType; //控制指令Label 定义见FlightContrlCMDType
    Z_U8 cmdValue;//指令定义说明
    Z_F32 param1;//控制指令参数1
    Z_I32 param2;//控制指令参数2
    Z_I32 param3;//3控制指令参数

    CONSTRUCT(FlightContrlCMD);
};

/*
包名称：数据设置同步包
TOPIC：TMP-DATASYNC-CMD
完整包结构：BasicPktHeader + UAVPayloadCtrlCmd + BasicPktTail
*/
struct SoftDataSyncCmd
{
    Z_U8  type;       //< 数据类型 0:电台1数值 1:电台2数值 2:XPDR数值 3:XPDR状态 4:ADF1数值 5:ADF2数值 6:NAV1数值 7:NAV2数值 8:电台1数值2 9:电台2数值2
    Z_U32 value;      //< 数据 uint8 分辨率0.001
                      //< XPDR状态 0:不显示 1:STBY 2:ALT 3:ON
    CONSTRUCT(SoftDataSyncCmd);
};

/*
包名称：无人机飞行航点信息数据包
TOPIC：DL-FCN-WPT-CMD    FCN-WPT-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + UAVWaypointInfoPublicSeg + UAVWaypointInfoArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct UAVWaypointInfoPublicSeg
{
    Z_U8 routeID;       //航路ID	    uint8	[0, 255]
    Z_U8 subRouteCount; //子航线条数	uint8	[0,10]

    CONSTRUCT(UAVWaypointInfoPublicSeg);
};

struct UAVWaypointInfoArraySeg
{
    Z_U8 subRouteID;        // 航点所属子航线ID	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorR;    // 子航线R(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorG;    // 子航线G(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorB;    // 子航线B(颜色)	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteColorA;    // 子航线A(透明度)	uint8[0, 100]	周期数据，无量纲数，LSB = 1
    Z_U8 subRouteType;      // 子航线类型	uint8 / "周期数据，1 - Take-off；2 - Climbing；3 - Cruise；4 - 下降；5 - GA；其它 - 无效；"
    Z_U8 wptIDInSubRoute;   // 航点在子航线里的ID	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_U8 wptIDInRoute;      // 航点导航ID（总航点ID）	uint8[0, 255]	周期数据，无量纲数，LSB = 1
    Z_I32 longitude;        //int32	(-180, 180]	周期数据，单位为度，LSB=0.0000001°
    Z_I32 latitude;         //int32	[-90, 90]	周期数据，单位为度，LSB=0.0000001°
    Z_F32 altitude;         //float	[-500,20000]	周期数据，单位为m
    Z_F32 speed;            // 航点速度	float[0, 1200]	周期数据，单位为km / h 
    Z_U8 motionType;        // 航路点机动指令			周期数据，0 - 过点；1 - 压点；
    Z_U16 reserve1;         // 预留	uint16 / 周期数据，预留置零
    Z_U8 reserve2;          // 预留	uint8 / 周期数据，预留置零

    CONSTRUCT(UAVWaypointInfoArraySeg);
};

/*
包名称：无人机切换控制指令数据包
TOPIC：FCN-CTRLID-CMD
完整包结构：BasicPktHeader + UAVCtrlSwitch + BasicPktTail
*/
struct UAVCtrlSwitch
{
    Z_U8 seatID;    //席位ID	uint8	0~255	无量纲数，LSB=1
    Z_U8 nCtrlUAVID; //待控无人机ID
    Z_U8 reserve1;  //预留	uint8	/	置零

    CONSTRUCT(UAVCtrlSwitch);
};

enum class FlightContrlCMDType
{
    //Flight Control指令相关
    CtrlMode = 1,           //1	飞控模式指令	uint8 / 0 - MC；1 - AC；其它 - 无效；
    TakeoffReturn = 2,      //2	放飞GA指令	uint8 / 1 - “放飞”；2 - “RTB”；3 - “GA”；其它 - 无效；
    RouteMotion = 3,        //3	航线机动指令	uint8 / 1 - “左盘旋”；2 - “右盘旋”；3 - “八字飞”；4 - “编队飞行”；5 - “定点盘旋”；6 - “恢复航线”；其它 - 无效；
                                //定点盘旋指令参数	定点高度	float[-500, 20000]	指令参数1，单位为m
                                //定点经度	int32(-180, 180]	指令参数2，单位为度，LSB = 0.0000001° 
                                //定点纬度	int32[-90, 90]	指令参数3，单位为度，LSB = 0.0000001°
    MCPHeading = 4,         //4	MCP定向指令	uint8 / 0 - Cancel；1 - 有效；其它 - 无效；
                                //定向指令参数	MCP航向	float[0, 360)	指令参数1，单位为度
    MCPHeight = 5,          //5	MCP定高指令	uint8 / 0 - Cancel；1 - 有效；其它 - 无效；
                                //定高指令参数	MCP高度	float[-500, 20000]	指令参数1，单位为m
    MCPSpeed = 6,           //6	MCP定速指令	uint8 / 0 - Cancel；1 - 有效；其它 - 无效；
                                //定速指令参数	MCP速度	float[0, 1200]	指令参数1，单位为km / h
    NavCtrl = 7,            //7	导航控制指令	uint8 / 1 - 直飞某点；其它 - 无效；
                                //直飞控制参数	直飞航点ID号	int32[0, 255]	指令参数2，在主航路的ID号

    //发动机控制指令相关
    EnginStartStop = 21,        //21	发动机启停指令	uint8 / 1 - 开车；2 - 停车；3 - 风启；其它 - 无效；
    InFlightStartEnable = 22,   //22	发动机空启使能指令	uint8 / 0 - 禁止空启；1 - 允许空启；其它 - 无效；
    EnginRPM = 23,              //23	发动机定转指令	uint8 / 0 - Cancel；1 - 有效；其它 - 无效；
                                    //定转指令参数	定转百分比	float[0, 100]	指令参数1，无量纲数

    //机电系统控制指令相关
    LandingGearCtrl = 41,       //41	起落架收放指令	uint8 / 0 - 放下；1 - 收起；其它 - 无效；
    SpeedBrakerCtrl = 42,       //42	减速板控制指令	uint8 / 0 - 0档；1 - 1档；2 - 2档；其它 - 无效；
    BrakeCtrl = 43,             //43	刹车控制指令	uint8 / 1 - 松刹车；2 - 静刹车；3 - 应急刹车；4 - 液压刹车；其它 - 无效；
    HydraulicPumpCtrl = 44,     //44	液压泵控制指令	uint8 / 0 - 关闭；1 - 打开；其它 - 无效；

    //航电系统控制指令相关
    AttitudeSensor = 61,        //61	姿态传感器切换指令	uint8 / 0 - 姿态主；1 - 姿态备份；其它 - 无效；
    PositionSensor = 62,        //62	位置传感器切换指令	uint8 / 0 - 位置主；1 - 位置备份；2 - 位置差分；其它 - 无效；
    AltitudeSensor = 63,        //63	高度传感器切换指令	uint8 / 0 - 高度左；1 - 高度右；2 - 高度差分；其它 - 无效；
    SpeedSensor = 64,           //64	速度传感器切换指令	uint8 / 0 - 速度左；1 - 速度右；2 - 速度差分；其它 - 无效；

    //地面站控制指令相关
    UAVCtrlSwitchCmd = 81       //81	无人机切换控制指令	uint8 / 1 - 有效；其它 - 无效；
                                    //无人机切换控制参数	无人机切换席位ID	uint32[1, 20]	指令参数2，无量纲数，LSB = 1
};


ICD2002G_NAMESPACE_END
#pragma pack(pop)