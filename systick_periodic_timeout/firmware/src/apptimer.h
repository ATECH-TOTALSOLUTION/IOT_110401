/* 
 * File:   apptimer.h
 * Author: Eric
 *
 * Created on 2022?10?11?, ?? 4:11
 */

#ifndef APPTIMER_H
#define	APPTIMER_H

#ifdef	__cplusplus
extern "C" {
#endif
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

typedef enum
{
    timer_off = 0,
    timer_on,
    
} TIMER_STATES;
typedef struct
{
   TIMER_STATES state;

} TIMER_DATA;
extern TIMER_DATA _timer;  
extern uint32_t timer1ms,timer10ms,timer100ms,timer1000ms;
void timer_update(void);
void init_timer(void);
void timer_main(void);
uint32_t readsystick(void);
 uint32_t platform_get_time_ms(void);



#ifdef	__cplusplus
}
#endif

#endif	/* APPTIMER_H */

