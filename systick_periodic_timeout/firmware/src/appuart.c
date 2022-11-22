/************************************


*************************************/
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes
#include "moden.h"
#include "appuart.h"
#include "app_uart_debug.h"
char buffer[UART_TX_RX_SIZE];
uint8_t rxBuffer[UART_TX_RX_SIZE];
uint8_t platformrxbuffer[UART_TX_RX_SIZE];
volatile uint32_t nBytesRead = 0;
void usartReadEventHandler(SERCOM_USART_EVENT event, uintptr_t context )
{
    uint32_t nBytesAvailable = 0;
   
    if (event == SERCOM_USART_EVENT_READ_THRESHOLD_REACHED)
    {
        /* Receiver should atleast have the thershold number of bytes in the ring buffer */
        nBytesAvailable = SERCOM1_USART_ReadCountGet();
        
        SERCOM1_USART_Read((uint8_t*)&rxBuffer[nBytesRead], nBytesAvailable);                          
    }
    nBytesRead += nBytesAvailable;    
}

void usartWriteEventHandler(SERCOM_USART_EVENT event, uintptr_t context )
{
    static uint16_t count=0;
    
    count++;    
    if(count>=strlen(buffer)){
        count = 0;
        
        _moden_cmd_data.state = COMMAND_SENDING;
    }   
}
 
void appurat_init ( void )
{
    SERCOM1_USART_WriteCallbackRegister(usartWriteEventHandler, (uintptr_t) NULL);
    SERCOM1_USART_ReadCallbackRegister(usartReadEventHandler, (uintptr_t) NULL);
    
    /*
    {
        uint8_t tmp[10];
        //uint32_t test=0;
    
        memset(tmp,0x55,sizeof(tmp));
        SERCOM1_USART_Write(tmp,1);    
        
        
        SERCOM1_USART_Write(tmp,1);
        
        
        
        SERCOM1_USART_Write(tmp,1);
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
