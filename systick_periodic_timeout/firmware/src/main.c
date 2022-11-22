/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
//#include <stdio.h>
//
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "canapp.h"
#include "appuart.h"
#include "app_uart_debug.h"
#include "apptimer.h"
#include "moden.h"
#include "appiot.h"
#include "app.h"
#include "appemueeprom.h"

void timeout_handler(uintptr_t context)
{
    timer_update();	
    
    //debug
    //PORT_PinToggle(PORT_PIN_PA07);
}

void ClrWDT(void){
    WDT_Clear();
}

void enableWDT(void){
    WDT_Enable();
}
void disableWDT(void){
    WDT_Disable();
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    initmachinestates();
    init_moden();
    init_can();
    appurat_init();
    appurat_debug_init();
    init_iot();
    emnueeprom_init();
    
    SYSTICK_TimerCallbackSet(&timeout_handler, (uintptr_t) NULL);
    SYSTICK_TimerStart();
    
    SYSTICK_DelayMs(10000);

    while ( true )
    {   
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        //SYS_Tasks ( );
        
        ClrWDT();
        can_main();
        timer_main();
        moden_main();
        //iot_main();
        /*
        {
            uint8_t message[8];
            
            sprintf((char *)message,"55AA");
            CAN0_MessageTransmit (0x00000055, 4, message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);
            SYSTICK_DelayMs(100);
            //SYSTICK_DelayMs(100);
        }
        */
    /* Execution should not come here during normal operation */

    
    }
    return ( EXIT_FAILURE );
}
/*******************************************************************************
 End of File
*/

