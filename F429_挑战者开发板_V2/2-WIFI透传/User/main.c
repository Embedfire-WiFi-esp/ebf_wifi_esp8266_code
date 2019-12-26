/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   DHT11温湿度传感器读取。
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火  STM32 F429 开发板
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "systick/bsp_SysTick.h"
#include "DHT11/bsp_dht11.h"
#include "bsp_SysTick.h"
#include "./ESP8266/bsp_esp8266.h"
#include "./test/test.h"
#include "bsp_led.h"
#include "bsp_beep.h"

DHT11_Data_TypeDef DHT11_Data;

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
  
  ESP8266_Init (); 
  LED_GPIO_Config ();
	BEEP_GPIO_Config ();
	
	/* DHT11初始化 */
	DHT11_GPIO_Config();
	
	printf("\r\n***野火F429挑战者APP控制开发板实验***\r\n");
  
  ESP8266_StaTcpClient_UnvarnishTest ();
	
  while(1);

}



/*********************************************END OF FILE**********************/

