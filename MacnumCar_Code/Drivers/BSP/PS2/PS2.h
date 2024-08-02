/*
 * @Author: lisir lisir@rehand.com
 * @Date: 2024-07-31 09:51:42
 * @LastEditors: lisir lisir@rehand.com
 * @LastEditTime: 2024-08-01 17:50:05
 * @FilePath: \MacnumCar_Code\Drivers\BSP\PS2\PS2.h
 * @Description: 
 * 
 * Copyright (c) 2024-2034  , Rehand Medical Technology Co. LTDl, All Rights Reserved. 
 */
#ifndef __PS2_H__
#define __PS2_H__
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"
/*通讯接口宏定义*/
#define PS2_COMAPOART  GPIOB
#define PS2_GPIO_CLK_ENABLE()  do{ __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)             
#define PS2_DI_PIN  GPIO_PIN_12
#define PS2_DO_PIN  GPIO_PIN_13
#define PS2_CS_PIN  GPIO_PIN_14
#define PS2_CLK_PIN GPIO_PIN_15

#define DI   PBin(12)           //PB12  输入

#define DO_H PBout(13)=1        //命令位高
#define DO_L PBout(13)=0        //命令位低

#define CS_H PBout(14)=1       //CS拉高
#define CS_L PBout(14)=0       //CS拉低

#define CLK_H PBout(15)=1      //时钟拉高
#define CLK_L PBout(15)=0      //时钟拉低

#define DELAY delay_us(16)



//每个按键对应一个数值
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2          9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16

#define PSS_RX 5              
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

typedef struct 
{
    uint8_t key;
    uint8_t LEFT_X;
    uint8_t LEFT_Y;
    uint8_t RIGHT_X;
    uint8_t RIGHT_Y;
    int8_t Handl_LX;
    int8_t Handl_LY;
    int8_t Handl_RX;
    int8_t Handl_RY;
}S_PS2DATA;

extern S_PS2DATA s_ps2data;


void PS2_GPIOInit(void);
void PS2_SetInit(void);
void PS2_Cmd(uint8_t CMD);
void PS2_ShortPoll(void);
void PS2_EnterConfig(void);
void PS2_WorkModeConfig(void);
void PS2_VibrationConfig(void);
void PS2_ExitSaveConfig(void);
uint8_t PS2_RedLight(void);
void PS2_ReadData(void);
uint8_t PS2_DataKey(void);
uint8_t PS2_AnologData(uint8_t button);
void PS2_VibrationSet(uint8_t motor1, uint8_t motor2);
void PS2_ClearData(void);
void PS2_CapData(void);
#endif