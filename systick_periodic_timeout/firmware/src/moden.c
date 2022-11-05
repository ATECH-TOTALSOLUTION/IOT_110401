#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "moden.h"
#include "appiot.h"
#include "apptimer.h"

#define AT_MODULE_CONNECT_TIMEOUT_MS                          3000  //3sec
#define AT_4GLTE_link_chk_TIMEOUT_MS                          3000  //3sec
#define AT_NETWORK_STATUS_TIMEOUT_MS                          3000  //3sec
#define AT_RELOG_IN_TIMEOUT_MS                                5000  //5SEC
#define AT_MQTT_BIDIR_AUTH_PARA_LOAD_TIMEOUT_MS               5000  //5SEC
#define AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_TIMEOUT_MS     5000  //5SEC   
#define AT_MQTT_PARA_OPERATION_TIMEOUT_MS                     5000  //5SEC
#define AT_4G_LTE_LOGIN_TIMEOUT_MS                            5000  //5SEC
#define AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_TIMEOUT_MS              5000  //5SEC

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
    static uint32_t at_module_connect_tick,at_4GLTE_link_chk_tick,at_NETWORK_STATUS_tick,at_RELOG_IN_tick,
                    at_MQTT_BIDIR_AUTH_PARA_LOAD_tick,at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_tick,
                    at_MQTT_PARA_OPERATION_tick,at_4G_LTE_LOGIN_tick,at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick;
    static uint16_t at_module_connect_state_bak,at_4GLTE_link_chk_state_bak,at_NETWORK_STATUS_state_bak,
                    at_RELOG_IN_state_bak,at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak,
                    at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_state_bak,at_MQTT_PARA_OPERATION_state_bak,
                    at_4G_LTE_LOGIN_state_bak,at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak;
    switch(_moden.AT_state){
        case _NONE_AT_CMD:
            break;
            
        ///////////////////////////////////////////////////////////////////////////    
        ///////////////////////////////////////////////////////////////////////////    
        case _AT1_CMD:
            sprintf(buffer,"AT\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;
        case _ATE0_CMD:
            sprintf(buffer,"ATE0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _ATE0_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;   
        case _AT_CLCK1_CMD:
            sprintf(buffer,"AT+CLCK=\"SC\",2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CLCK1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;  
        case _AT_CPIN1_CMD:
            sprintf(buffer,"AT+CPIN?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CPIN1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;  
        case _AT_COPS1_CMD:
            sprintf(buffer,"AT+COPS?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_COPS1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;  
        case _AT_CSQ1_CMD:
            sprintf(buffer,"AT+CSQ\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CSQ1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            break;  
        case _AT_MODULE_CONNECT_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_MODULE_CONNECT_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_MODULE_CONNECT_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_module_connect_tick)>AT_MODULE_CONNECT_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break;
        case _AT_MODULE_CONNECT_OK:            
            if(at_module_connect_state_bak != _AT_CSQ1_CMD)
                _moden.AT_state = at_module_connect_state_bak+1;
            else
                _moden.AT_state = _AT_MODULE_CONNECT_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_MODULE_CONNECT_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_MODULE_CONNECT_FINISH:
            
            
            break;   
        //////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////
        case _AT2_CMD:
            sprintf(buffer,"AT\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4GLTE_link_chk_state_bak = _AT2_CMD;
            _moden.AT_state = _AT_4GLTE_link_chk_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_4GLTE_link_chk_tick = timer1ms;
            break;
        case _AT_CEREG1_CMD:
            sprintf(buffer,"AT+CEREG?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4GLTE_link_chk_state_bak = _AT_CEREG1_CMD;
            _moden.AT_state = _AT_4GLTE_link_chk_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_4GLTE_link_chk_tick = timer1ms;
            break;
        case  _AT_CGDCONT1_CMD:
            sprintf(buffer,"AT+CGDCONT?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4GLTE_link_chk_state_bak = _AT_CGDCONT1_CMD;
            _moden.AT_state = _AT_4GLTE_link_chk_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_4GLTE_link_chk_tick = timer1ms;
            break;
        case  _AT_CCLK_CMD:
            sprintf(buffer,"AT+CCLK?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4GLTE_link_chk_state_bak = _AT_CCLK_CMD;
            _moden.AT_state = _AT_4GLTE_link_chk_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_4GLTE_link_chk_tick = timer1ms;
            break;
            
        case _AT_4GLTE_link_chk_SENDING:            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_4GLTE_link_chk_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_4GLTE_link_chk_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_4GLTE_link_chk_tick)>AT_4GLTE_link_chk_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break;            
        case _AT_4GLTE_link_chk_OK:            
            if(at_4GLTE_link_chk_state_bak != _AT_CCLK_CMD)
                _moden.AT_state = at_4GLTE_link_chk_state_bak+1;
            else
                _moden.AT_state = _AT_MODULE_CONNECT_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_4GLTE_link_chk_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;    
        case _AT_4GLTE_link_chk_FINISH:
            
            
            break;       
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_COPS2_CMD:
            sprintf(buffer,"AT+COPS?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_NETWORK_STATUS_state_bak = _AT_COPS2_CMD;
            _moden.AT_state = _AT_NETWORK_STATUS_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_NETWORK_STATUS_tick = timer1ms;
            break;
        case _AT_CSQ2_CMD:
            sprintf(buffer,"AT+CSQ\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_NETWORK_STATUS_state_bak = _AT_CSQ2_CMD;
            _moden.AT_state = _AT_NETWORK_STATUS_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_NETWORK_STATUS_tick = timer1ms;           
            break;
        case _AT_CEREG2_CMD:
            sprintf(buffer,"AT+CEREG?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_NETWORK_STATUS_state_bak = _AT_CEREG2_CMD;
            _moden.AT_state = _AT_NETWORK_STATUS_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_NETWORK_STATUS_tick = timer1ms;           
            break;
        case _AT_NETWORK_STATUS_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_NETWORK_STATUS_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_NETWORK_STATUS_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_NETWORK_STATUS_tick)>AT_NETWORK_STATUS_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break;
        case _AT_NETWORK_STATUS_OK:            
            if(at_NETWORK_STATUS_state_bak != _AT_CEREG2_CMD)
                _moden.AT_state = at_NETWORK_STATUS_state_bak+1;
            else
                _moden.AT_state = _AT_NETWORK_STATUS_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_NETWORK_STATUS_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;    
        case _AT_NETWORK_STATUS_FINISH:
            
            
            break;            
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_CLCK2_CMD:
            sprintf(buffer,"AT+CLCK=\"SC\",2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_CLCK2_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;
            break;  
        case _AT_CPIN2_CMD:
            sprintf(buffer,"AT+CPIN?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_CPIN2_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;
            break;  
        case _AT_COPS3_CMD:
            sprintf(buffer,"AT+COPS?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_COPS3_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;
            break;
        case _AT_CSQ3_CMD:
            sprintf(buffer,"AT+CSQ\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_CSQ3_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;           
            break;
        case _AT_CEREG3_CMD:
            sprintf(buffer,"AT+CEREG?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_CEREG3_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;           
            break;
        case _AT_UPSD1_CMD:
            sprintf(buffer,"AT+UPSD=0,0,0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_UPSD1_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;           
            break;
        case _AT_UPSDA1_CMD:
            sprintf(buffer,"AT+UPSDA=0,3\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_UPSDA1_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;           
            break;
        case _AT_RELOG_IN_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_RELOG_IN_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_RELOG_IN_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_RELOG_IN_tick)>AT_RELOG_IN_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break;
        case _AT_RELOG_IN_OK:
            if(at_RELOG_IN_state_bak != _AT_UPSDA1_CMD)
                _moden.AT_state = at_RELOG_IN_state_bak+1;
            else
                _moden.AT_state = _AT_RELOG_IN_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_RELOG_IN_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;    
        case _AT_RELOG_IN_FINISH:
            
            
            break;          
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_USECMNG1:
            sprintf(buffer,"AT+USECMNG=0,0,\"pcbca\",1359\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));  
            _moden.AT_state++;
            break;
        case _AT_USECMNG2:
            sprintf(buffer,"AT+USECMNG=0,1,\"pcbcc\",1257\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));    
            _moden.AT_state++;
            break;
        case _AT_USECMNG3:
            sprintf(buffer,"AT+USECMNG=0,2,\"pcbpk\",1675\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_USECMNG4:
            sprintf(buffer,"AT+USECMNG=3\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));  
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_FINISH;
            break;
        case _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_FINISH:
            
            
            break;
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////    
        case _AT_UMQTT1_CMD:
            sprintf(buffer,"AT+UMQTT=0,\"pcbuuid\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT2_CMD:
            sprintf(buffer,"AT+UMQTT=2,\"shareapp.stonetech.com.tw\",8883\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT3_CMD:
            sprintf(buffer,"AT+UMQTT=3,\"xxx.xxx.xxx.xxx\",8883\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT4_CMD:
            sprintf(buffer,"AT+UMQTT=6,1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT5_CMD:
            sprintf(buffer,"AT+UMQTT=7,1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT6_CMD:
            sprintf(buffer,"AT+UMQTT=8,\"EMOTO/DEV/pcbuuid/UP\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT7_CMD:
            sprintf(buffer,"AT+UMQTT=9,\"Unrequested disconnect\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT8_CMD:
            sprintf(buffer,"AT+UMQTT=10,3600,20\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT9_CMD:
            sprintf(buffer,"AT+UMQTT=11,1,2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTTC1_CMD:
            sprintf(buffer,"AT+UMQTTC=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTTC1_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;           
            break;
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_MQTT_BIDIR_AUTH_PARA_LOAD_tick)>AT_MQTT_BIDIR_AUTH_PARA_LOAD_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break;
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_OK:
            if(at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak != _AT_UMQTTC1_CMD)
                _moden.AT_state = at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak+1;
            else
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;    
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_FINISH:
            
            
            break;        
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_UMQTT10_CMD:
            sprintf(buffer,"AT+UMQTT=0,\"pcbuuid\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT11_CMD:
            sprintf(buffer,"AT+UMQTT=1,1883\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT12_CMD:
            sprintf(buffer,"AT+UMQTT=2,\"shareapp.stonetech.com.tw\",1883\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT13_CMD:
            sprintf(buffer,"AT+UMQTT=3,\"xxx.xxx.xxx.xxx\",8883\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT14_CMD:
            sprintf(buffer,"AT+UMQTT=4,\"test\",\"mqtt123\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT15_CMD:
            sprintf(buffer,"AT+UMQTT=6,1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT16_CMD:
            sprintf(buffer,"AT+UMQTT=7,1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT17_CMD:
            sprintf(buffer,"AT+UMQTT=8,\"EMOTO/DEV/pcbuuid/UP\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT18_CMD:
            sprintf(buffer,"AT+UMQTT=9,\"Unrequested disconnect\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT19_CMD:
            sprintf(buffer,"AT+UMQTT=10,3600,20\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTT20_CMD:
            sprintf(buffer,"AT+UMQTT=11,0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            break;
        case _AT_UMQTTNV1_CMD:
            sprintf(buffer,"AT+UMQTTNV=2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_state_bak = _AT_UMQTTNV1_CMD;
            _moden.AT_state = _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_tick = timer1ms;               
            break;
        case _AT_UMQTTC2_CMD:
            sprintf(buffer,"AT+UMQTTC=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_state_bak = _AT_UMQTTC2_CMD;
            _moden.AT_state = _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_tick = timer1ms;             
            break;
        case _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_tick)>AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break;
        case _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_OK:
            if(at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_state_bak != _AT_UMQTTC2_CMD)
                _moden.AT_state = at_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_state_bak+1;
            else
                _moden.AT_state = _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;    
        case _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_FINISH:
            
            
            break;        
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_UMQTTNV2_CMD:
            sprintf(buffer,"AT+UMQTTNV=2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_PARA_OPERATION_state_bak = _AT_UMQTTNV2_CMD;
            _moden.AT_state = _AT_MQTT_PARA_OPERATION_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_PARA_OPERATION_tick = timer1ms;               
            break;
        case _AT_UMQTTNV3_CMD:    
            sprintf(buffer,"AT+UMQTTNV=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_PARA_OPERATION_state_bak = _AT_UMQTTNV3_CMD;
            _moden.AT_state = _AT_MQTT_PARA_OPERATION_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_PARA_OPERATION_tick = timer1ms;          
            break;
        case _AT_MQTT_PARA_OPERATION_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_MQTT_PARA_OPERATION_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_MQTT_PARA_OPERATION_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_MQTT_PARA_OPERATION_tick)>AT_MQTT_PARA_OPERATION_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break; 
        case _AT_MQTT_PARA_OPERATION_OK:
            if(at_MQTT_PARA_OPERATION_state_bak != _AT_UMQTTNV3_CMD)
                _moden.AT_state = at_MQTT_PARA_OPERATION_state_bak+1;
            else
                _moden.AT_state = _AT_MQTT_PARA_OPERATION_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_MQTT_PARA_OPERATION_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;    
        case _AT_MQTT_PARA_OPERATION_FINISH:
            
            
            break;        
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_UPSD2_CMD:   
            sprintf(buffer,"AT+UPSD=0,0,0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4G_LTE_LOGIN_state_bak = _AT_UPSD2_CMD;
            _moden.AT_state = _AT_4G_LTE_LOGIN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_4G_LTE_LOGIN_tick = timer1ms;       
            break;
        case _AT_UPSDA2_CMD:   
            sprintf(buffer,"AT+UPSDA=0,3\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4G_LTE_LOGIN_state_bak = _AT_UPSDA2_CMD;
            _moden.AT_state = _AT_4G_LTE_LOGIN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_4G_LTE_LOGIN_tick = timer1ms;       
            break;    
        case _AT_CGDCONT2_CMD:
            sprintf(buffer,"AT+CGDCONT?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4G_LTE_LOGIN_state_bak = _AT_CGDCONT2_CMD;
            _moden.AT_state = _AT_4G_LTE_LOGIN_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_4G_LTE_LOGIN_tick = timer1ms;       
            break;              
        case _AT_4G_LTE_LOGIN_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_4G_LTE_LOGIN_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_4G_LTE_LOGIN_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_4G_LTE_LOGIN_tick)>AT_4G_LTE_LOGIN_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break; 
        case _AT_4G_LTE_LOGIN_OK:
            if(at_4G_LTE_LOGIN_state_bak != _AT_UPSDA2_CMD)
                _moden.AT_state = at_4G_LTE_LOGIN_state_bak+1;
            else
                _moden.AT_state = _AT_4G_LTE_LOGIN_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_4G_LTE_LOGIN_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;    
        case _AT_4G_LTE_LOGIN_FINISH:
            
            
            break;        
            
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_UPSD3_CMD:   
            sprintf(buffer,"AT+UPSD=0,0,0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UPSD3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;       
            break;
        case _AT_UPSDA3_CMD:   
            sprintf(buffer,"AT+UPSDA=0,3\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UPSDA3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;       
            break;    
        case _AT_CGDCONT3_CMD:
            sprintf(buffer,"AT+CGDCONT?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_CGDCONT3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;         
            break;         
        case _AT_UMQTTNV4_CMD:
            sprintf(buffer,"AT+UMQTTNV=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTTNV4_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;         
            break;            
        case _AT_USECPRF1_CMD:
            sprintf(buffer,"AT+USECPRF=2,0,1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_USECPRF1_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;         
            break;       
        case _AT_USECPRF2_CMD:
            sprintf(buffer,"AT+USECPRF=2,3,\"pcbca\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_USECPRF2_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;         
            break;              
        case _AT_USECPRF3_CMD:
            sprintf(buffer,"AT+USECPRF=2,5,\"pcbcc\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_USECPRF3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;         
            break;              
        case _AT_USECPRF4_CMD:
            sprintf(buffer,"AT+USECPRF=2,6,\"pcbpk\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_USECPRF4_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;         
            break;              
        case _AT_UMQTTC3_CMD:
            sprintf(buffer,"AT+UMQTTC=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTTC3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;                
            break;
        case _AT_UMQTTC4_CMD:
            sprintf(buffer,"AT+UMQTTC=0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTTC4_CMD;
            _moden.AT_state = _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_SENDING;
            _moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;             
            break;
        case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING:
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick)>AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_TIMEOUT_MS){
                
                
                
                _moden_cmd_data.state = COMMAND_NONE;
            }                
            break;
        case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_OK:
            if(at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak != _AT_UMQTTC4_CMD)
                _moden.AT_state = at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak+1;
            else
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_ERROR:
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;    
        case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_FINISH:
            
            
            break;        
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
            
        default:
            break;
    }
    
}
