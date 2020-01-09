
#include "headfile.h"
#include "SEEKFREE_FONT.h"


/*初始化左右两个编码器*/
void ENCODER_Init()
{
	  qtimer_quad_init(QTIMER_2,QTIMER2_TIMER0_C0,QTIMER2_TIMER1_C1);
    qtimer_quad_init(QTIMER_2,QTIMER2_TIMER2_C2,QTIMER2_TIMER3_C3);    
	//	EnableGlobalIRQ(0);
}


/*
param  num: 
*/
int ENCODER_Get(int num)
{
	int encoder;
	
	if(num==0)
	{
		encoder =qtimer_quad_get(QTIMER_2,QTIMER2_TIMER0_C0);
		qtimer_quad_clear(QTIMER_2,QTIMER2_TIMER0_C0);
     
	}
	else if(num==1)
	{
		 encoder =qtimer_quad_get(QTIMER_2,QTIMER2_TIMER2_C2);
		 qtimer_quad_clear(QTIMER_2,QTIMER2_TIMER2_C2);
		
	}
	return encoder;	
}