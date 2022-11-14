#ifndef appuart_H 
#define appuart_H

#ifdef __cplusplus 

    extern "C" {

#endif

typedef struct{
    uint8_t commandbuffer[1024];
} commanddata;

typedef struct{
    uint8_t atrcbufindex;
    uint8_t atrcbufhead;
    uint8_t atrcbufpost;
     commanddata atrcbuf[3];
 
}ATCOMMAND;
extern ATCOMMAND _atcomd;
/*
typedef struct{
    uint8_t rxbuflength;
    uint8_t mottrxbuffer[1024];
 
}MQTTTX;
extern MQTTTX _mqttrx[3];
*/
void usartReadEventHandler(SERCOM_USART_EVENT event, uintptr_t context );
void usartWriteEventHandler(SERCOM_USART_EVENT event, uintptr_t context );
void appurat_init ( void );
void appurat_debug_init ( void );
void app_uartmain(void);
void  uart_read(uint8_t size,uint8_t* buffer);
uint8_t platform_uart_read(uint8_t* );
int32_t platform_uart_write(uint8_t* data, uint16_t len);

extern uint8_t txBuffer[UART_TX_RX_SIZE];
extern uint8_t rxBuffer[UART_TX_RX_SIZE];
extern uint8_t platformrxbuffer[UART_TX_RX_SIZE];
extern volatile uint32_t nBytesRead;

void ClearRxatcommandbuffer(void);
#ifdef __cplusplus  

    }

#endif


#endif 