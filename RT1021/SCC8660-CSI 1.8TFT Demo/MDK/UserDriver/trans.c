//#include "headfile.h"
#include "trans.h"

int TRANSExtract[59]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
uint8 TRANSGray[TRANS_HEIGHT*TRANS_WIDTH];              //灰度图像的大小
	
	
void TRANS_Init()
{
	seekfree_wireless_init();
}


void TRANS_Image(uint8 type)
{	
		HEADFILE Head;
		HEADFILE *PtrHead=&Head;
		PtrHead->imageType=type;
		PtrHead->imageWidth=TRANS_WIDTH;
		PtrHead->imageHeight=TRANS_HEIGHT;
		seekfree_wireless_send_buff(&PtrHead->imageType,sizeof(PtrHead->imageType));
		seekfree_wireless_send_buff(&PtrHead->imageHeight,sizeof(PtrHead->imageHeight));
		seekfree_wireless_send_buff(&PtrHead->imageWidth,sizeof(PtrHead->imageWidth));
		TRANS_Extract(type);
}


void TRANS_Extract(uint8 type)
{
	int i=0,j,k=0,t=0;
	uint16 tmp;
	uint8 h,l;
	
	for(i=0;i<120;i=i+TRANSExtract[t],t++)
	{
	

		for(j=0; j<160; j++)
		{
				tmp=scc8660_image[i][j];
				l=tmp>>8;               //因为图像是以bgr存储，所以要交换高低位。
				h=tmp;
				tmp=h<<8|l;
			
			switch(type)
			{
			case 1:TRANS_Rgb(tmp);break;
			case 2:TRANS_Gray(tmp);break;
			case 3:TRANS_SaveGray(tmp,t*160+j);break;
			default: break;
			}
	
		}
	
	}
	if(type==3)
		TRANS_Binary();
	}


void TRANS_Rgb(uint16 n565Color)
{
    uint8 cRed   = (n565Color & RGB565_RED)    >> 8;
		uint8  cGreen = (n565Color & RGB565_GREEN)  >> 3;
		uint8 cBlue  = (n565Color & RGB565_BLUE)   << 3;
		seekfree_wireless_send_buff(&cBlue,sizeof(cRed));
		seekfree_wireless_send_buff(&cGreen,sizeof(cGreen));
		seekfree_wireless_send_buff(&cRed,sizeof(cBlue));
}

uint8 TRANS_Rgb2Gray(uint16 n565Color)
{
		uint8 Gray;
    uint8 cRed   = (n565Color & RGB565_RED)    >> 8;
		uint8  cGreen = (n565Color & RGB565_GREEN)  >> 3;
		uint8 cBlue  = (n565Color & RGB565_BLUE)   << 3;
		Gray = (cRed*612 + cGreen*1202 + cBlue*234) >> 11;
		return Gray;
}


void TRANS_Gray(uint16 n565Color )
{
		uint8 Gray;
		Gray=TRANS_Rgb2Gray(n565Color);
		seekfree_wireless_send_buff(&Gray,sizeof(Gray));

}

void TRANS_SaveGray(uint16 n565Color,int i)
{
		uint8 Gray;
		Gray=TRANS_Rgb2Gray(n565Color);
		TRANSGray[i]=Gray;
}

void TRANS_Binary()
{
		int flat=7;        //判断8位
	uint8 binary,binaryTemp;
	uint8 threshold;
	threshold=TRANS_Otsu(TRANSGray);
	for(int ks=0;ks<GETSUM*WIDTH;ks++)
{
	
	if(TRANSGray[ks]>threshold)
	{
			TRANSGray[ks]=1;
	}
	else
	{
			TRANSGray[ks]=0;
	}
	binaryTemp=TRANSGray[ks]<<flat;
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

uint8  TRANS_Otsu(uint8 gray[])               //灰度转二值的阈值
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




