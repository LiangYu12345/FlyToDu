#pragma once
#pragma pack(push)
#pragma pack(1)

//软件名称：教员站软件 Instructor Platform Software（IPS）
#include "ICDCommonData.h"
ICD2002G_NAMESPACE_BEGIN

/*
包名称：无人机初始化数据包
TOPIC：IPS-UAV-INIT
完整包结构：BasicPktHeader + UAVInit + BasicPktTail
*/
struct UAVInit
{
    Z_U8 freezeModel;   //冻结模型指令	uint8 / 0 - 不冻结；1 - 冻结；其它 - 无效；
    Z_U8 flightStage;   //飞行阶段初始化	uint8 / "0-Tarmac-delay；1 - Take-off；2 - Climbing；3 - Cruise；4 - RTB；5 - 下降；6 - 进场；7 - GA；其它 - 无效；"
    Z_I32 longitude;    //初始经度	int32(-180, 180]	周期数据块，单位为度，LSB = 0.0000001°
    Z_I32 latitude;     //初始纬度	int32[-90, 90]	周期数据块，单位为度，LSB = 0.0000001°
    Z_F32 altitude;     //初始高度	float[-500, 20000]	周期数据块，单位为m
    Z_F32 heading;      //初始航向角	float[0, 360)	周期数据块，单位为度
    Z_F32 pitch;        //初始俯仰角	float(-90, 90)	周期数据块，单位为度
    Z_F32 roll;         //初始横滚角	float(-180, 180)	周期数据块，单位为度
    Z_F32 airSpeed;     //初始空速	float[0, 1200]	单位为km / h
    Z_F32 fuelQuantity; //初始燃油量	float[0, 10000]	单位为kg 
    Z_F32 UAVEmptyWeight;       //无人机空重	float[0, 10000]	单位为kg
    Z_U8  mountMissileCount;     //挂弹数量	uint8[0, 10]	单位为枚，LSB = 1枚
    Z_F32 wingArea;             //机翼面积	float(0, 100]	单位为m2
    Z_F32 wingSpan;             //翼展	float(0, 50]	单位为m
    Z_F32 meanAerodynamicChord; //平均气动弦长	float(0, 5]	单位为m
    Z_F32 inertiaXX;            //惯性矩xx	float(0, 10000]	单位为m ^ 4
    Z_F32 inertiaYY;            //惯性矩yy	float(0, 10000]	单位为m ^ 4
    Z_F32 inertiaZZ;            //惯性矩zz	float(0, 10000]	单位为m ^ 4
    Z_F32 inertiaXZ;            //惯性炬xz	float(0, 10000]	单位为m ^ 4
    Z_F32 barycenterPos;        //重心位置	float(0, 10]	单位为m
    Z_F32 pneumaticPos;         //气动中心位置	float(0, 10]	单位为m
    Z_F32 curseHeight;          //Cruise高度
    Z_I16 reserve2;             //预留	int16 / 置零

    CONSTRUCT(UAVInit);
};

/*
包名称：无人机故障设置数据包
TOPIC：IPS-FAULTSET-CMD
完整包结构：BasicPktHeader + UAVFaultSet + BasicPktTail
*/
struct UAVFaultSet
{
    Z_U8 engineFault;           //发动机停车	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 rudderFault;           //方向舵卡死	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 elevatorFault;         //升降舵卡死	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 aileronFault;          //副翼卡死	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 flapFault;             //襟翼卡死	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 landingGearFault;      //起落架卡死	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 autopilotFault;        //自动驾驶故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 brakeFault;            //刹车故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 joyStickFault;         //OPER杆故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 throttleFault;         //油门台故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 VLFault;               //光电吊舱TV故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 IRFault;               //IR故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 EOFault;               //吊舱OPER故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 WeaponFault;           //武器故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
    Z_U8 SARFault;              //SAR故障	uint8 / 0 - 无故障；1 - 故障；其它 - 无效；
	Z_I32 reserve1;             //预留	int32 / 置零 
    Z_I16 reserve2;             //预留	int16 / 置零

    CONSTRUCT(UAVFaultSet);
};

/*
包名称：无人机MSL初始化数据包
TOPIC：IPS-MISSILE-INIT
完整包结构：BasicPktHeader + ArrayPktHeader + UAVMissileInitArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct UAVMissileInitArraySeg
{
    Z_U8 missileType;           //MSL类型	uint8	0~255	周期数据块，无量纲数，LSB = 1
    Z_U16 explosionRadius;      //爆炸半径	uint16(0, 1000]	周期数据块，单位为m，LSB = 1m 
    Z_I16 reserve1;             //预留	int16 / 周期数据块，预留置零

    CONSTRUCT(UAVMissileInitArraySeg);
};

/*
包名称：无人机光电吊舱初始化数据包
TOPIC：IPS-EO-INIT
完整包结构：BasicPktHeader + UAVEOInit + BasicPktTail
*/
struct UAVEOInit
{
    Z_F32 maxPitch;         //最大俯仰角	float(0, 90)	单位为度
    Z_F32 minPitch;         //最小俯仰角	float(0, 90)	单位为度
    Z_F32 maxAzimuth;       //最大方位角	float(0, 180)	单位为度
    Z_F32 minAzimuth;       //最小方位角	float(0, 180)	单位为度 
    Z_F32 packupAzimuth;    //收起方位角	float(0, 180)	单位为度
    Z_F32 packupPitch;      //收起俯仰角	float(0, 90)	单位为度
    Z_I16 reserve1;         //预留	int16 / 置零
    Z_U8 reserve2;          //预留	uint8 / 置零

    CONSTRUCT(UAVEOInit);
};

/*
包名称：无人机TV传感器初始化数据包
TOPIC：IPS-EOSENSOR-INIT
完整包结构：BasicPktHeader + UAVEOSensorInit + BasicPktTail
*/
struct UAVEOSensorInit
{
    Z_F32 minHFOV;                      //最小视场角H	float(0, 180)	单位为度 
    Z_F32 maxHFOV;                      //最大视场角H	float(0, 180)	单位为度
    Z_F32 minVFOV;                      //最小视场角V	float(0, 180)	单位为度
    Z_F32 maxVFOV;                      //最大视场角V	float(0, 180)	单位为度
    Z_U8  ratioH;                        //相机比例横向值	uint8(0, 100]	无量纲数，LSB = 1
    Z_U8  ratioV;                        //相机比例纵向值	uint8(0, 100]	无量纲数，LSB = 1
    Z_F32 hFOV;                         //相机视场角H	float(0, 180)	单位为度
    Z_F32 vFOV;                         //相机视场角V	float(0, 180)	单位为度
    Z_F32 beginWorkAngle;               //开机张角初始值	float(0, 180)	单位为度
    Z_F32 beginWorkFocal;               //开机焦距初始值	float(0, 300]	单位为毫m
    Z_F32 workDistance;                 //Effective_Distance	float(0, 100]	单位为Km
    Z_F32 maxRecognizeDistance;         //最远识别距离	float(0, 100]	单位为Km
    Z_U16 minDetectPixelNum;            //最小可发现像素个数	uint16(0, 2000]	单位为个，LSB = 1个
    Z_U16 minRecognizePixelNum;         //最小可识别像素个数	uint16(0, 2000]	单位为个，LSB = 1个
    Z_I32 reserve1;                     //预留	int32 / 置零
    Z_U8 reserve2;                      //预留	uint8 / 置零

    CONSTRUCT(UAVEOSensorInit);
};

/*
包名称：无人机IR传感器初始化数据包
TOPIC：IPS-IRSENSOR-INIT
完整包结构：BasicPktHeader + UAVIRSensorInit + BasicPktTail
*/
struct UAVIRSensorInit
{
	Z_F32 minHFOV;                      //最小视场角H	float(0, 180)	单位为度 
	Z_F32 maxHFOV;                      //最大视场角H	float(0, 180)	单位为度
	Z_F32 minVFOV;                      //最小视场角V	float(0, 180)	单位为度
	Z_F32 maxVFOV;                      //最大视场角V	float(0, 180)	单位为度
	Z_U8  ratioH;                        //相机比例横向值	uint8(0, 100]	无量纲数，LSB = 1
	Z_U8  ratioV;                        //相机比例纵向值	uint8(0, 100]	无量纲数，LSB = 1
	Z_F32 hFOV;                         //相机视场角H	float(0, 180)	单位为度
	Z_F32 vFOV;                         //相机视场角V	float(0, 180)	单位为度
	Z_F32 beginWorkAngle;               //开机张角初始值	float(0, 180)	单位为度
	Z_F32 beginWorkFocal;               //开机焦距初始值	float(0, 300]	单位为毫m
	Z_F32 workDistance;                 //Effective_Distance	float(0, 100]	单位为Km
	Z_F32 maxRecognizeDistance;         //最远识别距离	float(0, 100]	单位为Km
	Z_U16 minDetectPixelNum;            //最小可发现像素个数	uint16(0, 2000]	单位为个，LSB = 1个
	Z_U16 minRecognizePixelNum;         //最小可识别像素个数	uint16(0, 2000]	单位为个，LSB = 1个
	Z_I32 reserve1;                     //预留	int32 / 置零
	Z_U8 reserve2;                      //预留	uint8 / 置零

	CONSTRUCT(UAVIRSensorInit);
};

/*
包名称：无人机SAR雷达初始化数据包
TOPIC：IPS-SAR-INIT
完整包结构：BasicPktHeader + UAVSARInit + BasicPktTail
*/
struct UAVSARInit
{
    Z_F32 antennaHRangeMinValue;    //天线水平范围最小值	float(0, 90)	单位为度 
    Z_F32 antennaHRangeMaxValue;    //天线水平范围最大值	float(0, 90)	单位为度
    Z_F32 pitchMinValue;            //俯仰最小值	float(0, 90)	单位为度
    Z_F32 pitchMaxValue;            //俯仰最大值	float(0, 90)	单位为度
    Z_F32 beamFOVMin;               //波束最小视场角	float(0, 180)	单位为度
    Z_F32 beamFOVMax;               //波束最大视场角	float(0, 180)	单位为度
    Z_F32 workDistance;             //Effective_Distance	float(0, 100]	单位为Km
    Z_F32 dimRecognizeSet;          //模糊识别边界配置	float(0, 100]	单位为Km
    Z_F32 clearRecognizeSet;        //清晰识别边界配置	float(0, 100]	单位为Km
    Z_F32 scanCenterMinRotate;      //扫描中心转动限制最小值	float(0, 10]	单位为m / s
    Z_F32 scanCenterMaxRotate;      //扫描中心转动限制最大值	float(0, 10]	单位为m / s
    Z_U8  maxMoveTargetNum;          //最大动目标可指示数量	uint8[0, 50]	无量纲数，LSB = 1
    Z_F32 azimuthMonitorMin;        //方位监视范围最小值	float(0, 180)	单位为度
    Z_F32 azimuthMonitorMax;        //方位监视范围最大值	float(0, 180)	单位为度
    Z_I32 reserve1;                 //预留	int32 / 置零

    CONSTRUCT(UAVSARInit);
};

/*
包名称：场景目标初始化数据包
TOPIC：IPS-SCENETARGET-INIT
完整包结构：BasicPktHeader + ArrayPktHeader + SceneTargetInitPublicSeg + RoutePointsArraySeg * [ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct SceneTargetInitPublicSeg
{
	Z_U16 targetID;         //目标ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
	Z_U16 targetType;       //Type	uint16[0, 65535]	周期数据块，详见场景中Type定义
	Z_I32 longitude;        //经度	int32(-180, 180]	周期数据块，单位为度，LSB = 0.0000001°
	Z_I32 latitude;         //纬度	int32[-90, 90]	周期数据块，单位为度，LSB = 0.0000001°
	Z_F32 altitude;         //高度	float[-500, 20000]	周期数据块，单位为m
	Z_F32 heading;          //航向角	float[0, 360)	周期数据块，单位为度
	Z_F32 pitch;            //俯仰角	float(-90, 90)	周期数据块，单位为度
	Z_F32 roll;             //横滚角	float(-180, 180)	周期数据块，单位为度
	Z_F32 groundSpeed;      //地速	float[0, 1200]	周期数据块，单位为km / h
	Z_F32 influenceRadius;  //影响半径	float[0, 100]	周期数据块，单位为km / h
	Z_U16 raderScanSpeed;   //雷达扫描速率	uint16[0, 36000]	周期数据块，单位为度 / 秒，LSB = 1° / s
	Z_U8 raderWorkState;    //雷达开关状态	uint8 / "周期数据块，0 - 已关机；1 - 开机引导；2 - 已开机；3 - 关机中；其它 - 无效；"
	Z_U8 dangerFactor;      //危险因子	uint8[0, 100]	周期数据块，无量纲数，LSB = 1
	Z_U8 isStaticTarget;    //是否定点目标	uint8 / 周期数据块，0 - 非定点；1 - 定点；其它 - 无效；
	Z_U8 groupType;         //目标敌我属性	uint8 / 周期数据块，1 - 敌方；2 - 友方；3 - 中立；其它 - 未知；
	Z_U8 livingState;       //目标生存状态	uint8 / 周期数据块，0 - 生存；1 - 毁灭；2 - 毁伤；其它 - 无效；
	Z_U8 routeID;       //航路ID	    uint8	[0, 255]
	Z_U8 subRouteCount; //子航线条数	uint8	[0,10]
	Z_U8 reserve1;          //预留	uint8 / 周期数据块，预留置零

	CONSTRUCT(SceneTargetInitPublicSeg);
};

struct RoutePointsArraySeg
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

    CONSTRUCT(RoutePointsArraySeg);
};

/*
包名称：删除训练中目标数据包
TOPIC：IPS-SCENETARGET-REMOVE-INIT
完整包结构：BasicPktHeader + ArrayPktHeader + SceneTargetRemoveArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct SceneTargetRemoveArraySeg
{
	Z_U16 targetID;         //目标ID	uint16[256, 65535]	周期数据块，无量纲数，LSB = 1
	Z_I16 reserve1;         //预留	int16 / 周期数据块，预留置零

	CONSTRUCT(SceneTargetRemoveArraySeg);
};

/*
包名称：气象信息初始化数据包
TOPIC：IPS-WEATHER-INIT
完整包结构：BasicPktHeader + WeatherInit + BasicPktTail
*/
struct WeatherInit
{
    Z_U8 weatherType;       //天气类型	uint8 / 0 - 晴；1 - 雨；2 - 雪；其它 - 无效；
    Z_U8 weatherDensity;    //天气剧烈程度	uint8[0, 100]	无量纲数，LSB = 1
	Z_U16 visiableDis;      //能见度距离	uint16(0, 10000]	单位为m，LSB = 1千m
    Z_F32 windSpeed;        //风速	float[0, 40]	单位为m / s
    Z_F32 windDirection;    //风向	float[0, 360)	单位为度
    Z_U8 onflowState;       //湍流开关	uint8 / 0 - 关；1 - 开；其它 - 无效；
    Z_U8 gustState;         //阵风开关	uint8 / 0 - 关；1 - 开；其它 - 无效；
    Z_U8 windShearState;    //风切变开关	uint8 / 0 - 关；1 - 开；其它 - 无效；
    Z_F32 seaTemperature;   //海平面温度	float	(-50,100)	单位为摄氏度

    CONSTRUCT(WeatherInit);
};

/*
包名称：时间初始化数据包
TOPIC：IPS-TIME-INIT
完整包结构：BasicPktHeader + TimeInit + BasicPktTail
*/
struct TimeInit
{
    Z_U32 date;     //日期	uint32	[0,20500000]	用整数表示的当天日期：年月日，如2020-8-30，整数为20200830
    Z_U32 time;     //时间	uint32	[0,235959999]	用整数表示的当前时间：时分秒毫秒，如16:54:46:200，整数为165446200
    Z_U8 reserve1;  //预留	uint8 / 置零

    CONSTRUCT(TimeInit);
};

/*
包名称：训练指令数据包
TOPIC：IPS-TRAINCTRL-CMD
完整包结构：BasicPktHeader + TrainCtrlCmd + BasicPktTail
*/
struct TrainCtrlCmd
{
    Z_U8 trainCmd;      //训练控制指令	uint8 / 0 - 停止；1 - 开始；2 - 暂停；3 - 继续；4 - 初始化 其它 - 无效
    Z_I16 reserve1;     //预留	int16 / 置零

    CONSTRUCT(TrainCtrlCmd);
};

/*
包名称：训练模式控制指令数据包
TOPIC：IPS-TRAINCTRLMODE-CMD
完整包结构：BasicPktHeader + TrainCtrlModeCmd + BasicPktTail
*/
struct TrainCtrlModeCmd
{
	Z_U8 trainModeCmd;      //训练控制指令	uint8 / 1 - 实时模式；2 - 回放模式开始；3 - 回放模式结束；其它 - 无效
	Z_I16 reserve1;     //预留	int16 / 置零
	CONSTRUCT(TrainCtrlModeCmd);
};

/*
包名称：训练回放训练科目信息数据包
TOPIC：IPS-TRAIN-SUBJECT-REPLAY-INIT
完整包结构：BasicPktHeader + TrainSubjectReplayInit + BasicPktTail
*/
struct TrainSubjectReplayInit
{
	Z_U8 subjectID[40];     //训练科目Id	uuid	无量纲数，LSB = 1
	Z_U32 coachID;          //教练编号	uint16[0, 65535]	无量纲数，LSB = 1
	Z_U32 classId;			//班级编号  uint16[0, 65535]	无量纲数，LSB = 1
	Z_U32 date;				//日期	uint32	[0,20500000]	用整数表示的当天日期：年月日，如2020-8-30，整数为20200830
	Z_U32 time;				//时间	uint32	[0,235959999]	用整数表示的当前时间：时分秒毫秒，如16:54:46:200，整数为165446200
	Z_U32 IRPlayer;			// 0 不播放，1 播放(回放视频时，标记可回放视频类型)
	Z_U32 VLPlayer;			// 0 不播放，1 播放(回放视频时，标记可回放视频类型)
	Z_U32 SARPlayer;		// 0 不播放，1 播放(回放视频时，标记可回放视频类型)
	CONSTRUCT(TrainSubjectReplayInit);
};
/*
包名称：软件启停指令数据包
TOPIC：IPS-SOFTCTRL-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + SoftwareCtrlCmdPublicSeg + SoftwareCtrlCmdArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct SoftwareCtrlCmdPublicSeg
{
    Z_U8 seatID;    //被控席位ID	uint8	0~10	无量纲数，LSB = 1

    CONSTRUCT(SoftwareCtrlCmdPublicSeg);
};

struct SoftwareCtrlCmdArraySeg
{
	Z_U8 subSeatId;				//子席位ID
    Z_U8 softwareID;            //软件ID	uint8	0~255	无量纲数，LSB = 1
    Z_U8 softwareCmd;           //软件启停指令	uint8 / 0 - 停止；1 - 启动；其它 - 无效
    Z_U8 softwarePath[100];     //软件路径	char(100) / 软件的运行路径字符串

    CONSTRUCT(SoftwareCtrlCmdArraySeg);
};

/*
包名称：多边形区域数据包
TOPIC：IPS-POLYGON-AREA-INIT
完整包结构：BasicPktHeader + ArrayPktHeader + PolygonAreaInfoPublicSeg + PolygonAreaInfoArraySeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct PolygonAreaInfoPublicSeg
{
    Z_U16 areaID;       //区域id	uint16[0, 65535]	公共数据块，无量纲数，LSB = 1
    Z_U8 areaType;      //区域类型	uint8 / 公共数据块，1 - 圆形区域；2 - 多边形区域；
    Z_U8 colorR;        //区域颜色R	uint8[0, 255]	公共数据块，无量纲数，LSB = 1
    Z_U8 colorG;        //区域颜色G	uint8[0, 255]	公共数据块，无量纲数，LSB = 1
    Z_U8 colorB;        //区域颜色B	uint8[0, 255]	公共数据块，无量纲数，LSB = 1
    Z_U8 colorA;        //区域透明度A	uint8[0, 100]	公共数据块，无量纲数，LSB = 1
    Z_F32 radius;       //圆形区域半径	float(0, 100)	公共数据块，单位为km
    Z_U8 areaSource;    //区域来源	uint8 / 公共数据块，待定

    CONSTRUCT(PolygonAreaInfoPublicSeg);
};

struct PolygonAreaInfoArraySeg
{
    Z_I32 longitude;    //区域点经度	int32(-180, 180]	周期数据块，单位为度，LSB = 0.0000001°
    Z_I32 latitude;     //区域点纬度	int32[-90, 90]	周期数据块，单位为度，LSB = 0.0000001°
    Z_F32 altitude;     //区域点高度	float[-500, 20000]	周期数据块，单位为m

    CONSTRUCT(PolygonAreaInfoArraySeg);
};

/*
包名称：训练科目数据包
TOPIC：IPS-SUBJECT-CFG-INIT
完整包结构：BasicPktHeader + TrainSubjectInfo + BasicPktTail
*/
struct SeatItemInfo
{
	Z_U8 seatId;				//席位ID    [1,6]
	Z_U8 seatType;				//席位类型  [飞行、任务、链路]
	Z_U32 seatStuNum;			//席位学员编号
	CONSTRUCT(SeatItemInfo);
};
struct TrainSubjectInfo
{
	Z_U8 subjectID[40];     //训练科目Id	uuid	无量纲数，LSB = 1
	Z_U8 subjectType;       //训练科目类型	uint8[0, 255]	无量纲数，LSB = 1
	Z_U32 coachID;          //教练编号	uint16[0, 65535]	无量纲数，LSB = 1
	Z_U32 classId;			//班级编号  uint16[0, 65535]	无量纲数，LSB = 1
	Z_U32 date;				//日期	uint32	[0,20500000]	用整数表示的当天日期：年月日，如2020-8-30，整数为20200830
	Z_U32 time;				//时间	uint32	[0,235959999]	用整数表示的当前时间：时分秒毫秒，如16:54:46:200，整数为165446200
	SeatItemInfo seat[6];       //席位学员信息
	Z_I16 trainStage;         //保存训练阶段值bit0-Tarmac-delay bit1-Take-off bit2-Climbing bit3-Cruise bit4-RTB bit5-下降 bit6-进场 bit7-GA
	CONSTRUCT(TrainSubjectInfo);
};

/*
包名称：训练评估通讯数据包
TOPIC：IPS-TRAININGEVA-COM
完整包结构：BasicPktHeader  + TrainingEvaCom + BasicPktTail
*/
struct TrainingEvaCom
{
	Z_U8 cmd;				//命令	1、请求启动评估
	Z_U32 sequenceId;		//包序列号
	TrainSubjectInfo trainingSubjectInfo;//请求启动评估时有意义
	CONSTRUCT(TrainingEvaCom);
};

struct SeatStageInfoArraySegIPS {
	Z_U8 uavId;				//无人机ID
	Z_U8 stageState[6];		//阶段	
	CONSTRUCT(SeatStageInfoArraySegIPS);
};
/*
包名称：训练评估通讯响应数据包
TOPIC：IPS-TRAININGEVA-COM-ACK
完整包结构：BasicPktHeader + TrainingEvaComAck + BasicPktTail
*/
struct TrainingEvaComAck
{
	Z_U32 sequenceId;		//包序列号， 为响应的cmd包的序号加 1
	Z_U8 msg[40];			//响应信息
	CONSTRUCT(TrainingEvaComAck);
};

/*
包名称：客户端登录数据包
TOPIC：IPS-LOGIN-CMD
完整包结构：BasicPktHeader + ClientLogin + BasicPktTail
*/

struct ClientLogin
{
	Z_U8 seatId;	   //席位ID
	Z_U8 count[16];    //账户名称
	Z_U8 password[16]; //登录密码
	Z_U8 cmd;		   //cmd 登录控制cmd=1登录，cmd=2注销
	CONSTRUCT(ClientLogin);
};

/*
包名称：客户端登录状态数据包
TOPIC：IPS-LOGIN-STA
完整包结构：BasicPktHeader + ClientLoginState + BasicPktTail
*/

struct ClientLoginState
{
	Z_U8 seatId;	 //席位ID
	Z_U8 count[16]; //账户名称
	Z_U8 state;     //登录状态 0-未登录、1-登录成功、2-登录账户或者密码不正确、3-注销成功、4-注销失败
	CONSTRUCT(ClientLoginState);
};

/*
包名称：视频记录与回放控制录制对象包
TOPIC：IPS-TRAIN-VIDEO-RECORD-INIT
BasicPktHeader + ArrayPktHeader + VideoRecordConfigSeg[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct VideoRecordConfigSeg
{
	Z_U8    addr[16];      ///<服务端iP
	Z_U16   port;      ///<服务端端口号
	Z_U8     seatId;      ///<席位id
	Z_U8     mode;      ///<录制类型 0指定窗口，1录制屏幕（1时softWndName无效）
	Z_U8     type;      ///<IR = 1,TV = 2, SAR =3
	Z_U8     softWndName[50];  ///<对应软件窗口名称，暂时不支持区分同名窗口
};

/*
包名称：无人机飞行航点信息数据包
TOPIC：IPS-WPT-CMD
完整包结构：BasicPktHeader + ArrayPktHeader + UAVWaypointInfoPublicSegIPS + UAVWaypointInfoArraySegIPS[ArrayPktHeader.arrayCountInPkt] + BasicPktTail
*/
struct UAVWaypointInfoPublicSegIPS
{
	Z_U8 routeID;       //航路ID      uint8  [0, 255]
	Z_U8 subRouteCount; //子航线条数  uint8  [0,10]

	CONSTRUCT(UAVWaypointInfoPublicSegIPS);
};

struct UAVWaypointInfoArraySegIPS
{
	Z_U8 subRouteID;        // 航点所属子航线ID  uint8[0, 255]  周期数据，无量纲数，LSB = 1
	Z_U8 subRouteColorR;    // 子航线R(颜色)  uint8[0, 255]  周期数据，无量纲数，LSB = 1
	Z_U8 subRouteColorG;    // 子航线G(颜色)  uint8[0, 255]  周期数据，无量纲数，LSB = 1
	Z_U8 subRouteColorB;    // 子航线B(颜色)  uint8[0, 255]  周期数据，无量纲数，LSB = 1
	Z_U8 subRouteColorA;    // 子航线A(透明度)  uint8[0, 100]  周期数据，无量纲数，LSB = 1
	Z_U8 subRouteType;      // 子航线类型  uint8 / "周期数据，1 - Take-off；2 - Climbing；3 - Cruise；4 - 下降；5 - GA；其它 - 无效；"
	Z_U8 wptIDInSubRoute;   // 航点在子航线里的ID  uint8[0, 255]  周期数据，无量纲数，LSB = 1
	Z_U8 wptIDInRoute;      // 航点导航ID（总航点ID）  uint8[0, 255]  周期数据，无量纲数，LSB = 1
	Z_I32 longitude;        //int32  (-180, 180]  周期数据，单位为度，LSB=0.0000001°
	Z_I32 latitude;         //int32  [-90, 90]  周期数据，单位为度，LSB=0.0000001°
	Z_F32 altitude;         //float  [-500,20000]  周期数据，单位为m
	Z_F32 speed;            // 航点速度  float[0, 1200]  周期数据，单位为km / h 
	Z_U8 motionType;        // 航路点机动指令      周期数据，0 - 过点；1 - 压点；
	Z_U16 reserve1;         // 预留  uint16 / 周期数据，预留置零
	Z_U8 reserve2;          // 预留  uint8 / 周期数据，预留置零

	CONSTRUCT(UAVWaypointInfoArraySegIPS);
};

/*
包名称：训练指令数据包 freezeModel
TOPIC：IPS-TRAINCTRL-FZMODEL-CMD
完整包结构：BasicPktHeader + TrainCtrlFZModelCmd + BasicPktTail
*/
struct TrainCtrlFZModelCmd
{
	Z_U8 uavId;			//无人机ID	
    Z_U8 freezeModel;   //冻结模型指令	uint8 / 0 - 不冻结；1 - 冻结；其它 - 无效；
    Z_I16 reserve1;     //预留	int16 / 置零

    CONSTRUCT(TrainCtrlFZModelCmd);
};

/*
包名称：故障状态数据包 供数据记录软件使用
TOPIC：IPS-FAULTSTATE-CMD
完整包结构：BasicPktHeader + FaultStateCmd + BasicPktTail
*/
struct FaultStateCmd
{
	Z_U8 m_faultId; //故障类型
	Z_I32 data; //日期
	Z_I32 time; //时间
	Z_U8 m_state;	// 0-关闭 1-开启
	CONSTRUCT(FaultStateCmd);
};

/*
包名称：故障损失数据包 
TOPIC：IPS-LOSTFAULT-CMD
完整包结构：BasicPktHeader + LossFaultCmd + BasicPktTail
*/
struct LossFaultCmd
{
	Z_U8 m_faultLostType; //故障损失类型类型 1:推力故障	
	Z_F32 value;		  //故障值:0.1,0.25,0.5等
	
	CONSTRUCT(LossFaultCmd);
};

/*
包名称：异常注入数据包 
TOPIC：IPS-ABNORMALINJECT-CMD
完整包结构：BasicPktHeader + AbnormalInjectCmd + BasicPktTail
*/
struct AbnormalInjectCmd
{
	Z_U8 m_abnormalInjectType;	//异常类型：1: 发动机滑油温度、2:无线电高度值、3：航向值、4：起落架状态
	Z_U8 state;					//异常状态: 0:正常 ; 1:故障
	Z_F32 value;				//异常值

	CONSTRUCT(AbnormalInjectCmd);
};

ICD2002G_NAMESPACE_END
#pragma pack(pop)