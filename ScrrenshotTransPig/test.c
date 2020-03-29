#include <stdio.h>
#define row 60
#define height 120

int test();

int M[height][row];
int M_right[height*row],M_left[height*row];

int look_point()     //寻找结点
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
            if(M[59][i]==0&&M[59][i+1]==1&&M[59][i+2]==1&&M[59][i+3]==1)             //右边起点
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
                M_right[0]=i;                                                     //左边起点
                M_right[1]=59;
                break;
            }
            i--;
        }
        return flag;
    }
       
}
void draw_line();



int main()
{
    int flag;
    flag =look_point();
    draw_line(flag);  
}



void draw_line(flag)
{
    switch (flag)
   {
   case 0:
        int a=1;
        int xi=M_right[0];
        int yi=M_left[1];
        while (M_left[1]>=M_right[2*a+1])
        {
            a++;
            if (M[xi,yi+1]==0)
            {
                yi++;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi-1,yi+1]==0)
            {
                xi--;yi++;
                 M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi-1,yi]==0)
            {
                xi--;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi,yi-1]==0)
            {
                yi--;/* code */
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                
                continue;
            }
            if (M[xi+1,yi-1]==0)
            {
                yi--;/* code */
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi+1,yi]==0)
            {
                xi++;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }            
        }
        
       break;
   case 1:
       int a=1;

        int xi=M_left[0];
        int yi=M_left[1];
        while (M_right[1]>=M_left[2*a+1])
        {
            a++;
            if (M[xi,yi+1]==0)
            {
                yi++;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi-1,yi+1]==0)
            {
                xi--;yi++;
                 M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi-1,yi]==0)
            {
                xi--;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi,yi-1]==0)
            {
                yi--;/* code */
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi+1,yi-1]==0)
            {
                yi--;/* code */
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi+1,yi]==0)
            {
                xi++;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }            
        }
        
       break;
   case 2:
        int R_xi=M_right[0];
        int R_yi=M_right[1];
        int L_xi=M_left[0];
        int L_yi=M_left[1];
        while (1)
        {
            while (1)
            {
                a++;
            if (M[xi,yi+1]==0)
            {
                yi++;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                break;
            }
            if (M[xi-1,yi+1]==0)
            {
                xi--;yi++;
                 M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                break;
            }
            if (M[xi-1,yi]==0)
            {
                xi--;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }
            if (M[xi+1,yi]==0)
            {
                xi++;
                M_right[2*a]=xi;
                M_right[2*a+1]=yi;
                continue;
            }            
        }

            }
            while (1)
            {
                test();
                break;           //如果，
            }

        }
        
       break;
   case 3:
   default:
       break;
}



