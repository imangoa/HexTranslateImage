#ifndef _TRANS_h
#define _TRANS_h

#include "headfile.h"
#include "SEEKFREE_SCC8660.h"


#define TRANS_HEIGHT 60        //�����ͼƬ��ȡ���߶�
#define TRANS_WIDTH 160

#define RGB565_RED      0xf800
#define RGB565_GREEN    0x07e0
#define RGB565_BLUE     0x001f        //rgb565 to rgb888


typedef struct imageFile {
	uint8 imageType;
	uint8 imageHeight;
	uint8 imageWidth;
} IMAGEHEADER;	  //ͼƬ����ͷ





/*
��ȫ������extract��ֵΪ�м����ȡֵ,�����س鵽��ֵ
*/

void TRANS_Extract(uint8 type);


/*
	��ʼ��trans
*/

	void TRANS_Init();
	
/*	
type�������÷���ͼƬ�����ͣ�TRANS_Image���д��䡣   
typeֵ   1��rgn888,2��gray��3��binary
*/

void TRANS_Image(uint8 type);   


/*
����RGB88ͼƬ
*/

void TRANS_Rgb(uint16 tmp);


/*
����grayͼƬ
*/

void TRANS_Gray(uint16 n565Color);


/*
����binaryͼƬ
*/

void TRANS_Binary( );

/*
RGB565ת�Ҷ�
*/

void TRAMS_Rgb2Gray(uint16 n565Color);


/*����Ҷ�ֵ*/
void TRANS_SaveGray(uint16 n565Color,int i);

/*
�ô����ֵ��Ҷ�תRGB����ֵ
*/
uint8 TRANS_Otsu(uint8 gray[]);


#endif