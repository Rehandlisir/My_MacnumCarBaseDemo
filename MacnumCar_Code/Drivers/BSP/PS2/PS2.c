/*
 * @Author: lisir lisir@rehand.com
 * @Date: 2024-07-31 09:50:11
 * @LastEditors: lisir lisir@rehand.com
 * @LastEditTime: 2024-08-01 17:21:27
 * @FilePath: \MacnumCar_Code\Drivers\BSP\PS2\PS2.c
 * @Description: PS2 datacap
 * 
 * Copyright (c) 2024-2034  , Rehand Medical Technology Co. LTDl, All Rights Reserved. 
 */
#include "./BSP/PS2/PS2.h"

/**
 * @description: 通讯接口初始化
 * @return {*}
 */

S_PS2DATA s_ps2data;
static uint8_t Comd[2]={0x01,0x42};	//开始命令。请求数据
static uint8_t Data[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; //数据存储数组
static uint16_t MASK[]={
	PSB_SELECT,
	PSB_L3,
	PSB_R3 ,
	PSB_START,
	PSB_PAD_UP,
	PSB_PAD_RIGHT,
	PSB_PAD_DOWN,
	PSB_PAD_LEFT,
	PSB_L2,
	PSB_R2,
	PSB_L1,
	PSB_R1 ,
	PSB_GREEN,
	PSB_RED,
	PSB_BLUE,
	PSB_PINK
};	

void PS2_GPIOInit(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	//输入  DI->PB12
	PS2_GPIO_CLK_ENABLE();		//使能PORTB时钟
	GPIO_InitStructure.Pin  = PS2_DI_PIN;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Mode = GPIO_PULLDOWN; 		//设置成上拉、下拉、浮空输入皆可
	HAL_GPIO_Init(PS2_COMAPOART, &GPIO_InitStructure);       /* 初始化输入引脚 */
	//输出  DO->PB13    CS->PB14  CLK->PB15
	GPIO_InitStructure.Pin  = PS2_DO_PIN|PS2_CS_PIN|PS2_CLK_PIN;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 				//设置成推挽输出 
	HAL_GPIO_Init(PS2_COMAPOART, &GPIO_InitStructure);       /* 初始化输入引脚 */
}

void PS2_SetInit(void)
{
    uint8_t i;
    PS2_GPIOInit();
    //循环3次
    for(i=0;i<3;i++)
    {
        PS2_ShortPoll();
    }
    PS2_EnterConfig();  // 进入配置模式
    PS2_WorkModeConfig();//工作模式配置
    PS2_VibrationConfig();//震动配置
    PS2_ExitSaveConfig();//退出并保存设置
}


/**
 * @description: 主机向手柄发送命令
 * @param {uint8_t} CMD
 * @return {*}
 */
void PS2_Cmd(uint8_t CMD)
{
	volatile uint16_t ref=0x01;
	Data[1] = 0;
	for(ref=0x01;ref<0x0100;ref<<=1)
	{
		if(ref&CMD)
		{
			DO_H;                   //输出以为控制位
		}
		else DO_L;
		CLK_H;                        //产生时钟
		delay_us(10);
		CLK_L;
		delay_us(10);
		CLK_H;
		if(DI)
			Data[1] = ref|Data[1];
	}
    DELAY;
}

/**
 * @description: ps2初始短轮询
 * @return {*}
 */
void PS2_ShortPoll(void)
{
    CS_L;
    DELAY;
    PS2_Cmd(0X01);
    PS2_Cmd(0X42);
    PS2_Cmd(0X00);
    PS2_Cmd(0X00);
    PS2_Cmd(0X00);
    CS_H;
    DELAY;
}

/**
 * @description: 进入PS2配置
 * @return {*}
 */
void PS2_EnterConfig(void)
{
    CS_L;
    DELAY;
    PS2_Cmd(0X01);
    PS2_Cmd(0X43);
    PS2_Cmd(0X00);
    PS2_Cmd(0X01);
    PS2_Cmd(0X00);   
    PS2_Cmd(0X00);
    PS2_Cmd(0X00);
    PS2_Cmd(0X00);
    PS2_Cmd(0X00);  
    CS_H;
    DELAY;
}
/**
 * @description: //配置PS2 工作模式设置
 * @return {*}
 */
void PS2_WorkModeConfig(void)
{
	CS_L;
	PS2_Cmd(0x01);  
	PS2_Cmd(0x44);  
	PS2_Cmd(0X00);
	PS2_Cmd(0x01); //analog=0x01;digital=0x00  软件设置发送模式
	PS2_Cmd(0xEE); //Ox03锁存设置，即不可通过按键“MODE”设置模式。 //0xEE不锁存软件设置，可通过按键“MODE”设置模式。			  
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	CS_H;
	delay_us(16);
}

/**
 * @description: 允许震动初始化配置
 * @return {*}
 */
void PS2_VibrationConfig(void)
{
    CS_L;
    DELAY;
    PS2_Cmd(0x01);  
    PS2_Cmd(0x4D);  
    PS2_Cmd(0x00);  
    PS2_Cmd(0x00);  
    PS2_Cmd(0x01);  
    CS_H;
    DELAY;
}


/**
 * @description: 保存配置并退出
 * @return {*}
 */
void PS2_ExitSaveConfig(void)
{
    CS_L;
    DELAY;
    PS2_Cmd(0x01);  
    PS2_Cmd(0x43);  
    PS2_Cmd(0x00);  
    PS2_Cmd(0x00);  

    PS2_Cmd(0x5A); 
    PS2_Cmd(0x5A); 
    PS2_Cmd(0x5A);  
    PS2_Cmd(0x5A);  
    PS2_Cmd(0x5A);   
    CS_H;
    DELAY;
}

/**
 * @description: //清除数据缓冲区
 * @return {*}
 */
void PS2_ClearData(void)
{
	uint8_t a;
	for(a=0;a<9;a++)
		Data[a]=0x00;
}


/******************************************************************************************************************************* */
/***************************************************以下为 PS2应用调用相关的 函数***************************************************/
/******************************************************************************************************************************* */
/**
 * @description: 红绿灯模式判断 0x41 模拟绿灯  0x73 模拟红灯
 * @return {*}  0 ：红灯模式
 *              1： 绿灯模式
 */
uint8_t PS2_RedLight(void)
{
	CS_L;
	PS2_Cmd(Comd[0]);  //开始命令0x01
	PS2_Cmd(Comd[1]);  //请求数据0x42
	CS_H;
	if( Data[1] == 0X73)   return 0 ;
	else return 1;
}

/**
 * @description: //读取手柄所有数据
 * @return {*}
 */
void PS2_ReadData(void)
{
	volatile uint8_t byte=0;
	volatile uint16_t ref=0x01;
	CS_L;
	PS2_Cmd(Comd[0]);  //开始命令0x01
	PS2_Cmd(Comd[1]);  //请求数据0x42

	for(byte=2;byte<9;byte++)          //开始接受数据
	{
		for(ref=0x01;ref<0x100;ref<<=1)
		{
			CLK_H;
            delay_us(10);
			CLK_L;
			delay_us(10);
			CLK_H;
		      if(DI)
		      Data[byte] = ref|Data[byte];
		}
        DELAY;
	}
	CS_H;	
}

/**
 * @description: 
 * @description: 
 * @description: 按键部分处理，按下为0，未按下为1
 * @return {*}
 */
uint8_t PS2_DataKey(void)
{
	uint8_t index;
    uint16_t Handkey;
	PS2_ClearData();
	PS2_ReadData();

	Handkey=(Data[4]<<8)|Data[3];     //这是16个按键  按下为0， 未按下为1
	for(index=0;index<16;index++)
	{	    
		if((Handkey&(1<<(MASK[index]-1)))==0)
		return index+1;
	}
	return 0;          //没有任何按键按下
}


/**
 * @description: //得到一个摇杆的模拟量	 范围0~256
 * @param {uint8_t} button
 * @return {*}
 */
uint8_t PS2_AnologData(uint8_t button)
{
	return Data[button];
}


/**
 * @description: 
 * @param {uint8_t} motor1
 * @param {uint8_t} motor2
 * motor1:右侧小震动电机 0x00关，其他开
  motor2:左侧大震动电机 0x40~0xFF 电机开，值越大 震动越大
 * @return {*}
 */
void PS2_VibrationSet(uint8_t motor1, uint8_t motor2)
{
	CS_L;
	delay_us(16);
    PS2_Cmd(0x01);  //开始命令
	PS2_Cmd(0x42);  //请求数据
	PS2_Cmd(0X00);
	PS2_Cmd(motor1);
	PS2_Cmd(motor2);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	CS_H;
	delay_us(16);  
}

/**
 * @description: 测试代码
 * @return {*}
 */
void PS2_CapData(void)
{

    // uint8_t key,LEFT_X,LEFT_Y,RIGHT_X,RIGHT_Y;
    s_ps2data.key = PS2_DataKey();
    
    if (s_ps2data.key==9||s_ps2data.key==11)
    {
        PS2_VibrationSet(0,0xFF);
	}
    else if(s_ps2data.key==10||s_ps2data.key==12)
    {
        PS2_VibrationSet(0xFF,0);
    }
	else
	{
		 PS2_VibrationSet(0,0);

	}
    s_ps2data.LEFT_X = PS2_AnologData(PSS_LX);
    s_ps2data.LEFT_Y= PS2_AnologData(PSS_LY);
    s_ps2data.RIGHT_X = PS2_AnologData(PSS_RX);
    s_ps2data.RIGHT_Y = PS2_AnologData(PSS_RY);
	/*左手柄数据处理*/
	if(s_ps2data.LEFT_X>123 && s_ps2data.LEFT_X<133 )
	{
		s_ps2data.LEFT_X = 128;
	}

	if (s_ps2data.LEFT_Y>122 && s_ps2data.LEFT_Y<132)
	{

		s_ps2data.LEFT_Y = 127;
	}
	s_ps2data.Handl_LX = s_ps2data.LEFT_X -128;
	s_ps2data.Handl_LY = 127-s_ps2data.LEFT_Y;

	/*右手柄数据处理*/
	if(s_ps2data.RIGHT_X>123 && s_ps2data.RIGHT_X<133 )
	{
		s_ps2data.RIGHT_X = 128;
	}

	if (s_ps2data.RIGHT_Y>122 && s_ps2data.RIGHT_Y<132)
	{

		s_ps2data.RIGHT_Y = 127;
	}
	s_ps2data.Handl_LX = s_ps2data.LEFT_X -128;
	s_ps2data.Handl_LY = 127-s_ps2data.LEFT_Y;
	s_ps2data.Handl_RX = s_ps2data.RIGHT_X -128;
	s_ps2data.Handl_RY = 127-s_ps2data.RIGHT_Y;

    printf("\r\n %d is pressed\r\n",s_ps2data.key);
    printf("LEFT_X:%5d,LEFT_Y:%5d,RIGHT_X:%5d,RIGHT_Y:%5d\r\n",s_ps2data.LEFT_X,s_ps2data.LEFT_Y,s_ps2data.RIGHT_X,s_ps2data.RIGHT_Y);
}
