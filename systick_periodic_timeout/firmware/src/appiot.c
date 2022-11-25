//#include <stddef.h>                     // Defines NULL
//#include <stdbool.h>                    // Defines true
//#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "apptimer.h"
#include "appiot.h"
#include "moden.h"
#include "canapp.h"
#include "appemueeprom.h"
#define CGPSINFO_MAX_LEN				(64)

#define IOT_SEND_DATA_MS    (1000*60) //1min

uint32_t iot_send_data_tick=0;

IOT_DATA _iotdata;
IOT_RAM_DATA _iotram;

MACHINE_DATA mcahineData;
IOT_TIMER _iottimer;

/****************************************************/
typedef struct iot_s
{
 //   QueueHandle_t		tx_queue;
 //	SemaphoreHandle_t	tx_sem;
 //   EventGroupHandle_t  flags;
 //   EventGroupHandle_t  ctrl_flags;
	struct tm 			timer;
    char*               uuid;
    char*               broker_url;
	char*				motor_version;
	int 				mqtt_topic_total_len;
	int 				mqtt_payload_total_len;
	uint16_t 			mqtt_topic_idx;
	uint16_t 			mqtt_payload_idx;
    uint16_t            broker_port;
    uint8_t             uuid_len;
    uint8_t             broker_url_len;
	uint8_t				motor_version_len;
	char 				cgpsinfo[CGPSINFO_MAX_LEN];
	char 				mqtt_clientid[24];
    iot_request_e       mode;
    iot_request_e       previous_mode;
} iot_t;
static iot_t iot;
/****************************************************************/
uint32_t mqtttime;
void init_iot(void){
 //   iot_init_t  init;
    memset(&iot, 0, sizeof(iot));
   
//	iot.uuid = init->uuid;
	
//	iot.uuid_len = init->uuid_len;
//	iot.mode = init->mode;

    _iotdata.state = IOT_NORMAL;//IOT_SLEEP;
    mqtttime=0;
    readiotdata();
    _iotram.odo=readOdoFromRam();
}

void setiotstate(IOT_STATES state){
    _iotdata.state = state;
    
}
void incmqtttimer(void){
    mqtttime++;
}

void updateiotodo(uint32_t odo){
    _iotram.odo = odo;
}

void iot_main(void){
    
    if((timer1ms - iot_send_data_tick) > IOT_SEND_DATA_MS){
        iot_data_pack(0);
        _moden.lte_4G_TX_flag = 1;
        iot_send_data_tick = timer1ms;
    }
    
    switch(_iotdata.state){
        case IOT_SLEEP:
        break;
        case IOT_STANDBY:
        break;
        case IOT_NORMAL:
            
        break;
        case IOT_CLOSED:
        break;
        
//        case default:
//        break;
    }
    
}

void initmachinestates(void){
    mcahineData._moden = disconnect;
    mcahineData._network = disconnect;
    mcahineData._mqtt = disconnect;
    mcahineData._iot = working;
}

void setmcahinestates(MACHINE_STATES data){
    mcahineData._moden = data;
}
MACHINE_STATES readmcahinestates(void){
    return  mcahineData._moden ;
}
void setnetworkstates(MACHINE_STATES data){
    mcahineData._network = data;
}
void setmqttstates(MACHINE_STATES data){
    mcahineData._mqtt = data;
}

/*///////////////////////////////



*///////////////////////////////
void iot_data_pack(uint8_t pack_num){
    
    uint16_t lens;
    
    switch(pack_num){
        
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            
        default:
            
            memset(_moden.lte_4G_TX_data,0,sizeof(_moden.lte_4G_TX_data));
            sprintf((char *)_moden.lte_4G_TX_data,(const char *)"{"); 
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'PCBUUID':'%s',",_moden.moden_uuid_md5); 
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'STIME': '2020-04-08:05:23:00',"); 
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'LINKCMD': 'DEVPING',"); 
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'BASIC': {");
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)" 'MOTOVER': 'V0.1',");
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'IOTVER': 'V0.1',");
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'DEVSTU': '00',");
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'LOCKSTU': '00',");
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'BKPOW': 5,");
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"'GPSPOS': '%s,%s',",_moden.lte_4G_longitude,_moden.lte_4G_latitude);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)" 'MOTOECU':{");
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_batvoltage((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_motorpm((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_mototempture((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_ecuwarncode((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_ecuerrorcode((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_crankrpm((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_speed((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_crankavgpower((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            fill_motoavgpower((char *)&_moden.lte_4G_TX_data[lens]);
            lens = strlen((char *)_moden.lte_4G_TX_data);
            sprintf((char *)&_moden.lte_4G_TX_data[lens],(const char *)"}}}\"\r\n"); 
            
            break;
    }   
}