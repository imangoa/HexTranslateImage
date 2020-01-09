#ifndef _TRANS_h
#define _TRANS_h

#include "headfile.h"
#include "SEEKFREE_SCC8660.h"


#define TRANS_HEIGHT 60        //传输的图片的取样高度
#define TRANS_WIDTH 160

#define RGB565_RED      0xf800
#define RGB565_GREEN    0x07e0
#define RGB565_BLUE     0x001f        //rgb565 to rgb888


typedef struct imageFile {
	uint8 imageType;
	uint8 imageHeight;
	uint8 imageWidth;
} IMAGEHEADER;	  //图片传输头





/*
以全局数组extract的值为行间隔抽取值,并返回抽到的值
*/

void TRANS_Extract(uint8 type);


/*
	初始化trans
*/

	void TRANS_Init();
	
/*	
type参数设置发送图片的类型，TRANS_Image进行传输。   
type值   1：rgn888,2：gray。3：binary
*/

void TRANS_Image(uint8 type);   


/*
发送RGB88图片
*/

void TRANS_Rgb(uint16 tmp);


/*
发送gray图片
*/

void TRANS_Gray(uint16 n565Color);


/*
发送binary图片
*/

void TRANS_Binary( );

/*
RGB565转灰度
*/

void TRAMS_Rgb2Gray(uint16 n565Color);


/*保存灰度值*/
void TRANS_SaveGray(uint16 n565Color,int i);

/*
用大津阈值求灰度转RGB的阈值
*/
uint8 TRANS_Otsu(uint8 gray[]);


#endif