/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
                    ����ͷ���߶��壺
					------------------------------------ 
						ģ��ܽ�            ��Ƭ���ܽ�
						SDA(����ͷ��RX)     �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_COF_UART_TX�궨��
						SCL(����ͷ��TX)     �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_COF_UART_RX�궨��
                        ���ж�(VSY)         �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_VSYNC_PIN�궨��
						���ж�(HREF)		�鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_HREF_PIN�궨��
						�����ж�(PCLK)      �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_PCLK_PIN�궨��
						���ݿ�(D0-D7)		�鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_DATA_PIN�궨��
					------------------------------------ 
	
					Ĭ�Ϸֱ���               160*120
					Ĭ��FPS                  20֡
					
					��Ļ���߶��壺
					------------------------------------ 
						ģ��ܽ�            ��Ƭ���ܽ�
						SCL                 �鿴TFT_SCL�궨�������     Ӳ��SPI���Ų��������л�
						SDA                 �鿴TFT_SDA�궨�������     Ӳ��SPI���Ų��������л�
						RES                 �鿴REST_PIN�궨�������    
						DC                  �鿴DC_PIN�궨�������  
						CS                  �鿴TFT_CS�궨�������      Ӳ��SPI���Ų��������л�
						
						��Դ����
						BL  3.3V��Դ������������ţ�Ҳ���Խ�PWM���������ȣ�
						VCC 3.3V��Դ
						GND ��Դ��
						���ֱ���128*160
					------------------------------------ 
 ********************************************************************************************************************/


//�����Ƽ�IO�鿴Projecct�ļ����µ�TXT�ı�



//���µĹ��̻��߹����ƶ���λ�����ִ�����²���
//��һ�� �ر��������д򿪵��ļ�
//�ڶ��� project  clean  �ȴ��·�����������

#include "headfile.h"
#include "Trans.h"



int main(void)
{
   
    DisableGlobalIRQ();
	 
    board_init();   //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
	 scc8660_init();
    //����ת����ģ��������Ŷ����� wireless.h�ļ���
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
