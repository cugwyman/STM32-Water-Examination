/**
  ******************************************************************************
  * @author  WuShihong
  * @version V1.0
  * @date    2016-03-27
  * @brief   
  ******************************************************************************
  * @attention
  *
  * ����    :http://www.cdebyte.com
  * �Ա�    :http://yhmcu.taobao.com
  * ����Ͱ�:http://http://shop1399568656388.1688.com
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

void USART_Configuration(void)//���ڳ�ʼ������
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
        
        USART_InitStructure.USART_BaudRate = 9600;//���ô��ڲ�����
        USART_InitStructure.USART_WordLength = USART_WordLength_8b;//��������λ
        USART_InitStructure.USART_StopBits = USART_StopBits_1;//����ֹͣλ
        USART_InitStructure.USART_Parity = USART_Parity_No;//����Ч��λ
        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//����������
        USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//���ù���ģʽ
        USART_Init(USART1, &USART_InitStructure); //������ṹ��

        USART_Cmd(USART1, ENABLE);//ʹ�ܴ���1

		}			

void UART_send_byte(uint8_t byte) //����1�ֽ�����
{
 while(!((USART1->ISR)&(1<<7)));
 USART1->TDR=byte;	
}		

void UART_Send(uint8_t *Buffer, uint32_t Length)
{
	while(Length != 0)
	{
		while(!((USART1->ISR)&(1<<7)));//�ȴ�������
		USART1->TDR= *Buffer;
		Buffer++;
		Length--;
	}
}

uint8_t UART_Recive(void)
{	
	while(!(USART1->ISR & (1<<5)));//�ȴ����յ�����
	return(USART1->RDR);			 //��������
}


//PUTCHAR_PROTOTYPE 
//{
///* ��Printf���ݷ������� */
//  USART_SendData(USART1,(uint8_t)  ch);
//  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
//	{}
// 
//  return (ch);
//}
		
/************************************************************** 
* ������  : fputc()
* ����    : �ض���putc��������������ʹ��printf�����Ӵ���1��ӡ���
* ����    : None
* ���    : None
* ����    : None
* ����    : ���
* ��������: 2014.1.1
* �汾    : V1.00
*************************************************************/
int fputc(int ch, FILE *f)
{
		/* Place your implementation of fputc here */
		/* ����һ���ֽڵ����� */
		USART_SendData(USART1, (uint8_t) ch);
		/* �ȴ�������� */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
		return ch;
}

/************************************************************** 
* ������  : fputc()
* ����    : �ض���putc��������������ʹ��printf�����Ӵ���1��ȡ����
* ����    : None
* ���    : None
* ����    : None
* ����    : ���
* ��������: 2014.1.1
* �汾    : V1.00
*************************************************************/
int fgetc(FILE *f)
{
		/* �ȴ�����1�������� */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
		/* ���ؽ��յ������� */
		return (int)USART_ReceiveData(USART1);
}
