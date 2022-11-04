/* 
 * File:   moden.h
 * Author: Eric
 *
 * Created on 2022?10?11?, ?? 3:38
 */

#ifndef MODEN_H
#define	MODEN_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#ifdef	__cplusplus
extern "C" {
#endif

#define _NONE_AT_CMD (0x0000)   
#define _AT_CMD      (0x0100)
#define _ATE0_CMD    (0x0101)
#define _AT_CLCK_CMD (0x0102)
#define _AT_CPIN_CMD (0x0103)
#define _AT_COPS_CMD (0x0104)
#define _AT_CSQ_CMD  (0x0105)
#define _AT_MODULE_CONNECT_SENDING (0x01FC)
#define _AT_MODULE_CONNECT_OK      (0x01FD)
#define _AT_MODULE_CONNECT_ERROR   (0x01FE)
#define _AT_MODULE_CONNECT_FINISH  (0x01FF)    
typedef enum
{
    COMMAND_NONE = 0,       //NO send command
    COMMAND_SENDING,        //wait respond
    COMMAND_OK,    
    COMMAND_ERROR,        
} COMMAND_STATES;
typedef struct
{
   COMMAND_STATES state;
   uint16_t ModenCommand;
   uint16_t RespondCommand;
   uint32_t CommandTumeoutTimer;
} MODEN_COMMAND_DATA;
extern MODEN_COMMAND_DATA _moden_cmd_data;
typedef enum
{
    moden_closed = 0, //can't send command
    moden_open,       //ready to send command
    moden_ready,     //ath0 ok    
    moden_connection_initial, //power on need to check moden,network mqtt 
} MODEN_STATES;

typedef struct
{
   MODEN_STATES state;
   MODEN_STATES moden_connection_state;
   MODEN_STATES moden_network_connection_state;
   MODEN_STATES moden_mqtt_connection_state;
   uint16_t AT_MODULE_CONNECT_state;

} MODEN_DATA;
extern MODEN_DATA _moden;
MODEN_STATES readmodenstatue(void);
void setmoden(MODEN_STATES );
void init_moden(void);
void setldoon(void);
void setldoff(void);
void resetiot(void);
void moden_main(void);

void SendATCOmmand(void);
#ifdef	__cplusplus
}
#endif

#endif	/* MODEN_H */

