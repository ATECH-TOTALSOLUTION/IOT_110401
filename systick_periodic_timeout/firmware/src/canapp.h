/* 
 * File:   canapp.h
 * Author: Eric
 *
 * Created on 2022?6?24?, ?? 6:53
 */

#ifndef CANAPP_H
#define	CANAPP_H
//#include "../../app/app.h"
#include "config/sam_c21n_xpro/peripheral/can/plib_can_common.h"
//#include "config/release/peripheral/can/plib_can_common.h"
#ifdef	__cplusplus
extern "C" {
#endif

#define CAN_Normal false;
#define CAN_Standby true;   
#define MOTOID_LEN_MAX      8
 typedef struct ecu_init_s
{
   // can_evt_callback_t  callback;
 //   char*               motorid;
    char        motorid[MOTOID_LEN_MAX];
    char*       ptrmotoid;
    uint8_t             motorid_len;
 
} ecu_init_t;
extern  ecu_init_t  ecu_init;

typedef enum{
    CAN_Off= 0,
    CAN_Open,
    CAN_Sleep,
    CAN_Satndby,        
   
}CAN_STATE_TypeDef;
typedef enum
{
    APP_STATE_CAN_RECEIVE = 0,
    APP_STATE_CAN_TRANSMIT,
    APP_STATE_CAN_IDLE,
} CAN_APP_STATES;

typedef struct
{
    /* The application's current state */
    CAN_APP_STATES state;
//    TaskHandle_t    task_handle;
    /* TODO: Define any additional data used by the application. */
} CAN_APP_DATA;
extern CAN_APP_DATA appCAN;

#define NUM_RX_FIFO0_ELEMENTS 10U

typedef struct
{
    /* Rx Message ID */
    uint32_t rxfifo0ID;
    /* Rx Message buffer */
    uint8_t rxBuffer[8];
    /* Rx Message size */
    uint8_t rxfifo0rxsize;
    /* Rx Message timestamp */
    /* Rx Message frame attribute */
    CAN_MSG_RX_FRAME_ATTRIBUTE *msgFrameAtt_rxfifo0;
} CAN_RX_FIFO_0_BUFFER;
extern  CAN_RX_FIFO_0_BUFFER rx0_buf[NUM_RX_FIFO0_ELEMENTS];


/* ================================== ECU_Data_1 (0x18f11fef)==================================== */

typedef struct {
    //ATECH MOTOR CAN ID :8 byte(0~7)
    /************ECU_Data_1 (0x18f11fef)****************/
    uint8_t CAN_BAT_H;				//CAN_BATVoltage_H byte1
    uint8_t CAN_BAT_L;				//CAN_BATVoltage_L byte 0
    float   _f_ecu_batvoltage;
    uint8_t CAN_MOT_RPM_H;			// MOTOR RPM_H  byte 3
    uint8_t CAN_MOT_RPM_L;			// MOTOR RPM_L  byte 2
	int16_t   _d_ecu_motorpm;
    uint8_t CAN_MOTO_TEMPTURE   ;
    /************ECU_Data_2 (0x18f120ef)****************/
    uint8_t ECU_WARN_CODE;		//byte 1
    uint8_t ECU_ERROR_CODE;		//byte 2
    uint8_t carnk_rpm;          //byte 3
    //uint8_t torque_sensor_L;     //byte 4
    //uint8_t torque_sensor_H;     //byte 5
    //float   _f_torque_sensor;
    uint8_t speed;              //byte 7
    /************ECU_Data_3 (0x18f131ef)****************/
    uint8_t eecu_dagred;        //byte 1
    int8_t _int8_dagred;
     /************ECU_Data_4 (0x18f142ef)****************/
    uint8_t CAN_Crank_AvgAcc_H;		//CAN CRANK average accumulation HIGHT  byte 3
    uint8_t CAN_Crank_AvgAcc_L;     //CAN CRANK average accumulation LOW    byte 2
    float   _f_crank_avgacc;
    uint8_t CAN_MOT_AvgAcc_H;		//CAN CMotor rpm  average accumulation HIGHT    byte 5 
    uint8_t CAN_MOT_AvgAcc_L;		//CAN CMotor rpm  average accumulation HIGHT    byte 4
    float   _f_moto_avgacc;
    int8_t  g_xl;
    int8_t  g_xh;
    int16_t g_x;
    int8_t  g_yl;
    int8_t  g_yh;
    int16_t g_y;
    int8_t  g_zl;
    int8_t  g_zh;
    int16_t g_z;
    
    int8_t  gyro_xl;
    int8_t  gyro_xh;
    int16_t gyro_x;
    int8_t  gyro_yl;
    int8_t  gyro_yh;
    int16_t gyro_y;
    int8_t  gyro_zl;
    int8_t  gyro_zh;
    int16_t gyro_z;
    
    /**********battery id not define*********************/
    uint8_t  CAN_SOC;
    
}CAN_ECU_Data_1_TypeDef;



#define CAN_Voltage_H()             (CAN_ECU_Data_1.CAN_BAT_H)
#define CAN_Voltage_L()             (CAN_ECU_Data_1.CAN_BAT_L)
#define CAN_Engine_RPM_H()			(CAN_ECU_Data_1.CAN_MOT_RPM_H)
#define CAN_Engine_RPM_L()			(CAN_ECU_Data_1.CAN_MOT_RPM_L)
/* ================================== ECU_Data_2 (0x18f120ef)==================================== */
/* ================================== ECU_Data_3 (0x18f131ef)==================================== */
/* ================================== ECU_Data_4 (0x18f142ef)==================================== */
extern CAN_ECU_Data_1_TypeDef			CAN_ECU_Data_1;
typedef enum
{
    _standerid = 0,
    _extendid,
   
} CAN_ID_TYPE;

typedef struct{
    uint8_t canrx0_head;
    uint8_t canrx0_host;
    uint8_t canrx0index;
    uint32_t _canid;
    CAN_ID_TYPE _canidtype;
    uint8_t buffer[8];
    
}CANRXF0;

extern CANRXF0 _canrx0buffer[10];
extern uint8_t rx0ReadIndex ;
extern uint8_t rx0Writeindex;
#define CAN_AvgCrank_H()                 (CAN_ECU_Data_2.CAN_MOT_AvgAcc_H)
#define CAN_AvgCrang_L()                 (CAN_ECU_Data_2.CAN_MOT_AvgAcc_L)
#define CAN_Motor_AvgRpm_H()			(CAN_ECU_Data_2.CAN_MOT_AvgAcc_H)
#define CAN_Engine_AvgRpm_L()			(CAN_ECU_Data_2.CAN_MOT_AvgAcc_L)



void enable_CAN(void);
void standby_CAN(void);
void can_main(void);
void ClearRx0(void);

void SetCANData1(uint8_t *ptr);
void SetCANData2(uint8_t *ptr);
void SetCANData3(uint8_t *ptr);
void SetCANData4(uint8_t *ptr);
void ClerCAN_ECU(void);
void init_can(void);

void ReadMotoID(void);
void can_init(void);
int fill_batvoltage(char* buf);
int fill_motorpm(char* buf);
int fill_crankrpm(char* buf);
int fill_mototempture(char* buf);
int fill_bikegrade(char* buf);
int fill_ecuwarncode(char* buf);
int fill_ecuerrorcode(char* buf);
int fill_crankavgpower(char* buf);
int fill_motoavgpower(char* buf);
int fill_speed(char* buf);
int fillbatterysoc(char* buf);
int fillodo(char* buf);
void init_ODO(void);
void precalculateODO(void);
void calculateODO(void);
void inccanbussleeptimer(void);
uint32_t readcanbussleeptimer(void);
void clearcanbussleeptimer(void);
void set_canstatenew(CAN_STATE_TypeDef );
CAN_STATE_TypeDef read__canstatenew(void);
void entrySleep(void);
//void fill_bykeeuc(iot_tx_t* tx);
#ifdef	__cplusplus
}
#endif

#endif	/* CANAPP_H */

