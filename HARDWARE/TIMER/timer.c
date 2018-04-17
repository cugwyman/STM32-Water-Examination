#include "timer.h"
#include "key.h"
#include "oled.h"

//通用定时器5中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
u8 number_send_A[10];
u8 number_send_B[10];
u8 number_send_C[10];
u8 num_cnt_A;
u8 num_cnt_B;
u8 num_cnt_C;
u8 send_sign = 0;
void TIMER_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE); //时钟使能
	
	//定时器TIM5初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE ); //使能指定的TIM5中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;  //TIM5中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器


	TIM_Cmd(TIM5, ENABLE);  //使能TIMx					 
}
//定时器3中断服务程序
void TIM5_IRQHandler(void)   //TIM5中断,函数名不能改，在startup_stm32f10x_hd.s文件确定了
{
    
	if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)  //检查TIM5更新中断发生与否
	{
        static u8 cnt = 0;
//        get_mpu();
//        get_pwm();
//        motor_proc(left_pwm, right_pwm);
        cnt++;
//        if(cnt % 25 == 0)	   //150ms扫描一次
//        {
//            cnt = 0;
////            KeyScan();
//            key_value = keyscanf();
//            if(key_value!=0x10)
//            {
//                if(key_value==key_A)
//                {
//                    channel = 'A';
//                    OLED_Clear();
//                }
//                if(key_value==key_B)
//                {
//                    channel = 'B';
//                    OLED_Clear();
//                }
//                if(key_value==key_C)
//                {
//                    channel = 'C';
//                    OLED_Clear();
//                }
//                if(key_value==key_D)
//                {
//                    OLED_Clear();
//                    Item++;
//                    if(Item>3)	
//                    Item = 0;
//                
//                }
//                if(key_value==OK)
//                    send_sign = ~send_sign;
//                if(channel == 'A')
//                {
//                    if(Item == 1)
//                    {
//                        number_send_A[0] = key_value;

////                        if(key_value <= 9)
////                        {
////                            number_send_A[num_cnt_A] = key_value;
////                            num_cnt_A++;
////                            if(num_cnt_A > 9)
////                                num_cnt_A = 0;
////                        }
//                    }
//                }
//                if(channel == 'B')
//                {
//                    if(Item == 1)
//                    {
//                        number_send_B[0] = key_value;
////                        if(key_value <= 9)
////                        {
////                            number_send_B[num_cnt_B] = key_value;
////                            num_cnt_B++;
////                            if(num_cnt_B > 9)
////                                num_cnt_B = 0;
////                        }
//                    }
//                }
//                if(channel == 'C')
//                {
//                    if(Item == 1)
//                    {
//                        number_send_C[0] = key_value;
////                        if(key_value <= 9)
////                        {
////                            number_send_C[num_cnt_C] = key_value;
////                            num_cnt_C++;
////                            if(num_cnt_C > 9)
////                                num_cnt_C = 0;
////                        }
//                    }
//                }

//            }
////            printf("%d\n", key_value);
////            switch(Item)
////            {
////                case 0:
////                    TIM_SetCompare1(TIM3,100);	//tm3 ch1
////                    TIM_SetCompare2(TIM3,100);    //tm3 ch2
////                    TIM_SetCompare3(TIM3,100);    //tm3 ch2
////                    break;
////                case 1:
////                    TIM_SetCompare1(TIM3,100);	//tm3 ch1
////                    TIM_SetCompare2(TIM3,100);    //tm3 ch2
////                    TIM_SetCompare3(TIM3,100);    //tm3 ch2
////                    break;
////                case 2:
////                    TIM_SetCompare1(TIM3,100);	//tm3 ch1
////                    TIM_SetCompare2(TIM3,100);    //tm3 ch2
////                    TIM_SetCompare3(TIM3,100);    //tm3 ch2
////                    break;
////                default: break;
////               

////            }
//        }
        TIM_ClearITPendingBit(TIM5, TIM_IT_Update);  //清除TIMx更新中断标志 
	}
}












