image=imread('赛道/S弯出弯.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);%二值化
width = 160;
height = 60;
count =1; %计数，大于height*width时候，停止写入值
output =[]; %创建一个大小为60*120的空矩阵来存放取的值
InitalX=3;
InitalY=46;
RiseX=0;      %x,y的增量
RiseY=0;
RISE=12;     %x,y的每次增量
output(1,count)=M(InitalX,InitalY);
size=width*height;
while count<size
    RiseX=RiseX+RISE;
    if RiseX >1901
        RiseX=0;
        RiseY=RiseY+RISE;      %把RISE写成了Rise，一个小时过去了。响了一下，没有报错，以为自己是对的。还一直质疑为啥他会运行到这里就退出while了。hh
    end
    count=count+1;
    output(1,count)=M(InitalY+RiseY,InitalX+RiseX);
end

writematrix(output);


