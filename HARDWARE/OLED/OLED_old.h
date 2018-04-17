#ifndef _OLED_H
#define _OLED_H

#include "stm32f10x.h"
#define OLED_GPIO    GPIOA
#define OLED_RCCEN   RCC_APB2Periph_GPIOA
#define OLED_SCL     GPIO_Pin_5      //D0
#define OLED_SDA     GPIO_Pin_4      //D1
#define OLED_RST     GPIO_Pin_3     //RST
#define OLED_DC      GPIO_Pin_2      //DC

#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

#define OLED_D0_OL		GPIO_ResetBits(OLED_GPIO, OLED_SCL)	//D0 IO口输出低电平
#define OLED_D0_OH		GPIO_SetBits(OLED_GPIO, OLED_SCL)  	//D0 IO口输出高电平

#define OLED_D1_OL		GPIO_ResetBits(OLED_GPIO, OLED_SDA)	//D1 IO口输出低电平
#define OLED_D1_OH		GPIO_SetBits(OLED_GPIO, OLED_SDA) 	//D1 IO口输出高电平

#define OLED_RST_OL		GPIO_ResetBits(OLED_GPIO, OLED_RST)	//RST IO口输出低电平
#define OLED_RST_OH		GPIO_SetBits(OLED_GPIO, OLED_RST) 	//RST IO口输出高电平

#define OLED_DC_OL		GPIO_ResetBits(OLED_GPIO, OLED_DC)	//DC IO口输出低电平
#define OLED_DC_OH		GPIO_SetBits(OLED_GPIO, OLED_DC) 	//DC IO口输出高电平

#define OLED_RST_Clr()  GPIO_ResetBits(OLED_GPIO, OLED_RST) //RST IO口输出低电平
#define OLED_RST_Set()  GPIO_SetBits(OLED_GPIO, OLED_RST) 	//RST IO口输出高电平

#define OLED_RS_Clr()   GPIO_ResetBits(OLED_GPIO, OLED_DC)	//DC IO口输出低电平
#define OLED_RS_Set()   GPIO_SetBits(OLED_GPIO, OLED_DC) 	  //DC IO口输出高电平

#define OLED_SCLK_Clr() GPIO_ResetBits(OLED_GPIO, OLED_SCL)	//D0 IO口输出低电平
#define OLED_SCLK_Set() GPIO_SetBits(OLED_GPIO, OLED_SCL)  	//D0 IO口输出高电平

#define OLED_SDIN_Clr() GPIO_ResetBits(OLED_GPIO, OLED_SDA)	//D1 IO口输出低电平
#define OLED_SDIN_Set() GPIO_SetBits(OLED_GPIO, OLED_SDA) 	//D1 IO口输出高电平

void OLED_Init(void);//初始化oled
void OLED_P6x8Str(unsigned char x,unsigned char y,char ch[]);//显示6*8字母
void OLED_P8x16Str(unsigned char x,unsigned char y, char ch[]);//显示8*16字母
void OLED_P14x16Str(unsigned char x,unsigned char y, char ch[]);//显示14*16汉字
void OLED_Print(unsigned char x, unsigned char y,  char ch[]);//显示字母和汉字的混合组合
void Draw_Logo(void);//显示HENTO LOGO
void OLED_Fill(unsigned char dat);//清屏或者填充屏幕
void Face(void);


void Dis_unint(unsigned char x, unsigned char y, unsigned int num,unsigned char len) ;//显示无符号整形数据
void Dis_int(unsigned char x, unsigned char y, int num,unsigned char len) ;//显示有符号整型数据
void Dis_Float(unsigned char x,unsigned char y,float num,unsigned char len) ;//显示float类型数据
#endif
