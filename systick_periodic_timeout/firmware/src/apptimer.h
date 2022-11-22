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
    
#define time_1ms_event    0x0001
#define time_2ms_event    0x0002
#define time_4ms_event    0x0004
#define time_8ms_event    0x0008
#define time_16ms_event   0x0010
#define time_32ms_event   0x0020
#define time_64ms_event   0x0040
#define time_128ms_event  0x0080
#define time_256ms_event  0x0100
#define time_512ms_event  0x0200
#define time_1024ms_event 0x0400
//#define time_1s_event     0x8000

extern volatile uint32_t timer1ms,time_1ms_bak,time_100ms,time_event,time_full,time_1s_count;
extern volatile uint32_t timermqttupload;

void timer_update(void);
void timer_main(void);
uint32_t readsystick(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APPTIMER_H */
