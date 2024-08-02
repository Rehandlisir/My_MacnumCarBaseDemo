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


void MoterFoward_pwm_chy_init(uint16_t arr, uint16_t psc) // ǰ��
{
    TIM_HandleTypeDef g_time8_pwm_chy_handle ;  /* ǰ�ֵ�� 1 �������*/
    TIM_OC_InitTypeDef tim8_oc_pwm_chy = {0};                       /* ��ʱ��9������ */
    g_time8_pwm_chy_handle.Instance = GTIM_TIM8_PWM;                 /* ��ʱ��x */
    g_time8_pwm_chy_handle.Init.Prescaler = psc;                     /* Ԥ��Ƶϵ�� */
    g_time8_pwm_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;    /* ��������ģʽ */
    g_time8_pwm_chy_handle.Init.Period = arr;                        /* �Զ���װ��ֵ */
    HAL_TIM_PWM_Init(&g_time8_pwm_chy_handle);                       /* ��ʼ��PWM */
    tim8_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                       /* ģʽѡ��PWM1 */
    tim8_oc_pwm_chy.Pulse = 0;                                /* ���ñȽ�ֵ,��ֵ����ȷ��ռ�ձ� */
    tim8_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                                        /* ����Ƚϼ���Ϊ�� */
    HAL_TIM_PWM_ConfigChannel(&g_time8_pwm_chy_handle, &tim8_oc_pwm_chy, GTIM_TIM8_PWM_CH3); /* ����TIMxͨ��y */
    HAL_TIM_PWM_Start(&g_time8_pwm_chy_handle, GTIM_TIM8_PWM_CH3);                           /* ������ӦPWMͨ�� */
	HAL_TIM_PWM_ConfigChannel(&g_time8_pwm_chy_handle, &tim8_oc_pwm_chy, GTIM_TIM8_PWM_CH4); /* ����TIMxͨ��y */
    HAL_TIM_PWM_Start(&g_time8_pwm_chy_handle, GTIM_TIM8_PWM_CH4);                           /* ������ӦPWMͨ�� */
    HAL_TIM_PWM_ConfigChannel(&g_time8_pwm_chy_handle, &tim8_oc_pwm_chy, GTIM_TIM8_PWM_CH1); /* ����TIMxͨ��y */
    HAL_TIM_PWM_Start(&g_time8_pwm_chy_handle, GTIM_TIM8_PWM_CH1);                           /* ������ӦPWMͨ�� */
	HAL_TIM_PWM_ConfigChannel(&g_time8_pwm_chy_handle, &tim8_oc_pwm_chy, GTIM_TIM8_PWM_CH2); /* ����TIMxͨ��y */
    HAL_TIM_PWM_Start(&g_time8_pwm_chy_handle, GTIM_TIM8_PWM_CH2);                           /* ������ӦPWMͨ�� */

}

void MoterBack_pwm_chy_init(uint16_t arr, uint16_t psc) // ����
{
    TIM_HandleTypeDef g_time4_pwm_chy_handle ;  /* ���ֵ�� 2 �������*/
    TIM_OC_InitTypeDef tim4_oc_pwm_chy = {0};                       /* ��ʱ��9������ */
    g_time4_pwm_chy_handle.Instance = GTIM_TIM4_PWM;                 /* ��ʱ��x */
    g_time4_pwm_chy_handle.Init.Prescaler = psc;                     /* Ԥ��Ƶϵ�� */
    g_time4_pwm_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;    /* ��������ģʽ */
    g_time4_pwm_chy_handle.Init.Period = arr;                        /* �Զ���װ��ֵ */
    HAL_TIM_PWM_Init(&g_time4_pwm_chy_handle);                       /* ��ʼ��PWM */
    tim4_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                         /* ģʽѡ��PWM1 */
    tim4_oc_pwm_chy.Pulse = 0;                                /* ���ñȽ�ֵ,��ֵ����ȷ��ռ�ձ� */
    tim4_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                                        /* ����Ƚϼ���Ϊ�� */
    HAL_TIM_PWM_ConfigChannel(&g_time4_pwm_chy_handle, &tim4_oc_pwm_chy, GTIM_TIM4_PWM_CH3); /* ����TIMxͨ��y */
    HAL_TIM_PWM_Start(&g_time4_pwm_chy_handle, GTIM_TIM4_PWM_CH3);                           /* ������ӦPWMͨ�� */
	HAL_TIM_PWM_ConfigChannel(&g_time4_pwm_chy_handle, &tim4_oc_pwm_chy, GTIM_TIM4_PWM_CH4); /* ����TIMxͨ��y */
    HAL_TIM_PWM_Start(&g_time4_pwm_chy_handle, GTIM_TIM4_PWM_CH4);                           /* ������ӦPWMͨ�� */
    HAL_TIM_PWM_ConfigChannel(&g_time4_pwm_chy_handle, &tim4_oc_pwm_chy, GTIM_TIM4_PWM_CH1); /* ����TIMxͨ��y */
    HAL_TIM_PWM_Start(&g_time4_pwm_chy_handle, GTIM_TIM4_PWM_CH1);                           /* ������ӦPWMͨ�� */
	HAL_TIM_PWM_ConfigChannel(&g_time4_pwm_chy_handle, &tim4_oc_pwm_chy, GTIM_TIM4_PWM_CH2); /* ����TIMxͨ��y */
    HAL_TIM_PWM_Start(&g_time4_pwm_chy_handle, GTIM_TIM4_PWM_CH2);                           /* ������ӦPWMͨ�� */

}

/**
 * @brief       ��ʱ���ײ�������ʱ��ʹ�ܣ���������
                �˺����ᱻHAL_TIM_PWM_Init()����
 * @param       htim:��ʱ�����
 * @retval      ��
 */
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == GTIM_TIM8_PWM)
    {   // ǰ��
        GPIO_InitTypeDef gpio_init_struct;
		GTIM_TIM8_PWM_CHY_GPIOC_CLK_ENABLE();                            /* ����ͨ��y��GPIOʱ�� */
        GTIM_TIM8_PWM_CHY_CLK_ENABLE();                                 /* ʹ�ܶ�ʱ��ʱ�� */
        gpio_init_struct.Pin = GTIM_TIM8_PWM_CHY_GPIO_PIN6 | GTIM_TIM8_PWM_CHY_GPIO_PIN7|GTIM_TIM8_PWM_CHY_GPIO_PIN8|GTIM_TIM8_PWM_CHY_GPIO_PIN9;              /* ͨ��1 2��CPIO�� */
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;                        /* ����������� */
        gpio_init_struct.Pull = GPIO_PULLUP;                            /* ���� */
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;                  /* ���� */
        gpio_init_struct.Alternate = GTIM_TIM8_PWM_CHY_GPIO_AF;         /* IO��REMAP����, �Ƿ��Ҫ�鿴ͷ�ļ����õ�˵��! */
        HAL_GPIO_Init(GTIM_TIM8_PWM_CHY_GPIO_PORT, &gpio_init_struct);

    }
    if (htim->Instance == GTIM_TIM4_PWM)
    {   // ����
        GPIO_InitTypeDef gpio_init_struct;
		GTIM_TIM4_PWM_CHY_GPIOC_CLK_ENABLE();                            /* ����ͨ��y��GPIOʱ�� */
        GTIM_TIM4_PWM_CHY_CLK_ENABLE();                                 /* ʹ�ܶ�ʱ��ʱ�� */
        gpio_init_struct.Pin = GTIM_TIM4_PWM_CHY_GPIO_PIN6 | GTIM_TIM4_PWM_CHY_GPIO_PIN7|GTIM_TIM4_PWM_CHY_GPIO_PIN8|GTIM_TIM4_PWM_CHY_GPIO_PIN9;              /* ͨ��1 2��CPIO�� */
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;                        /* ����������� */
        gpio_init_struct.Pull = GPIO_PULLUP;                            /* ���� */
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;                  /* ���� */
        gpio_init_struct.Alternate = GTIM_TIM4_PWM_CHY_GPIO_AF;         /* IO��REMAP����, �Ƿ��Ҫ�鿴ͷ�ļ����õ�˵��! */
        HAL_GPIO_Init(GTIM_TIM4_PWM_CHY_GPIO_PORT, &gpio_init_struct);
    }
}
void MoterdriveInit(void)
{
    MoterFoward_pwm_chy_init(1000 - 1, 84 - 1);    //* 168 000 000 / 1000*84     R  2khzƵ�ʵ�PWM ����*/ 
    MoterBack_pwm_chy_init(1000 - 1, 42 - 1);     //* 84 000 000 / 1000*42      L 2khzƵ�ʵ�PWM ����*  /
    FrontLmoter_Stop();
    FrontRmoter_Stop();
    BackLmoter_Stop();
    BackRmoter_Stop();
}
/*�����趨�м亯��*/
void FrontLmoter_PwmSet(uint16_t ccr1,uint16_t ccr2)
{
    GTIM_TIM8_PWM_CH1_CCRX = ccr1;                      /* ���ñȽϼĴ��� */
    GTIM_TIM8_PWM_CH2_CCRX = ccr2;  
}
void FrontRmoter_PwmSet(uint16_t ccr3,uint16_t ccr4)
{
    
    GTIM_TIM8_PWM_CH1_CCRX = ccr3;                      /* ���ñȽϼĴ��� */
    GTIM_TIM8_PWM_CH2_CCRX = ccr4;  
    
}

void BackLmoter_PwmSet(uint16_t ccr1,uint16_t ccr2)
{
    GTIM_TIM4_PWM_CH1_CCRX = ccr1;                      /* ���ñȽϼĴ��� */
    GTIM_TIM4_PWM_CH2_CCRX = ccr2;  
}


void BackRmoter_PwmSet(uint16_t ccr3,uint16_t ccr4)
{
    GTIM_TIM4_PWM_CH1_CCRX = ccr3;                      /* ���ñȽϼĴ��� */
    GTIM_TIM4_PWM_CH2_CCRX = ccr4;  
}

/*���ֹͣ����*/

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

/*���ɲ������*/
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

/*�������������*/
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
