#pragma once
#pragma  pack (1)
// DDS_TOPIC_HUD_PERIOD_SEND
struct FS_HudPeriod
{
	float SideslipAngle;//�໬�� *100
	float AttackAngle;//���� *100
	float CurrentAirSpeed;//��ǰ���� *50
	float VacuoSpeed;//����� *50
	float CurrentMachNumber;//��ǰ����� *1000
	float PressueAltitude;//��ʾ��ѹ�߶�
	float AmbientTemperature;//�����¶�
	float CurrentVerticalSpeed;//��ǰ��ֱ�ٶ�
	float CourseBeaconDeviation;//�����ű�ƫ��(LOC)
	float GlidePathDeviation;//�»���ƫ�루GS)
	float RadioAltitude;//���ߵ�߶�
	float FrontWheelLoadSignal;//�����źţ�WOW��ǰ����������
	float LeftWheelLoadSignal;//�����źţ�WOW��������������
	float RightWheelLoadSignal;//�����źţ�WOW��������������
	float FrontUndercarriageCondition;//�����״̬ ǰ������/����
	float LeftUndercarriageCondition;//�����״̬ ��������/����
	float RightUndercarriageCondition;//�����״̬ ��������/����
	float TheFlapsPosition;//����λ��
	float StallingSpeed;//ʧ���ٶ�
	float ChannelOff;//����ƫ��
	float DecisionAltitude;//���ϸ߶�
	float TrueHeading;//�溽��
	float PitchAngle;//������
	float RollAngle;//�����
	float GroundSpeed;//����
	float WindSpeed;//����		
	float WindDirection;//����
};

// DDS_TOPIC_DU_SEND
struct FS_DU
{
	double GNSSLongtitude;//GNSS����
	double GNSSLatitude;//GNSSγ��
	double GNSSAltitude;//GNSS�߶�
	float GNSSEastToSpeed;//GNSS�����ٶ�
	float GNSSNorthToSpeed;//GNSS�����ٶ�
	float GNSSHeavenToSpeed;//GNSS�����ٶ�
	double Longtitude;//����
	double Latitude;//γ��
	double Altitude;//�߶�
	float EastToSpeed;//�����ٶ�

	float NorthToSpeed;//�����ٶ�
	float HeavenToSpeed;//�����ٶ�
	float AxialAcceleration;//������ٶ�
	float LateralAcceleration;//������ٶ�
	float NormalAcceleration;//������ٶ�
	float YawAngle;//ƫ����
	float PitchAngle;//������
	float RollAngle;//�����
	float YawRate;//ƫ�����ٶ�
	float PitchRate;//�������ٶ�

	float RollRate;//��ת���ٶ�
	float WindSpeed;//����
	float WindDirection;//����
	float GNSSGroundSpeed;//GNSS����
	float GNSSTrackAngle;//GNSS������
	float CourseErrorCorrection;//�������������	
	float PitchErrorCorrection;//�������������
	float RollErrorCorrection;//������������
	float SideslipAngleAOS;//�໬��AOS
	float AttackAngleAOA;//����AOA

	float CalibratedAirspeedVc;//У׼����Vc
	float VacuoSpeedVt;//�����Vt
	float MachNumberM;//�����M
	float BarometricHeightH;//��ʾ��ѹ�߶�H
	float StaticTempTs;//����Ts
	float LiftingSpeedHPR;//�����ٶ�HPR
	float TotalTempTt;//����Tt
	float StandardPressureAltitudeHQNE;//��׼��ѹ�߶�HQNE
	float StandardPressurePs;//��ѹPs	
	float TotalPressurePt;//ȫѹPt

	float DMECurrentChannelNumber;//DME��ǰ������
	float DMEDistance;//DME����
	float DMEGroundSpeed;//DME����
	float DMEInTheTime;//DME��̨ʱ��
	float VORAzimuthAngle;//VOR��λ��
	float LOCDiviation;//LOCƫ��
	float GSDiviation;//GSƫ��
	float RAAltitude;//RA�߶�
	float FrontWheelLoadSignal;//�����źţ�WOW��ǰ����������
	float LeftWheelLoadSignal;//�����źţ�WOW��������������

	float RightWheelLoadSignal;//�����źţ�WOW��������������
	float FrontUndercarriageCondition;//�����״̬ ǰ������/����
	float LeftUndercarriageCondition;//�����״̬ ��������/����
	float RightUndercarriageCondition;//�����״̬ ��������/����
	float TheFlapsPosition;//����λ��	
	float AmbientTemperature;//�����¶�OAT(Ch8 Temp)
	float N1;//N1(Ch 1 RPM)
	float PROP;//PROP(Ch 2 RPM)
	float RWing;//R Wing (Ch2 Fuel Level)
	float Elevator;//Elevator (Ch6 Pressure)	

	float PWR;//PWR (Ch14 Temp)
	float OILT;//OIL T (Ch2 Temp)
	float LWing;//L Wing (Ch1 Fuel Level)
	float Aileron;//Aileron (Ch5 Pressure)
	float EGT;//EGT(Ch1 Temp)
	float CENTER;//CENTER (Ch3 Fuel Level)
	float RUDDER;//RUDDER (Ch4 Pressure)
	float OILP;//OIL P (Ch3 Pressure)
	float FUELP;//FUEL P (Ch2 Pressure)
	float TORQ;//TORQ          (Ch1 Pressure)
	float FuelFlow;//Fuel Flow
}

//��ʼ��HUD����
struct ST_HUD_INIT_DATA
{
	unsigned char packageType;		//���ݰ�����
	unsigned char cycleCount;		//ѭ������
	unsigned char dataValidity;		//������Ч��
	unsigned short VFE;				//����������ٶ�
	unsigned short VMO;				//������������ٶ�
	unsigned short VMax;			//�����ʾ�����ٶ�
	unsigned short VS;				//ʧ���ٶ�Vs
	unsigned short minPressureAlt;	//�����ѹ�߶�
	unsigned short VSO;				//ʧ���ٶ�Vso
	unsigned short VD;				//��󸩳��ٶ�Vd
	unsigned char checksum;			//У���
};
#pragma  pack()