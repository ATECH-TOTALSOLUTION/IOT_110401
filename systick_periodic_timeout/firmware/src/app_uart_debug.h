#ifndef appuart_debug_H 
#define appuart_debug_H

#ifdef __cplusplus 

    extern "C" {

#endif

void usart_debug_ReadEventHandler(SERCOM_USART_EVENT event, uintptr_t context );
void usart_debug_WriteEventHandler(SERCOM_USART_EVENT event, uintptr_t context );

void uart_debug_megssage(uint8_t * data,uint16_t lens);

#ifdef __cplusplus  

    }

#endif


#endif 