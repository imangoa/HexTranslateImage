image=imread('����/S�����.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);%��ֵ��
width = 160;
height = 60;
count =1; %����������height*widthʱ��ֹͣд��ֵ
output =[]; %����һ����СΪ60*120�Ŀվ��������ȡ��ֵ
InitalX=3;
InitalY=46;
RiseX=0;      %x,y������
RiseY=0;
RISE=12;     %x,y��ÿ������
output(1,count)=M(InitalX,InitalY);
size=width*height;
while count<size
    RiseX=RiseX+RISE;
    if RiseX >1901
        RiseX=0;
        RiseY=RiseY+RISE;      %��RISEд����Rise��һ��Сʱ��ȥ�ˡ�����һ�£�û�б�����Ϊ�Լ��ǶԵġ���һֱ����Ϊɶ�������е�������˳�while�ˡ�hh
    end
    count=count+1;
    output(1,count)=M(InitalY+RiseY,InitalX+RiseX);
end

writematrix(output);


