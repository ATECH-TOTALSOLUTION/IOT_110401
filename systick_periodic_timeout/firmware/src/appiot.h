/* 
 * File:   appiot.h
 * Author: Eric
 *
 * Created on 2022?10?11?, ?? 3:37
 */

#ifndef APPIOT_H
#define	APPIOT_H
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "iot_msg.h"
#ifdef	__cplusplus
extern "C" {
#endif
    typedef enum
{
    IOT_EVT_NONE = 0,
    IOT_EVT_CONNECTION,
    IOT_EVT_MQTT_RECV,
    IOT_EVT_GNSS_UPDATE,
    IOT_EVT_TIME_UPDATE,
    IOT_EVT_ENTER_SLEEP,

    IOT_EVT_COUNT
} iot_evt_e;

typedef enum
{
    IOT_REQUEST_NONE = 0,
    IOT_REQUEST_NETWORK_ONLY,
    IOT_REQUEST_GNSS_ONCE,
    IOT_REQUEST_GNSS_CONTINUOUS,
    IOT_REQUEST_SLEEP,
} iot_request_e;


typedef struct iot_evt_connection_s
{
    bool connected;
} iot_evt_connection_t;

typedef struct iot_evt_mqtt_recv_s
{
    mqtt_msg_t  msg;
} iot_evt_mqtt_recv_t;

typedef struct iot_evt_gnss_update_s
{
    double  latitude;
    double  longitude;
} iot_evt_gnss_update_t;

typedef struct iot_evt_time_update_s
{
    uint16_t    year;
    uint8_t     month;
    uint8_t     day;
    uint8_t     hour;
    uint8_t     minute;
    uint8_t     second;
} iot_evt_time_update_t;

typedef struct iot_evt_enter_sleep_s
{

} iot_evt_enter_sleep_t;

typedef union iot_evt_s
{
    iot_evt_connection_t    connection;
    iot_evt_mqtt_recv_t     mqtt_recv;
    iot_evt_gnss_update_t   gnss_update;
    iot_evt_time_update_t   time_update;
    iot_evt_enter_sleep_t   enter_sleep;
} iot_evt_t;
 struct tm
{
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
};

typedef struct iot_init_s
{

    char*               uuid;
    char*               motor_version;
    uint8_t             uuid_len;
    uint8_t             motor_version_len;
    iot_request_e       mode;
} iot_init_t;


typedef struct iot_tx_s
{
	iot_msg_type_e			type;
	iot_up_msg_payload_t	payload;
} iot_tx_t;


typedef enum
{
    /* Application's state machine's initial state. */
    IOT_CLOSED=0,
    IOT_SLEEP,
    IOT_STANDBY,
    IOT_NORMAL,  
  
    /* TODO: Define states used by the application state machine. */

} IOT_STATES;


typedef struct
{
    /* The application's current state */
      IOT_STATES state;
    /* TODO: Define any additional data used by the application. */

} IOT_DATA;

typedef struct
{
  
    uint8_t         soc;                        //Offset 0                      
    uint16_t        rpm;                        //offset 1        
    uint16_t        crank_avg;                  //offset 3    
    uint8_t         alarmstate1;                //offset 5   0:no alarm /1:alarming
    uint32_t        odo;                        //offset 6
    uint8_t         iotstatue;                  //offset 10  
    uint32_t        mqttuploadtime;             //offset 11 
    uint8_t         mqttreturytime;             //offset 15  
    uint8_t         alarmTempture;              //offset 16 
    uint8_t         alarmvoltage;               //offset 17
    uint8_t         alarmmode;                  //offset 18 0:disarm / 1:arm
}IOT_RAM_DATA;

extern IOT_RAM_DATA _iotram;
typedef enum
{
    /* Application's state machine's initial state. */
    none=0,
    disconnect,
    connected,
            
    waitrespond,
    ready,       
     
    working,   
    standby,
    sleep,
            
    /* TODO: Define states used by the application state machine. */

} MACHINE_STATES;    
typedef struct
{
    /* The application's current state */
    MACHINE_STATES _moden;  //
    MACHINE_STATES _network;
    MACHINE_STATES _mqtt;
    MACHINE_STATES _iot;
   /* TODO: Define any additional data used by the application. */

}  MACHINE_DATA;

typedef struct
{
    /* The application's current state */
    uint32_t _iotsleeptimer;
    uint32_t _iotreloadtimer;
    uint32_t _iotgpstimer;
    uint32_t _iotmqtttimer;
   /* TODO: Define any additional data used by the application. */
}IOT_TIMER;
extern IOT_TIMER _iottimer;

void iot_init(iot_init_t* init);
void iot_request_mode(iot_request_e mode);
void iot_request_time_update(void);
int iot_send_msg(iot_tx_t* tx); //int iot_send_msg(iot_msg_type_e type, iot_msg_payload_t* payload);

void initmachinestates(void);
void setmcahinestates(MACHINE_STATES data);
void setnetworkstates(MACHINE_STATES data);
void setmqttstates(MACHINE_STATES data);

void init_iot(void);
void incmqtttimer(void);
void iot_main(void);
void setiotstate(IOT_STATES );
void updateiotodo(uint32_t );
void iot_data_pack(uint8_t pack_num);

MACHINE_STATES readmcahinestates(void);
#ifdef	__cplusplus
}
#endif

#endif	/* APPIOT_H */

