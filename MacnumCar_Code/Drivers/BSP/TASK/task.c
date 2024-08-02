/*
 * @Author: lisir lisir@rehand.com
 * @Date: 2024-07-31 10:04:10
 * @LastEditors: lisir lisir@rehand.com
 * @LastEditTime: 2024-08-01 17:00:44
 * @FilePath: \MacnumCar_Code\Drivers\BSP\TASK\task.c
 * @Description: 
 * 
 * Copyright (c) 2024-2034  , Rehand Medical Technology Co. LTDl, All Rights Reserved. 
 */
#include "./BSP/TASK/task.h"

/*************************主任务列表*****************************/
/**
 * @description: 
 * @return {*}
 */
void Hard_devInit(void)
{
    /*系统部件初始化*/
	HAL_Init();                             /* 初始化HAl库 */
    sys_stm32_clock_init(336, 8, 2, 7);     /* 初始化时钟频率,168Mhz 主时钟*/
    delay_init(168);                        /*初始化延时时钟频率*/
    usart_init(115200);                     /* 串口通讯波特率 115200 */
    btim_timx_int_init(10 - 1, 8400 - 1);   /*定时器中断初始化 产生固定 1ms 的定时器中断 */
    // iwdg_init(IWDG_PRESCALER_64, 500);      /* 预分频数为64,重载值为500,溢出时间约为1s */
    /*外设初始化*/
    led_init();                             /* 运行指示初始化 */
	PS2_SetInit();                          /*PS2摇杆初始化*/                        
}

/**
 * @description: 
 * @return {*}
 */
void Task_LedFlash(void)
{
    LED1_TOGGLE();
}

void Task_GetPS2Data(void)
{
   PS2_CapData();
}

void Task_MacnumWhellDrive(void)
{
    ;
}


	