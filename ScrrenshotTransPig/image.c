#include <stdio.h>

#define WDIST 12
#define HDIST 12
#define IMWIDTH 1911
#define IMHIGHT 794
#define SIZE 60*160
#define MSIZE IMWIDTH * IMHIGHT


// 坐标结构体
typedef struct postion_Element
{
	int x;
	int y;
}POSTION;

//初始化位置
POSTION inital;
POSTION current={0,0};
inintal.x=9;
inital.y=40;


//使用matlab实现比较好，若使用C语言则还要将matlab里面的图像数组导出来，再进行抽取。
POSTION image[SIZE];
int M[IMWIDTH][IMHEIGHT];
int count=0;

int main()
{
	//数组结界不好处理，用current判断
	while(count<MSiZE)
	{
		image[count]=M[inital.x+current.x][inital.y+current.y];
		if(current.x>IMWIDTH)
		{
			current.x=0;
			current.y+=HDIST；
		}
		else
		{
		current.x+=WDIST;
		}
	}

//导出image里面的数据，把8位的bit转出1byte，加上文件头输出。
}






