#include "stdio.h"
#include "bmp.h"
#include "string.h"
#define RGB565_RED      0xf800
#define RGB565_GREEN    0x07e0
#define RGB565_BLUE     0x001f        //rgb565 to rgb888
#define IMAGESITE       28400

 FILE* fgetPath;      //rgb888
 FILE* frad;
  int h,w;           //三维数组的长宽
 int flat=0;         //标志位
 int sum=1;              //计数生成图片个数
 unsigned char RgbBuff[IMAGESITE];
  unsigned short RgbBuff1[9600];
 unsigned char Rgb[60][160][3];
  char name[100] ="SmartCarImage/";
   char filename[200];

const char* RAD = "test.swp";

void createImage();
int RGB5652RGB888(unsigned short n565Color);
void reverse( unsigned char cRed, unsigned char cGreen, unsigned char cBlue );

int main()
{
    FILE*frad;
    unsigned int hight, low;
	unsigned short mid1,mid2,val;
    int timer=0;
    if ((frad = fopen(RAD,"rb")) == NULL)
    {
        puts("Fail to open file!");
    };
    while (!feof(frad))
	{
		fscanf(frad, "%x%x", &hight, &low);
		mid1 = hight<<8;
		mid2 = low ;
		val = mid1 | mid2;
        if(timer==9600)
        {
           // getchar();
            createImage();
            timer=0;         
        }
         RgbBuff1[timer]=val;
    
        timer++;
      
	}
    fclose(frad);

    
}

int RGB5652RGB888(unsigned short n565Color)
{
    unsigned char cRed   = (n565Color & RGB565_RED)    >> 8;
	unsigned char cGreen = (n565Color & RGB565_GREEN)  >> 3;
	unsigned char cBlue  = (n565Color & RGB565_BLUE)   << 3;
    reverse(cRed,cGreen,cBlue);
}

void reverse( unsigned char cRed, unsigned char cGreen, unsigned char cBlue )
{
    if(flat>=9600)
       return;
    Rgb[h][w][0]=cBlue;
    Rgb[h][w][1]=cGreen;
    Rgb[h][w][2]=cRed;
    w++;
    flat++;
    if(w>=160)
    {
        h++;
        w=0;
 
    }
}

void createImage()
{   
    flat=0;
     h=0;
    w=0;
    for (int i = 0; i < 9600; i++)
    {
      //  printf("%d",RgbBuff1[i]);
       RGB5652RGB888(RgbBuff1[i]);
    }
    
    int i=59,j=0,k=0,ls=0;
    for(i=59;i>=0;i--)
    {
        for(j=0;j<160;j++)
        {
            for(k=0;k<3;k++)
           {
               
                RgbBuff[ls] = Rgb[i][j][k];
                ls++;
            }                   
        }
    }
     sprintf(filename,"%s%d%s",name,sum,".bmp");
    MySaveBmp(filename,RgbBuff,160,60);
    sum++;
    }

       




