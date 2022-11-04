#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "moden.h"
#include "appiot.h"
#include "apptimer.h"

#define AT_MODULE_CONNECT_TIMEOUT_MS    3000  //3sec

uint32_t commandtimeouttimer;
uint16_t _moden_command;
MODEN_COMMAND_DATA _moden_cmd_data;
MODEN_DATA _moden;
MODEN_STATES readmodenstatue(void){
  
    return  (_moden.state);
}

void setmoden(MODEN_STATES states){
    _moden.state = states;
}

void init_moden(void){
    setmcahinestates(disconnect);
    setmoden (moden_open);
    setldoon();
    resetiot();
    _moden_cmd_data.ModenCommand=_NONE_AT_CMD;
    _moden_cmd_data.RespondCommand =_NONE_AT_CMD;
    _moden_cmd_data.state = COMMAND_NONE;
    
}

void setldoon(void){
     EN_3V8_Set();//turn LDO ON
}

void setldoff(void){
     EN_3V8_Clear();//turn LDO off
}

void resetiot(void){
    RST_IOT_Clear();  
    SYSTICK_DelayMs(10);
    RST_IOT_Set() ;
    SYSTICK_DelayMs(100);
    RST_IOT_Clear();  
}
void moden_main(void){
    if(_moden.state== moden_closed) return;
    if(readmcahinestates()==disconnect && readmcahinestates()==none){
            _moden_cmd_data.state = COMMAND_SENDING;
            _moden_cmd_data.CommandTumeoutTimer = platform_get_time_ms();
            //SendATCOmmand();
            setmcahinestates(waitrespond);
     }
    if(readmcahinestates()==disconnect && readmcahinestates()==none){
        
    }
    else if(readmcahinestates()==connected){
        
    }
    else{
        
    }
    
    
}

void SendATCOmmand(void){
    static char buffer[100];
    static uint32_t at_module_connect_tick;
    static uint16_t at_module_connect_state_bak;
    switch(_moden.AT_MODULE_CONNECT_state){
        case _NONE_AT_CMD:
            break;
        case _AT_CMD:
            sprintf(buffer,"AT\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CMD;
            _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;
        case _ATE0_CMD:
            sprintf(buffer,"ATE0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _ATE0_CMD;
            _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;   
        case _AT_CLCK_CMD:
            sprintf(buffer,"AT+CLCK=\"SC\",2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CLCK_CMD;
            _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;  
        case _AT_CPIN_CMD:
            sprintf(buffer,"AT+CPIN?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CPIN_CMD;
            _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;  
        case _AT_COPS_CMD:
            sprintf(buffer,"AT+COPS?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_COPS_CMD;
            _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;  
        case _AT_CSQ_CMD:
            sprintf(buffer,"AT+CSQ\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CSQ_CMD;
            _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;  
        case _AT_MODULE_CONNECT_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_module_connect_tick)>AT_MODULE_CONNECT_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break;
        case _AT_MODULE_CONNECT_OK:            
            if(at_module_connect_state_bak != _AT_CSQ_CMD)
                _moden.AT_MODULE_CONNECT_state = at_module_connect_state_bak++;
            else
                _moden.AT_MODULE_CONNECT_state = _AT_MODULE_CONNECT_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_MODULE_CONNECT_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_MODULE_CONNECT_FINISH:
            
            
            break;        
        default:
            break;
    }
    
}
