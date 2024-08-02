#ifndef __TASK_H__
#define __TASK_H__
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/MoterDrive/moterdriver.h"
#include "./BSP/TIMER/btim.h"
#include "./BSP/WDG/wdg.h"
#include "./BSP/PS2/PS2.h"
//任务列表
void Hard_devInit(void);
void Task_LedFlash(void);
void Task_GetPS2Data(void);
void Task_MacnumWhellDrive(void);

#endif
