/************************************


*************************************/
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes

#include "appuart.h"
uint8_t txBuffer[1024];
uint8_t rxBuffer[256];
uint8_t platformnBytesRead=0;
uint8_t platformrxbuffer[256];
ATCOMMAND _atcomd;
uint8_t atcomdindex=0;
volatile uint32_t nBytesRead = 0;
volatile bool txThresholdEventReceived = false;
volatile bool rxThresholdEventReceived = false;
uint32_t nBytes = 0;     
uint8_t mqtttxbufindex;
uint8_t uarttxbufferindex=0;
void usartReadEventHandler(SERCOM_USART_EVENT event, uintptr_t context )
{
    uint32_t nBytesAvailable = 0;
   
    if (event == SERCOM_USART_EVENT_READ_THRESHOLD_REACHED)
    {
        /* Receiver should atleast have the thershold number of bytes in the ring buffer */
        nBytesAvailable = SERCOM1_USART_ReadCountGet();
        
        nBytesRead += SERCOM1_USART_Read((uint8_t*)&rxBuffer[nBytesRead], nBytesAvailable);                          
    }
    uart_read(nBytesRead,(uint8_t *)rxBuffer);//[nBytesRead]);   
    nBytesRead=0;
}

void usartWriteEventHandler(SERCOM_USART_EVENT event, uintptr_t context )
{
    txThresholdEventReceived = true;
}
 
void appurat_init ( void )
{
    
    SERCOM1_USART_WriteCallbackRegister(usartWriteEventHandler, (uintptr_t) NULL);

    SERCOM1_USART_ReadCallbackRegister(usartReadEventHandler, (uintptr_t) NULL);              
   
//    SERCOM1_USART_Read((uint8_t*)rxBuffer, 1); 
//    SERCOM1_USART_Write((uint8_t*)rxBuffer, 1);
    //SERCOM1_USART_ReadThresholdSet(1);//SERCOM1_USART_ReadThresholdSet(5);
    
    /* Enable RX event notifications */
    //SERCOM1_USART_ReadNotificationEnable(true, false);
    uarttxbufferindex=0;
    ClearRxatcommandbuffer();
    
    /*
    {
        uint8_t tmp=0x55;
        uint32_t test=0;
    
        SERCOM1_USART_Write(&tmp,1);
        
        for(test=0;test<100000000;){
            test++;
        }
        
        SERCOM1_USART_Write(&tmp,1);
        SERCOM1_USART_Write(&tmp,1);
    }
    */
    /*
    while(1)
    {
        // Wait until at-least 10 characters are entered by the user 
        while (!nBytesRead );    
    
       //Echo the received data 
        SERCOM1_USART_Write((uint8_t*)rxBuffer, nBytesRead);
        
        SERCOM1_USART_Write((uint8_t*)"\r\n>", 3);

        nBytesRead = 0;
    }*/
}

void app_uartmain(void){
    
}
/***********************
 platformrxbuffer:to r5 lib 
 *************************/

void  uart_read(uint8_t size,uint8_t* buffer){
    uint8_t index;
   for(index=0;index<size;index++){
        platformrxbuffer[platformnBytesRead] = buffer[index];
        platformnBytesRead++;
    }
}

/**********************************
 r5 lib get rxd data
 ***********************************/
uint8_t platform_uart_read(uint8_t* buffer){
    uint8_t index,len;
     len = platformnBytesRead;
    for(index=0;index<platformnBytesRead;index++){
        buffer[index]=platformrxbuffer[index];
    }
   platformnBytesRead =0;
    return len;
 }

/*******************************************
 typedef struct{
   
    uint8_t atcommandlength;
    uint8_t atcommandbuffer[1024];
 
}ATCOMMAND;
extern ATCOMMAND _atcomd[3];
 
 r5 lib at command data
 ******************************************/
int32_t platform_uart_write(uint8_t* data, uint16_t len){
  
    int32_t result =1;
    _atcomd.atrcbufindex++;
    if(_atcomd.atrcbufindex <3){
         memcpy(_atcomd.atrcbuf[_atcomd.atrcbufhead].commandbuffer,data,len);
         _atcomd.atrcbufhead++;
         if(_atcomd.atrcbufhead>2){
              _atcomd.atrcbufhead=0;
         }
         result =0;
    }
      
   
   return result;
}

void ClearRxatcommandbuffer(void){
//    memset(_atcomd,0,(sizeof _atcomd));
    memset(_atcomd.atrcbuf,0,(sizeof _atcomd.atrcbuf));
    _atcomd.atrcbufhead=0;
    _atcomd.atrcbufpost=0;
     _atcomd.atrcbufindex=0;
    atcomdindex =0;
}

