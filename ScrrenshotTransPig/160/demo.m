image=imread('S��ǰ.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);%��ֵ��

% ��������
M_left = [] ;  %��¼����ߵĹ켣
M_right = [] ; %��¼�ұ��ߵĹ켣
flag = 0;     %�ж�ͼ���������͡�




% �����Ϊ��ɫ,���ұ�Ϊ��ɫʱ

if M(63,0)==1&&M(63,120)==0
    flag = 0;           % ��flag��Ϊ0
    num =0;             %����
    i = 63;

    while M(i,0)==1      %�õ�����߰׵�������չ������ߵ�          
        M_left(num*2)=i;  %��¼������    
        M_left(um*2+1)=0;  %��¼������
        i=i-1;        
        num=num+1;
    end

    i=120;
    while 1           %�õ����Ϊ�׵�ĺڵ�
        if M(63,i)==0&&M(63,i-1)&&M(63,i-2)==1&&M(63,i-3)==1
            M_right(0) =63;
            M_right[(1) = i;
            break;
        end
        i=i-1;
        
    end
    
    



% �����Ϊ��ɫ,���ұ�Ϊ��ɫʱ
%����Ƭ����flag==0����

elseif M(63,120)==1&&M(63,0)==0
    flag =1;       
    num = 0;
    i =63;

    while M(i,120)
        M_right(num*2) = i;
        M_right(num*2+1) = 120;
        i = i-1;
        num = num+1;
    end
    
    i = 0;
    while 1
        if M(63,i)==0&&M(63,i+1)==1&&M(63,i+2)==1&&M(63,i+3)==1
            M_left(0)=63;
            M_left(1) = i;
            break;
    end
    i=i+1;



    
    %��������ұ߶�Ϊ����ʱ,��¼�������ǽ����ߵĳ�ʼλ��
elseif M(63,0)==0&&M(63,120)==0
    flag =2;
    i = 0;
    while 1
        if M(63,i)==0&&M(63,i-1)&&M(63,i-2)==1&&M(63,i-3)==1
            M_right(0)=63;
            M_right(1) = i;
            break;
        end
        i=i-1;        
    end

    i = 0;
    while 1
        if M(63,i)==0&&M(63,i+1)==1&&M(63,i+2)==1&&M(63,i+3)==1
            M_left(0) =63;
            M_left(1) = i;
            break;
    end
    i=i+1;


end





%�����ڵ�һ�����ʱ�����߳���
if flag==0
    num = 0;
    yi = M_left(0);
    xi = M_left(1);
    while M_left(2*num+1)<M_right(end)
        num++;
        if M(xi,yi+1)==0&&direction~=5
            yi=yi+1;
            coord_left(2*num+1)=xi;coord_left(2*num+2)=yi;
            direction=1;
            continue;
        end
        if M(xi-1,yi+1)==0
            xi=xi-1;yi=yi+1;
            coord_left(2*num+1)=xi;coord_left(2*num+2)=yi;
            direction=2;
            continue;
        end
        if M(xi-1,yi)==0
            xi=xi-1;
            coord_left(2*num+1)=xi;coord_left(2*num+2)=yi;
            direction=3;
            continue;
        end
        if M(xi-1,yi-1)==0
            xi=xi-1;yi=yi-1;
            coord_left(2*num+1)=xi;coord_left(2*num+2)=yi;
            direction=4;
            continue;
        end
        if M(xi,yi-1)==0
           yi=yi-1;
           coord_left(2*num+1)=xi;coord_left(2*num+2)=yi;
           direction=5;
           continue;
        end
        if M(xi+1,yi-1)==0
           yi=yi-1;
           coord_left(2*num+1)=xi;coord_left(2*num+2)=yi;
           direction=6;
           continue;
        end
        if M(xi+1,yi)==0
           xi=xi+1;
           coord_left(2*num+1)=xi;coord_left(2*num+2)=yi;
           direction=7;
           continue;
        end   
    end

    






        