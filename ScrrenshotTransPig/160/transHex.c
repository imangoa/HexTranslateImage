#include <stdio.h>
FILE *fp;
char name[20];
int val[10000];

int main()
{
	int count=1;   //计数，若为单数读入到数组，为双数不读
	puts("input filename");
	scanf("%s",name);
	fp =fopen(name,"r");
	int wsp;
	if (fp==NULL)
	{
		puts("filenamt error")；
	}
	while(!feof(fp))
	{
		if(count%2==0)
		{
			fscanf(fp,"%d",&wsp)
		}
		else
		{
		fscanf(fp,"%d",&val[count-1]);
		}
	}
	for (int i=0;i<1000;i++)
	{
	printf("%d",val[i]);
	}
	printf("\n%d",count);
	
}
