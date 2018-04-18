#ifndef _TYPEDEF_H
#define _TYPEDEF_H

#include <stdint.h>

typedef struct PID_speed_mode {
    int16_t DC_PID_P_COEF;
    int16_t DC_P_MIN;
    int16_t DC_P_MAX;
    float DC_PID_D;
    int16_t DC_Out_MAX;
    
    int16_t VC_Set;
    int16_t pre_sight;
    float Ke;
    float Kec;
    float Ku;
    int8_t mid_angle;
    float pre_sight_offset;
    int8_t ring_offset;
    int8_t ring_end_offset;
}
mode;

#endif
