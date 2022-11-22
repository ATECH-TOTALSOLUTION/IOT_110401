#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "apptimer.h"
#include "appiot.h"
#include "config/sam_c21n_xpro/peripheral/systick/plib_systick.h"
#include "canapp.h"
#define standbytime 3//3000mS
 
volatile uint32_t timer1ms=0,time_1ms_bak=0,time_100ms=0,time_event=0,time_full=0xFFFF,time_1s_count=0;
volatile uint32_t timermqttupload=0;
void timer_update(void){
    
    timer1ms++;
    time_100ms++;
    time_1s_count++;
    time_event = timer1ms ^ time_1ms_bak;
    time_1ms_bak = timer1ms;   
    timermqttupload++;
}
uint32_t readsystick(void){
    return timer1ms;
}

void timer_main(void){
    {
        
        if(time_event & time_1ms_event){
            time_event &= ~(time_full&time_1ms_event);
        }
        
        if(time_event & time_2ms_event){
            time_event &= ~(time_full&time_2ms_event);
        }
        
        if(time_event & time_4ms_event){
            time_event &= ~(time_full&time_4ms_event);
        }
        
        if(time_event & time_8ms_event){
            time_event &= ~(time_full&time_8ms_event);
        }
        
        if(time_event & time_16ms_event){
            time_event &= ~(time_full&time_16ms_event);
        }
        
        if(time_event & time_32ms_event){
            time_event &= ~(time_full&time_32ms_event);
        }
        
        if(time_event & time_64ms_event){
            time_event &= ~(time_full&time_64ms_event);
        }
        
        if(time_100ms >= 100){
            time_100ms = 0;
            incmqtttimer();
        }
        
        if(time_event & time_128ms_event){
            time_event &= ~(time_full&time_128ms_event);
        }
        
        if(time_event & time_256ms_event){
            time_event &= ~(time_full&time_256ms_event);
        }
        
        if(time_event & time_512ms_event){
            time_event &= ~(time_full&time_512ms_event);
        }
        
        if(time_event & time_1024ms_event){
            time_event &= ~(time_full&time_1024ms_event);
        }
        
        if(time_1s_count >= 1000){
            time_1s_count = 0;
            
            inccanbussleeptimer();
            if(readcanbussleeptimer()>standbytime){//can bus no data 3000mS
                set_canstatenew (CAN_Satndby);
            }
            calculateODO();
        }
    }
}
