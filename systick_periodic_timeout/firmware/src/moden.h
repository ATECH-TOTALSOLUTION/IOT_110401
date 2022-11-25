/* 
 * File:   moden.h
 * Author: Eric
 *
 * Created on 2022?10?11?, ?? 3:38
 */

#ifndef MODEN_H
#define	MODEN_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "app.h"
#ifdef	__cplusplus
extern "C" {
#endif

#define _NONE_AT_CMD                                    (0x0000)   
#define _AT1_CMD                                        (0x0100)
#define _ATE0_CMD                                       (0x0101)
#define _AT_CLCK1_CMD                                   (0x0102)
#define _AT_CPIN1_CMD                                   (0x0103)
#define _AT_COPS1_CMD                                   (0x0104)
#define _AT_CSQ1_CMD                                    (0x0105)
#define _AT_RD_P0_CMD                                   (0x0106)
#define _AT_MODULE_CONNECT_SENDING                      (0x01FC)
#define _AT_MODULE_CONNECT_OK                           (0x01FD)
#define _AT_MODULE_CONNECT_ERROR                        (0x01FE)
#define _AT_MODULE_CONNECT_FINISH                       (0x01FF)  
#define _AT2_CMD                                        (0x0200) 
#define _AT_CEREG1_CMD                                  (0x0201) 
#define _AT_CGDCONT1_CMD                                 (0x0202)
#define _AT_CCLK_CMD                                    (0x0203)
#define _AT_4GLTE_link_chk_SENDING                      (0x02FC)
#define _AT_4GLTE_link_chk_OK                           (0x02FD)
#define _AT_4GLTE_link_chk_ERROR                        (0x02FE)
#define _AT_4GLTE_link_chk_FINISH                       (0x02FF)  
#define _AT_COPS2_CMD                                   (0x0300)   
#define _AT_CSQ2_CMD                                    (0x0301)   
#define _AT_CEREG2_CMD                                  (0x0302) 
#define _AT_NETWORK_STATUS_SENDING                      (0x03FC)
#define _AT_NETWORK_STATUS_OK                           (0x03FD)
#define _AT_NETWORK_STATUS_ERROR                        (0x03FE)
#define _AT_NETWORK_STATUS_FINISH                       (0x03FF)  
#define _AT_CLCK2_CMD                                   (0x0400)
#define _AT_CPIN2_CMD                                   (0x0401)
#define _AT_COPS3_CMD                                   (0x0402)
#define _AT_CSQ3_CMD                                    (0x0403)
#define _AT_CEREG3_CMD                                  (0x0404)
#define _AT_UPSD1_CMD                                    (0x0405)
#define _AT_UPSDA1_CMD                                   (0x0406)
#define _AT_RELOG_IN_SENDING                            (0x04FC)
#define _AT_RELOG_IN_OK                                 (0x04FD)
#define _AT_RELOG_IN_ERROR                              (0x04FE)
#define _AT_RELOG_IN_FINISH                             (0x04FF)  
#define _AT_USECMNG1                                    (0x0500)
#define _AT_USECMNG2                                    (0x0501)
#define _AT_USECMNG3                                    (0x0502)
#define _AT_USECMNG4                                    (0x0503)
#define _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_WAIT             (0x05FE)    
#define _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_FINISH           (0x05FF)
#define _AT_RD_P01_CMD                                  (0x0600)
#define _AT_UMQTT1_CMD                                  (0x0601)
#define _AT_UMQTT2_CMD                                  (0x0602)   
//#define _AT_UMQTT021_CMD                                (0x0602) 
#define _AT_UMQTT3_CMD                                  (0x0603)
#define _AT_UMQTT4_CMD                                  (0x0604)
#define _AT_UMQTT5_CMD                                  (0x0605)
#define _AT_UMQTT6_CMD                                  (0x0606)
#define _AT_UMQTT7_CMD                                  (0x0607) 
#define _AT_UMQTT8_CMD                                  (0x0608)
#define _AT_UMQTT9_CMD                                  (0x0609)
#define _AT_UMQTTC1_CMD                                 (0x060A)
#define _AT_MQTT_BIDIR_AUTH_PARA_LOAD_WAIT              (0x06FB)  
#define _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING           (0x06FC)
#define _AT_MQTT_BIDIR_AUTH_PARA_LOAD_OK                (0x06FD)
#define _AT_MQTT_BIDIR_AUTH_PARA_LOAD_ERROR             (0x06FE)
#define _AT_MQTT_BIDIR_AUTH_PARA_LOAD_FINISH            (0x06FF)  
#define _AT_UMQTT10_CMD                                 (0x0700)
#define _AT_UMQTT11_CMD                                 (0x0701)
#define _AT_UMQTT12_CMD                                 (0x0702)
#define _AT_UMQTT13_CMD                                 (0x0703)
#define _AT_UMQTT14_CMD                                 (0x0704)
#define _AT_UMQTT15_CMD                                 (0x0705)
#define _AT_UMQTT16_CMD                                 (0x0706)
#define _AT_UMQTT17_CMD                                 (0x0707)
#define _AT_UMQTT18_CMD                                 (0x0708)
#define _AT_UMQTT19_CMD                                 (0x0709)
#define _AT_UMQTT20_CMD                                 (0x070A)
#define _AT_UMQTTNV1_CMD                                (0x070B)
#define _AT_UMQTTC2_CMD                                 (0x070C)
#define _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_WAIT    (0x07FE) 
#define _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_FINISH  (0x07FF)  
#define _AT_UMQTTNV2_CMD                                (0x0800)
#define _AT_UMQTTNV3_CMD                                (0x0801)
#define _AT_MQTT_PARA_OPERATION_WAIT                    (0x08FB)  
#define _AT_MQTT_PARA_OPERATION_SENDING                 (0x08FC) 
#define _AT_MQTT_PARA_OPERATION_OK                      (0x08FD)
#define _AT_MQTT_PARA_OPERATION_ERROR                   (0x08FE) 
#define _AT_MQTT_PARA_OPERATION_FINISH                  (0x08FF)  
#define _AT_UPSD2_CMD                                   (0x0900)
#define _AT_UPSDA2_CMD                                  (0x0901)
#define _AT_CGDCONT2_CMD                                (0x0902)
#define _AT_4G_LTE_LOGIN_SENDING                        (0x09FC)
#define _AT_4G_LTE_LOGIN_OK                             (0x09FD)
#define _AT_4G_LTE_LOGIN_ERROR                          (0x09FE)
#define _AT_4G_LTE_LOGIN_FINISH                         (0x09FF)  
#define _AT_UPSD3_CMD                                   (0x0A00)
#define _AT_UPSDA3_CMD                                  (0x0A01)
#define _AT_UMQTT022_CMD                                (0x0A02) 
#define _AT_UMQTT091_CMD                                (0x0A03) 
#define _AT_CGDCONT3_CMD                                (0x0A04)

#define _AT_USECPRF1_CMD                                (0x0A05)
#define _AT_USECPRF2_CMD                                (0x0A06)
#define _AT_USECPRF3_CMD                                (0x0A07)
#define _AT_USECPRF4_CMD                                (0x0A08)
#define _AT_UMQTTNV4_CMD                                (0x0A09)
#define _AT_UMQTTNV5_CMD                                (0x0A0A)
//#define _AT_UMQTTNV5_CMD                                (0x0A08)
//#define _AT_UMQTTNV6_CMD                                (0x0A09)    
#define _AT_UMQTT21_CMD                                 (0x0A0B)
#define _AT_UMQTTC3_CMD                                 (0x0A0C)
#define _AT_CERTIFY_DOWN_CMD                            (0x0A0D)
#define _AT_CERTIFY_PUB_CMD                             (0x0A0E)    
#define _AT_UMQTTC4_CMD                                 (0x0A0F)
    
#define _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING          (0x0AFC)
#define _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_OK               (0x0AFD)
#define _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_ERROR            (0x0AFE)
#define _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_FINISH           (0x0AFF)  
    
#define _AT_UGRMC1_CMD                                  (0x0B00)
#define _AT_UGIND_CMD                                   (0x0B01)
#define _AT_UGPS1_CMD                                   (0x0B02)
#define _AT_UGRMC2_CMD                                  (0x0B03)
#define _AT_GPS_SENDING                                 (0x0BFC)
#define _AT_GPS_OK                                      (0x0BFD)
#define _AT_GPS_ERROR                                   (0x0BFE)
#define _AT_GPS_FINISH                                  (0x0BFF)      
    
#define _AT_MQTT_TX_UP_DATA1_CMD                        (0x0C00)
#define _AT_MQTT_TX_UP_DATA1_SENDING                    (0x0CFC)
#define _AT_MQTT_TX_UP_DATA1_OK                         (0x0CFD)
#define _AT_MQTT_TX_UP_DATA1_ERROR                      (0x0CFE)
#define _AT_MQTT_TX_UP_DATA1_FINISH                     (0x0CFF)  
    
#define _AT_RAED_LISTEN_CMD                             (0x8000)   
#define _AT_RAED_ACTION_CMD                             (0x8001)   
#define _AT_READ_SENDING                                (0x80FC)
#define _AT_READ_OK                                     (0x80FD)
#define _AT_READ_ERROR                                  (0x80FE)
#define _AT_READ_FINISH                                 (0x80FF)  
   
typedef enum
{
    COMMAND_NONE = 0,       //NO send command
    COMMAND_SENDING,        //wait respond
    COMMAND_OK,    
    COMMAND_ERROR,        
} COMMAND_STATES;

typedef struct
{
   volatile COMMAND_STATES state;   
} MODEN_COMMAND_DATA;

typedef enum
{
    moden_closed = 0, //can't send command
    moden_open,       //ready to send command
    moden_ready,     //ath0 ok    
    moden_connection_initial, //power on need to check moden,network mqtt 
} MODEN_STATES;

typedef struct MODEN_DATA
{
   MODEN_STATES state;
   uint16_t AT_state;
   uint16_t AT_READ_state;
   uint8_t moden_uuid_md5[32];
   uint8_t lte_4G_TX_flag;
   uint8_t lte_4G_TX_data[UART_TX_RX_SIZE];
   uint8_t lte_4G_RX_flag;
   uint16_t lte_4G_RX_count;
   uint8_t lte_4G_RX_data[UART_TX_RX_SIZE];
   uint8_t lte_4G_TX_error_count;
   uint8_t lte_4G_RX_error_count;
   uint8_t lte_4G_reset_initial_flag;
   
   //gps   
   uint8_t  lte_4G_gps_first_flag;
   uint8_t  lte_4G_gps_read_flag;
   uint32_t lte_4G_gps_tick;
   uint8_t  lte_4G_latitude[20];
   uint8_t  lte_4G_longitude[20];
} MODEN_DATA;

extern MODEN_COMMAND_DATA _moden_cmd_data;
extern MODEN_DATA _moden;
MODEN_STATES readmodenstatue(void);
void setmoden(MODEN_STATES );
void init_moden(void);
void setldoon(void);
void setldoff(void);
void resetiot(void);
void moden_main(void);

void SendATCOmmand(void);
#ifdef	__cplusplus
}
#endif

#endif	/* MODEN_H */
