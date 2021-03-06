#ifndef __DEFINE_H
#define __DEFINE_H

#include "stm32f2xx_hal.h"

/***********************************************
**任务优先级设置
***********************************************/
#define  Falg_SUCCEED_PRIO_MEM                1 //标志继承优先级
#define  Falg_SUCCEED_PRIO                    2 //标志继承优先级
#define  SYSMonitorTask_PRIO                  3
#define  LED1Task_PRIO                        4
#define  LED2Task_PRIO                        5
#define  LED3Task_PRIO		                  6



/***********************************************
**任务堆栈长度设置
***********************************************/
#define SYSMonitorTaskStackLengh              128
#define LED1TaskStackLengh                  128
#define LED2TaskStackLengh				          128
#define LED3TaskStackLengh    			128

extern 	uint8_t ReadBuffer[100];
//CAN通信报文事件的状态机
extern uint8_t  ubCANEventStatus;
/* CAN通信数据帧定义  */
/*----------------------------------------------
-----------------握手阶段定义------------------
-----------------------------------------------*/
 //辨识结果，物理连接之后，充电机向BMS发送此报文，在收到BMS发送的辨识报文之前发送0x00，在收到BMS辨识报文之后发送0xAA
extern uint8_t ubRecognitionResult;	
//充电机编号，1/位，1偏移量，数据范围1-100	
extern uint8_t ubChargerNumber;

/*------------------------------------------------
------------PGN512,BRM报文参数--------------------
-------------------------------------------------*/
//BMS通信协议版本号，本标准规定当前版本为V1.0 表示为：byte3 byte2 byte1  0x 00 01 00
extern uint32_t ulBmsProtocolVersion;
//电池类型：01H：铅酸电池 02H：镍氢电池	03：磷酸铁锂电池 04H：锰酸锂电池 05H：钴酸锂电池 06H：三元材料电池 07H：聚合物锂离子电池 08H：钛酸锂电池 FFH：其他电池
extern uint8_t ubBatteryType;
//整车动力蓄电池系统额定容量/A*h,0.1A*h/位，0.1A*h偏移量 数据范围 :0-——1000A.h
extern uint16_t uwBmsRateCapacity;
//整车动力蓄电池系统额定总电压 /V ，O.l V/位 ，0 V 偏移量，数据范 围:0  750 V
extern uint16_t uwBatteryRateVoltage;
//电池生产厂商名称，标准 ASCII 码
extern uint8_t ubBatteryManufacturerName[4];
//电池组序号，预留，由厂商自行定义
extern uint16_t ulBatteryManufacturerName;
//电池组生产日期，年 1985偏移位
extern uint8_t ubBatteryProduceYear;
//电池组生产日期，月
extern uint8_t ubBatteryProduceMonth;
//电池组生产日期，日
extern uint8_t ubBatteryProduceDay;
//电池组充电次数，1次每位  ,3个字节
extern uint16_t ulBatteryChargeCycle;
//电池组产权标志  0表示租赁   1表示 车自有
extern uint8_t ubPropertyMark;
//预留
extern uint8_t ubBMSReserved;
//车辆识别码VehicleIdentificationNumber
extern uint8_t ubVIN[17];

/*-----------------------------------------------
-------------------参数配置阶段报文--------------
-------------------------------------------------*/


/*-----------------------------------------------
-------------------PGN1536 BCP报文参数-------------
-------------------------------------------------*/
//单体动力蓄电池最高允许充电电压  数据分辨率 :0.01 V/位， 0 V 偏移量 E 数据范围 :0 V~24V;   
extern uint16_t uwCellMaxAllowChargeVoltage;
//最高允许充电电流	 数据分辨率 :0.lA/位， -400 A 偏移量;数据范围: -400 A ~O A;
extern  uint16_t uwMaxAllowChargeCurrent;
//动力蓄电池标称总能量	  数据分辨率 :0.1 kW  o h/ 位， 0 kW. h 偏移量;数据范围 :0，.....，1 000  kW o h; 
extern uint16_t uwBatteryTotalEnergy;
//最高允许充电总电压   数据分辨率 :0.1 V/ 位， 0  V 偏移量;数据范围 :0 V ，......750  V;
extern uint16_t uwMaxAllowChargeVoltage;
//最高允许温度		 数据分辨率 :1 oC/位，-50 OC 偏移量 F 数据范围:一 50 oC ，.....， +200 oC;
extern uint8_t ubMaxAllowTemperature;
//整车动力蓄电池荷电状态	数据分辨率 :0.1%/位， 0%偏移量;数据范围 :0，.....，100% ; 
extern uint16_t uwBmsSOC;
//整车动力蓄电池总电压
extern uint16_t uwBmsTotalVoltage;
//---------PGN2048 CML报文-------------
//DC最高输出电压
extern uint16_t uwDCMaxOutputVoltage;
//DC最低输出电压
extern uint16_t uwDCMinOutputVoltage;
//DC最大输出电流
extern uint16_t uwDCMaxOutputCurrent;
//BMS 是否充电准备好(< OxOO-) := BMS 未做好充电准备; (OxAA):=BMS 完成充电准备; (OxFF):=元效)
extern uint8_t ubBmsChargeReady;
//充电机是否充电准备好 ((OxOO):=充电机未完成充电准备; (OxAA):=充电机完成充电准备; (OxFF):=无效)
extern  uint8_t ubChargerOutputReady;

/*充电阶段报文*/
//电压需求(V)
extern uint16_t uwVoltageRequirement;
extern uint8_t uwVoltageRequirementLow;
extern uint8_t uwVoltageRequirementHigh;
//电流需求 (A)
extern int16_t uwCurrentRequirement;
extern int8_t uwCurrentRequirementLow;
extern int8_t uwCurrentRequirementHigh;
extern int8_t uwCurrentRequirementLowbuf;
extern int8_t uwCurrentRequirementHighbuf;
extern int16_t uwCurrentRequirementbuf;
extern uint16_t CURRENT;
//充电模式 (Ox01:恒压充电	;Ox02:恒流充电)
extern uint8_t ubChargeMode;
//充电电压测量值 (V)
extern  uint16_t uwChargeVoltageMeasurement;
//充电电流测量值 (A)
extern uint16_t uwChargeCurrentMeasurement;
//最高单体动力蓄电池电压及其组号
extern uint16_t uwHighestCellVoltageAndGroupNumber;
//当前荷电状态 SOC(%)
extern  uint8_t ubCurrentSOC;
//估算剩余充电时间 (min)
extern  uint16_t uwRemainChargeTime;
//电压输出值 (V)
extern  uint32_t uwOutputVoltageValue;
//电流输出值 (A)
extern uint32_t uwOutputCurrentValue;
//累计充电时间 (min)
extern uint16_t uwAccumulateChargeTime;
//最高单体动力蓄电池电压所在编号
extern uint8_t ubMaxCellVoltageNumber;
//最高动力蓄电池温度
extern uint8_t ubMaxTemperature;
//最高温度检测点编号
extern uint8_t ubMaxTemperatureNumber;
//最低动力蓄电池温度
extern uint8_t ubMinTemperature;
//最低动力蓄电池温度检测点编号
extern uint8_t ubMinTemperatureNumber;
//异常状态信息	 
//单体动力蓄电池电压过高/过低 ((00): =正常 ;{01):= 过高;(10):=过低)
//整车动力蓄电池荷电状态 soc 过高/过低 ((00): =正常 ;(01):= 过高;(10):= 过低〉
//动力蓄电池充电过电流 ((00):= 正常 ;(01):== 过流;(10): =不可信 状态〉
//动力蓄电池温度过高 ((00): =正常; (01): =:过高;(1 0):= 不可信 状态
//动力蓄电池绝缘状态 ((00): =正常 ;(01):=不正常;(10):= 不可信 状态〉
//动力蓄电池组输出连接器连接状态 ((00):= 正常; (01): =不正常;(10): =不可信状态〉
//充电允许 ((00):= 禁止 ;(01):=允许〉
extern uint16_t uwStatusAndAbnormal;
//单体动力蓄电池电压
extern uint16_t uwCellVoltage[256];
//单体动力蓄电池温度
extern uint8_t ubCellTemperature[128];
//单体动力蓄电池预留报文
extern uint8_t ubCellReserved[16];
//BMS  中止充电原因
extern uint8_t ubBmsChargeStopReason;
//BMS  中止充电故障原因
extern uint16_t uwBmsChargeStopFaultReason;
//BMS  中止充电错误原因
extern uint8_t ubBmsChargeStopErrorReason;
//充电机中止充电原因
extern uint8_t ubChargerStopReason;
//克电机中止充电故障原因
extern uint16_t uwChargerStopFaultReason;
//充电机中止充电错误原因
extern uint8_t ubChargerStopErrorReason;
//中止荷电状态 SOC(%)
extern uint8_t ubBmsEndOfSOC;
//动力蓄电池单体最低电压 (V)
extern  uint16_t uwBmsEndMinCellVoltage;
//动力蓄电池单体最高电压 (V)
extern uint16_t uwBmsEndMaxCellVoltage;
//动力蓄电池最低温度 CC)
extern uint8_t ubBmsEndMinTemperature;
//动力蓄电池最高温度 CC)
extern uint8_t ubBmsEndMaxTemperature;
//累计充电时间 (min)
extern uint16_t uwChargerEndChargeTime;
//输出能量 (kW. h)
extern uint16_t uwChargerEndChargePower;
//BMS 错误报文 (BEM)
extern  uint8_t ubBmsError[4];
//充电机错误报文 (CEM)
extern  uint8_t ubChargerError[4];


//DC直流充电模块状态
//extern uint8_t ubDCModuleStatusHigh;
//extern uint8_t ubDCModuleStatusLow;

extern uint8_t ubDCModuleStatusHigh[4];
extern uint8_t ubDCModuleStatusLow[4];
// DC电压输出
extern uint16_t uwDCOutputVoltage[4];
//DC电流输出
extern uint16_t uwDCOutputCurrent[4];
// BMS需求充电方式缓存值 (Ox01:恒压充电	;Ox02:恒流充电)
extern uint8_t ubChargeModeBuf;

//DC直流充电模块状态
extern uint8_t ubDCModuleStatusHighAll; 
                                 //第0位 0表示模块运行 1表示关机 
                                 //第1位 0表示模块正常 1表示故障 
                                 //第2位 0表示模块恒压 1表示限流
                                 //第3位 0表示风扇正常 1表示故障  
                                 //第4位 0表示输入正常 1表示过压  
                                 //第5位 0表示输入正常 1表示欠压  
                                 //第6位 0表示输出正常 1表示过压  
                                 //第7位 0表示输出正常 1表示欠压                                
extern uint8_t ubDCModuleStatusLowAll; 
                                 //第0位 0表示过流保护 1表示正常 
                                 //第1位 0表示过温保护 1表示正常 
                                 //第2位 0表示设置关机 1表示开机
                              
//DC直流充电模块状态
extern uint16_t uwDCModuleStatus;



//标志，是否超时5s 0x00不满足，0xAA满足
extern  uint8_t FlagIfTimeout;
//标志，DC电源模块是否超时5s 0x00不满足，0xAA满足
extern uint8_t FlagIfDCTimeout;
//超时时间设置，ubTimeNs表示多少个100ms
extern uint8_t ubTimeN100ms;


//标志，是否满足周期发送 发送周期10ms 0不满足，1满足
extern uint8_t FlagIfCycleSend10ms;
//标志，是否满足周期发送 发送周期50ms 0不满足，1满足
extern uint8_t FlagIfCycleSend50ms;
//标志，是否满足周期发送 发送周期250ms 0不满足，1满足
extern uint8_t FlagIfCycleSend250ms;
//标志，是否满足周期发送 发送周期500ms 0不满足，1满足
extern uint8_t FlagIfCycleSend500ms;
//标志，是否满足周期发送 发送周期1000ms 0不满足，1满足
extern uint8_t FlagIfCycleSend1000ms;

//标志，是否收到BMS发送的BMS和车辆辨识报文 0x00未收到，0xAA收到
extern uint8_t ubFlagIfReceBmsIdentifyMeg;
//标志，是否收到BMS发送的电池充电参数报文 0x00未收到，0xAA收到
extern uint8_t ubFlagIfReceBatteryParameterMeg;
//标志，是否收到BMS发送的电池充电准备就绪状态报文 0未收到，1收到
extern uint8_t FlagIfReceBmsReadyMeg;
//标志，是否收到BMS发送的电池充电总状态报文 0x00未收到，0xAA收到
extern uint8_t ubFlagIfReceBmsAllChargeStateMeg;
//标志，是否收到BMS发送的电池充电需求报文 0x00未收到，0xAA收到
extern uint8_t FlagIfReceBmsChargeRequirementMeg;
//标志，是否收到BMS发送的动力蓄电池状态 0x00未收到，0xAA收到
extern uint8_t FlagIfReceBmsBatteryStateMeg;
//标志，是否收到BMS发送结束充电或者BMS中止充电报文 0x00未收到，0xAA收到
extern uint8_t ubFlagIfReceBmsEndAndStopChargeMeg;
//标志，是否收到BMS发送的BMS中止充电报文 0x00未收到，0xAA收到
extern uint8_t FlagIfReceBmsStopChargeMeg;
//标志，是否收到BMS发送的充电统计数据报文 0x00未收到，0xAA收到
extern uint8_t FlagIfReceBmsStatisticsDataMeg;


//标志，是否发送报文给DC直流充电机模块 0x00不发送，0xAA发送
extern uint8_t FlagIfSendDCModuleMeg;
//标志，是否收到DC直流充电机模块发送的报文 0没收到，1收到
extern uint8_t FlagIfReceDCModuleMeg;

//标志，是否发送充电机辨识报文 0x00不发送，0xAA发送
extern uint8_t ubFlagIfSendChargerIdentifyMeg;
//标志，是否发送充电机时间同步信息报文 0x00不发送，0xAA发送
extern uint8_t ubFlagIfSendChargerTimeMeg;
//标志，是否发送最大输出能力报文 0x00不发送，0xAA发送
extern uint8_t ubFlagIfSendChargerMaxOutputCapactityMeg;
//标志，是否发送充电机输出就绪状态报文 0x00不发送，0xAA发送
extern uint8_t ubFlagIfSendChargerOutputReadyMeg;
//标志，是否发送充电机充电状态报文 0x00不发送，0xAA发送
extern uint8_t FlagIfSendChargerChargingStateMeg;
//标志，是否充电机中止充电报文 0x00不发送，0xAA发送
extern uint8_t ubFlagIfSendChargerStopChargeMeg;
//标志，是否发送充电机充电统计数据报文 0x00不发送，0xAA发送
extern uint8_t ubFlagIfSendChargerStatisticsDataMeg;

//定时器6计数，10ms计数一次   
extern uint8_t ubCANTim3Count;
//定时器6计数，10ms计数一次,CAN通信车辆通信超时计数器   
extern uint16_t uwCANTimeOutCount;
//定时器6计数，10ms计数一次,CAN通信DC电源模块超时计数器   
extern uint16_t uwCANDCTimeOutCount;

//CAN接收BMS数据缓冲器  通用排除以下几种情况
extern uint8_t ubCANBuf_BMS[8];
//CAN接收数据缓冲器二位数组索引
extern uint8_t ubCANBufIndex_BMS;
//CAN收到BMS数据的ID
extern uint32_t uCANBufID_BMS;

//CAN接收DC数据缓冲器  通用排除以下几种情况
extern uint8_t ubCANBuf_DC[8];
//CAN接收DC数据缓冲器二位数组索引
extern uint8_t ubCANBufIndex_DC;
//CAN收到DC数据的ID
extern uint32_t uCANBufID_DC;


//多帧连接报文建立连接用
extern uint8_t ubCANConnect[8];
extern uint8_t ubCANMultiFrame[70][8];
extern uint8_t ubCANMultiFrameIndex;


extern uint16_t uwCANReceFlagState;//是否收到CAN数据帧标志位 0表示无效 1表示有效  
                                 //第0位 BMS和车辆辨识报文
                                 //第1位 动力蓄电池充电参数
                                 //第2位 电池充电准备就绪报文
                                 //第3位 电池充电需求
                                 //第4位 电池充电总状态
                                 //第5位 动力蓄电池状态信息
                                 //第6位 单体动力蓄电池电压
                                 //第7位 动力蓄电池温度
                                 //第8位 动力蓄电池预留报文
                                 //第9位 BMS中止充电
                                 //第10位 BMS统计报文
                                 //第11位 BMS错误报文
                                 //第12位 DC电源输出状态报文
extern uint16_t uwCANSendFlagState;//是否发送CAN数据帧标志位 0表示无效 1表示有效  
                                 //第0位 充电机辨识报文
                                 //第1位 充电机发送时间同步信息
                                 //第2位 充电机最大输出能力
                                 //第3位 充电机输出准备就绪报文
                                 //第4位 充电机充电状态
                                 //第5位 充电机中止充电
                                 //第6位 充电机统计数据
                                 //第7位 充电机错误报文
                                 //第8位 DC电源设置报文
                                 //第9位 DC电源启动停止报文           

extern uint8_t ubManyBytesStateBCS;//多帧数据的标志
extern uint8_t ubManyBytesStateBMV;//多帧数据的标志
extern uint8_t ubManyBytesStateBMT;//多帧数据的标志
extern uint8_t ubManyBytesStateBSP;//多帧数据的标志

//多数据传输协议连接管理缓存数据
extern uint8_t ubCANConnect[8];

extern uint8_t ubCellVoltageQuantity;     //单体动力蓄电池电池电压数量 
extern uint8_t ubCellTemperatureQuantity; //动力蓄电池温度 数量
extern uint8_t ubCellReservedQuantity;    //动力蓄电池预留报文  数量

extern uint8_t ubCellVoltageMegQuantity;     //单体动力蓄电池电池电压 报文帧数量 
extern uint8_t ubCellTemperatureMegQuantity; //动力蓄电池温度 报文帧数量
extern uint8_t ubCellReservedMegQuantity;    //动力蓄电池预留报文  报文帧数量

//物理连接正常标志
extern uint8_t ubPhysicalConnect;  //0x00表示未连接，0xAA表示物理连接正常，其他无效

extern uint16_t uwReadTimeCount;//CAN通信最小计时单位是分钟    这里定义30秒读取一次时间，后期根据要求修改
extern uint8_t FlagIfReadTime;//是否读取时间标志位
extern uint8_t FlagIfSendDCMeg;
extern uint8_t FlagIfShowInformation5S ;  //刷卡结束后停留标志位
extern uint8_t FlagShowInformation ;

extern uint32_t Flag;

extern uint8_t ubDCModue;      //DC模块是否启动
//多个DC充电模块的地址，1-N个模块分别为0x01 0x02 0x03 ......，
extern uint8_t ubDCModueAddress;
#define CAN_STARTDCMODUE 0x55
#define CAN_STOPDCMODUE 0xAA


extern uint8_t Time[8];

extern uint8_t ChargeFlag ;  //充电标志 1:正在充电 0:不在充电
extern uint8_t CANChargeFlag ; //充电阶段标志

//---------------------------------
//读卡器
//-----------------------------------------
extern uint8_t ICDataBfr[16];
extern uint8_t ICCard_Snr[4];
extern uint8_t ICKEYA_BUF[6];
extern uint8_t ICKEYB_BUF[6];
extern uint8_t ICDataReadBuf[16];
extern uint8_t ICMoney[4];
extern uint32_t ulMoney;
extern uint8_t ICCharge;
extern uint8_t ICDataWriteBuf[16];
extern uint8_t ICCard1[4];
extern uint8_t ICMoney1[4];
extern uint8_t ICCard2[4];
extern uint8_t ICMoney2[4];
extern uint8_t ICReadFlag;
extern uint8_t ICWriteFlag;
extern uint8_t FlagIfOperationCard;
extern uint8_t WriteBlockFlag;//写卡模块标志位，调用WriteBlock(1,ICDataReadBuf)函数时，此标志位置1,写卡成功之后此标志位复位0
extern uint8_t WriteBlockTimeFlag;//写卡模块周期发送标志，100ms置位一次，用完即清0

extern uint8_t Tim3ICWaitCount;
extern UART_HandleTypeDef huart6;
extern uint8_t pData[1];

extern uint8_t   StartICMoney[4];
extern uint32_t  StartICMoneyAll;
extern uint8_t   DealMoney[4];
extern uint32_t  DealMoneyAll;
extern uint32_t  StopMoneyAll;
//---------------------------------
//电表
//-----------------------------------------
extern uint8_t UART5RxBuffCount;
extern uint8_t UART5RxBuff[24];
extern uint8_t UART5RxFlag;

extern uint8_t	PMsendBuf[8];
extern uint8_t  VoltageA[2];
extern uint8_t  VoltageB[2];
extern uint8_t  VoltageC[2];
extern uint8_t  RectivePower[2];//无功功率
extern uint8_t  ApparentPower[2];//总视在功率
extern uint8_t  Frequency[2];//频率
extern uint8_t  ACEnergy [4]; //有功电能
extern uint8_t  CurrentA[2];//A相电流
extern uint8_t  CurrentB[2];//
extern uint8_t  CurrentC[2];//
extern uint8_t  DCVoltage[2];//直流表电压
extern uint8_t  DCEnergy [4]; //直流表电能
extern uint8_t  DCCurrent[2];//直流表电流
extern uint8_t  InsulationRes[4];//绝缘电阻
extern uint8_t  Crc485[2];

extern uint8_t  TxFlag485;  //为1时发送，
extern uint8_t  RxFlag485;  //
extern uint8_t  PMCount485;
extern uint8_t  Tim4Flag;
extern uint8_t  Flag485;//代表发送不同的指令：
extern uint8_t  Fun485Flag;  // 1:三相电流  2:三相电压  3:交流电能 4:交流频率   5:总无功功率   6:总视在功率  7:绝缘检测电阻  8:直流电表 0:不发指令

extern uint8_t   StartEnergy[4];
extern uint32_t   StartEnergyAll;
extern uint8_t   DealEnergy[4];
extern uint32_t  DealEnergyAll;



//----------------------------------
//触摸屏
//----------------------------------
#define MAX_CMD_BUFFER 500
extern uint8_t   cmd_buffer[MAX_CMD_BUFFER];
extern uint16_t  MoneyAverageElectricity;                     //平均电价
extern uint16_t  MoneyPeakElectricity;                        //峰值电价
extern uint16_t  MoneyValleyElectricity;                      //谷值电价
extern uint16_t  SetTimeHourStartPeakElectricity;             //峰值电价开始时间（时）
extern uint16_t  SetTimeMinStartPeakElectricity;              //峰值电价开始时间（分）
extern uint16_t  SetTimeHourStopPeakElectricity;              //峰值电价结束时间（时）
extern uint16_t  SetTimeMinStopPeakElectricity;               //峰值电价结束时间（分）
extern uint16_t  SetTimeHourStartValleyElectricity;           //谷值电价开始时间（时）
extern uint16_t  SetTimeMinStartValleyElectricity;            //谷值电价开始时间（分）
extern uint16_t  SetTimeHourStopValleyElectricity;            //谷值电价结束时间（时）
extern uint16_t  SetTimeMinStopValleyElectricity;             //谷值电价结束时间（分）

/*         一般定义               */
extern  uint8_t FaultOperation;
extern	uint8_t SystemState;      //系统状态：0，空闲状态；1，充电状态 ；2，异常状态；默认为0；初始化为0；根据设置条件切换系统状态
extern	uint8_t ChargingMethod ;  //充电方式：0，自动充电；1，手动充电 ；默认为0；初始化为0；屏幕选择手动模式置1
extern	uint8_t ChargingMode;     //充电模式：0，充满为止；1，按时间充 ；2.按电量充；3，按金额充；默认为0；初始化为0；屏幕选择
extern uint8_t ChargingMode;     //充电模式：0，充满为止；1，按时间充 ；2.按电量充；3，按金额充；默认为0；初始化为0；屏幕选择
extern uint16_t SetKwh;                             //充电模式界面，设置电量
extern uint16_t SetMoney;                           //充电模式界面，设置金额
extern uint16_t SetHour;                            //充电模式界面，设置时间（时）
extern uint16_t SetMin;                             //充电模式界面，设置时间（分）
extern uint16_t SetChargeCutOffCurrent;           //设置截止电流
extern uint16_t SetChargeVoltage;                 //设置充电电压
extern uint16_t SetChargeCurrent;                 //设置充电电?

extern	uint8_t Timer1CountNumber; //每500ms加1，10s复位，定时器1用
extern	uint8_t FlagCycle30s;     //10s循环定时标志位，默认为0；定时器1置位，使用完清零
extern	uint8_t FlagCycle10s;     //10s循环定时标志位，默认为0；定时器1置位，使用完清零
extern	uint8_t FlagCycle1s;      //1s循环定时标志位，默认为0；定时器1置位，使用完清零
extern	uint8_t FlagCycle500ms;   //500ms循环定时标志位，默认为0；定时器1置位，使用完清零

extern uint16_t SystemFaultState;   //系统故障状态?
                             //0000 0000 0000 0001 急停按钮按下   //0000 0001 0000 0000   存储器异常
							 //0000 0000 0000 0010 仓门未关闭     //0000 0010 0000 0000   时钟异常
							 //0000 0000 0000 0100 桩体倾斜       //0000 0100 0000 0000   读卡器异常
							 //0000 0000 0000 1000 桩体撞击       //0000 1000 0000 0000   三相电缺相
                             //0000 0000 0001 0000 环境温度过高   //0001 0000 0000 0000   绝缘电阻异常
                             //0000 0000 0010 0000 环境温度过低   //0010 0000 0000 0000   绝缘检测仪异常 
                             //0000 0000 0100 0000 环境湿度过高   //0100 0000 0000 0000   电源仓温度过高
							 //0000 0000 1000 0000 环境湿度过低   //1000 0000 0000 0000   电表异常
extern	uint8_t PileTiltState;              //充电桩桩体倾斜状态，0，未倾斜；1，倾斜；默认为0；
extern	uint8_t CabinDoorState;             //仓门状态，0，关闭；1，打开；默认为0；
extern	uint8_t EmergencyStopButtonState;   //急停按钮状态状态，0，正常；1，按下；默认为0；
extern	uint8_t PileState;                  //枪头状态，0表示未连接，1表示连接，默认为0
extern  uint8_t LevelState;                 //水平仪状态，0表示正常，1表示不正常，默认为0


extern  uint16_t DS18B20Temperature;       //DS18b20传感器温度
extern  uint16_t AM2321Temperature;        //AM2321温湿度传感器温度
extern  uint16_t Am2321Humidity;           //AM2321温湿度传感器湿度

extern  uint8_t SwipingCardFlag;   //扫卡标志，默认为0 无意义 1表示刷卡
extern  uint8_t SwipingPileFlag;    //扫枪标志  默认为0 无意义 1表示扫枪
extern  uint8_t SpeechFlag;        //语音标志，默认为0 1表示语音有效
extern uint8_t SpeechFlagMoney ;        //语音标志，默认为0 1表示语音有效
extern uint8_t SpeechFlagDeal ;        //语音标志，默认为0 1表示语音有效
extern uint8_t FlagIfSaveData;       //保存上次交易数据 默认为0 1表示有效
extern uint8_t FlagIfSaveToMemory ;
extern uint8_t FlagIfReadPriDeal;
extern uint8_t FlagIfCloseDoor;       // 关闭仓门标志
extern uint8_t FlagOpenDoor;           //打开仓门

extern uint16_t ReadPriDealNo ;

extern uint8_t *Recvdata;
extern uint16_t RecvLen;
extern uint32_t RecvIPNumber;





//-----------------------------------------
//时间
//-----------------------------------------
typedef struct 				 //定义充时间设定的结构体
{
	uint8_t Second;	
	uint8_t Minute;
	uint8_t Hour;
	uint8_t Week;
	uint8_t Day;
	uint8_t Month;
	uint8_t Year;      
}RTC_SD2405_HandleTypeDef;


typedef struct 				 //记录存储配置信息
{
	uint32_t  AcchAddress;       //充电桩号
	uint32_t  PosNumber;         //pos机号
	uint32_t  CardVer;           //卡版本号
	uint32_t  IPAddress;         //IP地址
	uint32_t  MACAddressHigh;     //MAC地址高16位 总48位
	uint32_t  MACAddressLow;      //MAC地址低32位 总48位
	uint16_t  AreaNumber;        //地区代码  
	uint16_t  ConsRate;          //电量倍率
	uint16_t  CardType;          //卡类型
	uint16_t  TransType;         //交易类型
	uint16_t  APrice;			 //平均电价
	uint16_t  HPrice;			 //峰值电价
	uint16_t  LPrice;			 //谷值电价
	uint16_t  HPriceStartH;		 //峰值起始时间(时)
	uint16_t  HPriceStartM;		 //峰值起始时间（分）
	uint16_t  HPriceStopH;		 //峰值结束时间（时）
	uint16_t  HPriceStopM;		 //峰值结束时间（分）
	uint16_t  LPriceStartH;	 	 //谷值起始时间(时)
	uint16_t  LPriceStartM;		 //谷值起始时间（分）
	uint16_t  LPriceStopH;		 //谷值结束时间(时)
	uint16_t  LPriceStopM;		 //谷值结束时间（分）
	uint16_t  StartMode;		 //启动模式
	uint16_t  BillMode;			 //计费模式
	uint32_t  Password;	 		 //密码
	uint8_t   CRCHigh;            //CRC
	uint8_t   CRCLow;             //CRC
}SystemParameterConfig_HandleTypeDef;//存储器数据

typedef struct 				 //记录存储实时信息 暂存在小存储器中，交易结束，整体搬移至大存储器
{
	uint32_t DealNo;       //交易流水号    
	uint32_t DealCardNo;   //交易卡号  已有
	uint32_t ParkFee;      //停车费
	uint32_t OriMoney;     //交易前余额 已有
	uint32_t FinMoney;     //交易后余额 已有
	uint32_t DealCounter;  //交易计数器
	uint32_t DealStartEnergy;
	uint16_t DealEnergy;   //交易电量   已有
	uint32_t DealStopEnergy;  
	uint16_t DealPrice;    //交易电价  已有
	uint16_t PileNum;      //充电桩号   本桩号
	uint16_t ChargMode;    //充电模式   分为自动充满，按时间金额电量等   
	uint16_t ChargMethod;    //充电方式 手动和自动
	uint16_t StartYear;    //交易起始时间（年） 已有
	uint16_t StartMonth;   //交易起始时间（月） 已有
	uint16_t StartDay;     //交易起始时间（日） 已有
	uint16_t StartWeek;    //交易起始时间（星期） 已有
	uint16_t StartHour;    //交易起始时间（时） 已有
	uint16_t StartMin;     //交易起始时间（分�    已有
	uint16_t StartSec;     //交易起始时间（秒）  已有
	uint16_t EndYear;      //交易结束时间（年）  已有
	uint16_t EndMonth;     //交易结束时间（月）  已有
	uint16_t EndDay;       //交易结束时间（日）  已有
	uint16_t EndWeek;      //交易结束时间（星期）  已有
	uint16_t EndHour;      //交易结束时间（时）   已有
	uint16_t EndMin;       //交易结束时间（分）   已有
	uint16_t EndSec;       //交易结束时间（秒）   已有
  uint8_t  ChargeFlag;   //交易是否成功标志0x00 交易成功 0xff交易不成功(突然断电，误拔枪)
	uint8_t  CRCHigh;      //CRC
	uint8_t  CRCLow;       //CRC
}SaveRealTimeData_HandleTypeDef;//存储实时数据

typedef struct
{
	uint8_t  IAPState;    //IAP索引
	uint32_t IAPStartAddress;    //IAP执行起始地址
	uint8_t  CRCHigh;      //CRC
	uint8_t  CRCLow;       //CRC
}IAPSystemParameter_HandleTypeDef;   //IAP结构体

typedef union
{
		uint8_t unbuffer[62];  
    SystemParameterConfig_HandleTypeDef SystemParameterConfigHandle;                                 
                           
} unSystemParameterConfig_HandleTypedef;
typedef union
{
		uint8_t unbuffer[73];  
    SaveRealTimeData_HandleTypeDef SaveRealTimeDataHandle;                                 
                           
} unSaveRealTimeData_HandleTypedef;
	
typedef union
{
	uint8_t unbuffer[7];
	IAPSystemParameter_HandleTypeDef IAPSystemParameter; 
}unIAPSystemParameter_HandleTypeDef;


typedef struct 				 //记录存储实时信息
{
	uint32_t IPNumber;       //交易流水号
	uint8_t Data[100];
	uint16_t Length;
}strETHData_Typedef;//存储实时数据

extern RTC_SD2405_HandleTypeDef RTCSetTime;
extern RTC_SD2405_HandleTypeDef RTCReadTime;
extern RTC_SD2405_HandleTypeDef RTCReadBCDTime;
extern RTC_SD2405_HandleTypeDef StartChargeBCDTime;
extern RTC_SD2405_HandleTypeDef StartChargeTime;
extern RTC_SD2405_HandleTypeDef ChargeTime;
extern unSaveRealTimeData_HandleTypedef  unSaveRealTimeDataHandle ;
extern unSystemParameterConfig_HandleTypedef   unSystemParameterConfigHandle;
extern unIAPSystemParameter_HandleTypeDef  unIAPSystemParameter;



#define FAULTLIGHTSET      1   //故障灯亮
#define FAULTLIGHTRESET    0   //故障灯灭
#define FULLFREELIGHTSET   1   //充满或者空闲灯亮
#define FULLFREELIGHTRESET 0   //充满或者空闲灯灭�

#define MAXAM2321TEMP     900    //温湿度传感器最高允许温度0.1/bit   偏移量40℃   
#define MINAM2321TEMP     200    //温湿度传感器最低允许温度0.1/bit   偏移量40℃
#define MAXAM2321HUMI     950    //温湿度传感器最高允许湿度0.1/bit
#define MINAM2321HUMI     50    //温湿度传感器最低允许湿度0.1/bit
#define DS18B20TEMP      800    //电源仓风扇开启温度阈0.1/bit   偏移量40℃
#define MAXDS18B20TEMP   1100    //电源仓最高温度阈值0.1/bit   偏移量40℃


void mDelayCAN10us(uint8_t n);
void HAL_Delay1us(uint16_t n);
void SPI_Delay(uint16_t n);

void AccumulateChargeEnergy(void);
void AccumulateChargeMoney(void);

void SetACRelay(void);//启动交流接触器
void ResetACRwlay(void);//停止交流继电器
void SetDCRelay(void);//启动直流接触器
void ResetDCRwlay(void);//停止直流接触器
void SetBMSRelay(void); //启动辅助电源
void ResetBMSRwlay(void);//停止辅助电源


void StartFan(void);//启动风扇
void StopFan(void);//停止风扇
void OpenDoor(void);//开门
void CloseDoor(void);//关门
uint8_t CheckPileState(void);//检测枪头状态，枪头连接为返回1 ，枪头未连接返回0
uint8_t CheckCabinDoorState(void);//检测仓门状态，仓门关闭为1，仓门未关闭为0
uint8_t CheckLevelState(void);  //检测水平仪状态，水平仪正常返回0，水平仪不正常返回1
uint8_t CheckEmergencyStopButtonState(void);//检测急停按钮状态，急停按钮未按下为0，急停按钮按下为1
void ShowPileFaultState(uint8_t);//充电桩故障，红灯亮
void ShowPileChargeFullOrFree(uint8_t);//充电桩充满或者空闲
void Enable_IRQ(void);                 //使能中断
void Disable_IRQ(void);                 //关闭中断
void ReadIAPSystemParatemer(void);      //读取系统参数
void SaveIAPSystemParatemer(void);       //保存系统参数

uint8_t SystemSelfingCheck(void);//系统自检
uint8_t Collect_System_State_Process(void);//采集系统状态子程序�
void ReadSystemParameter(void);   //开机时读取系统参数
void ReadDealData(void);      //刷卡前读取上次交易数据

void SetACRelay(void) ; //启动交流接触器
void ResetACRwlay(void); //停止交流继电器
void SetDCRelay(void); //启动直流接触器
void ResetDCRwlay(void);//停止直流接触器

void HMI_Event_Process(void);//处理屏幕子程序
void ETH_Event_Process(void);//处理网络数据子程序
strETHData_Typedef ETH_GetData(void);
void Charge_State_Process(void);//充电状态处理子程序
void Free_State_Process(void);//空闲状态处理子程序
void Error_State_Process(void);//异常处理子程序

void ETH_Send_HeartbeatMeg(void);  //上传心跳包

void DataInit(void);//一般变量初始化




#endif /* __DEFINE_H */
