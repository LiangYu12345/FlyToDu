#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：ALC软件 Load Control Software （LCS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：无人机ALC指令数据包
TOPIC：DL-LCS-PAYLOAD-CMD    LCS-PAYLOAD-CMD
完整包结构：BasicPktHeader + UAVPayloadCtrlCmd + BasicPktTail
*/
struct UAVPayloadCtrlCmd
{
    Z_U8 payloadType;   //被控载荷类型	uint8 / "1-光电吊舱；2 - IR；3 - TV；4 - SAR雷达；5 - 激光；6 - 火控；其它 - 无效；"
    Z_U8 cmdType;       //控制指令Label	见 UAVPayloadCtrlCmdType
    Z_U8 cmdValue;      //指令定义说明	uint8 / 指令定义说明，详见无人机ALC指令定义
    Z_F32 param1;       //控制指令参数1	float / 指令参数1，详见无人机ALC指令定义
    Z_I32 param2;       //控制指令参数2	int32 / 指令参数2，详见无人机ALC指令定义
    Z_I32 param3;       //控制指令参数3	int32 / 指令参数3，详见无人机ALC指令定义

	Z_I32 param4;       //控制指令参数4	int32 / 指令参数4，详见无人机ALC指令定义 //add By MK

    CONSTRUCT(UAVPayloadCtrlCmd);
};

/*
包名称：载荷DISP切换命令数据包
TOPIC：DL-LCS-DISPLAYSW-CMD  LCS-DISPLAYSW-CMD
完整包结构：BasicPktHeader + PayloadDisplaySwitchCCmd + BasicPktTail
*/
struct PayloadDisplaySwitchCCmd
{
    Z_U8 payloadType;       //载荷类型	uint8 / "1-光电吊舱；2 - SAR雷达；其它 - 无效；"
    Z_U8 payloadSubType;    //子类型	uint8 / "光电：1-IR；2-TV；SAR：1 - 条带；2 - 聚束；3 - GMTI；其它 - 无效；"
    Z_U8 reserve1;          //预留	uint8 / 置零

    CONSTRUCT(PayloadDisplaySwitchCCmd);
};

/*
包名称：无人机载荷切换控制指令数据包
TOPIC：LCS-CTRLID-CMD
完整包结构：BasicPktHeader + UAVPayloadSwitchCmd + BasicPktTail
*/
struct UAVPayloadSwitchCmd
{
    Z_U8 seatID;    //席位ID	uint8[0, 20]	无量纲数，LSB = 1
	Z_U8 nCtrlUAVID; //待控无人机ID
    Z_U8 reserve1;  //预留	uint8 / 置零

    CONSTRUCT(UAVPayloadSwitchCmd);
};
/*
包名称：无人机ALC模式切换指令数据包
TOPIC：DL-LCS-CTRLMODE-CMD LCS-CTRLMODE-CMD
完整包结构：BasicPktHeader + UAVPayloadCtrlModeSwitchCmd + BasicPktTail
*/
struct UAVPayloadCtrlModeSwitchCmd
{
	Z_U8 ctrlMode; //0:AC 1 MC
    Z_U8 reserve1;  //预留  uint8 / 置零

    CONSTRUCT(UAVPayloadCtrlModeSwitchCmd);
};
enum class UAVPayloadCtrlCmdType
{
    //SAR雷达控制指令相关
    SARModeCmd = 1,         //1	SAR模式指令	uint8 / 1 - 条带；2 - 聚束；3 - GMTI；其它 - 无效；
    RadiationCmd = 2,       //2	辐射开关指令	uint8 / 0 - 辐射关；1 - 辐射开；其它 - 无效；
    GainModeCmd = 3,        //3	增益模式指令	uint8 / 0 - 自动；1 - 手动；其它 - 无效；
                                //增益模式参数	增益控制参数	int32[0, 44]	指令参数2，无量纲数，LSB = 1
    FieldHeightCmd = 4,     //4	场高控制指令	uint8 / 1 - 有效；其它 - 无效；
                                //场高参数	场高控制参数	int32[0, 12000]	指令参数2，单位为m，LSB = 1m
    BeamTargetPosCmd = 5,   //5	聚束目标位置指令	uint8 / 1 - 有效；其它 - 无效；
                                //聚束位置指令参数	聚束高度	float[-500, 20000]	指令参数1，单位为m
                                //聚束经度	int32(-180, 180]	指令参数2，单位为度，LSB = 0.0000001°
                                //聚束纬度	int32[-90, 90]	指令参数3，单位为度，LSB = 0.0000001°
    StripeCmd = 6,          //6	条带控制指令	
								//uint8 / "1-DPI控制；2 - Effective_Distance控制；3 - 方位角控制；其它 - 无效；"
                                //条带控制参数	DPI参数	int32 / "指令参数2，0 - 3m；1 - 1m；2 - 0.5m；其它 - 无效；"
                                //Effective_Distance参数	float[20, 100]	指令参数1，单位为km 
                                //方位角参数	int32 / "指令参数2，0 - 左侧视；1 - 右侧视；其它 - 无效；"
    GMTIScanDis = 7,        //7	GMTI扫描距离指令	uint8 / 1 - 有效；其它 - 无效；
                                //扫描距离参数	GMTI扫描距离参数	float[20, 100]	指令参数1，单位为km
    GMTIScanAngle = 8,      //8	GMTI扫描角度指令	uint8 / 1 - 有效；其它 - 无效；
                                //扫描范围参数	GMTI扫描范围参数	float[0, 90]	指令参数1，单位为度 
    GMTIAntennaHeading=9,   //9	GMTI天线方位指令	uint8 / 1 - 有效；其它 - 无效；
                                //天线方位参数	GMTI天线方位参数	float[-60, 60]	指令参数1，单位为度 
    GMTITrackPrior = 10,    //10	GMTI航迹优先指令	uint8 / 0 - 不跟踪；1 - 跟踪；其它 - 无效；
                                //GMTI航迹跟踪指令参数	GMTI航迹跟踪方位	float(-180, 180]	指令参数1，单位为度
                                //GMTI航迹跟踪经度	int32(-180, 180]	指令参数2，单位为度，LSB = 0.0000001°
                                //GMTI航迹跟踪纬度	int32[-90, 90]	指令参数3，单位为度，LSB = 0.0000001°
    WorkMainMode = 11,      //11	工作主模式命令	uint8 / 0 - 空对地；1 - 空对海；其它 - 无效；
    BITCheck = 12,          //12	BIT自检命令	uint8 / 1 - 有效；其它 - 无效；

    //EO吊舱控制指令相关
    EOPowerOnOff = 21,      //21	EO吊舱上电指令	uint8 / 0 - 下电；1 - 上电；其它 - 无效；
    EOUpDown = 22,          //22	EO吊舱收放指令	uint8 / 0 - 收起；1 - 放下；其它 - 无效；
    EOWorkMode = 23,        //23	EO吊舱工作模式指令	uint8 / 1 - 人工搜索；2 - 自动扫描；3 - 地理跟踪；4 - 小区搜索；5 - 锁定；6-自动跟踪 其它 - 无效；
                                //锁定指令参数	被锁定目标ID	int32 / 指令参数2，无量纲数，LSB = 1
                                //地理跟踪指令参数	地理跟踪高度	float[-500, 20000]	指令参数1，单位为m
                                //地理跟踪经度	int32(-180, 180]	指令参数2，单位为度，LSB = 0.0000001°
                                //地理跟踪纬度	int32[-90, 90]	指令参数3，单位为度，LSB = 0.0000001°
    EOHeadingCtrl = 24,     //24	EO方位控制指令	uint8 / 1 - 有效；其它 - 无效；
                                //方位控制参数	EO方位控制参数	float(-180, 180]	指令参数1，单位为度
    EOPitchCtrl = 25,       //25	EO俯仰控制指令	uint8 / 1 - 有效；其它 - 无效；
                            //俯仰控制参数	EO俯仰控制参数	float[-90, 0]	指令参数1，单位为度

    //IR控制指令相关
    IRPowerOnOff = 41,      //41	IR上电指令	uint8 / 0 - 下电；1 - 上电；其它 - 无效；
    IRFOVCmd = 42,          //42	IR视场角指令	uint8 / 1 - 有效；其它 - 无效；
                                //视场角指令参数	视场角	float[-90, 0]	指令参数1，单位为度
    IRImageCtrl = 43,       //43	图像控制指令	uint8 / 1 - 字符叠加；2 - 字符消隐；3 - 图像增强；4 - 黑白热切换；5 - 非均匀校正；其它 - 无效；
    IRContrastCtrl = 44,    //44	对比度调节指令	uint8 / 1 - 对比 + ；2 - 对比 - ；其它 - 无效；
    IRLuminanceCtrl = 45,   //45	亮度调节指令	uint8 / 1 - 亮度 + ；2 - 亮度 - ；其它 - 无效；
    IRMultiTarget = 46,     //46	多目标控制指令	uint8 / 1 - 多目标SEL；2 - 标号 + ；3 - 标号 - ；4 - 多目标确认；其它 - 无效；

    //TV控制指令相关
    VisibleLightPower = 47,         //47	TV上电指令	uint8 / 0 - 下电；1 - 上电；其它 - 无效；
    VisibleLightFOV = 48,           //48	可将光视场角指令	uint8 / 1 - 有效；其它 - 无效；
                                        //视场角指令参数	视场角	float[-90, 0]	指令参数1，单位为度
    VisibleLightImageCtrl = 49,     //49	图像控制指令	uint8 / 1 - 字符叠加；2 - 字符消隐；3 - 图像增强；其它 - 无效；
    VisibleLightFocusLength = 50,   //50	焦距调节指令	uint8 / 1 - 焦距 + ；2 - 焦距 - ；3 - 焦距自动；其它 - 无效；
    VisibleLightMultiTarget = 51,   //51	多目标控制指令	uint8 / 1 - 多目标SEL；2 - 标号 + ；3 - 标号 - ；4 - 多目标确认；其它 - 无效；

    //火控控制指令相关
    MissileEmit = 61,           //61	MSL发射命令	uint8 / 1 - 发射；其它 - 无效；
    FireControlCmd = 62,         //62	火控解算命令	uint8 / 1 - 攻击目标ID有效；2 - 攻击点位置有效；3-Cancel解算 其它 - 无效；
                                    //火控解算参数	挂载点ID	int32[0, 255]	指令参数2，无量纲数，LSB = 1
                                    //传感器认定的目标ID	int32[256, 65535]	指令参数3，无量纲数，LSB = 1
                                    //攻击点高度	float[-500, 20000]	指令参数1，单位为m
                                    //攻击点经度	int32(-180, 180]	指令参数2，单位为度，LSB = 0.0000001°
                                    //攻击点纬度	int32[-90, 90]	指令参数3，单位为度，LSB = 0.0000001°
									//挂载点ID  参数4 //add By MK
    MissileSelect = 63,         //63    MSLSEL命令 uint8 / 1 - 发射；其它 - 无效；
};

//注： 强发MSL，必须走攻击确认（发挂载点和目标ID，或者位置，)。

ICD2002G_NAMESPACE_END
#pragma pack(pop)