/*
 * @Author: lisir lisir@rehand.com
 * @Date: 2024-07-31 09:31:38
 * @LastEditors: lisir lisir@rehand.com
 * @LastEditTime: 2024-07-31 15:30:02
 * @FilePath: \Macnum_Car\Drivers\SYSTEM\sys\sys.h
 * @Description: 
 * 
 * Copyright (c) 2024-2034  , Rehand Medical Technology Co. LTDl, All Rights Reserved. 
 */
/**


 ****************************************************************************************************
 */

#ifndef _SYS_H
#define _SYS_H

#include "stm32f4xx.h"
#include "core_cm4.h"
#include "stm32f4xx_hal.h"


/**
 * SYS_SUPPORT_OS用于定义系统文件夹是否支持OS
 * 0,不支持OS
 * 1,支持OS
 */
#define SYS_SUPPORT_OS         0

#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 

#define GPIOA_ODR_Addr    (GPIOA_BASE+20) //0x40020014
#define GPIOB_ODR_Addr    (GPIOB_BASE+20) //0x40020414 
#define GPIOC_ODR_Addr    (GPIOC_BASE+20) //0x40020814 
#define GPIOD_ODR_Addr    (GPIOD_BASE+20) //0x40020C14 


#define GPIOA_IDR_Addr    (GPIOA_BASE+16) //0x40020010 
#define GPIOB_IDR_Addr    (GPIOB_BASE+16) //0x40020410 
#define GPIOC_IDR_Addr    (GPIOC_BASE+16) //0x40020810 
#define GPIOD_IDR_Addr    (GPIOD_BASE+16) //0x40020C10 



#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //


void sys_nvic_set_vector_table(uint32_t baseaddr, uint32_t offset);                        
void sys_standby(void);                                                                    
void sys_soft_reset(void);                                                                  
uint8_t sys_stm32_clock_init(uint32_t plln, uint32_t pllm, uint32_t pllp, uint32_t pllq);   


void sys_wfi_set(void);             /* 执行WFI指令 */
void sys_intx_disable(void);        /* 关闭所有中断 */
void sys_intx_enable(void);         /* 开启所有中断 */
void sys_msr_msp(uint32_t addr);    /* 设置栈顶地址 */

#endif

