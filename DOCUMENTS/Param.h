#ifndef __PARAM_H
#define __PARAM_H

//æÿ’Ûº¸≈Ã
#define OK 0xb
#define key_A 0xc
#define key_B 0xd
#define key_C 0xe
#define key_D 0xf

//Angle
#define AC_Set               10
#define AC_Out_MAX           18000//25000

#define Kalman_Sample_Time   0.005
#define AC_PID_P             360//360//1000//600//        520//500//
#define AC_PID_D             42//33//8//20//45//39//           42///38////55//45//6//

/* Speed */
#define VC_PID_P             45//72//120//               85//90//60//210//250//250//90//
#define VC_PID_I             0.2//0.1//1//2//2//   0.25
#define VC_PID_D             10//20//22//25//                   6//8//10//5//50//3//50//25
#define VC_Out_MAX           12000//25000
#define VC_PERIOD            4//4

/* Direction */
//#define DC_Out_MAX           15000//25000
#define DC_PERIOD            2//2

/* Motor */
#define MOTOR_OUT_MAX     7800
#define FIX_OUT           0

////NVIC
//#define  HREF_IRQ  PORTD_IRQn
//#define  VSYN_IRQ  PORTC_IRQn
//#define  TIMR_IRQ  PIT0_IRQn

//PIT
#define  PIT_CHL  HW_PIT_CH0
#define  PIT_PRD  5000

//Camera
#define  IMG_ABDN_ROW    50//33//50//47
#define  IMG_ROW_INTV    4
#define  IMG_READ_DELAY  114 //170 for 8 nops

//Image Proc Bit Map Relative
/* byte is 8 (2^3) bits */
#define  SHIFT  3
/* make the after-shifted bit no more than 1 << 0x07 */
//#define  MASK   0x07

#define  IMG_ROW    50
#define  IMG_COL    225
#define  WHITE_VAL  0
#define  IMG_WHITE  0xfe
#define  IMG_BLACK  0x00
#define  IMG_EOF    0xff

//Image Proc Flag
#define  STRAIGHT_ROAD  1
#define  CROSS_ROAD     2
#define  CIRCLE         3
#define  LEFTCURVE      4
#define  RIGHTCURVE     5
#define  RINGEND        6
#define  RAMP           7
#define  BARRIER        8

#define Left true
#define Right false

#endif
