//  PA0~PA3行控制线
//  PA4~PA7列控制线

#include "Delay.h"
#include "key_4x4.h"
#include "Param.h"

char channel = 'A';
u8 key_value ;

void Key_Init(void) 
{
    GPIO_InitTypeDef  GPIOStru;

    GPIOStru.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIOStru.GPIO_Speed = GPIO_Speed_50MHz;     
	GPIOStru.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;    
                                     	//define PE0-PE3 out-pp
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);     
	GPIO_Init(GPIOA,&GPIOStru);                         
	GPIOStru.GPIO_Mode = GPIO_Mode_IPU; //内部上拉，0为按下
	GPIOStru.GPIO_Speed = GPIO_Speed_50MHz;      
	GPIOStru.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7; 
	                                   //define PE4-PE7 xialashuru
	GPIO_Init(GPIOA,&GPIOStru);
	GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3); 

}
  
uint8_t keyscanf(void)
{
    uint8_t KeyValue=0x10;  

   if((GPIO_ReadInputData(GPIOA)&0xff)!=0xff) 
   {  
     delay_ms(10);  
     if((GPIO_ReadInputData(GPIOA)&0xff)!=0xff) 
      { 
        GPIO_ResetBits(GPIOA, GPIO_Pin_3);  
        GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_0); 
       switch(GPIO_ReadInputData(GPIOA)&0xff) 
      {  
       case 0x77: KeyValue = key_D; break; 
       case 0xb7: KeyValue = OK; break; 
       case 0xd7: KeyValue = 0; break; 
       case 0xe7: KeyValue = 0x0a;break; 
       }  

      GPIO_ResetBits(GPIOA, GPIO_Pin_2);  
      GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3); 
      switch(GPIO_ReadInputData(GPIOA)&0xff) 
      {  
       case 0x7b: KeyValue = key_C; break; 
       case 0xbb: KeyValue = 9; break; 
       case 0xdb: KeyValue = 8;break; 
       case 0xeb: KeyValue = 7;break; 
      }  

      GPIO_ResetBits(GPIOA, GPIO_Pin_1);  
      GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3); 
       switch(GPIO_ReadInputData(GPIOA)&0xff) 
      {  
       case 0x7d: KeyValue = key_B; break; 
       case 0xbd: KeyValue = 6; break; 
       case 0xdd: KeyValue = 5;break; 
       case 0xed: KeyValue = 4;break; 
      }  

      GPIO_ResetBits(GPIOA, GPIO_Pin_0);  
      GPIO_SetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_1 | GPIO_Pin_2); 
      switch(GPIO_ReadInputData(GPIOA)&0xff) 
      {  
       case 0x7e: KeyValue = key_A; break; 
       case 0xbe: KeyValue = 3; break; 
       case 0xde: KeyValue = 2;break; 
       case 0xee: KeyValue = 1;break; 
      }  

        GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3); //准备下一次扫描
     while((GPIO_ReadInputData(GPIOA)&0xff)!=0xf0);
      }
		}
	return KeyValue; 
}

