/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   串口中断接收测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_esp8266.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
	
	uint16_t i;
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
	
	ESP8266_Init();
	/* 发送一个字符串 */
	printf("欢迎使用野火STM32开发板\n\n");
	printf("这是一个ESP8266AT指令测试实验\n\n");
	printf("请发送“AT”测试ESP8266是否准备好\n\n");
	printf("使用串口调试助手时记得加上换行回车\n\n");
	printf("更多AT指令请参考模块资料\n\n");
	printf("以下是ESP8266上电初始化打印的信息\n\n");
  while(1)
	{	
		if(strUSART_Fram_Record .InfBit .FramFinishFlag == 1)  //如果接收到了串口调试助手的数据
		{
			for(i = 0;i < strUSART_Fram_Record .InfBit .FramLength; i++)
			{
				 USART_SendData( macESP8266_USARTx ,strUSART_Fram_Record .Data_RX_BUF[i]); //转发给ESP82636
				 while(USART_GetFlagStatus(macESP8266_USARTx,USART_FLAG_TC)==RESET){}      //等待发送完成
			}
			strUSART_Fram_Record .InfBit .FramLength = 0;                                //接收数据长度置零
			strUSART_Fram_Record .InfBit .FramFinishFlag = 0;                            //接收标志置零
	  }
		if(strEsp8266_Fram_Record .InfBit .FramFinishFlag)                             //如果接收到了ESP8266的数据
		{                                                      
			for(i = 0;i < strEsp8266_Fram_Record .InfBit .FramLength; i++)               
			{
				 USART_SendData( DEBUG_USARTx ,strEsp8266_Fram_Record .Data_RX_BUF[i]);    //转发给ESP82636
				 while(USART_GetFlagStatus(DEBUG_USARTx,USART_FLAG_TC)==RESET){}
			}
			 strEsp8266_Fram_Record .InfBit .FramLength = 0;                             //接收数据长度置零
			 strEsp8266_Fram_Record.InfBit.FramFinishFlag = 0;                           //接收标志置零
		}
  }	
}	
/*********************************************END OF FILE**********************/
