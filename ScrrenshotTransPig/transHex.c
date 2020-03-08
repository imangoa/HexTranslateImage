#include <stdio.h>
#define uint8 char
#define start 480  //从第三行开始取

FILE *fp;
char name[20]="m.txt";
char outName[100]="ElemImage.swp";
int val[100000];
uint8 prin[2000];
struct head
{
	uint8 type;/* data */
	uint8 height;
	uint8 width;
};
struct head HEAD={3,60,160};


int getval()
{
	int count=1;   //计数，若为单数读入到数组，为双数不读
	int index=0;
	//puts("input filename");
	//scanf("%s",name);
	fp =fopen(name,"r");
	char wsp;
	if (fp==NULL)
	{
		puts("filename error");
	}
	puts("start\n");
	while(!feof(fp))
	{
		if(count%2==0)
		{
			fscanf(fp,"%c",&wsp);
		}
		else
		{
		fscanf(fp,"%d",&val[index]);      //数组从0开始存储。
			
				printf("%d",val[index]);
					index++;
		}

		count++;
	}
	printf("%d",count);
	printf("\n%d",index);
	
	// printf("\n%d",count);
	fclose(fp);
	return count;
}
void TRANS_hex()
{
	int flat=7;        //判断8位
	int count=0;
	uint8 binary,binaryTemp,eight;

	for (int i=0;i<9600;i++)
	{
		eight =val[i+start];      //将位数转为8位
		binaryTemp=eight<<flat;
		binary|=binaryTemp;
		flat--;
		if(flat==-1)
		{
		
			prin[count]=binary;
			flat=7;
			binary=0;
			count++;
		}
	}
	printf("%d",count);
	printf("\n");
	for (int i = 0; i < 1200; i++)
	{
		printf("%c",prin[i]);   
	}
	
}

void output()             //将1200个8位数据输入文件
{
	fp=fopen(outName,"wb");
	fprintf(fp,"%c",HEAD.type);
	fprintf(fp,"%c",HEAD.height);
	fprintf(fp,"%c",HEAD.width);
	for (int i = 0; i <1200; i++)
	{
		fprintf(fp,"%c",prin[i]);/* code */
	}
	fclose(fp);
}	

int main()
{
	getval();
	TRANS_hex();
	output();
}
