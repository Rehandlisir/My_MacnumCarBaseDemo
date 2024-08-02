/*
 * @Author: lisir lisir@rehand.com
 * @Date: 2024-07-31 10:04:41
 * @LastEditors: lisir lisir@rehand.com
 * @LastEditTime: 2024-07-31 19:02:43
 * @FilePath: \Macnum_Car\Drivers\BSP\WDG\wdg.c
 * @Description: ���Ź�
 * 
 * Copyright (c) 2024-2034  , Rehand Medical Technology Co. LTDl, All Rights Reserved. 
 */


#include "./BSP/WDG/wdg.h"


IWDG_HandleTypeDef iwdg_handler; /*�������Ź���� */

/**
 * @brief       ��ʼ���������Ź� 
 * @param       prer: IWDG_PRESCALER_4~IWDG_PRESCALER_256,��Ӧ4~256��Ƶ
 *   @arg       ��Ƶ���� = 4 * 2^prer. �����ֵֻ����256!
 * @param       rlr: �Զ���װ��ֵ,0~0XFFF. 
 * @note        ʱ�����(���):Tout=((4 * 2^prer) * rlr) / 32 (ms). 
 * @retval      ��
 */
void iwdg_init(uint32_t prer, uint16_t rlr)
{
    iwdg_handler.Instance = IWDG;
    iwdg_handler.Init.Prescaler = prer; /* ����IWDG��Ƶϵ�� */
    iwdg_handler.Init.Reload = rlr;     /* �Ӽ��ؼĴ��� IWDG->RLR ��װ��ֵ */
    HAL_IWDG_Init(&iwdg_handler);       /* ��ʼ��IWDG��ʹ�� */
}

/**
 * @brief       ι�������Ź�
 * @param       ��
 * @retval      ��
 */
void iwdg_feed(void)
{
    HAL_IWDG_Refresh(&iwdg_handler);    /* ι�� */
}
