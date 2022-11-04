/* 
 * File:   appemueeprom.h
 * Author: Eric
 *
 * Created on 2022?10?11?, ?? 5:26
 */

#ifndef APPEMUEEPROM_H
#define	APPEMUEEPROM_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "appiot.h"

#ifdef	__cplusplus
extern "C" {
#endif
typedef enum
{
    /* Application's state machine's initial state. */
    EEPROM_STATE_INIT =0,
    EEPROM_STATE_LIB_STATUS_VERIFY,
    EEPROM_STATE_WRITE_DATA,
    EEPROM_STATE_READ_DATA,
    EEPROM_STATE_VERIFY,
    EEPROM_STATE_IDLE,
    EEPROM_STATE_ERROR,
    /*  
    APP_STATE_INIT = 0,
    APP_STATE_LIB_STATUS_VERIFY,
    APP_STATE_WRITE_DATA,
    APP_STATE_READ_DATA,
    APP_STATE_VERIFY,
    APP_STATE_IDLE,
    APP_STATE_ERROR,
    */
    /* TODO: Define states used by the application state machine. */

} EEPROM_STATES;
typedef struct
{
    /* The application's current state */
    EEPROM_STATES state;    

} APP_EEPROM_DATA;

extern APP_EEPROM_DATA _appdata;

#define eepromStartAddress          0x400000;
typedef struct
{
    uint8_t         soc;                        //Offset 0                      
    uint16_t        rpm;                        //offset 1        
    uint16_t        crank_avg;                  //offset 3    
    uint8_t         alarmstate1;                //offset 5   
    uint32_t        odo;                        //offset 6
    uint8_t         iotstatue;                  //offset 10  
    uint32_t        mqttuploadtime;             //offset 11  
    uint8_t         mqttreturytime;             //offset 15  
    uint8_t         alarmTempture;              //offset 16  
    uint8_t         alarmvoltage;               //offset 17  
    uint8_t         alarmmode;                  //offset 18
    
    uint8_t         buffer[19];
    
}EEPROM_DATA;
void emnueeprom_init(void);
void ReadDaraFromEEPROM(void);

void rdmqttfromeeprom(void);

void readiotdata(void );
void writeiotdata(void);

void emueeprom_main(void);
void writeOdoToRam(uint32_t);
uint32_t readOdoFromRam(void);
#ifdef	__cplusplus
}
#endif

#endif	/* APPEMUEEPROM_H */

