#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "OLED.h"
#include "adc.h"
#include "ds18b20.h"

/**************************************
 *   
 *     STM32 Water Examination 
 *          水质检测 V0.99
 *     Date          2018.4.19
 *     CUG           Wyman    
 *     IDE           Keil MDK V5.23
 *     MCU           STM32F103ZET6
 *
 **************************************/
 	
int main(void)
{	 
//    uchar Receive_Buff[5];//接收数据缓冲区
//    uchar Receive_Count;
//    u16 Data_TDS;
	short temperature;    	   
    u16 adcx;
    u16 adcx2;
	float PH_temp;
	float TU_temp;
    u8 OLED_cnt = 0;
    
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	delay_init();	//延时初始化 
	uart3_init(9600);        //TDS	 	
    uart_init(9600);       //LoRa
    OLED_Init();        
 	Adc_Init();		  		//ADC初始化
 	Adc2_Init();
    DS18B20_Init();
    
    Temp[0]=6;
    Temp[1]=6;
    Temp[2]=6;
    Temp[3]=6;
    Temp[4]=6;
 	while(1)
	{
        adcx = Get_Adc_Average(ADC_Channel_1,10);
        adcx2 = Get_Adc_Average2(ADC_Channel_11,10);
        PH_temp = (float)(adcx*0.001*(-5.9647)+22.255);
        TU_temp = (float)(adcx2*(-0.538)+4.61);
        OLED_cnt++;
//		USART_SendData(USART3, (char)0xfd);
//		USART_SendData(USART3, (char)0xfd);
//		USART_SendData(USART3, (char)0xfd);
        delay_ms(300);
        USART3_Receive();
//        USART_SendData(USART1, 233);
        printf("counter: %d\n...", counter);
        printf("counter: %d\n...", Temp[0]);
        printf("counter: %d\n...", Temp[1]);
        printf("counter: %d\n...", Temp[2]);
        printf("counter: %d\n...", Temp[3]);
        printf("counter: %d\n...", Temp[4]);

        //OLED display
        if(OLED_cnt % 20==0)
        {
            OLED_cnt = 0;
            
//            OLED_ShowNum(48,0,Data_TDS,2,16);

//            adcx=PH_temp;
//            OLED_ShowNum(48,2,adcx,2,16);
//            OLED_ShowChar(52,2,'.',16);
//            PH_temp-=adcx;
//            PH_temp*=1000;
//            OLED_ShowNum(54,2,PH_temp,3,16);

            temperature=DS18B20_Get_Temp();	
//			if(temperature<0)
//			{
//				OLED_ShowChar(46,4,'-',16);			//显示负号
//				temperature=-temperature;			//转为正数
//			}else OLED_ShowChar(46,4,' ',16);		//去掉负号
//            OLED_ShowChar(52,4,'.',16);
//			OLED_ShowNum(48,4,temperature/10,2,16);
//            OLED_ShowNum(54,4,temperature%10,1,16);
//                        
//            OLED_ShowString(0,0,(u8 *)"TDS: ",16);
//            OLED_ShowString(0,2,(u8 *)"PH : ",16);
//            OLED_ShowString(0,4,(u8 *)"TEM: ",16);

            printf("TU: %f   \n", TU_temp);
            printf("PH:  %f   \n", PH_temp);
            printf("TEM: %d.%dc  \n", temperature/10, temperature%10);

        }
        delay_ms(5);

	} 	
}

