//#include <stddef.h>                     // Defines NULL
//#include <stdbool.h>                    // Defines true
//#include <stdlib.h>                     // Defines EXIT_FAILURE
//#include "definitions.h"                // SYS function prototypes
#include "appiot.h"
#include "appemueeprom.h"
#define CGPSINFO_MAX_LEN				(64)
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

