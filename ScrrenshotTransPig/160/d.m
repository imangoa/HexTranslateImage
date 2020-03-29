image=imread('÷±Ω«Õ‰»ÎÕ‰.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);


for i1=1:160
    if M(63,i1)==0&&M(63,i1+1)==1&&M(63,i1+2)==1&&M(63,i1+3)==1&&M(63,i1+4)==1
        y0=i1;
        break
    end
end
 
coord=[];
coord(1,1)=63;
coord(1,2)=y0;
%coord(1)=63;coord(2)=y0;
xi=63;yi=y0;
for a=1:30
    if M(xi,yi+1)==0
        yi=yi+1;
        coord(1,a)=xi;coord(2,a)=yi;
        continue;
    end
    if M(xi-1,yi+1)==0
        xi=xi-1;yi=yi+1;
        coord(1,a)=xi;coord(2,a)=yi;
           continue;
    end
    if M(xi-1,yi)==0
        xi=xi-1;
        coord(1,a)=xi;coord(2*a+2)=yi;
           continue;
    end
    if M(xi-1,yi-1)==0
        xi=xi-1;yi=yi-1;
        coord(1,a)=xi;coord(2,a)=yi;
          continue;
    end
    if M(xi,yi-1)==0
        yi=yi-1;
       coord(1,a)=xi;coord(2,a)=yi;
        continue;
    end
    if M(xi+1,yi-1)==0
       yi=yi-1;
       coord(1,a)=xi;coord(2,a)=yi;
          continue;
    end
    if M(xi+1,yi)==0
        xi=xi+1;
       coord(1,a)=xi;coord(2,a)=yi;
         continue;
    end   
end

subplot(3, 1, 1); imshow(image);
subplot(3, 1, 2); imshow(M);
writematrix(coord);

