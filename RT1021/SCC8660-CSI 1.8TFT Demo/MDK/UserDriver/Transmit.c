#include "headfile.h"
#include "Transmit.h"




/*

weight_factor[] 以数组的权重取
*/
void  TRANSMIT_ExtractRgb565Tran()
{
	
	int weight_factor[59]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	int i=0,j,k=0,t=0,temp;
	uint16 s;
	uint8 h,l;
	
	for(i=0;i<=120;i+=1)
	{
	
		if(GETSUM==k)
			{
				return;
			}

		for(j=0; j<160; j++)
		{
				s=scc8660_image[i][j];
				h=s>>8;               //因为图像是以bgr存储，所以要交换高低位。
				l=s;
				temp=h;
				h=l;
				l=temp;
				seekfree_wireless_send_buff(&h,sizeof(h));
				seekfree_wireless_send_buff(&l,sizeof(l));		
		}
		k++;
	
}}


uint8 rgb2gray(uint16 n565Color)
{
	
	unsigned int n888Color = 0;
    uint8 cRed   = (n565Color & RGB565_RED)    >> 8;
		uint8  cGreen = (n565Color & RGB565_GREEN)  >> 3;
		uint8 cBlue  = (n565Color & RGB565_BLUE)   << 3;
		uint8 Gray;
		   Gray = (cRed*612 + cGreen*1202 + cBlue*234) >> 11;
	return Gray;
}


void  TRANSMIT_ExtractGrayTran()
{
	
	int weight_factor[59]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	int i=0,j,k=0,t=0,temp;
	uint16 s;
	uint8 val,h,l;
	//TRANSMIT_ExtractRgbProcessTran(2,60,160);
	for(i=0,t=0;i<=HEIGHT;i=i+weight_factor[t]+1,t++)
	{
	
		if(60==k)
			{
				return;
			}

		for(j=0; j<WIDTH; j++)
		{
				s=scc8660_image[i][j];
			h=s>>8;               //因为图像是以bgr存储，所以要交换高低位。
				l=s;
				temp=h;
				h=l;
				l=temp;
				s=h<<8|l;
				val=rgb2gray(s);
				seekfree_wireless_send_buff(&val,sizeof(val));
		}
		k++;
	
}}




/*	
传送带文件头的图片  

imageType  图片类型
imageHeight  图片高
imageWidth  图片宽

*/

void  TRANSMIT_ExtractRgbProcessTran(uint8 imageType,uint8 imageHeight,uint8 imageWidth)
{
		HEADFILE Head;
		HEADFILE *PtrHead=&Head;
		PtrHead->imageType=imageType;
		PtrHead->imageWidth=imageWidth;
		PtrHead->imageHeight=imageHeight;
		seekfree_wireless_send_buff(&PtrHead->imageType,sizeof(PtrHead->imageType));
		seekfree_wireless_send_buff(&PtrHead->imageHeight,sizeof(PtrHead->imageHeight));
		seekfree_wireless_send_buff(&PtrHead->imageWidth,sizeof(PtrHead->imageWidth));
		//TRANSMIT_ExtractRgbTran();               //可以根据传送文件类型更改，或者后期定义switch语句
	//TRANSMIT_ExtractGrayTran();
		//TRANSMIT_ExtractRgb888Tran();
				TRANSMIT_ExtractBinaryTran();
	
}



 int RGB5652RGB888Send(uint16 n565Color)
{
   
    unsigned int n888Color = 0;
    uint8 cRed   = (n565Color & RGB565_RED)    >> 8;
		uint8  cGreen = (n565Color & RGB565_GREEN)  >> 3;
		uint8 cBlue  = (n565Color & RGB565_BLUE)   << 3;
		seekfree_wireless_send_buff(&cBlue,sizeof(cRed));
		seekfree_wireless_send_buff(&cGreen,sizeof(cGreen));
		seekfree_wireless_send_buff(&cRed,sizeof(cBlue));
 
}



void TRANSMIT_ExtractRgb888Tran()
{
		int weight_factor[59]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	int i=0,j,k=0,temp;
	uint16 s;
	uint8 h,l;
	
	for(i=0;i<120;i+=1)
	{
	
		if(60==k)
			{
				return;
			}

		for(j=0; j<160; j++)
		{
				s=scc8660_image[i][j];
				h=s>>8;               //因为图像是以bgr存储，所以要交换高低位。
				l=s;
				temp=h;
				h=l;
				l=temp;
				s=h<<8|l;
				RGB5652RGB888Send(s);
				
		}
		k++;
	
	}
}


void TRANSMIT_ExtractBinaryTran()
{
		int weight_factor[59]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

			int flat=7;        //判断8位
	int i=0,j,k=0,temp,cout=0;
	uint16 s;
	uint8 h,l,val,threshold ;
	uint8 gray[9600],binary,binaryTemp;
	
	for(i=0;i<=120;i+=1)
	{
	
		if(GETSUM==k)
			{
				break;
			}

		for(j=0; j<160; j++)
		{
				s=scc8660_image[i][j];
				h=s>>8;               //因为图像是以bgr存储，所以要交换高低位。
				l=s;
				temp=h;
				h=l;
				l=temp;
				s=h<<8|l;
				val=rgb2gray(s);
		
				gray[cout]=val;
				cout++;
		}
		
		k++;		
	}
	threshold=TRANSMIT_Otsu(gray);
	//seekfree_wireless_send_buff(&threshold,sizeof(threshold));

for(int ks=0;ks<GETSUM*WIDTH;ks++)
{
	
	if(gray[ks]>threshold)
	{
			gray[ks]=1;
	}
	else
	{
			gray[ks]=0;
	}
	binaryTemp=gray[ks]<<flat;
	binary|=binaryTemp;
	flat--;
	if(flat==-1)
	{
		seekfree_wireless_send_buff(&binary,sizeof(binary));
		flat=7;
		binary=0;
	}
	
	
}
}
uint8  TRANSMIT_Otsu(uint8 gray[])               //灰度转二值的阈值
{
	int pixCount[GRAYSCALE];
  uint8 th=0;
  int w0, w1, u0tmp, u1tmp, u0, u1;
  unsigned int  deltaTmp, deltaMax = 0;

   for(int i = 0; i < GRAYSCALE;i++)
	{
			pixCount[i]=0;  
    
	}

  for(int i = 0; i < 9600;i++)
	{
			pixCount[gray[i]]++;//统计每个灰度级中像素的个数   
            
             
	}

 
	for(int i = 1; i < 256; i++)//遍历所有从0到255灰度级的阈值分割条件，测试哪一个的类间方差最大
	{
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = deltaTmp = 0;  
		for(int j = 0; j < GRAYSCALE; j++)
		{
			if(j <= i)//背景
			{
				w0 += pixCount[j];
				u0tmp += j * pixCount[j]; 
			}
			else//前景
			{
				w1 += pixCount[j];
				u1tmp += j * pixCount[j];
			}
		}

    if (w0==0||w1==0)
    {
        continue;
    }
		u0 = u0tmp / w0;
		u1 = u1tmp / w1;
        unsigned int wx;
        wx=w1*w0*10/9600;
		deltaTmp = wx*pow((u0 - u1), 2); //类间方差公式 g = w1 * w2 * (u1 - u2) ^ 2
		if(deltaTmp > deltaMax) 
		{
			deltaMax = deltaTmp;
			th = i;  
      
          
		}  
	}
	return th;
}





