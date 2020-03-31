image=imread('入环靠外.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);%二值化

% 变量申明
M_left =[] ;  %记录左边线的轨迹
M_right = []; %记录右边线的轨迹
flag = 0;     %判断图的三种类型。




% 最左边为白色,最右边为黑色时

if M(63,1)==1&&M(63,160)==0
    flag = 0;           % 将flag置为0
    num_l =0;             %计数
    i = 63;

    while M(i,1)==1      %得到最左边白点连续扩展到的最高点          
        M_left(num_l*2+1)=i;  %记录纵坐标    
        M_left(num_l*2+2)=1;  %记录横坐标
        final =i;
        i=i-1;        
        num_l=num_l+1;
    end

    i=160;
    while 1           %得到左边为白点的黑点
        if M(63,i)==0&&M(63,i-1)&&M(63,i-2)==1&&M(63,i-3)==1
            M_right(1) =63;
            M_right(2) = i;
            break;
        end
        i=i-1;
        
    end
    
    



% 最左边为黑色,最右边为白色时
%代码片段与flag==0类似

elseif M(63,160)==1&&M(63,1)==0
    flag =1;       
    num_l = 0;
    i =63;

    while M(i,160)==1
        M_right(num_l*2+1) = i;
        M_right(num_l*2+2) = 160;
        final =i;
        i = i-1;
        num_l = num_l+1;
    end
    
    i = 1;
    while 1
        if M(63,i)==0&&M(63,i+1)==1&&M(63,i+2)==1&&M(63,i+3)==1
            M_left(1)=63;
            M_left(2) = i;
            break;
        end
        i=i+1;
    end




    
    %最左和最右边都为黑线时,记录下来它们将划线的初始位置
elseif M(63,1)==0&&M(63,160)==0
    flag =2;
    i = 160;
    while 1
        if M(63,i)==0&&M(63,i-1)&&M(63,i-2)==1&&M(63,i-3)==1
            M_right(1)=63;
            M_right(2) = i;
            break;
        end
        i=i-1;        
    end

    i = 1;
    while 1
        if M(63,i)==0&&M(63,i+1)==1&&M(63,i+2)==1&&M(63,i+3)==1
            M_left(1) =63;
            M_left(2) = i;
            break;
        end
        i=i+1;
    end


end



%当处于第一种情况时
if flag == 0
    yi=M_right(2);
    xi=M_right(1);
    num_l =0;
    while M_right(2*num_l+1)>=final
        num_l =num_l+1;
        if M(xi,yi-1)==0
            yi=yi-1;
            M_right(2*num_l+1)=xi;M_right(2*num_l+2)=yi;
            direction=1;
            continue;
        end
        if M(xi-1,yi-1)==0
            xi=xi-1;yi=yi-1;
            M_right(2*num_l+1)=xi;M_right(2*num_l+2)=yi;
            direction=2;
            continue;
        end
        if M(xi-1,yi)==0
            xi=xi-1;
            M_right(2*num_l+1)=xi;M_right(2*num_l+2)=yi;
            direction=3;
            continue;
        end
        if M(xi-1,yi+1)==0
            xi=xi-1;yi=yi+1;
            M_right(2*num_l+1)=xi;M_right(2*num_l+2)=yi;
            direction=4;
            continue;
        end
        if M(xi,yi+1)==0
           yi=yi+1;
           M_right(2*num_l+1)=xi;M_right(2*num_l+2)=yi;
           direction=5;
           continue;
        end
        if M(xi+1,yi+1)==0
           xi=xi+1;yi=yi+1;
           M_right(2*num_l+1)=xi;M_right(2*num_l+2)=yi;
           direction=6;
           continue;
        end
        if M(xi+1,yi)==0
           xi=xi+1;
           M_right(2*num_l+1)=xi;M_right(2*num_l+2)=yi;
           direction=7;
           continue;             
        end
    end
    
end



%当处于第二种情况时，划线程序
if flag==1
    num_l = 0;
    yi = M_left(2);
    xi = M_left(1);
    while M_left(2*num_l+1)>=final
        num_l=num_l+1;
        
        
        if M(xi,yi+1)==0&&direction~=5
            yi=yi+1;
            M_left(2*num_l+1)=xi;M_left(2*num_l+2)=yi;
            direction=1;
            continue;
        end
        if M(xi-1,yi+1)==0
            xi=xi-1;yi=yi+1;
            M_left(2*num_l+1)=xi;M_left(2*num_l+2)=yi;
            direction=2;
            continue;
        end
        if M(xi-1,yi)==0
            xi=xi-1;
            M_left(2*num_l+1)=xi;M_left(2*num_l+2)=yi;
            direction=3;
            continue;
        end
        if M(xi-1,yi-1)==0
            xi=xi-1;yi=yi-1;
            M_left(2*num_l+1)=xi;M_left(2*num_l+2)=yi;
            direction=4;
            continue;
        end
        if M(xi,yi-1)==0
           yi=yi-1;
           M_left(2*num_l+1)=xi;M_left(2*num_l+2)=yi;
           direction=5;
           continue;
        end
        if M(xi+1,yi-1)==0
           yi=yi-1;
           M_left(2*num_l+1)=xi;M_left(2*num_l+2)=yi;
           direction=6;
           continue;
        end
        if M(xi+1,yi)==0
           xi=xi+1;
           M_left(2*num_l+1)=xi;M_left(2*num_l+2)=yi;
           direction=7;
           continue;
        end   
    end
end


%当处于第三种情况的时候
if flag==2
    R_xi=M_right(1);
    R_yi=M_right(2);
    L_xi=M_left(1);
    L_yi=M_left(2);
    R_flat=1;L_flat=1;     %只有当R_flat和L_flat同时为1时，才继续执行while
    num_l=0  ;
        num_r=0;       %计数初始化
    direction =0;
    directionl =0;
    while R_flat&&L_flat
        while 1  
            num_l=num_l+1;             
          
            if L_yi==1||L_yi==160||L_xi==10
                L_flat=0;
                break;
            end
            if M(L_xi,L_yi+1)==0&&directionl~=5
                L_yi=L_yi+1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=1;
                continue;
            end
            if M(L_xi-1,L_yi+1)==0
                L_xi=L_xi-1;L_yi=L_yi+1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=2;
                break;
            end
            if M(L_xi-1,L_yi)==0
                L_xi=L_xi-1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=3;
                break;
            end
            if M(L_xi-1,L_yi-1)==0
                L_xi=L_xi-1;L_yi=L_yi-1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=4;
                break;
            end
            if M(L_xi,L_yi-1)==0
               L_yi=L_yi-1;
               M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
               directionl=5;
               break;
            end
          
            L_flat=0; 
            break;
        end

        while 1
            if R_yi==1||R_xi==10
                R_flat=0;
                break;
            end
            num_r =num_r+1;
            if M(R_xi,R_yi-1)==0&&direction~=5
                R_yi=R_yi-1;
                M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
                direction=1;
                continue;
            end
            if M(R_xi-1,R_yi-1)==0
                R_xi=R_xi-1;R_yi=R_yi-1;
                M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
                direction=2;
                break;
            end
            if M(R_xi-1,R_yi)==0
                R_xi=R_xi-1;
                M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
                direction=3;
                break;
            end
            if M(R_xi-1,R_yi+1)==0
                R_xi=R_xi-1;R_yi=R_yi+1;
                M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
                direction=4;
                break;
            end
            if M(R_xi,R_yi+1)==0
               R_yi=R_yi+1;
               M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
               direction=5;
               continue;
            end
            R_flat=0;
            break;

        end
    end
end




N=ones(63,160);
r_end=length(M_right)/2;
l_end=length(M_left)/2;
for a=1:l_end
    xn=M_left(2*a-1);yn=M_left(2*a);
    N(xn,yn)=0;
end
for a=1:r_end
    xn=M_right(2*a-1);
    yn=M_right(2*a);
    N(xn,yn)=0;
end
subplot(2, 1, 1); imshow(M);%显示图片

subplot(2, 1, 2); imshow(N);

    






        