/* 
 * File:   iot_msg.h
 * Author: Eric
 *
 * Created on 2022?10?21?, ?? 5:50
 */

#ifndef IOT_MSG_H
#define	IOT_MSG_H
/**
 * @file iot_msg.h
 * @author Xavier Yin
 * @brief Implement Emoto_iot_MQTT_deviotboard_specv1_7_20210813.pdf
 * @version 0.1
 * @date 2021-10-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef IOT_MSG_H__
#define IOT_MSG_H__

#include "stdint.h"

#define MQTT_TOPIC_MAX_LEN  (128)
#define MQTT_MSG_MAX_LEN    (512)

#define UUID_LEN            (18)                    // "8thE00010000000001"
#define STATION_SN_LEN      (18)                    // "8thD00010000000001"
#define STIME_FORMAT        "%Y-%m-%d %H:%M:%S"     // "2020-04-08 05:23:00"
#define STIME_LEN           (19)                    // "2020-04-08 05:23:00"
#define DEVSN_LEN           UUID_LEN                // same thing as UUID
#define CSSN_LEN            (9)                     // "123456789" 
#define GPSPOS_LEN          (24)                    // "-25.0798298,-121.5721021"
#define MOTORVER_LEN        (8)
#define IOTVER_LEN          (8)
#define LCSN_LEN            (8)
#define LCSN_COUNT          (2)

#define TIME_TOLERANCE_SEC  (10)


typedef enum
{
    MQTT_TOPIC_UP = 0,
    MQTT_TOPIC_DOWN,
    MQTT_TOPIC_PUB,
} mqtt_topic_e;

typedef enum
{
    IOT_MSG_TYPE_DOWN_DEVLOGIN = 0,
    IOT_MSG_TYPE_DOWN_DEVLOGOUT,
    IOT_MSG_TYPE_DOWN_DEVCHKLIST,
    IOT_MSG_TYPE_DOWN_DEVLOCK,
    IOT_MSG_TYPE_DOWN_DEVUNLOCK,
    IOT_MSG_TYPE_UP_DEVPING,
    IOT_MSG_TYPE_UP_DEVCHKLIST,
    IOT_MSG_TYPE_UP_DEVSTDEVLEASE,
    IOT_MSG_TYPE_UP_DEVENDDEVLEASE,
    IOT_MSG_TYPE_UP_DEVUNLOCKOK,
    IOT_MSG_TYPE_UP_DEVUNLOCKFAIL,
    IOT_MSG_TYPE_UP_DEVLOCKOK,
    IOT_MSG_TYPE_UP_DEVLOCKFAIL,
    IOT_MSG_TYPE_PUB_DEVCHKLIST,

    IOT_MSG_TYPE_COUNT
} iot_msg_type_e;
#define IOT_MSG_TYPE_INVALID        IOT_MSG_TYPE_COUNT
#define IOT_MSG_TYPE_UP_START       IOT_MSG_TYPE_UP_DEVPING
#define IOT_MSG_TYPE_UP_END         IOT_MSG_TYPE_UP_DEVLOCKFAIL
#define IS_VALID_UP_MSG_TYPE(_type) (((_type) >= IOT_MSG_TYPE_UP_START) && ((_type) <= IOT_MSG_TYPE_UP_END))

typedef enum
{
    DEVSTU_IN_STOCK = 0,
    DEVSTU_READY,
    DEVSTU_ACTIVE,
    DEVSTU_SNOOZING,

    DEVSTU_SCRAPPED = 10,
    DEVSTU_UNDER_MAINTAINENCE = 20,
    DEVSTU_FAILED = 21,
} iot_devstu_e;


typedef struct string_obj_s
{
    char*       p;
    uint32_t    len;
} string_obj_t;

typedef struct stationsn_s
{
    char        data[STATION_SN_LEN + 1];
} stationsn_t;

typedef struct uuid_s
{
    char        data[UUID_LEN + 1];
} uuid_t;

typedef struct devsn_s
{
    char        data[DEVSN_LEN + 1];
} devsn_t;

typedef struct cssn_s
{
    char        data[CSSN_LEN + 1];
} cssn_t;

typedef struct motorver_s
{
    char        data[MOTORVER_LEN + 1];
} motorver_t;

typedef struct iotver_s
{
    char        data[IOTVER_LEN + 1];
} iotver_t;

typedef struct lcsn_s
{
    char        data[LCSN_LEN + 1];
} lcsn_t;

typedef struct down_devlogin_s
{
    stationsn_t stationsn;
} down_devlogin_t;

typedef struct down_devlogout_s
{
    stationsn_t stationsn;
} down_devlogout_t;

typedef struct down_devchklist_s
{

} down_devchklist_t;

typedef struct down_devlock_s
{
    cssn_t      cssn;
} down_devlock_t;

typedef struct down_devunlock_s
{
    cssn_t      cssn;
} down_devunlock_t;

typedef struct up_devping_s
{
    uint8_t     devstu;
    uint8_t     lockstu;
    uint8_t     bkpow;
    double      latitude;
    double      longitude;
    // stationsn_t stationsn;
} up_devping_t;

typedef struct up_devlogin_s
{
    uint8_t     devstu;
    stationsn_t stationsn;
} up_devlogin_t;

typedef struct up_devlogout_s
{
    uint8_t     devstu;
    stationsn_t stationsn;
} up_devlogout_t;

typedef struct up_devchklist_s
{
    uint8_t     devstu;
    uint8_t     lockstu;
    uint8_t     bkpow;
    double      latitude;
    double      longitude;
    lcsn_t      lcsn[LCSN_COUNT];
    stationsn_t stationsn;
} up_devchklist_t;

typedef struct up_devstdevlease_s
{
    lcsn_t      lcsn[LCSN_COUNT];
    stationsn_t stationsn;
    double      latitude;
    double      longitude;
} up_devstdevlease_t;

typedef struct up_devenddevlease_s
{
    lcsn_t      lcsn[LCSN_COUNT];
    stationsn_t stationsn;
    double      latitude;
    double      longitude;
} up_devenddevlease_t;

typedef struct up_devunlockok_s
{
    cssn_t      cssn;
    lcsn_t      lcsn[LCSN_COUNT];
    stationsn_t stationsn;
    double      latitude;
    double      longitude;
} up_devunlockok_t;

typedef struct up_devunlockfail_s
{
    cssn_t      cssn;
    lcsn_t      lcsn[LCSN_COUNT];
    stationsn_t stationsn;
    double      latitude;
    double      longitude;
} up_devunlockfail_t;

typedef struct up_devlockok_s
{
    cssn_t      cssn;
    lcsn_t      lcsn[LCSN_COUNT];
    stationsn_t stationsn;
    double      latitude;
    double      longitude;
} up_devlockok_t;

typedef struct up_devlockfail_s
{
    cssn_t      cssn;
    lcsn_t      lcsn[LCSN_COUNT];
    stationsn_t stationsn;
    double      latitude;
    double      longitude;
} up_devlockfail_t;

typedef struct pub_devchklist_s
{

} pub_devchklist_t;

typedef union iot_msg_payload_s
{
    down_devlogin_t     down_devlogin;
    down_devlogout_t    down_devlogout;
    down_devchklist_t   down_devchklist;
    down_devlock_t      down_devlock;
    down_devunlock_t    down_devunlock;
    up_devping_t        up_devping;
    up_devchklist_t     up_devchklist;
    up_devstdevlease_t  up_devstdevlease;
    up_devenddevlease_t up_devenddevlease;
    up_devunlockok_t    up_devunlockok;
    up_devunlockfail_t  up_devunlockfail;
    up_devlockok_t      up_devlockok;
    up_devlockfail_t    up_devlockfail;
    pub_devchklist_t    pub_devchklist;
} iot_msg_payload_t;

typedef union iot_down_msg_payload_s
{
    down_devlogin_t     login;
    down_devlogout_t    logout;
    down_devchklist_t   chklist;
    down_devlock_t      lock;
    down_devunlock_t    unlock;
} iot_down_msg_payload_t;

typedef union iot_up_msg_payload_s
{
    up_devping_t        ping;
    up_devlogin_t       login;
    up_devlogout_t      logout;
    up_devchklist_t     chklist;
    up_devstdevlease_t  stdevlease;
    up_devenddevlease_t enddevlease;
    up_devunlockok_t    unlockok;
    up_devunlockfail_t  unlockfail;
    up_devlockok_t      lockok;
    up_devlockfail_t    lockfail;
} iot_up_msg_payload_t;

typedef struct mqtt_msg_s
{
    char*       topic;
    char*       msg;
    uint16_t    topic_len;
    uint16_t    msg_len;
} mqtt_msg_t;



#endif
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* IOT_MSG_H */

