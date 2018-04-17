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
 *          水质检测 V0.9
 *     Date          2018.4.17
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
	float PH_temp;
    u8 OLED_cnt = 0;
//    u8 num_print = 0;
//    u8 send_BUF = 0;
//    u8 buf_head = 0x55;
    
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	delay_init();	//延时初始化 
	uart_init(115200);	 	
//    uart3_init(115200);
//    uart4_init(115200);
	LED_Init();		  			//初始化与LED连接的硬件接口
    Key_IO_Init();	 //按键IO配置
    OLED_Init();        
 	Adc_Init();		  		//ADC初始化
    DS18B20_Init();
    //	EXTIX_Init();  //外部中断初始化

    TIMER_Init(50-1,7200-1);      //5ms定时中断
 	while(1)
	{
        adcx = Get_Adc_Average(ADC_Channel_1,10);
        PH_temp = (float)adcx*(-5.9647)+22.255;
        OLED_cnt++;

        //OLED display
        if(OLED_cnt % 20==0)
        {
            OLED_cnt = 0;
            
            OLED_ShowNum(48,0,Data_TDS,2,16);

            adcx=PH_temp;
            OLED_ShowNum(48,2,adcx,2,16);
            OLED_ShowChar(52,2,'.',16);
            PH_temp-=adcx;
            PH_temp*=1000;
            OLED_ShowNum(54,2,PH_temp,3,16);

            temperature=DS18B20_Get_Temp();	
			if(temperature<0)
			{
				OLED_ShowChar(46,4,'-',16);			//显示负号
				temperature=-temperature;					//转为正数
			}else OLED_ShowChar(46,4,' ',16);			//去掉负号
            OLED_ShowChar(52,4,'.',16);
			OLED_ShowNum(48,4,temperature/10,2,16);
            OLED_ShowNum(54,4,temperature%10,1,16);
                        
            OLED_ShowString(0,0,(u8 *)"TDS: ",16);
            OLED_ShowString(0,2,(u8 *)"PH : ",16);
            OLED_ShowString(0,4,(u8 *)"TEM: ",16);
        }
        delay_ms(5);

	} 	
}

