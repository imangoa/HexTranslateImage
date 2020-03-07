#include <stdio.h>
#define uint8 char
#define start 480  //从第三行开始取

FILE *fp;
char name[20];
int val[100000];
uint8 prin[2000];


int getval()
{
	int count=1;   //计数，若为单数读入到数组，为双数不读
	puts("input filename");
	scanf("%s",name);
	fp =fopen(name,"r");
	char wsp;
	if (fp==NULL)
	{
		puts("filenamt error");
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
		fscanf(fp,"%d",&val[count-1]);      //数组从0开始存储。
		}
		count++;
	}
	
	for(int i=0;i<9600;i++)
	{
		printf("%d",val[i]);
	}
	
	printf("\n%d",count);
	fclose(fp);
	return count;
}
void TRANS_hex()
{
	int flat=7;        //判断8位
	int count=0;
	uint8 binary,binaryTemp;
	for (int i=0;i<9600;i++)
	{
		binaryTemp=val[i+start]<<flat;
		flat--;
		if(flat=-1)
		{
			prin[count]=binaryTemp;
			flat=7;
			binary=0;
		}
	}

	for (int i = 0; i < 1000; i++)
	{
		printf("%c",prin[i]);
	}
	
}

int main()
{
	getval();
//	TRANS_hex();
}
