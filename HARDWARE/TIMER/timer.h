#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

extern u8 number_send_A[10];
extern u8 number_send_B[10];
extern u8 number_send_C[10];
extern u8 num_cnt_A;
extern u8 num_cnt_B;
extern u8 num_cnt_C;
extern u8 send_sign;
void TIMER_Init(u16 arr,u16 psc);
 
#endif
