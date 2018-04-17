/**
  ******************************************************************************
  * @author  WuShihong
  * @version V1.0
  * @date    2016-03-27
  * @brief   
  ******************************************************************************
  * @attention
  *
  * πŸÕ¯    :http://www.cdebyte.com
  * Ã‘±¶    :http://yhmcu.taobao.com
  * ∞¢¿Ô∞Õ∞Õ:http://http://shop1399568656388.1688.com
  ******************************************************************************
  */ 
#ifndef __UART_H
#define	__UART_H

#include "stm32f0xx.h"
#include <stdio.h>




void USART_Configuration(void);
int fputc(int ch, FILE *f);
void UART_send_byte(uint8_t byte);
void UART_Send(uint8_t *Buffer, uint32_t Length);
uint8_t UART_Recive(void);

#endif /* __UART_H */
