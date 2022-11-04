
//#include <stddef.h>                     // Defines NULL
//#include <stdbool.h>                    // Defines true
//#include <stdlib.h>                     // Defines EXIT_FAILURE
//#include "definitions.h"                // SYS function prototypes

#include "appemueeprom.h"
#include "library/emulated_eeprom/emulated_eeprom.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define OFFSETOF(s, m) ((size_t)&(((s *)0)->m))
#define SIZEOF(s, m) ((size_t) sizeof(((s *)0)->m))
#define EMU_EEPROM_READ(MEM, DEST) EMU_EEPROM_BufferRead(OFFSETOF(EEPROM_DATA, MEM), (uint8_t*)DEST, SIZEOF(EEPROM_DATA, MEM))
#define EMU_EEPROM_WRITE(MEM, DATA) EMU_EEPROM_BufferWrite(OFFSETOF(EEPROM_DATA, MEM), (const uint8_t*)DATA, SIZEOF(EEPROM_DATA, MEM))

#define meterPage   0
#define mqttPage    1

APP_EEPROM_DATA _appdata;
EEPROM_DATA MeterMqttData = {0};
EEPROM_DATA testData = {0};

void clearemueeprom(void){
     memset(&_appdata, 0xff, sizeof(_appdata));
}

void ReadDaraFromEEPROM(void){
    uint8_t buffer[sizeof(MeterMqttData)];
    memset(buffer,0xff,sizeof(buffer));
}

void WriteDaraToEEPROM(void){
    uint8_t buffer[sizeof(MeterMqttData)];
    memset(buffer,0xff,sizeof(buffer));
    
}



void readiotdata(void){
    _iotram.iotstatue =  MeterMqttData.iotstatue ;
    _iotram.mqttreturytime =MeterMqttData.mqttreturytime;
    _iotram.mqttuploadtime=MeterMqttData.mqttuploadtime;
    _iotram.alarmTempture=MeterMqttData.alarmTempture;
    _iotram.alarmvoltage=MeterMqttData.alarmvoltage;
 
}

void writeiotdata(void){

   
    MeterMqttData.iotstatue = _iotram.iotstatue;
    MeterMqttData.mqttreturytime = _iotram.mqttreturytime;
    MeterMqttData.mqttuploadtime = _iotram.mqttuploadtime;
    MeterMqttData.alarmTempture = _iotram.alarmTempture;
    MeterMqttData.alarmvoltage = _iotram.alarmvoltage;
    MeterMqttData.alarmmode= _iotram.alarmmode;
}
void writeOdoToRam(uint32_t  odo){
    MeterMqttData.odo = odo;
    
}
uint32_t readOdoFromRam(void){
    
    return MeterMqttData.odo;
}
void emnueeprom_init(void){
    
}

void emueeprom_main(void){
    
    
    
    
    
    
    
 
    
    
    
}








/*******************************************************************************
 End of File
 */