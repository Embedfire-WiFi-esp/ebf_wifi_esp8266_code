/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   wifi 串口透传例程
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火  STM32 F407 开发板
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./systick/bsp_SysTick.h"
#include "./DHT11/bsp_dht11.h"
#include "./esp8266/bsp_esp8266.h"
#include "./test/test.h"


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  /*初始化USART，配置模式为 115200 8-N-1*/
  Debug_USART_Config();
 
	/* 系统定时器初始化 */
	SysTick_Init();
	
	ESP8266_Init ();          //初始化WiFi模块使用的接口和外设

	
	printf ( "\r\n野火 WF-ESP8266 WiFi模块测试例程\r\n" );    //打印测试例程提示信息

	
  ESP8266_StaTcpClient_UnvarnishTest ();
	
	
  while ( 1 );


}



/*********************************************END OF FILE**********************/

