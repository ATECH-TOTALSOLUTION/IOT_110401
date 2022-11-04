
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
//#include "../iot.h"
#include "canapp.h"
#include "appemueeprom.h"
uint32_t canbussleeptimer=0;
ecu_init_t  ecu_init;
/*
 * add following function  in "plib0can0.c"
 * void enable_rxfifo0_interrupt(void){
     CAN0_REGS->CAN_IE |= CAN_IE_RF0NE_Msk;
}
void enable_rxfifo1_interrupt(void){
     CAN0_REGS->CAN_IE |= CAN_IE_RF1NE_Msk;
}
 */
CAN_ECU_Data_1_TypeDef			CAN_ECU_Data_1;
CANRXF0 _canrx0buffer[10];
//CAN_ECU_Data_2_TypeDef			CAN_ECU_Data_2;
//CAN_ECU_Data_3_TypeDef			CAN_ECU_Data_3;
//CAN_ECU_Data_4_TypeDef			CAN_ECU_Data_4;

CAN_APP_DATA appCAN;
uint8_t Can0MessageRAM[CAN0_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));
uint32_t messageID = 0;
uint8_t  message[8];

uint32_t rx_messageID=0;
uint8_t  rx_message[8];
uint8_t  rx_messageLength = 0;

/* Application's state machine enum */


//static CAN_APP_STATES Canapp;

static CAN_STATE_TypeDef _canstate = CAN_Off;
static CAN_STATE_TypeDef _canstatenew = CAN_Off;
/* Variable to save Tx/Rx transfer status and context */
static CAN_ERROR status = 0;

/* Variable to save application state */
volatile static APP_STATES state = APP_STATE_CAN_IDLE;

static CAN_MSG_RX_FRAME_ATTRIBUTE msgFrameAttr = CAN_MSG_RX_DATA_FRAME;
static uint32_t ODO_PRE=0,ODOVALUE=0;
static uint8_t odocnt=0;
float _f_ODOVALUE=0;
//#define NUM_RX_FIFO0_ELEMENTS 10U
CAN_RX_FIFO_0_BUFFER rx0_buf[NUM_RX_FIFO0_ELEMENTS];
uint8_t rx0ReadIndex = 0,rx0Writeindex = 0;
bool STATUS_RX_PREPARE=true;
bool STATUS_RX_COMPLETED=false;
bool STATUS_TX_PREPARE=false;

void ClearRx0(void){
    memset(rx0_buf,0,(sizeof rx0_buf));
}
void ClearRx0buffeerarr(void){
    memset(_canrx0buffer,0,(sizeof _canrx0buffer));
}

void enable_CAN(void)
{
	PORT_PinWrite(EN_CAN_PIN, false);
}
void standby_CAN(void)
{
	PORT_PinWrite(EN_CAN_PIN, true);
}

void SetCanBusState(CAN_STATE_TypeDef value){
    
}
void APP_CAN_TX_Callback(uintptr_t context)
{
  STATUS_RX_PREPARE=true;
  CAN0_InterruptClear (CAN_INTERRUPT_TC_MASK);
}


void APP_CAN_RX_Callback (uintptr_t context)
{
  /* Check CAN Status, Do something here */
    
  clearcanbussleeptimer();
  status = CAN0_ErrorGet ();
  STATUS_RX_COMPLETED=true;
  CAN0_MessageReceive (&rx_messageID, &rx_messageLength, rx_message, 0, CAN_MSG_ATTR_RX_FIFO0, &msgFrameAttr);
  CAN0_InterruptClear (CAN_INTERRUPT_RF0N_MASK);
} 
/*
void OUTPUT_LED2_Toggle(){
    
}
*/
/*
void CheckErrorCount(void){
    //CAN0_ErrorCountGet(tx_err0ccnt,rx_erroecnt);
}*/

void can_main(void)
{
//  uint8_t  i=0;
  messageID = 0x01;
  /* Set Message RAM Configuration */
    
    switch(_canstate){
        case CAN_Off:
            break;
        case CAN_Open:
             enable_CAN();
            
             break;
         case CAN_Sleep:
             standby_CAN();
             entrySleep();
             break;
             
             default:
             break;
         }
    if(_canstate!=_canstatenew){
       
        switch (_canstatenew){
            case CAN_Off:
                break;
            case CAN_Open:
                _canstate = CAN_Open;
                break;
            case CAN_Sleep:
                _canstate = CAN_Sleep;
                 break;
            case CAN_Satndby:    

                break;
             default:
                break;
        }
        
    }
   
   /*
      if(STATUS_RX_COMPLETED==true)
        {

          STATUS_TX_PREPARE=true;
        }
      else if(STATUS_RX_PREPARE==true) // && STATUS_RX_COMPLETED==false
        {
          STATUS_RX_PREPARE=false;
 
        }
      else if(STATUS_TX_PREPARE==true)
        {
          if(CAN0_MessageTransmit (messageID, rx_messageLength+2, message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME) == false)
             OUTPUT_LED2_Toggle();
          else
            STATUS_TX_PREPARE=false;                  
        }
        
    */
}

void init_can(void){
     ReadMotoID();
     can_init();
}
void can_init(void){
//	BaseType_t ret;
   ClearRx0();
   ClerCAN_ECU();
   enable_CAN();
   CAN0_MessageRAMConfigSet (Can0MessageRAM);
   CAN0_RxCallbackRegister (APP_CAN_RX_Callback, (uintptr_t)APP_STATE_CAN_RECEIVE, CAN_MSG_ATTR_RX_FIFO0);
   CAN0_TxCallbackRegister (APP_CAN_TX_Callback, (uintptr_t) APP_STATE_CAN_TRANSMIT);

   CAN0_MessageReceive (&rx_messageID, &rx_messageLength, rx_message, 0, CAN_MSG_ATTR_RX_FIFO0, &msgFrameAttr);
   
 //  enable_rxfifo0_interrupt();
 
	
}




void SetCANData1(uint8_t *ptr){
     uint16_t tmp1;

     CAN_ECU_Data_1.CAN_BAT_L = *(ptr);
     CAN_ECU_Data_1.CAN_BAT_H= *(ptr+1);
     tmp1 = (uint16_t) CAN_ECU_Data_1.CAN_BAT_L+((uint16_t)CAN_ECU_Data_1.CAN_BAT_H<<8);
     CAN_ECU_Data_1._f_ecu_batvoltage=(float)tmp1*0.01;
     CAN_ECU_Data_1.CAN_MOT_RPM_L = *(ptr+2);
     CAN_ECU_Data_1.CAN_MOT_RPM_H = *(ptr+3);

     CAN_ECU_Data_1._d_ecu_motorpm=(int16_t) CAN_ECU_Data_1.CAN_MOT_RPM_L+((int16_t)CAN_ECU_Data_1.CAN_MOT_RPM_H<<8);
     CAN_ECU_Data_1.CAN_MOTO_TEMPTURE =*(ptr+4);
}
void SetCANData2(uint8_t *ptr){
    CAN_ECU_Data_1.ECU_ERROR_CODE = *(ptr+2);
    CAN_ECU_Data_1.ECU_WARN_CODE= *(ptr+1);
    CAN_ECU_Data_1.carnk_rpm=*(ptr+3);
    CAN_ECU_Data_1.speed=*(ptr+7);
    precalculateODO();
}
void SetCANData3(uint8_t *ptr){
   
     CAN_ECU_Data_1.eecu_dagred= *(ptr+1);
     CAN_ECU_Data_1._int8_dagred=(int)CAN_ECU_Data_1.eecu_dagred -128;
}

void SetCANData4(uint8_t *ptr){
    uint16_t tmp1;
    uint8_t tmp2;
    tmp2= *(ptr+7);
    if (tmp2 == 1){
        CAN_ECU_Data_1.CAN_Crank_AvgAcc_L = *(ptr+2);
        CAN_ECU_Data_1.CAN_Crank_AvgAcc_H = *(ptr+3);
        tmp1 = (uint16_t)CAN_ECU_Data_1.CAN_Crank_AvgAcc_L+((uint16_t)CAN_ECU_Data_1.CAN_Crank_AvgAcc_H<<8);
        CAN_ECU_Data_1._f_crank_avgacc = tmp1*0.01;
        CAN_ECU_Data_1.CAN_MOT_AvgAcc_L = *(ptr+4);
        CAN_ECU_Data_1.CAN_MOT_AvgAcc_H= *(ptr+5);
        tmp1 = (uint16_t) CAN_ECU_Data_1.CAN_MOT_AvgAcc_L+((uint16_t)CAN_ECU_Data_1.CAN_MOT_AvgAcc_H<<8);
        CAN_ECU_Data_1._f_moto_avgacc=tmp1*0.01;
    }
    else if (tmp2 == 2){
        /*
         CAN_ECU_Data_1.g_xl=*(ptr);
         CAN_ECU_Data_1.g_xh=*(ptr+1);
         CAN_ECU_Data_1.g_x =(uint16_t) CAN_ECU_Data_1.g_xl+((uint16_t)CAN_ECU_Data_1.g_xh<<8);
         CAN_ECU_Data_1.g_yl=*(ptr+2);
         CAN_ECU_Data_1.g_yh=*(ptr+3);
         CAN_ECU_Data_1.g_y =(uint16_t) CAN_ECU_Data_1.g_yl+((uint16_t)CAN_ECU_Data_1.g_yh<<8);
         CAN_ECU_Data_1.g_zl=*(ptr+4);
         CAN_ECU_Data_1.g_zh=*(ptr+5);
         CAN_ECU_Data_1.g_z =(uint16_t) CAN_ECU_Data_1.g_zl+((uint16_t)CAN_ECU_Data_1.g_zh<<8);*/
         
    }
    else{
        if (tmp2 == 3){
        /* CAN_ECU_Data_1.gyro_xl=*(ptr);
         CAN_ECU_Data_1.gyro_xh=*(ptr+1);
         CAN_ECU_Data_1.gyro_x =(uint16_t) CAN_ECU_Data_1.gyro_xl+((uint16_t)CAN_ECU_Data_1.gyro_xh<<8);
                CAN_ECU_Data_1.gyro_yl=*(ptr+2);
                CAN_ECU_Data_1.gyro_yh=*(ptr+3);
                CAN_ECU_Data_1.gyro_y =(uint16_t) CAN_ECU_Data_1.gyro_yl+((uint16_t)CAN_ECU_Data_1.gyro_yh<<8);
                CAN_ECU_Data_1.gyro_zl=*(ptr+4);
                CAN_ECU_Data_1.gyro_zh=*(ptr+5);
                CAN_ECU_Data_1.gyro_z =(uint16_t) CAN_ECU_Data_1.gyro_zl+((uint16_t)CAN_ECU_Data_1.gyro_zh<<8);*/
       }
    }
   
}
void ClerCAN_ECU(void){
    memset(&CAN_ECU_Data_1, 0, sizeof(CAN_ECU_Data_1));
   
}

void ReadMotoID(void){
    int i;
    uint8_t* p_unique_sn;
    const char id[4]={0x13,0x0f,0xde,0xff};
    p_unique_sn = (uint8_t*) id;
    for (i=0; i<4; i++)
    {
        sprintf(ecu_init.motorid+2*i, "%02X", p_unique_sn[i]);
    }
    ecu_init.motorid_len = MOTOID_LEN_MAX; 
   
}

int fill_batvoltage(char* buf)
{
	int len = 0;
//    CAN_ECU_Data_1._f_ecu_batvoltage =34.5;
	
	len += sprintf(buf+len, "\"V001\":\"%d.%01d\",", 
    (int) CAN_ECU_Data_1._f_ecu_batvoltage, abs((int) ((CAN_ECU_Data_1._f_ecu_batvoltage - (int) CAN_ECU_Data_1._f_ecu_batvoltage) * 10)));//10000000)));
	
	return len;
}
int fill_motorpm(char* buf)
{
	int len = 0;
    int16_t tmp;
   
   tmp = CAN_ECU_Data_1._d_ecu_motorpm -32768;
    if( tmp>-1){ //>=0
        if( tmp<10){
           len += sprintf(buf+len, "\"R001\":\"%01d\",",tmp); 
        }
        else if(tmp<100){
           len += sprintf(buf+len, "\"R001\":\"%02d\",",tmp); 
        }
        else if(tmp <1000){
            len += sprintf(buf+len, "\"R001\":\"%03d\",",tmp);
        }
        else if(tmp<10000){
            len += sprintf(buf+len, "\"R001\":\"%04d\",",tmp);
        }
        else{
             len += sprintf(buf+len, "\"R001\":\"%05d\",",tmp);
        }
    }
    else{
        if( tmp>-10){//0~-9
           len += sprintf(buf+len, "\"R001\":\"%02d\",",tmp); 
        }
        else if(tmp >-100){ //-10~-99
           len += sprintf(buf+len, "\"R001\":\"%03d\",",tmp); 
        }
        else if(tmp>-1000){//-100~-999
            len += sprintf(buf+len, "\"R001\":\"%04d\",",tmp);
        }
        else if(tmp >-10000){//-1000 
            len += sprintf(buf+len, "\"R001\":\"%05d\",",tmp);
        }
        else{//-1000 ~ -30000
             len += sprintf(buf+len, "\"R001\":\"%06d\",",tmp);
        }
    }
   
    return len;
}

int fill_crankrpm(char* buf)//(0x18f120ef) 
{
	int len = 0;
     if( CAN_ECU_Data_1.carnk_rpm>99){
       len += sprintf(buf+len, "\"T001\":\"%03d\",",CAN_ECU_Data_1.CAN_MOTO_TEMPTURE);
    }
    else if( CAN_ECU_Data_1.carnk_rpm>9){
        len += sprintf(buf+len, "\"T001\":\"%02d\",",CAN_ECU_Data_1.CAN_MOTO_TEMPTURE);
    }
    else{
        len += sprintf(buf+len, "\"T001\":\"%01d\",",CAN_ECU_Data_1.CAN_MOTO_TEMPTURE);
    }
//    len += sprintf(buf+len, "\"R002\":\"%02x\",", CAN_ECU_Data_1.carnk_rpm);
	return len;
}

int fill_mototempture(char* buf)
{
	int len = 0;
//    CAN_ECU_Data_1.CAN_MOTO_TEMPTURE =0x64;
     if( CAN_ECU_Data_1.CAN_MOTO_TEMPTURE>99){
       len += sprintf(buf+len, "\"T001\":\"%03d\",",CAN_ECU_Data_1.CAN_MOTO_TEMPTURE);
    }
    else if( CAN_ECU_Data_1.CAN_MOTO_TEMPTURE>9){
        len += sprintf(buf+len, "\"T001\":\"%02d\",",CAN_ECU_Data_1.CAN_MOTO_TEMPTURE);
    }
    else{
        len += sprintf(buf+len, "\"T001\":\"%01d\",",CAN_ECU_Data_1.CAN_MOTO_TEMPTURE);
    }
//    len += sprintf(buf+len, "\"T001\":\"%03d\",",CAN_ECU_Data_1.CAN_MOTO_TEMPTURE);
    return len;
}
int fill_speed(char* buf)
{
	int len = 0;
 
    if( CAN_ECU_Data_1.speed>99){
        len += sprintf(buf+len, "\"SP001\":\"%03d\",",CAN_ECU_Data_1.speed);
    }
    else if( CAN_ECU_Data_1.speed>9){
        len += sprintf(buf+len, "\"SP001\":\"%02d\",",CAN_ECU_Data_1.speed);
    }
    else{
        len += sprintf(buf+len, "\"SP001\":\"%01d\",",CAN_ECU_Data_1.speed);
    }
//    len += sprintf(buf+len, "\"SP001\":\"%01d\",",CAN_ECU_Data_1.speed);
    return len;
}
int fill_bikegrade(char* buf)
{
	int len = 0;
    /*
    static uint8_t index =0;
    index++;
    switch(index){
        case 1:
            CAN_ECU_Data_1._int8_dagred =0;
        break;
        case 2:
            CAN_ECU_Data_1._int8_dagred = 9;
        break;
         case 3:
            CAN_ECU_Data_1._int8_dagred = 20;
        break;
         case 4:
            CAN_ECU_Data_1._int8_dagred =110;
        break;
        case 5:
            CAN_ECU_Data_1._int8_dagred =-8;
        break;
         case 6:
            CAN_ECU_Data_1._int8_dagred =-50;
        break;
         case 7:
            CAN_ECU_Data_1._int8_dagred =-109;
        break;
        default:
            index=0;
              CAN_ECU_Data_1._int8_dagred =0;       
        break;
          
    }
     * */
    if(CAN_ECU_Data_1._int8_dagred>-1){
        if(CAN_ECU_Data_1._int8_dagred>99){
        len += sprintf(buf+len, "\"GRD001\":\"%03d\",",CAN_ECU_Data_1._int8_dagred);
        }
        else if(CAN_ECU_Data_1._int8_dagred>9){
             len += sprintf(buf+len, "\"GRD001\":\"%02d\",",CAN_ECU_Data_1._int8_dagred);
        }
        else{
             len += sprintf(buf+len, "\"GRD001\":\"%01d\",",CAN_ECU_Data_1._int8_dagred);
        }
    }
    else{
        if(CAN_ECU_Data_1._int8_dagred> -10){
        len += sprintf(buf+len, "\"GRD001\":\"%01d\",",CAN_ECU_Data_1._int8_dagred);
        }
        else if(CAN_ECU_Data_1._int8_dagred>-100){
             len += sprintf(buf+len, "\"GRD001\":\"%02d\",",CAN_ECU_Data_1._int8_dagred);
        }
        else{
             len += sprintf(buf+len, "\"GRD001\":\"%03d\",",CAN_ECU_Data_1._int8_dagred);
        }
    }
    
 //   len += sprintf(buf+len, "\"GRD001\":\"%02d\",",CAN_ECU_Data_1._int8_dagred);
 // len += sprintf(buf+len, "\"GRD001\":\"%02f\",",CAN_ECU_Data_1._int8_dagred);
    return len;
}
int fill_ecuwarncode(char* buf)
{
	int len = 0;
//    CAN_ECU_Data_1.ECU_WARN_CODE =0x64;
//    len += sprintf(buf+len, "\"EWD000\":\"%02x\",",CAN_ECU_Data_1.ECU_WARN_CODE); //show hex in json
    len += sprintf(buf+len, "\"EWD000\":\"%0u\",",CAN_ECU_Data_1.ECU_WARN_CODE);
    return len;
}
int fill_ecuerrorcode(char* buf)
{
	int len = 0;
 //   CAN_ECU_Data_1.ECU_ERROR_CODE =0x48;
//    len += sprintf(buf+len, "\"ER000\":\"%02x\",",CAN_ECU_Data_1.ECU_ERROR_CODE); //show hex in json
      len += sprintf(buf+len, "\"ER000\":\"%0u\",",CAN_ECU_Data_1.ECU_ERROR_CODE);
    return len;
}
int fill_crankavgpower(char* buf)
{
	int len = 0;
 //   CAN_ECU_Data_1._f_crank_avgacc = 650.31;
   len += sprintf(buf+len, "\"C_AVG01\":\"%d.%01d\",", 
    (int) CAN_ECU_Data_1._f_crank_avgacc, abs((int) ((CAN_ECU_Data_1._f_crank_avgacc - (int) CAN_ECU_Data_1._f_crank_avgacc) * 10)));//10000000)));
    return len;
}
int fill_motoavgpower(char* buf)
{
	int len = 0;
 //   CAN_ECU_Data_1._f_moto_avgacc = 123;
    len += sprintf(buf+len, "\"M_AVG01\":\"%d.%01d\",", 
    (int) CAN_ECU_Data_1._f_moto_avgacc, abs((int) ((CAN_ECU_Data_1._f_moto_avgacc - (int) CAN_ECU_Data_1._f_moto_avgacc) * 10)));//10000000)));
    return len;
}
int fillbatterysoc(char* buf)
{
	int len = 0;
    
 //   CAN_ECU_Data_1.CAN_SOC =  0;//CAN_ECU_Data_1.CAN_SOC+1;
    len += sprintf(buf+len, "\"SOC01\":\"%d\",",CAN_ECU_Data_1.CAN_SOC);
    return len;
}
int fillodo(char* buf){
    int len = 0;
  //   len += sprintf(buf+len, "\"ODO\":\"%d.%01d\",", 
  //  (int) CAN_ECU_Data_1._f_crank_avgacc, abs((int) ((CAN_ECU_Data_1._f_crank_avgacc - (int) CAN_ECU_Data_1._f_crank_avgacc) * 10)));//10000000)));
       len += sprintf(buf+len, "\"ODO\":\"%ld.%01d\",", 
        (int32_t) _f_ODOVALUE, abs((int32_t) ((_f_ODOVALUE- (int32_t)_f_ODOVALUE) * 10)));//10000000)));
    return len;
}


void init_ODO(void){
    ODOVALUE = readOdoFromRam();
    ODO_PRE = 0;
    odocnt=0;
    _f_ODOVALUE=(float)ODOVALUE/10;
}

void precalculateODO(void){
    odocnt++;
    ODO_PRE = ODO_PRE+CAN_ECU_Data_1.speed*10; //
 }
/******************************************
 speed == 100mS/pre
 
 ****************************************/
void calculateODO(void){
    ODO_PRE = ODO_PRE/odocnt;
    odocnt=0;
    ODOVALUE = ODOVALUE+ODO_PRE/10;
    _f_ODOVALUE=(float)ODOVALUE/10;
}
void inccanbussleeptimer(void){
    canbussleeptimer++;
}
uint32_t readcanbussleeptimer(void){
    return canbussleeptimer;
}

void clearcanbussleeptimer(void){
    canbussleeptimer=0;
}

void set_canstatenew(CAN_STATE_TypeDef value){
    _canstatenew = value;
    
}

CAN_STATE_TypeDef read__canstatenew(void){
    return _canstatenew;
}

void entrySleep(void){
    
}
/*******************************************************************************
 End of File
*/
