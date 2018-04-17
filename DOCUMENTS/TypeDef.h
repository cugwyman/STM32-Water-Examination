#ifndef _TYPEDEF_H
#define _TYPEDEF_H

#include <stdint.h>

//#define SPEED_BUF_SIZE 5

////typedef struct _PID {
////    int16_t currentValue;
////    int16_t valueBuf[SPEED_BUF_SIZE];
////    uint8_t cursor;
////    int16_t targetValue;
////    double kp;
////    double ki;
////    double kd;
////    int16_t lastError;
////    int16_t prevError;
////    int16_t sumError;
////    double output;
////}
////PID;

//typedef uint8_t byte;

//#define NUMBER_OF_MODES 16

//typedef void (*mode_type)(void);
//typedef mode_type mode_type_array[NUMBER_OF_MODES];

//#define NUMBER_OF_IMG_PROC IMG_ROW_INTV

//typedef void (*img_proc_type)(void);
//typedef img_proc_type img_proc_type_array[NUMBER_OF_IMG_PROC];

//typedef struct _img_proc_struct {
//    int16_t leftBorder[IMG_ROW];
//    int16_t rightBorder[IMG_ROW];
//    int16_t middleLine[IMG_ROW];
//    bool foundLeftBorder[IMG_ROW];
//    bool foundRightBorder[IMG_ROW];
//    int16_t leftSlope[IMG_ROW];
//    int16_t leftZero[IMG_ROW];
//    int16_t rightSlope[IMG_ROW];
//    int16_t rightZero[IMG_ROW];
//    int16_t middleSlope[IMG_ROW];
//    int16_t middleZero[IMG_ROW];
//    int16_t leftTrend[IMG_ROW];
//    int16_t rightTrend[IMG_ROW];
//    uint16_t imgProcFlag;
//    int16_t leftBorderNotFoundCnt;
//    int16_t rightBorderNotFoundCnt;
//}
//img_proc_struct;

//enum _road_type {
//    Unknown,
//    Ring,
//    RingEnd,
//    LeftCurve,
//    RightCurve,
//    CrossRoad,
//    LeftBarrier,
//    RightBarrier
//};

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
