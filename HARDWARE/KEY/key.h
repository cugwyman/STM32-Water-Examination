#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
#include "delay.h"
#include "stdio.h"
#include "usart.h"
#include "Typedef.h"
#include "Param.h"
#include "Config.h"

#define KEY_PRESSED 1  //根据上下拉电阻不同而变
#define KEY_UNPRESS	0  //根据上下拉电阻不同而变

extern uint8_t Item;
extern uint8_t Param;
extern mode MODE;

void Key_IO_Init(void);
void KeyScan(void);

#endif
