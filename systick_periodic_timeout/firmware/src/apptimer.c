#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "apptimer.h"
#include "appiot.h"
#include "config/sam_c21n_xpro/peripheral/systick/plib_systick.h"
#include "canapp.h"
#define standbytime 3//3000mS
TIMER_DATA _timer;  
volatile uint32_t timer1ms=0,timer10ms=0,timer100ms=0,timer1000ms=0;
uint32_t timermqttupload;
void timer_update(void){
    timer1ms++;
    timer10ms++;
    timer100ms++;
    timer1000ms++;
    timermqttupload++;
}
uint32_t readsystick(void){
    return timer1ms;
}
void init_timer(void){
    timer1ms=0;
    timer10ms=0;
    timer100ms=0;
    timer1000ms=0;
    timermqttupload=0;
    _timer.state = timer_off;
}
void timer_main(void){
    if(_timer.state != timer_on){
        _timer.state = timer_on;
        //init_timer();
        //SYSTICK_TimerCallbackSet(&timer_update, (uintptr_t)NULL);
    }
    else{
        if(timer1000ms >1000){
            timer1000ms = 0;
            inccanbussleeptimer();
            if(readcanbussleeptimer()>standbytime){//can bus no data 3000mS
                set_canstatenew (CAN_Satndby);
            }
            calculateODO();
        }
        if(timer100ms>100){
            timer100ms =0;
            incmqtttimer();
        }
        if(timer10ms>10){
            timer10ms =0;
        }
        
    }
}

 uint32_t platform_get_time_ms(void){
     return timer1ms;
 }


