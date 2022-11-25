#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "moden.h"
#include "appiot.h"
#include "apptimer.h"
#include "appuart.h"
#include "app_uart_debug.h"

#define AT_MODULE_CONNECT_TIMEOUT_MS                          5000  //5sec
#define AT_4GLTE_link_chk_TIMEOUT_MS                          5000  //5sec
#define AT_NETWORK_STATUS_TIMEOUT_MS                          5000  //5sec
#define AT_RELOG_IN_TIMEOUT_MS                                5000  //5SEC
#define AT_MQTT_BIDIR_AUTH_PARA_LOAD_TIMEOUT_MS               5000  //5SEC
#define AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_TIMEOUT_MS     5000  //5SEC   
#define AT_MQTT_PARA_OPERATION_TIMEOUT_MS                     5000  //5SEC
#define AT_4G_LTE_LOGIN_TIMEOUT_MS                            5000  //5SEC
#define AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_TIMEOUT_MS              10000 //10SEC
#define AT_GPS_TIMEOUT_MS                                     5000  //5SEC
#define AT_MQTT_TX_UP_DATA1_TIMEOUT_MS                        10000 //10SEC
#define AT_READ_TIMEOUT_MS                                    10000 //10SEC
#define AT_RESET_INITIAL_TIMEOUT_MS                           (1000*60) //60SEC  

#define AT_ERROR_RESET_INITIAL_COUNT 3
#define AT_GPS_READ_TIME                                      (1000*10) //10SEC 

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
    
    _moden_cmd_data.state = COMMAND_NONE;
    
    //memset(_moden,0,sizeof(MODEN_DATA));
    //_moden.state = moden_closed;
    _moden.AT_state = _NONE_AT_CMD;
    _moden.AT_READ_state = _AT_RAED_LISTEN_CMD;
    memset(_moden.moden_uuid_md5,0,sizeof(_moden.moden_uuid_md5));
    _moden.lte_4G_TX_flag = 0;
    memset(_moden.lte_4G_TX_data,0,sizeof(_moden.lte_4G_TX_data));
    _moden.lte_4G_RX_flag = 0;
    _moden.lte_4G_RX_count = 0;
    memset(_moden.lte_4G_RX_data,0,sizeof(_moden.lte_4G_RX_data));
    _moden.lte_4G_TX_error_count = 0;
    _moden.lte_4G_RX_error_count = 0;
    _moden.lte_4G_reset_initial_flag = 0;
    
    _moden.lte_4G_gps_first_flag = 0;
    _moden.lte_4G_gps_read_flag = 0;
    _moden.lte_4G_gps_tick = 0;
    
    memset(_moden.lte_4G_latitude,0,sizeof(_moden.lte_4G_latitude));
    memset(_moden.lte_4G_longitude,0,sizeof(_moden.lte_4G_longitude));
        
    memset(buffer,0,sizeof(buffer));    
    memset(rxBuffer,0,sizeof(rxBuffer)); 
    memset(platformrxbuffer,0,sizeof(platformrxbuffer)); 
    nBytesRead = 0;    
    
    if(_moden.lte_4G_reset_initial_flag == 1){
        _moden.lte_4G_reset_initial_flag = 0;
        SYSTICK_DelayMs(1000);
    }
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
    if(readmodenstatue()== moden_closed) return;
    
    //if((readmcahinestates()==disconnect) && (_moden_cmd_data.state == COMMAND_NONE)){
    if((_moden_cmd_data.state == COMMAND_NONE)){
        
        switch(_moden.AT_state){
                    
            case  _NONE_AT_CMD:
                
                setmoden(moden_connection_initial);
                
                //_moden.AT_state = _AT1_CMD;
                _moden.AT_state = _AT_RD_P01_CMD; //send data test OK
                break;
        
            case _AT_MODULE_CONNECT_FINISH:
                _moden.AT_state = _AT2_CMD;
                //_moden.AT_state = _AT_UMQTT1_CMD;
                __NOP();
                break;    
                
            case _AT_4GLTE_link_chk_FINISH:
                _moden.AT_state = _AT_COPS2_CMD;
                
                __NOP();               
                break;
                
            case _AT_NETWORK_STATUS_FINISH:
                //_moden.AT_state = _AT_CLCK2_CMD;
                //_moden.AT_state = _AT_USECMNG1;
                _moden.AT_state = _AT_UMQTT1_CMD;
                __NOP();               
                break;
                
            case _AT_RELOG_IN_FINISH:
                __NOP();   
                break;
            case _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_FINISH:
                _moden.AT_state = _AT_UMQTT1_CMD;
                __NOP();   
                break;
            case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_FINISH:  
                //_moden.AT_state = _AT_UMQTT10_CMD;
                _moden.AT_state = _AT_UMQTTNV2_CMD;
                __NOP();   
                break;
            //case _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_FINISH:
            //    _moden.AT_state = _AT_UMQTTNV2_CMD;
            //    __NOP();   
            //    break;
            case _AT_MQTT_PARA_OPERATION_FINISH:
                _moden.AT_state = _AT_UPSD3_CMD;     
                __NOP();   
                break;
                
            //case  _AT_4G_LTE_LOGIN_FINISH:
                
                
            //    __NOP();
            //    break;  
                
            case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_FINISH:
                
                setmoden(moden_ready);                
                _moden.AT_state = _AT_MQTT_TX_UP_DATA1_FINISH;  
                //_moden.AT_state = _AT_MQTT_TX_UP_DATA1_CMD;
                __NOP(); 
                break;
                
            case _AT_MQTT_TX_UP_DATA1_FINISH:     
                
                if(((_moden.lte_4G_TX_flag == 1) || (_moden.lte_4G_gps_read_flag == 1)) && (_moden.AT_state == _AT_MQTT_TX_UP_DATA1_FINISH) && (_moden.AT_READ_state == _AT_RAED_LISTEN_CMD)){
                    
                    if(_moden.lte_4G_TX_flag == 1){
                        _moden.lte_4G_TX_flag = 0;
                        _moden.AT_state = _AT_MQTT_TX_UP_DATA1_CMD; 
                    }
                    else if(_moden.lte_4G_gps_read_flag == 1){
                                               
                        _moden.lte_4G_gps_read_flag = 0;
                        
                        if(_moden.lte_4G_gps_first_flag == 0){
                            _moden.lte_4G_gps_first_flag = 1;
                            _moden.AT_state = _AT_UGRMC1_CMD;
                        }
                        else
                            _moden.AT_state = _AT_UGRMC2_CMD;
                    }                   
                }
                break;
            default:
                break;
        }
    }
    
    if(_moden.lte_4G_reset_initial_flag == 0)
        SendATCOmmand();
    
    if((_moden.lte_4G_TX_error_count >= AT_ERROR_RESET_INITIAL_COUNT) || (_moden.lte_4G_RX_error_count >= AT_ERROR_RESET_INITIAL_COUNT)){
        static uint32_t reset_tick;
        
        if(_moden.lte_4G_reset_initial_flag == 0){
            setmoden(moden_open);
            reset_tick = timer1ms;
            _moden.lte_4G_reset_initial_flag = 1;            
        }
        else{
            if((timer1ms-reset_tick)>AT_RESET_INITIAL_TIMEOUT_MS){
                
                #ifdef AT_UART_DEBUG_ON
                    char string[100];
                    sprintf(string,"ERROR:LTE 4G RESET INITIAL");
                    uart_debug_megssage((uint8_t*)string, strlen(string));
                #endif
                
                setmoden(moden_closed);
                setldoff();
                SYSTICK_DelayMs(1000);
                init_moden();
            }
        }
    }
    
    //gps
    if((timer1ms - _moden.lte_4G_gps_tick)> AT_GPS_READ_TIME){        
        _moden.lte_4G_gps_read_flag = 1;
        _moden.lte_4G_gps_tick = timer1ms;
    }
}

void SendATCOmmand(void){
    static uint32_t at_module_connect_tick,at_4GLTE_link_chk_tick,at_NETWORK_STATUS_tick,at_RELOG_IN_tick,
                    at_4G_LTE_LOGIN_tick,at_MQTT_BIDIR_AUTH_PARA_LOAD_tick,at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick,
                    at_MQTT_PARA_OPERATION_tick,at_MQTT_TX_UP_DATA1_tick,at_READ_tick,at_GPS_tick;
    static uint16_t at_module_connect_state_bak,at_4GLTE_link_chk_state_bak,at_NETWORK_STATUS_state_bak,
                    at_RELOG_IN_state_bak,at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak,                
                    at_4G_LTE_LOGIN_state_bak,at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak,
                    at_MQTT_PARA_OPERATION_state_bak,at_MQTT_TX_UP_DATA1_state_bak,at_RAED_state_bak,at_GPS_state_bak;
    
    #ifdef AT_UART_DEBUG_ON
        char tmp[256];
    #endif

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
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t *)buffer, strlen(buffer));
            #endif
            break;
        case _ATE0_CMD:
            sprintf(buffer,"ATE0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _ATE0_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;   
        case _AT_CLCK1_CMD:
            sprintf(buffer,"AT+CLCK=\"SC\",2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CLCK1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;  
        case _AT_CPIN1_CMD:
            sprintf(buffer,"AT+CPIN?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CPIN1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;  
        case _AT_COPS1_CMD:
            sprintf(buffer,"AT+COPS?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_COPS1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;  
        case _AT_CSQ1_CMD:
            sprintf(buffer,"AT+CSQ\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_CSQ1_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;  
        case _AT_RD_P0_CMD:
            sprintf(buffer,"AT+URDFILE=\"P0\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_module_connect_state_bak = _AT_RD_P0_CMD;
            _moden.AT_state = _AT_MODULE_CONNECT_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_module_connect_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;              
        case _AT_MODULE_CONNECT_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
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
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MODULE_CONNECT  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t *)platformrxbuffer,strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }
            break;
        case _AT_MODULE_CONNECT_OK:            
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            if(at_module_connect_state_bak != _AT_RD_P0_CMD)
                _moden.AT_state = at_module_connect_state_bak+1;
            else{
                char * adr;
                
                adr = strstr((const char *)platformrxbuffer,(const char *)",32,");
                adr += 5;
                memcpy(_moden.moden_uuid_md5,adr,sizeof(_moden.moden_uuid_md5));                
                
                _moden.AT_state = _AT_MODULE_CONNECT_FINISH;               
            }
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));    
                
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_MODULE_CONNECT_ERROR:            
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MODULE_CONNECT  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif            

            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            break;
            
            
        case _AT_MODULE_CONNECT_FINISH:            
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            _moden_cmd_data.state = COMMAND_NONE;            
            break;   
        //////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////
        case _AT2_CMD:
            sprintf(buffer,"AT\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4GLTE_link_chk_state_bak = _AT2_CMD;
            _moden.AT_state = _AT_4GLTE_link_chk_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_4GLTE_link_chk_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_CEREG1_CMD:
            sprintf(buffer,"AT+CEREG?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4GLTE_link_chk_state_bak = _AT_CEREG1_CMD;
            _moden.AT_state = _AT_4GLTE_link_chk_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_4GLTE_link_chk_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case  _AT_CGDCONT1_CMD:
            sprintf(buffer,"AT+CGDCONT?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4GLTE_link_chk_state_bak = _AT_CGDCONT1_CMD;
            _moden.AT_state = _AT_4GLTE_link_chk_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_4GLTE_link_chk_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case  _AT_CCLK_CMD:
            sprintf(buffer,"AT+CCLK?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4GLTE_link_chk_state_bak = _AT_CCLK_CMD;
            _moden.AT_state = _AT_4GLTE_link_chk_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_4GLTE_link_chk_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
            
        case _AT_4GLTE_link_chk_SENDING:      
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }                
            
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
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_4GLTE_link_chk  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break;            
        case _AT_4GLTE_link_chk_OK:           
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            if(at_4GLTE_link_chk_state_bak != _AT_CCLK_CMD)
                _moden.AT_state = at_4GLTE_link_chk_state_bak+1;
            else
                _moden.AT_state = _AT_4GLTE_link_chk_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_4GLTE_link_chk_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_4GLTE_link_chk  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif          
                
            memset(platformrxbuffer,0,sizeof(platformrxbuffer)); 
               
            break;    
        case _AT_4GLTE_link_chk_FINISH:
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            break;       
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_COPS2_CMD:
            sprintf(buffer,"AT+COPS?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_NETWORK_STATUS_state_bak = _AT_COPS2_CMD;
            _moden.AT_state = _AT_NETWORK_STATUS_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_NETWORK_STATUS_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_CSQ2_CMD:
            sprintf(buffer,"AT+CSQ\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_NETWORK_STATUS_state_bak = _AT_CSQ2_CMD;
            _moden.AT_state = _AT_NETWORK_STATUS_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_NETWORK_STATUS_tick = timer1ms;      
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_CEREG2_CMD:
            sprintf(buffer,"AT+CEREG?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_NETWORK_STATUS_state_bak = _AT_CEREG2_CMD;
            _moden.AT_state = _AT_NETWORK_STATUS_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_NETWORK_STATUS_tick = timer1ms;     
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_NETWORK_STATUS_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
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
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_NETWORK_STATUS  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break;
        case _AT_NETWORK_STATUS_OK:        
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            if(at_NETWORK_STATUS_state_bak != _AT_CEREG2_CMD)
                _moden.AT_state = at_NETWORK_STATUS_state_bak+1;
            else
                _moden.AT_state = _AT_NETWORK_STATUS_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_NETWORK_STATUS_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_NETWORK_STATUS  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif          
                
            memset(platformrxbuffer,0,sizeof(platformrxbuffer)); 
            break;    
        case _AT_NETWORK_STATUS_FINISH:
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            break;            
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_CLCK2_CMD:
            sprintf(buffer,"AT+CLCK=\"SC\",2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_CLCK2_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;  
        case _AT_CPIN2_CMD:
            sprintf(buffer,"AT+CPIN?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_CPIN2_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;  
        case _AT_COPS3_CMD:
            sprintf(buffer,"AT+COPS?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_COPS3_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_CSQ3_CMD:
            sprintf(buffer,"AT+CSQ\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_CSQ3_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_CEREG3_CMD:
            sprintf(buffer,"AT+CEREG?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_CEREG3_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;       
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UPSD1_CMD:
            sprintf(buffer,"AT+UPSD=0,0,0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_UPSD1_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;       
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UPSDA1_CMD:
            sprintf(buffer,"AT+UPSDA=0,3\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_RELOG_IN_state_bak = _AT_UPSDA1_CMD;
            _moden.AT_state = _AT_RELOG_IN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_RELOG_IN_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_RELOG_IN_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
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
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_RELOG_IN  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break;
        case _AT_RELOG_IN_OK:
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            if(at_RELOG_IN_state_bak != _AT_UPSDA1_CMD)
                _moden.AT_state = at_RELOG_IN_state_bak+1;
            else
                _moden.AT_state = _AT_RELOG_IN_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_RELOG_IN_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_RELOG_IN  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif          
                
            memset(platformrxbuffer,0,sizeof(platformrxbuffer)); 
            break;    
        case _AT_RELOG_IN_FINISH:
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            break;          
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_USECMNG1:
            sprintf(buffer,"AT+USECMNG=0,0,\"pcbca\",1359\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));  
            _moden.AT_state++;
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_USECMNG2:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+USECMNG=0,1,\"pcbcc\",1257\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));    
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_USECMNG3:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+USECMNG=0,2,\"pcbpk\",1675\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_USECMNG4:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+USECMNG=3\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));  
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_WAIT;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_WAIT:
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_FINISH;
            }
            break;
        case _AT_MQTT_BIDIR_AUTH_KEY_UPLOAD_FINISH:
            break;
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////   
        case _AT_RD_P01_CMD:
            sprintf(buffer,"AT+URDFILE=\"P0\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_RD_P01_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms; 
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;     
        case _AT_UMQTT1_CMD:
            sprintf(buffer,"AT+UMQTT=0,\"9C490D32BB20833601820E1A7298CE22\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT1_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UMQTT2_CMD:
            sprintf(buffer,"AT+UMQTT=2,\"shareapp.stonetech.com.tw\",8883\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT2_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;  
        /*
        case _AT_UMQTT021_CMD:
            sprintf(buffer,"AT+UMQTT=2,\"shareapp.stonetech.com.tw\",8883\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT021_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;       
        */    
        case _AT_UMQTT3_CMD:
            sprintf(buffer,"AT+UMQTT=3,\"\",8883\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;           
        case _AT_UMQTT4_CMD:
            sprintf(buffer,"AT+UMQTT=6,1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT4_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;                  
        case _AT_UMQTT5_CMD:
            sprintf(buffer,"AT+UMQTT=7,1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT5_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;                    
        case _AT_UMQTT6_CMD:
            sprintf(buffer,"AT+UMQTT=8,\"seraphim/lastwill\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT6_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;                 
        case _AT_UMQTT7_CMD:
            sprintf(buffer,"AT+UMQTT=9,\"Unrequested disconnect\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT7_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;                             
        case _AT_UMQTT8_CMD:
            sprintf(buffer,"AT+UMQTT=10,3600,20\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT8_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;                            
        case _AT_UMQTT9_CMD:
            sprintf(buffer,"AT+UMQTT=11,1,2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT9_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;                        
        case _AT_UMQTTC1_CMD:
            sprintf(buffer,"AT+UMQTTC=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak = _AT_UMQTT1_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_PARA_LOAD_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;                       
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_WAIT:
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_FINISH;
            }
            
            break;
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
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
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MQTT_BIDIR_AUTH_PARA_LOAD  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break;
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_OK:
            
            if(at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak == _AT_RD_P01_CMD){
                    char * adr;
                
                    adr = strstr((const char *)platformrxbuffer,(const char *)",32,");
                    adr += 5;
                    memcpy(_moden.moden_uuid_md5,adr,sizeof(_moden.moden_uuid_md5));
            }
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            if(at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak != _AT_UMQTT9_CMD){                
                _moden.AT_state = at_MQTT_BIDIR_AUTH_PARA_LOAD_state_bak+1;
            }    
            else
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_PARA_LOAD_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MQTT_BIDIR_AUTH_PARA_LOAD  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif          
                
            memset(platformrxbuffer,0,sizeof(platformrxbuffer)); 
            break;    
        case _AT_MQTT_BIDIR_AUTH_PARA_LOAD_FINISH:
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            break;              
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_UMQTT10_CMD:
            sprintf(buffer,"AT+UMQTT=0,\"9C490D32BB20833601820E1A7298CE22\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
            _moden.AT_state++;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UMQTT11_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=1,1883\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT12_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=2,\"shareapp.stonetech.com.tw\",1883\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT13_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=3,\"xxx.xxx.xxx.xxx\",8883\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
                _moden.AT_state++;
                
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT14_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=4,\"test\",\"mqtt123\"\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT15_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=6,1\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT16_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=7,1\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT17_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=8,\"EMOTO/DEV/9C490D32BB20833601820E1A7298CE22/UP\"\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT18_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=9,\"Unrequested disconnect\"\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT19_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=10,3600,20\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTT20_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTT=11,0\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));   
                _moden.AT_state++;
            
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
            }
            break;
        case _AT_UMQTTNV1_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTTNV=2\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
                _moden.AT_state++;
                
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif            
            }
            break;
        case _AT_UMQTTC2_CMD:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                sprintf(buffer,"AT+UMQTTC=1\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
                _moden.AT_state = _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_WAIT;
                
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif       
            }
            break;
        case _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_WAIT:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){   
                
                _moden_cmd_data.state = COMMAND_NONE;
                _moden.AT_state = _AT_MQTT_NO_AUTH_USERID_LOGIN_PARA_LOAD_FINISH;
                
            }
            
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
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_PARA_OPERATION_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UMQTTNV3_CMD:    
            sprintf(buffer,"AT+UMQTTNV=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_PARA_OPERATION_state_bak = _AT_UMQTTNV3_CMD;
            _moden.AT_state = _AT_MQTT_PARA_OPERATION_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_PARA_OPERATION_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;           
        case _AT_MQTT_PARA_OPERATION_WAIT:
            
            if(_moden_cmd_data.state == COMMAND_SENDING){
                
                _moden_cmd_data.state = COMMAND_NONE;
                _moden.AT_state = _AT_MQTT_PARA_OPERATION_FINISH;     
                
            }
            
            break;        
        case _AT_MQTT_PARA_OPERATION_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
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
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MQTT_PARA_OPERATION  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break;
        case _AT_MQTT_PARA_OPERATION_OK:
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            if(at_MQTT_PARA_OPERATION_state_bak != _AT_UMQTTNV3_CMD)
                _moden.AT_state = at_MQTT_PARA_OPERATION_state_bak+1;
            else
                _moden.AT_state = _AT_MQTT_PARA_OPERATION_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_MQTT_PARA_OPERATION_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MQTT_PARA_OPERATION  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif          
                
            memset(platformrxbuffer,0,sizeof(platformrxbuffer)); 
            break;    
        case _AT_MQTT_PARA_OPERATION_FINISH:
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            break;                    
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_UPSD2_CMD:   
            sprintf(buffer,"AT+UPSD=0,0,0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4G_LTE_LOGIN_state_bak = _AT_UPSD2_CMD;
            _moden.AT_state = _AT_4G_LTE_LOGIN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_4G_LTE_LOGIN_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UPSDA2_CMD:   
            sprintf(buffer,"AT+UPSDA=0,3\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4G_LTE_LOGIN_state_bak = _AT_UPSDA2_CMD;
            _moden.AT_state = _AT_4G_LTE_LOGIN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_4G_LTE_LOGIN_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;    
        case _AT_CGDCONT2_CMD:
            sprintf(buffer,"AT+CGDCONT?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_4G_LTE_LOGIN_state_bak = _AT_CGDCONT2_CMD;
            _moden.AT_state = _AT_4G_LTE_LOGIN_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_4G_LTE_LOGIN_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;              
        case _AT_4G_LTE_LOGIN_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
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
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_4G_LTE_LOGIN  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break; 
        case _AT_4G_LTE_LOGIN_OK:
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            if(at_4G_LTE_LOGIN_state_bak != _AT_UPSDA2_CMD)
                _moden.AT_state = at_4G_LTE_LOGIN_state_bak+1;
            else
                _moden.AT_state = _AT_4G_LTE_LOGIN_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_4G_LTE_LOGIN_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_4G_LTE_LOGIN  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif          
                
            memset(platformrxbuffer,0,sizeof(platformrxbuffer)); 
            break;    
        case _AT_4G_LTE_LOGIN_FINISH:
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            break;        
            
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_UPSD3_CMD:   
            
            sprintf(buffer,"AT+UPSD=0,0,0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UPSD3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;   
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UPSDA3_CMD:   
            sprintf(buffer,"AT+UPSDA=0,3\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UPSDA3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;     
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;    
        
        case _AT_CGDCONT3_CMD:
            sprintf(buffer,"AT+CGDCONT?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_CGDCONT3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;     
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;         
        
        
        case _AT_UMQTTNV4_CMD:
            sprintf(buffer,"AT+UMQTTNV=2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTTNV4_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        
        
        case _AT_UMQTTNV5_CMD:
            sprintf(buffer,"AT+UMQTTNV=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTTNV5_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        
        
        case _AT_USECPRF1_CMD:
            sprintf(buffer,"AT+USECPRF=2,0,1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_USECPRF1_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_USECPRF2_CMD:
            sprintf(buffer,"AT+USECPRF=2,3,\"pcbca\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_USECPRF2_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_USECPRF3_CMD:
            sprintf(buffer,"AT+USECPRF=2,5,\"pcbcc\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_USECPRF3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;              
        case _AT_USECPRF4_CMD:
            sprintf(buffer,"AT+USECPRF=2,6,\"pcbpk\"\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_USECPRF4_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;      
        
        /*
        case _AT_UMQTTNV6_CMD:
            sprintf(buffer,"AT+UMQTTNV=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTTNV6_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;           
        */
        
        case _AT_UMQTT21_CMD:
            sprintf(buffer,"AT+UMQTT? \r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTT21_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif

            break;         
        
        case _AT_UMQTT022_CMD:
            sprintf(buffer,"AT+UMQTT=2,\"shareapp.stonetech.com.tw\",8883\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTT022_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;    
        case _AT_UMQTT091_CMD:
            sprintf(buffer,"AT+UMQTT=11,1,2\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTT091_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;      
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;                    
        
        case _AT_UMQTTC3_CMD:
            sprintf(buffer,"AT+UMQTTC=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTTC3_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;        
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif

            SYSTICK_DelayMs(5000); //do not remove this is nesessary
            break;
            
        case _AT_CERTIFY_DOWN_CMD:
            {
                uint32_t lens;
                char tmp_lte[100];                
                                
                sprintf((char *)buffer,(const char *)"AT+UMQTTC=4,0,\"EMOTO/DEV/");
                lens = strlen((const char *)buffer);
                //memcpy(_moden.moden_uuid_md5,"9C490D32BB20833601820E1A7298CE22",sizeof(_moden.moden_uuid_md5));
                memcpy(&buffer[lens],_moden.moden_uuid_md5,sizeof(_moden.moden_uuid_md5));
                sprintf((char *)tmp_lte,(const char *)"/DOWN\"\r\n");                
                strcat((char *)buffer,tmp_lte);
            }       
            
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_CERTIFY_DOWN_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;        
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            
            SYSTICK_DelayMs(3000); //do not remove this is nesessary
            break;
        case _AT_CERTIFY_PUB_CMD:
            {
                uint32_t lens;
                char tmp_lte[100];                        
                
                memset(buffer,0,sizeof(buffer));
                memset(tmp_lte,0,sizeof(tmp_lte));
                sprintf((char *)buffer,(const char *)"AT+UMQTTC=4,0,\"EMOTO/DEV/");
                lens = strlen((const char *)buffer);
                //memcpy(_moden.moden_uuid_md5,"9C490D32BB20833601820E1A7298CE22",sizeof(_moden.moden_uuid_md5));
                memcpy(&buffer[lens],_moden.moden_uuid_md5,sizeof(_moden.moden_uuid_md5));
                sprintf((char *)tmp_lte,(const char *)"/PUB\"\r\n");                
                strcat((char *)buffer,tmp_lte);
            }       
            
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_CERTIFY_PUB_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;        
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            
            SYSTICK_DelayMs(3000); //do not remove this is nesessary
            break;
        case _AT_UMQTTC4_CMD:
            sprintf(buffer,"AT+UMQTTC=0\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak = _AT_UMQTTC4_CMD;
            _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_BIDIR_AUTH_LOGIN_FLOW_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
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
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MQTT_BIDIR_AUTH_LOGIN_FLOW  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break;
        case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_OK:
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            if(at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak != _AT_CERTIFY_PUB_CMD)
                _moden.AT_state = at_MQTT_BIDIR_AUTH_LOGIN_FLOW_state_bak+1;
            else{
                _moden.AT_state = _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_FINISH;
            }
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MQTT_BIDIR_AUTH_LOGIN_FLOW  Error_meg\r\n");
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:");
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            break;
        case _AT_MQTT_BIDIR_AUTH_LOGIN_FLOW_FINISH:
            
            _moden.lte_4G_TX_error_count = 0;
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            break;
        ////////////////////////////////////////////////////////////////////////    
        ////////////////////////////////////////////////////////////////////////    
        case _AT_UGRMC1_CMD:
            sprintf(buffer,"AT+UGRMC=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_GPS_state_bak = _AT_UGRMC1_CMD;
            _moden.AT_state = _AT_GPS_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_GPS_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UGIND_CMD:
            sprintf(buffer,"AT+UGIND=1\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_GPS_state_bak = _AT_UGIND_CMD;
            _moden.AT_state = _AT_GPS_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_GPS_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UGPS1_CMD:
            sprintf(buffer,"AT+UGPS=1,9,67\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_GPS_state_bak = _AT_UGPS1_CMD;
            _moden.AT_state = _AT_GPS_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_GPS_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_UGRMC2_CMD:
            sprintf(buffer,"AT+UGRMC?\r\n");
            SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
            at_GPS_state_bak = _AT_UGRMC2_CMD;
            _moden.AT_state = _AT_GPS_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_GPS_tick = timer1ms;       
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
            #endif
            break;
        case _AT_GPS_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_GPS_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_GPS_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }                
            //timeout
            else if((timer1ms-at_GPS_tick)>AT_GPS_TIMEOUT_MS){
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _NONE_AT_CMD;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_GPS  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break;
        case _AT_GPS_OK:
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            if(at_GPS_state_bak != _AT_UGRMC2_CMD)
                _moden.AT_state = at_GPS_state_bak+1;
            else{
                char *adr;
                float latitude,longitude,tmp_float;
                int32_t tmp1_int32; 
                
                adr = strstr((char *)platformrxbuffer,",A,");
                if(adr != 0){
                    adr += 3;
                    latitude =atof(adr);
                    
                    if(strstr((char *)platformrxbuffer,",N,") == 0){
                        latitude = -latitude;
                        
                        adr = strstr((char *)platformrxbuffer,",S,");
                        adr += 3;
                        longitude  =atof(adr);
                        
                        if(strstr((char *)platformrxbuffer,",E,") == 0)
                            longitude = -longitude;                        
                    }else{
                        
                        adr = strstr((char *)platformrxbuffer,",N,");
                        adr += 3;
                        longitude  =atof(adr);
                        
                        if(strstr((char *)platformrxbuffer,",E,") == 0)
                            longitude = -longitude;                          
                    }
                    
                    memset(_moden.lte_4G_latitude,0,sizeof(_moden.lte_4G_latitude));
                    memset(_moden.lte_4G_longitude,0,sizeof(_moden.lte_4G_longitude));
                    
                    tmp_float = latitude/100;
                    tmp1_int32 = tmp_float;
                    tmp_float = (latitude - (tmp1_int32*100));
                    tmp_float = tmp_float/60;
                    latitude = tmp1_int32 + tmp_float;
                    
                    tmp_float = longitude/100;
                    tmp1_int32 = tmp_float;
                    tmp_float = (longitude - (tmp1_int32*100));
                    tmp_float = tmp_float/60;
                    longitude = tmp1_int32 + tmp_float;
                    
                    sprintf((char *)_moden.lte_4G_latitude,"%.07f",latitude);
                    sprintf((char *)_moden.lte_4G_longitude,"%.07f",longitude);
                    
                    #ifdef AT_UART_DEBUG_ON
                        sprintf(tmp,"latitude= %s  longitude= %s\r\n",(char *)_moden.lte_4G_latitude,(char *)_moden.lte_4G_longitude);
                        uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                    #endif
                }
                
                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
                
                _moden.AT_state = _AT_GPS_FINISH;
            }
            _moden_cmd_data.state = COMMAND_NONE;
            
            break;
        case _AT_GPS_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _NONE_AT_CMD;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_GPS  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif          
                
            memset(platformrxbuffer,0,sizeof(platformrxbuffer)); 
            break;    
        case _AT_GPS_FINISH:
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            
            _moden.AT_state = _AT_MQTT_TX_UP_DATA1_FINISH;
            
            break;   
            
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        case _AT_MQTT_TX_UP_DATA1_CMD:
            {
                uint32_t lens;
                char tmp_lte[100];       
                memset(buffer,0,sizeof(buffer));
                sprintf((char *)buffer,(const char *)"AT+UMQTTC=2,0,0,0, \"EMOTO/DEV/");
                lens = strlen((const char *)buffer);
                //memcpy(_moden.moden_uuid_md5,"9C490D32BB20833601820E1A7298CE22",sizeof(_moden.moden_uuid_md5));
                memcpy(&buffer[lens],_moden.moden_uuid_md5,sizeof(_moden.moden_uuid_md5));
                sprintf((char *)tmp_lte,(const char *)"/UP\",\"");  
                strcat((char *)buffer,tmp_lte);
                strcat((char *)buffer,(char *)_moden.lte_4G_TX_data);
                
                /*
                memset(buffer,0,sizeof(buffer));
                sprintf((char *)buffer,(const char *)"AT+UMQTTC=2,0,0,0, \"EMOTO/DEV/");
                lens = strlen((const char *)buffer);
                //memcpy(_moden.moden_uuid_md5,"9C490D32BB20833601820E1A7298CE22",sizeof(_moden.moden_uuid_md5));
                memcpy(&buffer[lens],_moden.moden_uuid_md5,sizeof(_moden.moden_uuid_md5));
                sprintf((char *)tmp_lte,(const char *)"/UP\",\"{\"LINKCMD\":");                
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)_moden.lte_4G_TX_data,(const char *)"Williamwangtest");  
                strcat((char *)buffer,(char *)_moden.lte_4G_TX_data);
                sprintf((char *)tmp_lte,(const char *)"}\"\r\n");
                strcat((char *)buffer,tmp_lte);
                */
                /*
                memset(buffer,0,sizeof(buffer));
                sprintf((char *)buffer,(const char *)"AT+UMQTTC=2,0,0,0, \"EMOTO/DEV/");
                lens = strlen((const char *)buffer);
                memcpy(&buffer[lens],_moden.moden_uuid_md5,sizeof(_moden.moden_uuid_md5));
                sprintf((char *)tmp_lte,(const char *)"/UP\",\"{'PCBUUID':'"); 
                strcat((char *)buffer,tmp_lte);
                lens = strlen((const char *)buffer);
                memcpy(&buffer[lens],_moden.moden_uuid_md5,sizeof(_moden.moden_uuid_md5));
                sprintf((char *)tmp_lte,(const char *)"','STIME': '2020-04-08:05:23:00',"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)"'LINKCMD': 'DEVPING',"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)"'BASIC': {"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)" 'MOTOVER': 'V0.1',"); 
                strcat((char *)buffer,tmp_lte); 
                sprintf((char *)tmp_lte,(const char *)"'IOTVER': 'V0.1',"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)"'DEVSTU': '00',"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)"'LOCKSTU': '00',"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)"'BKPOW': '5',"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)"'GPSPOS': '25.0798298,121.5721021',"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)" 'MOTOECU':{"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)"'SP001':'100'"); 
                strcat((char *)buffer,tmp_lte);
                sprintf((char *)tmp_lte,(const char *)"}}}\"\r\n"); 
                strcat((char *)buffer,tmp_lte);
                */                
            }
            SERCOM1_USART_Write((uint8_t*)buffer, strlen((char *)buffer));
            at_MQTT_TX_UP_DATA1_state_bak = _AT_MQTT_TX_UP_DATA1_CMD;
            _moden.AT_state = _AT_MQTT_TX_UP_DATA1_SENDING;
            //_moden_cmd_data.state = COMMAND_SENDING;
            at_MQTT_TX_UP_DATA1_tick = timer1ms;       
            
             #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)buffer, strlen(buffer));                  
            #endif
            break;
            
        case _AT_MQTT_TX_UP_DATA1_SENDING:
            
            if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                _moden_cmd_data.state = COMMAND_OK;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;
            }
            else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                _moden_cmd_data.state = COMMAND_ERROR;
                memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                memset(rxBuffer,0,sizeof(rxBuffer));     
                nBytesRead = 0;       
            }    
            
            if(_moden_cmd_data.state == COMMAND_OK){
                _moden.AT_state = _AT_MQTT_TX_UP_DATA1_OK;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            else if(_moden_cmd_data.state == COMMAND_ERROR){
                _moden.AT_state = _AT_MQTT_TX_UP_DATA1_ERROR;
                //_moden_cmd_data.state = COMMAND_NONE;
            }
            //timeout
            else if((timer1ms-at_MQTT_TX_UP_DATA1_tick)>AT_MQTT_TX_UP_DATA1_TIMEOUT_MS){
                
                _moden.lte_4G_TX_error_count++;
                _moden.AT_state = _AT_MQTT_TX_UP_DATA1_FINISH;
                
                _moden_cmd_data.state = COMMAND_NONE;
                
                #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_AT_MQTT_TX_UP_DATA1  Error_timeout\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t *)platformrxbuffer,strlen((char *)platformrxbuffer));
                #endif

                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            }                
            break;
        case _AT_MQTT_TX_UP_DATA1_OK:            
            
            _moden.lte_4G_TX_error_count = 0;
            
            #ifdef AT_UART_DEBUG_ON
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif
            
            if(at_MQTT_TX_UP_DATA1_state_bak != _AT_MQTT_TX_UP_DATA1_CMD)
                _moden.AT_state = at_MQTT_TX_UP_DATA1_state_bak+1;
            else{               
                _moden.AT_state = _AT_MQTT_TX_UP_DATA1_FINISH;               
            }
            
            memset(platformrxbuffer,0,sizeof(platformrxbuffer));    
                
            _moden_cmd_data.state = COMMAND_NONE;
            break;
        case _AT_MQTT_TX_UP_DATA1_ERROR:
            
            _moden.lte_4G_TX_error_count++;
            _moden.AT_state = _AT_MQTT_TX_UP_DATA1_FINISH;
            
            _moden_cmd_data.state = COMMAND_NONE;
            
            #ifdef AT_UART_DEBUG_ON
                sprintf(tmp,"_MQTT_TX_UP_DATA1  Error_meg\r\n");       
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                sprintf(tmp,"tx_ERROR:"); 
                strcat(tmp,buffer);
                uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
            #endif            

            memset(platformrxbuffer,0,sizeof(platformrxbuffer));
            break;
            
            
        case _AT_MQTT_TX_UP_DATA1_FINISH:            
                        
            _moden_cmd_data.state = COMMAND_NONE;            
            break;   
            
        
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        default:
            break;
    }
    
    if((readmodenstatue()== moden_ready) && (_moden.AT_state == _AT_MQTT_TX_UP_DATA1_FINISH)){
        
        switch(_moden.AT_READ_state){
            case _AT_RAED_LISTEN_CMD:
                {
                    char *adr1;
                    char *adr2;
                    
                    adr1 = strstr((const char *)rxBuffer,(const char *)"+UUMQTTC: 6,");
                    adr1 += strlen("+UUMQTTC: 6,");
                    adr2 = strstr((const char *)adr1,(const char *)"\r\n");
                    if(adr2 != 0){
                        _moden.lte_4G_RX_count = atoi((const char *)adr1);
                        _moden.AT_READ_state = _AT_RAED_ACTION_CMD;
                    }
                }
                
                break;
                
            case _AT_RAED_ACTION_CMD:
                sprintf(buffer,"AT+UMQTTC=6\r\n");
                SERCOM1_USART_Write((uint8_t*)buffer, strlen(buffer));
                at_RAED_state_bak = _AT_RAED_ACTION_CMD;
                _moden.AT_READ_state = _AT_READ_SENDING;
                //_moden_cmd_data.state = COMMAND_SENDING;
                at_READ_tick = timer1ms;
                
                #ifdef AT_UART_DEBUG_ON
                    uart_debug_megssage((uint8_t*)buffer, strlen(buffer));
                #endif
                
                break;
                
            case _AT_READ_SENDING:
                
                if(strstr((const char *)rxBuffer,(const char *)"OK\r\n") != 0){
                    _moden_cmd_data.state = COMMAND_OK;
                    memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                    memset(rxBuffer,0,sizeof(rxBuffer));
                    nBytesRead = 0;
                }
                else if(strstr((const char *)rxBuffer,(const char *)"ERROR\r\n") != 0){
                    _moden_cmd_data.state = COMMAND_ERROR;
                    memcpy(platformrxbuffer,rxBuffer,strlen((const char *)rxBuffer));
                    memset(rxBuffer,0,sizeof(rxBuffer));
                    nBytesRead = 0;
                }
                
                if(_moden_cmd_data.state == COMMAND_OK){
                    _moden.AT_READ_state = _AT_READ_OK;
                    //_moden_cmd_data.state = COMMAND_NONE;
                }
                else if(_moden_cmd_data.state == COMMAND_ERROR){
                    _moden.AT_READ_state = _AT_READ_ERROR;
                    //_moden_cmd_data.state = COMMAND_NONE;
                }
                //timeout
                else if((timer1ms-at_READ_tick)>AT_READ_TIMEOUT_MS){
                
                    _moden_cmd_data.state = COMMAND_NONE;
                    
                    _moden.lte_4G_RX_error_count++;
                    _moden.AT_READ_state = _AT_RAED_LISTEN_CMD;
                    
                    #ifdef AT_UART_DEBUG_ON
                    sprintf(tmp,"_AT_READ  Error_timeout\r\n");
                    uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                    sprintf(tmp,"tx_ERROR:");
                    strcat(tmp,buffer);
                    uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                    uart_debug_megssage((uint8_t *)platformrxbuffer,strlen((char *)platformrxbuffer));
                    #endif

                    memset(platformrxbuffer,0,sizeof(platformrxbuffer));
                }
                break;
                
            case _AT_READ_OK:
                {
                    char * adr1;
                    char * adr2;
                
                    adr1 = strstr((char *)platformrxbuffer,(char *)"/DOWN\",");
                    adr2 = strstr((char *)platformrxbuffer,(char *)"/PUB\",");
                    if((adr1 != 0) || (adr2 != 0)){
                        adr1 = strstr((char *)platformrxbuffer,(char *)",\"{");
                        adr1 += strlen(",\"{");
                        adr2 = strstr((char *)platformrxbuffer,(char *)"}\"\r\n");
                        memcpy(_moden.lte_4G_RX_data,adr1,adr2-adr1);
                        _moden.lte_4G_RX_flag = 1;
                        _moden.lte_4G_RX_error_count = 0;
                    }
                }
                
                #ifdef AT_UART_DEBUG_ON
                    {
                        char rx_data_tmp[512];
                                        
                        sprintf(rx_data_tmp,"RX DATA:");
                        strcat(rx_data_tmp,(const char *)_moden.lte_4G_RX_data);
                        strcat(rx_data_tmp,"\r\n");
                        uart_debug_megssage((uint8_t*)rx_data_tmp, strlen((char *)rx_data_tmp));
                    }
                #endif
            
                if(at_RAED_state_bak != _AT_RAED_ACTION_CMD)
                    _moden.AT_READ_state = at_RAED_state_bak+1;
                else{
                    _moden.lte_4G_RX_count--;
                    if(_moden.lte_4G_RX_count == 0)
                        _moden.AT_READ_state = _AT_RAED_LISTEN_CMD;
                    else
                        _moden.AT_READ_state = _AT_RAED_ACTION_CMD;
                }
            
                memset(platformrxbuffer,0,sizeof(platformrxbuffer));    
                
                _moden_cmd_data.state = COMMAND_NONE;
                break;
                
            case _AT_READ_ERROR:            
            
                _moden_cmd_data.state = COMMAND_NONE;
                _moden.lte_4G_RX_error_count++;
                _moden.AT_READ_state = _AT_RAED_LISTEN_CMD;
            
                #ifdef AT_UART_DEBUG_ON
                    sprintf(tmp,"_AT_READ  Error_meg\r\n");       
                    uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                    sprintf(tmp,"tx_ERROR:"); 
                    strcat(tmp,buffer);
                    uart_debug_megssage((uint8_t*)tmp, strlen(tmp));
                    uart_debug_megssage((uint8_t*)platformrxbuffer, strlen((char *)platformrxbuffer));
                #endif            
                
                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
                break;            
                
            case _AT_READ_FINISH:
                
                memset(platformrxbuffer,0,sizeof(platformrxbuffer));
                
                _moden_cmd_data.state = COMMAND_NONE;
                break;
            
            default:
                break;
        }
    }
}
