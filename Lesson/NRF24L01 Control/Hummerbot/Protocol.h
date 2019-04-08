#ifndef  _PROTOCOL_H_
#define  _PROTOCOL_H_
#include  "Arduino.h"

#define PROTOCOL_START_CODE 0xAA
#define PROTOCOL_END_CODE   0x55

typedef enum
{
    E_BATTERY = 1,
    E_LED,
    E_BUZZER,
    E_INFO,
    E_ROBOT_CONTROL_DIRECTION,
    E_ROBOT_CONTROL_SPEED,
    E_TEMPERATURE,
    E_INFRARED_TRACKING,
    E_ULTRASONIC,
    E_INFRARED_REMOTE,
    E_VERSION,
    E_UPGRADE,
} E_CONTOROL_FUNC;

typedef enum
{
    E_SMARTCAR = 0,
    E_HUMMER_BOT,
    E_AURORA_RACING,
    E_BALANCE_CAR,
    E_OTTO,
    E_EBOT,
    E_QUADCOPTER,
    E_TYPE_MAX,
} E_TYPE;

typedef struct
{
    unsigned short int degree;
    byte speed;
} ST_CONTROL_CODE;

typedef struct
{
    byte start_code ;   // 8bit 0xAA
    byte len;           // protocol data length
    E_TYPE type;
    byte addr;
    byte function;      // 8 bit
    byte *data;         // n bit
    uint16_t sum;       // check sum 16bit
    byte end_code;      // 8bit 0x55
} ST_PROTOCOL;

#endif // _PROTOCOL_H_
