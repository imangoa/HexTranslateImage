#include <stdio.h>
#define row 60
#define height 120

int look_point();      //Ѱ�ҽ��
void draw_line();

int M[height][row];
int M_right[height*row],M_left[height*row];

int main()
{
    int flag;
    flag =look_point();
    draw_line(flag);  
}



void draw_line()
{
    
}



int look_point()
{
int flag;

 if (M[59][0]==1&&M[59][119]==0)
    {
        flag =0;
        int i= 59;
        while (M[i][0]!=1)
            i--;
        M_left[0]=0;
        M_left[1]=i;
        i=119;
        while (1)
        {
            if(M[59][i]==0&&M[59][i-1]==1&&M[59][i-2]==1&&M[59][i-3]==1)
            {
                M_right[0]=i;
                M_right[1]=59;
                break;
            }
            i--;
        }
        return flag;
            
    }

    
    else if (M[59][119]==1&&M[59][0]==0)
    {
        flag=1;
        int i= 59;
        while (M[i][119]!=1)
            i--;
        M_right[0]=0;
        M_right[1]=i;
        i=0;
        while (1)
        {
            if(M[59][i]==0&&M[59][i+1]==1&&M[59][i+2]==1&&M[59][i+3]==1)
            {
                M_left[0]=i;
                M_left[1]=59;
                break;
            }
            i++;
        }
        return flag;
            
    }
    else if(M[59][0]==0&&M[59][119]==0)
    {
        flag=2;
        int i=0;
        while (1)
        {
            if(M[59][i]==0&&M[59][i+1]==1&&M[59][i+2]==1&&M[59][i+3]==1)             //�ұ����
            {
                M_left[0]=i;
                M_left[1]=59;
                break;
            }
            i++;
        }
          i=119;
        while (1)
        {
            if(M[59][i]==0&&M[59][i-1]==1&&M[59][i-2]==1&&M[59][i-3]==1)
            {
                M_right[0]=i;                                                     //������
                M_right[1]=59;
                break;
            }
            i--;
        }
        return flag;
    }
       
}