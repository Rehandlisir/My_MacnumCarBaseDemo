/*
 * @Author: lisir lisir@rehand.com
 * @Date: 2024-07-31 10:05:49
 * @LastEditors: lisir lisir@rehand.com
 * @LastEditTime: 2024-08-01 18:03:35
 * @FilePath: \MacnumCar_Code\Drivers\BSP\MoterDrive\moterdriver.h
 * @Description: 
 * 
 * Copyright (c) 2024-2034  , Rehand Medical Technology Co. LTDl, All Rights Reserved. 
 */

#ifndef __MOTERDRIVER_H
#define __MOTERDRIVER_H

#include "./SYSTEM/sys/sys.h"
#include "./BSP/PS2/PS2.h"
#include "math.h"
/* 前轮定时器 接口宏定义*/
#define GTIM_TIM8_PWM_CHY_GPIO_PORT GPIOC
#define GTIM_TIM8_PWM_CHY_GPIO_PIN6 GPIO_PIN_6 
#define GTIM_TIM8_PWM_CHY_GPIO_PIN7 GPIO_PIN_7
#define GTIM_TIM8_PWM_CHY_GPIO_PIN8 GPIO_PIN_8 
#define GTIM_TIM8_PWM_CHY_GPIO_PIN9 GPIO_PIN_9
#define GTIM_TIM8_PWM TIM8				  /* TIM8 */
#define GTIM_TIM8_PWM_CH1 TIM_CHANNEL_1	  /* 通道Y,  1<= Y <=4 */
#define GTIM_TIM8_PWM_CH2 TIM_CHANNEL_2	  /* 通道Y,  1<= Y <=4 */
#define GTIM_TIM8_PWM_CH3 TIM_CHANNEL_3	  /* 通道Y,  1<= Y <=4 */
#define GTIM_TIM8_PWM_CH4 TIM_CHANNEL_4	  /* 通道Y,  1<= Y <=4 */
#define GTIM_TIM8_PWM_CH1_CCRX TIM8->CCR1 /* 通道1的输出比较寄存器 */
#define GTIM_TIM8_PWM_CH2_CCRX TIM8->CCR2 /* 通道2的输出比较寄存器 */
#define GTIM_TIM8_PWM_CH3_CCRX TIM8->CCR3 /* 通道3的输出比较寄存器 */
#define GTIM_TIM8_PWM_CH4_CCRX TIM8->CCR4 /* 通道4的输出比较寄存器 */
#define GTIM_TIM8_PWM_CHY_GPIO_AF GPIO_AF3_TIM8 /* 端口复用到TIM8 */
#define GTIM_TIM8_PWM_CHY_GPIOC_CLK_ENABLE() \
	do                                       \
	{                                        \
		__HAL_RCC_GPIOC_CLK_ENABLE();        \
	} while (0) /* PC口时钟使能 */
#define GTIM_TIM8_PWM_CHY_CLK_ENABLE() \
	do                                 \
	{                                  \
		__HAL_RCC_TIM8_CLK_ENABLE();   \
	} while (0) /* TIM8 时钟使能 */
/*后轮定时器宏定义*/
#define GTIM_TIM4_PWM_CHY_GPIO_PORT 	GPIOB
#define GTIM_TIM4_PWM_CHY_GPIO_PIN6 	GPIO_PIN_6 // 
#define GTIM_TIM4_PWM_CHY_GPIO_PIN7 	GPIO_PIN_7
#define GTIM_TIM4_PWM_CHY_GPIO_PIN8 	GPIO_PIN_8 // 
#define GTIM_TIM4_PWM_CHY_GPIO_PIN9 	GPIO_PIN_9
#define GTIM_TIM4_PWM               	TIM4				  /* TIM4 */
#define GTIM_TIM4_PWM_CH1 				TIM_CHANNEL_1	  /* 通道Y,  1<= Y <=4 */
#define GTIM_TIM4_PWM_CH2 				TIM_CHANNEL_2	  /* 通道Y,  1<= Y <=4 */
#define GTIM_TIM4_PWM_CH3 				TIM_CHANNEL_3	  /* 通道Y,  1<= Y <=4 */
#define GTIM_TIM4_PWM_CH4 				TIM_CHANNEL_4	  /* 通道Y,  1<= Y <=4 */
#define GTIM_TIM4_PWM_CH1_CCRX 			TIM4->CCR1 /* 通道1的输出比较寄存器 */
#define GTIM_TIM4_PWM_CH2_CCRX 			TIM4->CCR2 /* 通道2的输出比较寄存器 */
#define GTIM_TIM4_PWM_CH3_CCRX 			TIM4->CCR3 /* 通道3的输出比较寄存器 */
#define GTIM_TIM4_PWM_CH4_CCRX 			TIM4->CCR4 /* 通道4的输出比较寄存器 */
#define GTIM_TIM4_PWM_CHY_GPIO_AF 		GPIO_AF2_TIM4 /* 端口复用到TIM4*/
#define GTIM_TIM4_PWM_CHY_GPIOC_CLK_ENABLE() \
	do                                       \
	{                                        \
		__HAL_RCC_GPIOB_CLK_ENABLE();        \
	} while (0) /* PC口时钟使能 */
#define GTIM_TIM4_PWM_CHY_CLK_ENABLE() \
	do                                 \
	{                                  \
		__HAL_RCC_TIM4_CLK_ENABLE();   \
	} while (0) /* TIM4 时钟使能 */

/*运动指令控制宏定义*/
typedef enum 
	{
		IDDLE =0 ,
		FORWARD =1,
		BACKWARD =2,
		MOVE_LEFT_PARALLEL =3,
		MOVE_RIGHT_PARALLEL =4,
		TURN_LEFT_AROUND =5,
		TURN_RIGHT_AROUND =6,
		FRONT_LEFT =7,
		FRONT_RIGHT =8,
		BACK_LEFT =9,
		BACK_RIGHT =10,
		TURN_FRONTAXISLEFT_AROUND= 11,
		TURN_FRONTAXISRIGHT_AROUND =12,
		TURN_BACKAXISLEFT_AROUND =13,
		TURN_BACKAXISRIGHT_AROUND =14,
	}E_CARSTATE;

typedef struct 
{
	E_CARSTATE state;/* data */
}MACNAUM_CAR;


/*************************电机驱动变量*****************************/
// extern TIM_HandleTypeDef g_time8_pwm_chy_handle;  /* 前轮电机 1 函数句柄*/
// extern TIM_HandleTypeDef g_time4_pwm_chy_handle;  /* 后轮电机 2 函数句柄*/
void MoterdriveInit(void);
void MoterFront_pwm_chy_init(uint16_t arr, uint16_t psc);
void MoterBack_pwm_chy_init(uint16_t arr, uint16_t psc) ;
void FrontLmoter_PwmSet(uint16_t ccr1,uint16_t ccr2);
void FrontRmoter_PwmSet(uint16_t ccr3,uint16_t ccr4);
void BackLmoter_PwmSet(uint16_t ccr1,uint16_t ccr2);
void BackRmoter_PwmSet(uint16_t ccr3,uint16_t ccr4);
void FrontLmoter_Stop(void);
void FrontRmoter_Stop(void);
void BackLmoter_Stop(void);
void BackRmoter_Stop(void);
void FrontLmoter_Brake(void);
void FrontRmoter_Brake(void);
void BackLmoter_Brake(void);
void BackRmoter_Brake(void);
void FrontLmoter_Move(uint8_t dir,double duty_cycle);
void FrontRmoter_Move(uint8_t dir,double duty_cycle);
void BackLmoter_Move(uint8_t dir,double duty_cycle);
void BackRmoter_Move(uint8_t dir,double duty_cycle);
void MacnamuWhellDrive(void);
#endif
