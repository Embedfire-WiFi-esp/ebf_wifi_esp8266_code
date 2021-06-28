/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-01-xx
  * @brief   WF-ESP8266 WiFi模块测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "bsp_usart1.h"
#include "bsp_SysTick.h"
#include "bsp_esp8266.h"
#include "bsp_esp8266_test.h"
#include "bsp_dht11.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "./dwt_delay/core_delay.h"

 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main ( void )
{
	/* 初始化 */
  USARTx_Config ();                                                              //初始化串口1
	SysTick_Init ();                                                               //配置 SysTick 为 1ms 中断一次 
  CPU_TS_TmrInit();
	ESP8266_Init ();                                                               //初始化WiFi模块使用的接口和外设
	DHT11_Init ();
  LED_Init ();
	Beep_Init ();
	
	
	printf ( "\r\n野火 WF-ESP8266 WiFi模块测试例程\r\n" );                          //打印测试例程提示信息
	
  
  ESP8266_StaTcpClient_Unvarnish_ConfigTest();                                  //对ESP8266进行配置
  
  
  while ( 1 )
  {
    if(Task_Delay[0] >= TASK_DELAY_0)     //判断是否执行任务0
    {
      Task_Delay[0] = 0;
      
      //执行任务0
      //macLED1_TOGGLE();
      ESP8266_CheckRecv_SendDataTest(); // ESP8266 每10 ms检查接收到的数据

    }
    
    if(Task_Delay[1] >= TASK_DELAY_1)     //判断是否执行任务1
    {
      Task_Delay[1] = 0;
      
      //执行任务1
      macLED2_TOGGLE();  //绿灯会闪烁
      
      
    }
    
    if(Task_Delay[2] >= TASK_DELAY_2)     //判断是否执行任务2
    {
      Task_Delay[2] = 0;
      
      //执行任务2
      
      //LED3_TOGGLE;
    }

    
    /*****************************************************************************/
    // 最好确保任务能在其执行周期内完成执行
    // Delay_ms(1000);
    // 另外，不要在判断是否执行任务的这些 if 语句外面像这样子加入延时，会影响任务的执行
    /*****************************************************************************/
  }
	
	
}


/*********************************************END OF FILE**********************/
