/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
                    摄像头接线定义：
					------------------------------------ 
						模块管脚            单片机管脚
						SDA(摄像头的RX)     查看SEEKFREE_SCC8660.h文件中的SCC8660_COF_UART_TX宏定义
						SCL(摄像头的TX)     查看SEEKFREE_SCC8660.h文件中的SCC8660_COF_UART_RX宏定义
                        场中断(VSY)         查看SEEKFREE_SCC8660.h文件中的SCC8660_VSYNC_PIN宏定义
						行中断(HREF)		查看SEEKFREE_SCC8660.h文件中的SCC8660_HREF_PIN宏定义
						像素中断(PCLK)      查看SEEKFREE_SCC8660.h文件中的SCC8660_PCLK_PIN宏定义
						数据口(D0-D7)		查看SEEKFREE_SCC8660.h文件中的SCC8660_DATA_PIN宏定义
					------------------------------------ 
	
					默认分辨率               160*120
					默认FPS                  20帧
					
					屏幕接线定义：
					------------------------------------ 
						模块管脚            单片机管脚
						SCL                 查看TFT_SCL宏定义的引脚     硬件SPI引脚不可随意切换
						SDA                 查看TFT_SDA宏定义的引脚     硬件SPI引脚不可随意切换
						RES                 查看REST_PIN宏定义的引脚    
						DC                  查看DC_PIN宏定义的引脚  
						CS                  查看TFT_CS宏定义的引脚      硬件SPI引脚不可随意切换
						
						电源引脚
						BL  3.3V电源（背光控制引脚，也可以接PWM来控制亮度）
						VCC 3.3V电源
						GND 电源地
						最大分辨率128*160
					------------------------------------ 
 ********************************************************************************************************************/


//整套推荐IO查看Projecct文件夹下的TXT文本



//打开新的工程或者工程移动了位置务必执行以下操作
//第一步 关闭上面所有打开的文件
//第二步 project  clean  等待下方进度条走完

#include "headfile.h"
#include "Trans.h"



int main(void)
{
   
    DisableGlobalIRQ();
	 
    board_init();   //务必保留，本函数用于初始化MPU 时钟 调试串口
	 scc8660_init();
    //无线转串口模块相关引脚定义在 wireless.h文件中
    seekfree_wireless_init();
    EnableGlobalIRQ(0);
		
		 while(1)
		 {
			 if(scc8660_finish_flag)
        {
					scc8660_finish_flag=0;	
					TRANS_Image(3);
				systick_delay_ms(400);
          
				}
		}
 }



/*
uint8 rgb2gray(uint16 rgb565)
{
	uint16 pixel;
	
	uint8 Red,Green,Blue,gray;
		pixel = ((pixel&0xff)<<8) |(pixel>>8);
	Red=pixel>>11;
	Green=(pixel>>5)&0x3f; 
  Blue=pixel&0x1f;
	gray=(Red*77+Green*150+Blue*29+128)/256;
	return gray;
	
}


       */      
