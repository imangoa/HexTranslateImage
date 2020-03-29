image=imread('直角弯入弯.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);%二值化


for i1=1:160
    if M(63,i1)==0&&M(63,i1+1)==1&&M(63,i1+2)==1&&M(63,i1+3)==1&&M(63,i1+4)==1
        y_left=i1;
        break
    end
end
 % 左线起始坐标
 
 for i1=160:-1:1
    if M(63,i1)==0&&M(63,i1-1)==1&&M(63,i1-2)==1&&M(63,i1-3)==1&&M(63,i1-4)==1
        y_right=i1;
        break
    end
end
 % 右线起始坐标
 
coord_left=[];direction=0;   %记录位置坐标   一次方向
coord_left(1)=63;coord_left(2)=y_left;
xi=63;yi=y_left;
for a=1:40
    if M(xi,yi+1)==0&&direction~=5
        yi=yi+1;
        coord_left(2*a+1)=xi;coord_left(2*a+2)=yi;
        direction=1;
        continue;
    end
    if M(xi-1,yi+1)==0
        xi=xi-1;yi=yi+1;
        coord_left(2*a+1)=xi;coord_left(2*a+2)=yi;
        direction=2;
        continue;
    end
    if M(xi-1,yi)==0
        xi=xi-1;
        coord_left(2*a+1)=xi;coord_left(2*a+2)=yi;
        direction=3;
        continue;
    end
    if M(xi-1,yi-1)==0
        xi=xi-1;yi=yi-1;
        coord_left(2*a+1)=xi;coord_left(2*a+2)=yi;
        direction=4;
        continue;
    end
    if M(xi,yi-1)==0
       yi=yi-1;
       coord_left(2*a+1)=xi;coord_left(2*a+2)=yi;
       direction=5;
       continue;
    end
    if M(xi+1,yi-1)==0
       yi=yi-1;
       coord_left(2*a+1)=xi;coord_left(2*a+2)=yi;
       direction=6;
       continue;
    end
    if M(xi+1,yi)==0
       xi=xi+1;
       coord_left(2*a+1)=xi;coord_left(2*a+2)=yi;
       direction=7;
       continue;
    end   
end
%边左线坐标数组   一维

coord_right=[];direction=0;   %记录位置坐标   一次方向
coord_right(1)=63;coord_right(2)=y_right;
xi=63;yi=y_right;
for a=1:40
    if M(xi,yi-1)==0
        yi=yi-1;
        coord_right(2*a+1)=xi;coord_right(2*a+2)=yi;
        direction=1;
        continue;
    end
    if M(xi-1,yi-1)==0
        xi=xi-1;yi=yi-1;
        coord_right(2*a+1)=xi;coord_right(2*a+2)=yi;
        direction=2;
        continue;
    end
    if M(xi-1,yi)==0
        xi=xi-1;
        coord_right(2*a+1)=xi;coord_right(2*a+2)=yi;
        direction=3;
        continue;
    end
    if M(xi-1,yi+1)==0
        xi=xi-1;yi=yi+1;
        coord_right(2*a+1)=xi;coord_right(2*a+2)=yi;
        direction=4;
        continue;
    end
    if M(xi,yi+1)==0
       yi=yi+1;
       coord_right(2*a+1)=xi;coord_right(2*a+2)=yi;
       direction=5;
       continue;
    end
    if M(xi+1,yi+1)==0
       xi=xi+1;yi=yi+1;
       coord_right(2*a+1)=xi;coord_right(2*a+2)=yi;
       direction=6;
       continue;
    end
    if M(xi+1,yi)==0
       xi=xi+1;
       coord_right(2*a+1)=xi;coord_right(2*a+2)=yi;
       direction=7;
       continue;
    end   
end
%边右线坐标数组   一维


N=ones(63,160);
for a=1:40
    xn=coord_left(2*a-1);yn=coord_left(2*a);
    N(xn,yn)=0;
    continue;
end
for a=1:40
    xn=coord_right(2*a-1);yn=coord_right(2*a);
    N(xn,yn)=0;
end



subplot(2, 1, 1); imshow(M);%显示图片
subplot(2, 1, 2); imshow(N);