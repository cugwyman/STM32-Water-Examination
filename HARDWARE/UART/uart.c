/**
  ******************************************************************************
  * @author  WuShihong
  * @version V1.0
  * @date    2016-03-27
  * @brief   
  ******************************************************************************
  * @attention
  *
  * 官网    :http://www.cdebyte.com
  * 淘宝    :http://yhmcu.taobao.com
  * 阿里巴巴:http://http://shop1399568656388.1688.com
  ******************************************************************************
  */ 
#include "uart.h"
#include <stdarg.h>
#include <stdio.h>

/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
  
/* Private functions ---------------------------------------------------------*/

void USART_Configuration(void)//串口初始化函数
  {  

        GPIO_InitTypeDef  GPIO_InitStructure;
        USART_InitTypeDef USART_InitStructure;
                
        RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE );
                
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_1);
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_1);        
        /*
        *  USART1_TX -> PA9 , USART1_RX ->        PA10
        */                                
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;                 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
        GPIO_Init(GPIOA, &GPIO_InitStructure);        
        
        USART_InitStructure.USART_BaudRate = 9600;//设置串口波特率
        USART_InitStructure.USART_WordLength = USART_WordLength_8b;//设置数据位
        USART_InitStructure.USART_StopBits = USART_StopBits_1;//设置停止位
        USART_InitStructure.USART_Parity = USART_Parity_No;//设置效验位
        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//设置流控制
        USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//设置工作模式
        USART_Init(USART1, &USART_InitStructure); //配置入结构体

        USART_Cmd(USART1, ENABLE);//使能串口1

		}			

void UART_send_byte(uint8_t byte) //发送1字节数据
{
 while(!((USART1->ISR)&(1<<7)));
 USART1->TDR=byte;	
}		

void UART_Send(uint8_t *Buffer, uint32_t Length)
{
	while(Length != 0)
	{
		while(!((USART1->ISR)&(1<<7)));//等待发送完
		USART1->TDR= *Buffer;
		Buffer++;
		Length--;
	}
}

uint8_t UART_Recive(void)
{	
	while(!(USART1->ISR & (1<<5)));//等待接收到数据
	return(USART1->RDR);			 //读出数据
}


//PUTCHAR_PROTOTYPE 
//{
///* 将Printf内容发往串口 */
//  USART_SendData(USART1,(uint8_t)  ch);
//  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
//	{}
// 
//  return (ch);
//}
		
/************************************************************** 
* 函数名  : fputc()
* 描述    : 重定义putc函数，这样可以使用printf函数从串口1打印输出
* 输入    : None
* 输出    : None
* 返回    : None
* 作者    : 青风
* 创建日期: 2014.1.1
* 版本    : V1.00
*************************************************************/
int fputc(int ch, FILE *f)
{
		/* Place your implementation of fputc here */
		/* 发送一个字节的数据 */
		USART_SendData(USART1, (uint8_t) ch);
		/* 等待发送完成 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
		return ch;
}

/************************************************************** 
* 函数名  : fputc()
* 描述    : 重定义putc函数，这样可以使用printf函数从串口1获取数据
* 输入    : None
* 输出    : None
* 返回    : None
* 作者    : 青风
* 创建日期: 2014.1.1
* 版本    : V1.00
*************************************************************/
int fgetc(FILE *f)
{
		/* 等待串口1输入数据 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
		/* 返回接收到的数据 */
		return (int)USART_ReceiveData(USART1);
}
