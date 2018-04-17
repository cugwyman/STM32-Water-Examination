#ifndef __EXTI_H
#define __EXTI_H	 
#include "sys.h"  	

//ccd 
#define row  70//图像行数
#define line 100//图像列数
#define standard line/2 //图像中心点

extern  int h,k;  //h为实际行数，k为采集数组行数
extern  unsigned char image[row][line];		//采集原始图像二维数组
extern  int left[row];             //左边界数组
extern  int right[row];            //右边界数组
extern  int bottom[row];           //中线数组

void EXTIX_Init(void);	//外部中断初始化		 	

#endif
