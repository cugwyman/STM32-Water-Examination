#include "key.h"
#include "oled.h"

uint8_t Item = 0;
uint8_t Param = 1;

void Key_IO_Init(void)	 //按键IO配置
{
    GPIO_InitTypeDef IO_Init;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE , ENABLE);	
    IO_Init.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5;				    
    IO_Init.GPIO_Mode = GPIO_Mode_IPD;	
    GPIO_Init(GPIOE, &IO_Init);
}

void KeyScan(void)
{
//        printf("scan\n");
	
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0) == KEY_PRESSED) //K1
	{	
//        OLED_Clear();
//        printf("add\n");
		switch(Item)
		{
			case 1:
//                if(Param==1)		//共有4行
//                    MODE.DC_PID_P_COEF += 1;
//                if(Param==3)		//共有4行
//                    MODE.DC_PID_D += 1;
				   break; 
//			case 2:R+=5.0;
//				   if(R >= 35.0) R = 35.0;
//				   sprintf(buf,"DS16(6,60,'设置长度:%.1f ',10)\r\n",R);
//				   GpuSend(buf);	
//			       break;  //第2问按下S4增加距离

//			case 3:angle+=10.0;
//				   if(angle >= 180.0) 
//				   	  angle = 180.0;
//				   sprintf(buf,"DS16(6,80,'设置角度:%.1f ',10)\r\n",angle);
//				   GpuSend(buf);	
//			       break;  //第3问按下S4增加角度;  
//			
//			case 5:R+=5.0;
//				   if(R >= 35.0) R = 35.0;
//				   sprintf(buf,"DS16(6,100,'设置半径:%.1f ',10)\r\n",R);
//				   GpuSend(buf);
//				   break;

//			case 6:R+=5.0;
//				   if(R >= 35.0) R = 35.0;
//				   sprintf(buf,"DS16(6,100,'设置半径:%.1f ',10)\r\n",R);
//				   GpuSend(buf);
//				   break;
//				   

			default:break;
		}				
	}

	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1) == KEY_PRESSED) //K2
	{
//        OLED_Clear();
//        printf("sub\n");
		switch(Item)
		{
			case 1:
//                if(Param==1)		//共有4行
//                    MODE.DC_PID_P_COEF -= 1;
//                if(Param==3)		//共有4行
//                    MODE.DC_PID_D -= 1;
                        
				   break; 
//			case 2:R-=5.0;
//				   if(R <= 15.0) R = 15.0;
//				   sprintf(buf,"DS16(6,60,'设置长度:%.1f ',10)\r\n",R);
//				   GpuSend(buf);	
//			       break;  //第2问按下S4增加距离

//			case 3:angle-=10.0;
//				   if(angle <= 0.0) 
//				   	  angle = 0.0;
//				   sprintf(buf,"DS16(6,80,'设置角度:%.1f ',10)\r\n",angle);
//				   GpuSend(buf);	
//			       break;  //第3问按下S4增加角度;  
//			
//			case 5:R-=5.0;
//				   if(R <= 15.0) R = 15.0;
//				   sprintf(buf,"DS16(6,100,'设置半径:%.1f ',10)\r\n",R);
//				   GpuSend(buf);
//				   break;

//			case 6:R-=5.0;
//				   if(R <= 15.0) R = 15.0;
//				   sprintf(buf,"DS16(6,100,'设置半径:%.1f ',10)\r\n",R);
//				   GpuSend(buf);
//				   break;
//				   

			default:break;
		}		
	}
	
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == KEY_PRESSED) //K3
	{
//        OLED_Clear();
//        printf("last\n");
        Param--;
        if(Param<1)		//共有3行
            Param = 3;
//        OLED_Clear();
//		switch(Item)
//		{
//			case 1:Q1_Start = 1;
//				   sprintf(buf,"DS16(6,120,'开始!',10)\r\n");
//				   GpuSend(buf);
//				   break; 

//			case 2:Q2_Start = 1;
//				   sprintf(buf,"DS16(6,120,'开始!',10)\r\n");
//				   GpuSend(buf);
//				   break;

//			case 3:Q3_Start = 1;
//				   sprintf(buf,"DS16(6,120,'开始!',10)\r\n");
//				   GpuSend(buf);
//				   break;  

//			case 4:Q4_Start = 1;
//				   sprintf(buf,"DS16(6,120,'开始!',10)\r\n");
//				   GpuSend(buf);break;
//				   
//			case 5:Q5_Start = 1;
//				   RoundDir = !RoundDir;
//				   if(RoundDir == 1)
//			       	   sprintf(buf,"DS16(6,120,'顺时针旋转!',10)\r\n");
//				   else
//				   	   sprintf(buf,"DS16(6,120,'逆时针旋转!',10)\r\n");
//				   GpuSend(buf);break;
//				   
//			case 6:Q6_Start = 1;	       
//			       sprintf(buf,"DS16(6,120,'开始!',10)\r\n");
//				   GpuSend(buf);break;   

//			default:break;
//		}	
	} 	

    if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == KEY_PRESSED)  //K4
	{
//        OLED_Clear();
//        printf("next\n");
        Param++;
        if(Param>3)		//共有3行
            Param = 1;
    }
    
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5) == KEY_PRESSED)  //K4
	{
        OLED_Clear();
		Item++;
		if(Item>3)		//共有7项
			Item = 0;
//		sprintf(buf,"DS16(6,40,'第%d问',10)\r\n",Item);
//		GpuSend(buf);
	}
}

