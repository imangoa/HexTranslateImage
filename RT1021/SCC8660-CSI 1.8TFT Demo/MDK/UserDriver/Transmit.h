#ifndef _TRANSMIT_h
#define _TRANSMIT_h


#include "headfile.h"

#define HEIGHT 120
#define WIDTH 160
#define RGB565_RED      0xf800
#define RGB565_GREEN    0x07e0
#define RGB565_BLUE     0x001f        //rgb565 to rgb888


#define GRAYSCALE 256
#define GETSUM 60        //采样高度




typedef struct headfile {
	uint8 imageType;
	uint8 imageHeight;
	uint8 imageWidth;
} HEADFILE;	  //文件头



void  TRANSMIT_ExtractRgb565Tran();
void  TRANSMIT_ExtractRgbProcessTran(uint8 imageType,uint8 imageHeight,uint8 imageWidth);
void  TRANSMIT_ExtractGrayTran();
uint8 rgb2gray(uint16 rgb565);
int RGB5652RGB888Send(uint16 n565Color);
void TRANSMIT_ExtractRgb888Tran();
uint8 TRANSMIT_Otsu(uint8 gray[])  ;
void TRANSMIT_ExtractBinaryTran();

#endif