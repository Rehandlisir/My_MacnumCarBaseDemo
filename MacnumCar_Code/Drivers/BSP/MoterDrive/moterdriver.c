/*
 * @Author: lisir lisir@rehand.com
 * @Date: 2024-07-31 10:05:49
 * @LastEditors: lisir lisir@rehand.com
 * @LastEditTime: 2024-08-01 18:33:37
 * @FilePath: \MacnumCar_Code\Drivers\BSP\MoterDrive\moterdriver.c
 * @Description: Macnum_Car MoterDrive
 * 
 * Copyright (c) 2024-2034  , Rehand Medical Technology Co. LTDl, All Rights Reserved. 
 */
#include "./BSP/MoterDrive/moterdriver.h"


MACNAUM_CAR car;


void MoterFoward_pwm_chy_init(uint16_t arr, uint16_t psc) // 前轮
{
    TIM_HandleTypeDef g_time8_pwm_chy_handle ;  /* 前轮电机 1 函数句柄*/
    TIM_OC_InitTypeDef tim8_oc_pwm_chy = {0};                       /* 定时器9输出句柄 */
    g_time8_pwm_chy_handle.Instance = GTIM_TIM8_PWM;                 /* 定时器x */
    g_time8_pwm_chy_handle.Init.Prescaler = psc;                     /* 预分频系数 */
    g_time8_pwm_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;    /* 递增计数模式 */
    g_time8_pwm_chy_handle.Init.Period = arr;                        /* 自动重装载值 */
    HAL_TIM_PWM_Init(&g_time8_pwm_chy_handle);                       /* 初始化PWM */
    tim8_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                       /* 模式选择PWM1 */
    tim8_oc_pwm_chy.Pulse = 0;                                /* 设置比较值,此值用来确定占空比 */
    tim8_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                                        /* 输出比较极性为低 */
    HAL_TIM_PWM_ConfigChannel(&g_time8_pwm_chy_handle, &tim8_oc_pwm_chy, GTIM_TIM8_PWM_CH3); /* 配置TIMx通道y */
    HAL_TIM_PWM_Start(&g_time8_pwm_chy_handle, GTIM_TIM8_PWM_CH3);                           /* 开启对应PWM通道 */
	HAL_TIM_PWM_ConfigChannel(&g_time8_pwm_chy_handle, &tim8_oc_pwm_chy, GTIM_TIM8_PWM_CH4); /* 配置TIMx通道y */
    HAL_TIM_PWM_Start(&g_time8_pwm_chy_handle, GTIM_TIM8_PWM_CH4);                           /* 开启对应PWM通道 */
    HAL_TIM_PWM_ConfigChannel(&g_time8_pwm_chy_handle, &tim8_oc_pwm_chy, GTIM_TIM8_PWM_CH1); /* 配置TIMx通道y */
    HAL_TIM_PWM_Start(&g_time8_pwm_chy_handle, GTIM_TIM8_PWM_CH1);                           /* 开启对应PWM通道 */
	HAL_TIM_PWM_ConfigChannel(&g_time8_pwm_chy_handle, &tim8_oc_pwm_chy, GTIM_TIM8_PWM_CH2); /* 配置TIMx通道y */
    HAL_TIM_PWM_Start(&g_time8_pwm_chy_handle, GTIM_TIM8_PWM_CH2);                           /* 开启对应PWM通道 */

}

void MoterBack_pwm_chy_init(uint16_t arr, uint16_t psc) // 后轮
{
    TIM_HandleTypeDef g_time4_pwm_chy_handle ;  /* 后轮电机 2 函数句柄*/
    TIM_OC_InitTypeDef tim4_oc_pwm_chy = {0};                       /* 定时器9输出句柄 */
    g_time4_pwm_chy_handle.Instance = GTIM_TIM4_PWM;                 /* 定时器x */
    g_time4_pwm_chy_handle.Init.Prescaler = psc;                     /* 预分频系数 */
    g_time4_pwm_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;    /* 递增计数模式 */
    g_time4_pwm_chy_handle.Init.Period = arr;                        /* 自动重装载值 */
    HAL_TIM_PWM_Init(&g_time4_pwm_chy_handle);                       /* 初始化PWM */
    tim4_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                         /* 模式选择PWM1 */
    tim4_oc_pwm_chy.Pulse = 0;                                /* 设置比较值,此值用来确定占空比 */
    tim4_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                                        /* 输出比较极性为低 */
    HAL_TIM_PWM_ConfigChannel(&g_time4_pwm_chy_handle, &tim4_oc_pwm_chy, GTIM_TIM4_PWM_CH3); /* 配置TIMx通道y */
    HAL_TIM_PWM_Start(&g_time4_pwm_chy_handle, GTIM_TIM4_PWM_CH3);                           /* 开启对应PWM通道 */
	HAL_TIM_PWM_ConfigChannel(&g_time4_pwm_chy_handle, &tim4_oc_pwm_chy, GTIM_TIM4_PWM_CH4); /* 配置TIMx通道y */
    HAL_TIM_PWM_Start(&g_time4_pwm_chy_handle, GTIM_TIM4_PWM_CH4);                           /* 开启对应PWM通道 */
    HAL_TIM_PWM_ConfigChannel(&g_time4_pwm_chy_handle, &tim4_oc_pwm_chy, GTIM_TIM4_PWM_CH1); /* 配置TIMx通道y */
    HAL_TIM_PWM_Start(&g_time4_pwm_chy_handle, GTIM_TIM4_PWM_CH1);                           /* 开启对应PWM通道 */
	HAL_TIM_PWM_ConfigChannel(&g_time4_pwm_chy_handle, &tim4_oc_pwm_chy, GTIM_TIM4_PWM_CH2); /* 配置TIMx通道y */
    HAL_TIM_PWM_Start(&g_time4_pwm_chy_handle, GTIM_TIM4_PWM_CH2);                           /* 开启对应PWM通道 */

}

/**
 * @brief       定时器底层驱动，时钟使能，引脚配置
                此函数会被HAL_TIM_PWM_Init()调用
 * @param       htim:定时器句柄
 * @retval      无
 */
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == GTIM_TIM8_PWM)
    {   // 前轮
        GPIO_InitTypeDef gpio_init_struct;
		GTIM_TIM8_PWM_CHY_GPIOC_CLK_ENABLE();                            /* 开启通道y的GPIO时钟 */
        GTIM_TIM8_PWM_CHY_CLK_ENABLE();                                 /* 使能定时器时钟 */
        gpio_init_struct.Pin = GTIM_TIM8_PWM_CHY_GPIO_PIN6 | GTIM_TIM8_PWM_CHY_GPIO_PIN7|GTIM_TIM8_PWM_CHY_GPIO_PIN8|GTIM_TIM8_PWM_CHY_GPIO_PIN9;              /* 通道1 2的CPIO口 */
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;                        /* 复用推完输出 */
        gpio_init_struct.Pull = GPIO_PULLUP;                            /* 上拉 */
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;                  /* 高速 */
        gpio_init_struct.Alternate = GTIM_TIM8_PWM_CHY_GPIO_AF;         /* IO口REMAP设置, 是否必要查看头文件配置的说明! */
        HAL_GPIO_Init(GTIM_TIM8_PWM_CHY_GPIO_PORT, &gpio_init_struct);

    }
    if (htim->Instance == GTIM_TIM4_PWM)
    {   // 后轮
        GPIO_InitTypeDef gpio_init_struct;
		GTIM_TIM4_PWM_CHY_GPIOC_CLK_ENABLE();                            /* 开启通道y的GPIO时钟 */
        GTIM_TIM4_PWM_CHY_CLK_ENABLE();                                 /* 使能定时器时钟 */
        gpio_init_struct.Pin = GTIM_TIM4_PWM_CHY_GPIO_PIN6 | GTIM_TIM4_PWM_CHY_GPIO_PIN7|GTIM_TIM4_PWM_CHY_GPIO_PIN8|GTIM_TIM4_PWM_CHY_GPIO_PIN9;              /* 通道1 2的CPIO口 */
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;                        /* 复用推完输出 */
        gpio_init_struct.Pull = GPIO_PULLUP;                            /* 上拉 */
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;                  /* 高速 */
        gpio_init_struct.Alternate = GTIM_TIM4_PWM_CHY_GPIO_AF;         /* IO口REMAP设置, 是否必要查看头文件配置的说明! */
        HAL_GPIO_Init(GTIM_TIM4_PWM_CHY_GPIO_PORT, &gpio_init_struct);
    }
}
void MoterdriveInit(void)
{
    MoterFoward_pwm_chy_init(1000 - 1, 84 - 1);    //* 168 000 000 / 1000*84     R  2khz频率的PWM 波形*/ 
    MoterBack_pwm_chy_init(1000 - 1, 42 - 1);     //* 84 000 000 / 1000*42      L 2khz频率的PWM 波形*  /
    FrontLmoter_Stop();
    FrontRmoter_Stop();
    BackLmoter_Stop();
    BackRmoter_Stop();
}
/*参数设定中间函数*/
void FrontLmoter_PwmSet(uint16_t ccr1,uint16_t ccr2)
{
    GTIM_TIM8_PWM_CH1_CCRX = ccr1;                      /* 设置比较寄存器 */
    GTIM_TIM8_PWM_CH2_CCRX = ccr2;  
}
void FrontRmoter_PwmSet(uint16_t ccr3,uint16_t ccr4)
{
    
    GTIM_TIM8_PWM_CH1_CCRX = ccr3;                      /* 设置比较寄存器 */
    GTIM_TIM8_PWM_CH2_CCRX = ccr4;  
    
}

void BackLmoter_PwmSet(uint16_t ccr1,uint16_t ccr2)
{
    GTIM_TIM4_PWM_CH1_CCRX = ccr1;                      /* 设置比较寄存器 */
    GTIM_TIM4_PWM_CH2_CCRX = ccr2;  
}


void BackRmoter_PwmSet(uint16_t ccr3,uint16_t ccr4)
{
    GTIM_TIM4_PWM_CH1_CCRX = ccr3;                      /* 设置比较寄存器 */
    GTIM_TIM4_PWM_CH2_CCRX = ccr4;  
}

/*电机停止函数*/

void FrontLmoter_Stop(void)
{
    FrontLmoter_PwmSet(0,0);
}

void FrontRmoter_Stop(void)
{
    FrontRmoter_PwmSet(0,0);
}

void BackLmoter_Stop(void)
{
    BackLmoter_PwmSet(0,0);
}

void BackRmoter_Stop(void)
{
    BackRmoter_PwmSet(0,0);
}

/*电机刹车函数*/
void FrontLmoter_Brake(void)
{
    FrontLmoter_PwmSet(1000,1000);
}

void FrontRmoter_Brake(void)
{
    FrontRmoter_PwmSet(1000,1000);
}

void BackLmoter_Brake(void)
{
    BackLmoter_PwmSet(1000,1000);
}

void BackRmoter_Brake(void)
{
    BackRmoter_PwmSet(1000,1000);
}

/*单电机操作函数*/
void FrontLmoter_Move(uint8_t dir,double duty_cycle)
{
    if (dir==1)
    {
        FrontLmoter_PwmSet((uint16_t)(duty_cycle*1000),0);
    }
    else if(dir==0)
    {
        FrontLmoter_PwmSet(0,(uint16_t)(duty_cycle*1000));
    }
    else
    {
        FrontLmoter_Stop();   
    }
}

void FrontRmoter_Move(uint8_t dir,double duty_cycle)
{
    if (dir==1)
    {
        FrontRmoter_PwmSet((uint16_t)(duty_cycle*1000),0);
    }
    else if(dir==0)
    {
        FrontRmoter_PwmSet(0,(uint16_t)(duty_cycle*1000));
    }
    else
    {
        FrontRmoter_Stop();   
    }
}

void BackLmoter_Move(uint8_t dir,double duty_cycle)
{
    if (dir==1)
    {
        BackLmoter_PwmSet((uint16_t)(duty_cycle*1000),0);
    }
    else if(dir==0)
    {
        BackLmoter_PwmSet(0,(uint16_t)(duty_cycle*1000));
    }
    else
    {
        BackLmoter_Stop();   
    }
}

void BackRmoter_Move(uint8_t dir,double duty_cycle)
{
    if (dir==1)
    {
        BackRmoter_PwmSet((uint16_t)(duty_cycle*1000),0);
    }
    else if(dir==0)
    {
        BackRmoter_PwmSet(0,(uint16_t)(duty_cycle*1000));
    }
    else
    {
        BackRmoter_Stop();   
    }
}

void MacnamuWhellDrive(void)
{
    if(s_ps2data.key == 0 && s_ps2data.Handl_LX == 0 && s_ps2data.Handl_RX==0 && s_ps2data.Handl_LY==0 && s_ps2data.Handl_RY==0)
    {
        car.state = IDDLE;
    }
    if (s_ps2data.Handl_LX == 0 && s_ps2data.Handl_RX==0 && s_ps2data.Handl_LY>0 && s_ps2data.Handl_RY>0) 
    {
        car.state = FORWARD;
    }
    if (s_ps2data.Handl_LX == 0 && s_ps2data.Handl_RX==0 && s_ps2data.Handl_LY<0 && s_ps2data.Handl_RY<0) 
    {
        car.state = BACKWARD;
    }
    if (s_ps2data.Handl_LX <0 && s_ps2data.Handl_RX<0 && s_ps2data.Handl_LY==0 && s_ps2data.Handl_RY==0) 
    {
        car.state = MOVE_LEFT_PARALLEL;
    }
    
    if (s_ps2data.Handl_LX >0 && s_ps2data.Handl_RX>0 && s_ps2data.Handl_LY==0 && s_ps2data.Handl_RY==0) 
    {
        car.state = MOVE_RIGHT_PARALLEL;
    }
    if (s_ps2data.Handl_LX == 0 && s_ps2data.Handl_RX==0 && s_ps2data.Handl_LY<0 && s_ps2data.Handl_RY>0) 
    {
        car.state = TURN_LEFT_AROUND;
    }
    if (s_ps2data.Handl_LX == 0 && s_ps2data.Handl_RX==0 && s_ps2data.Handl_LY>0 && s_ps2data.Handl_RY<0) 
    {
        car.state = TURN_RIGHT_AROUND;
    }
    if ((s_ps2data.Handl_LX < 0 &&  s_ps2data.Handl_RY>0) || (s_ps2data.Handl_LY> 0 &&  s_ps2data.Handl_RX<0 ))  
    {
        car.state = FRONT_LEFT;
    }   

    if ((s_ps2data.Handl_LX > 0 &&  s_ps2data.Handl_RY>0) || (s_ps2data.Handl_LY> 0 &&  s_ps2data.Handl_RX>0 ) ) 
    {
        car.state = FRONT_RIGHT;
    }   

    if ((s_ps2data.Handl_LX < 0 &&  s_ps2data.Handl_RY<0) || (s_ps2data.Handl_LY < 0 &&  s_ps2data.Handl_RX<0 ))  
    {
        car.state = BACK_LEFT;
    }   

    if ((s_ps2data.Handl_LX > 0 &&  s_ps2data.Handl_RY<0) || (s_ps2data.Handl_LY< 0 &&  s_ps2data.Handl_RX>0 ) ) 
    {
        car.state = BACK_RIGHT;
    }   

    if(s_ps2data.key == PSB_L1)
    {

         car.state = TURN_FRONTAXISLEFT_AROUND;
    }

    if(s_ps2data.key == PSB_L2)
    {
        car.state = TURN_BACKAXISLEFT_AROUND;
        
    }
    
    if(s_ps2data.key == PSB_R1)
    {

        car.state = TURN_FRONTAXISRIGHT_AROUND;
    }

    if(s_ps2data.key == PSB_R2)
    {

        car.state = TURN_BACKAXISRIGHT_AROUND;
    }

    switch (car.state)
    {
    case /* constant-expression */: IDDLE
        FrontLmoter_Stop();
        FrontRmoter_Stop();
        BackLmoter_Stop();
        BackRmoter_Stop();
        break;
    
    default:
        break;
    }


}
