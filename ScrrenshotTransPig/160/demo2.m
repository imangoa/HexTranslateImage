image=imread('�뻷.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);%��???��

% ��������
M_left =[] ;  %��¼����ߵĹ켣
M_right = []; %��¼�ұ��ߵĹ켣
flag = 0;     %�ж�ͼ����������??




% ??���Ϊ��??,??�ұ�Ϊ��ɫʱ

if M(63,1)==1&&M(63,160)==0
    flag = 0;           % ��flag��Ϊ0
    num_l =0;             %����
    i = 63;

    while M(i,1)==1      %�õ�??��߰׵�������չ����??�ߵ�          
        M_left(num_l*2+1)=i;  %��¼����??    
        M_left(num_l*2+2)=1;  %��¼����??
        final =i;
        i=i-1;        
        num_l=num_l+1;
    end

    i=160;
    while 1           %�õ����Ϊ�׵�ĺڵ�
        if M(63,i)==0&&M(63,i-1)&&M(63,i-2)==1&&M(63,i-3)==1
            M_right(1) =63;
            M_right(2) = i;
            break;
        end
        i=i-1;
        
    end
    
    



% ??���Ϊ��??,??�ұ�Ϊ��ɫʱ
%����Ƭ����flag==0����

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




    
    %??���??�ұ߶�Ϊ����??,��¼�������ǽ����ߵĳ�ʼλ��
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



%�����ڵ�??�����ʱ
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



%�����ڵڶ������ʱ�����߳���
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


%�����ڵ����������ʱ??
if flag==2
    R_xi=M_right(1);
    R_yi=M_right(2);
    L_xi=M_left(1);
    L_yi=M_left(2);
    R_flat=1;L_flat=1;     %ֻ�е�R_flat��L_flatͬʱ??1ʱ���ż���ִ��while
    num_l=0  ;
        num_r=0;       %������ʼ??
    direction =0;
    directionl =0;
    height=63;
    while R_flat&&L_flat
        while 1
            if M_left(num_l*2+1)==height-1  
                break;
            end

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
            if M(L_xi-1,L_yi+1)==0&&directionl~=6
                L_xi=L_xi-1;L_yi=L_yi+1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=2;
                continue;
            end
            if M(L_xi-1,L_yi)==0&&directionl~=7
                L_xi=L_xi-1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=3;
                continue;
            end
            if M(L_xi-1,L_yi-1)==0&&directionl~=8
                L_xi=L_xi-1;L_yi=L_yi-1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=4;
                continue;
            end
            if M(L_xi,L_yi-1)==0
               L_yi=L_yi-1;
               M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
               directionl=5;
               continue;
            end
            if M(L_xi+1,L_yi-1)==0
                L_yi=L_yi-1;
                L_xi=L_xi+1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=6;
                continue;
             end
             if M(L_xi+1,L_yi)==0
                L_xi=L_xi+1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=7;
                continue;
             end 
             if M(L_xi+1,L_yi+1)==0
                L_xi=L_xi+1;
                L_yi=L_yi+1;
                M_left(2*num_l+1)=L_xi;M_left(2*num_l+2)=L_yi;
                directionl=8;
                continue;
             end     
          
            L_flat=0; 
            break;
        end

        while 1
            if M_right(num_r*2+1)==height-1  
                break;
            end
            if R_yi==1||R_xi==10||R_yi==160
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
                continue;
            end
            if M(R_xi-1,R_yi)==0
                R_xi=R_xi-1;
                M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
                direction=3;
                continue;
            end
            if M(R_xi-1,R_yi+1)==0
                R_xi=R_xi-1;R_yi=R_yi+1;
                M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
                direction=4;
                continue;
            end
            if M(R_xi,R_yi+1)==0
               R_yi=R_yi+1;
               M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
               direction=5;
               continue;
            end
            if M(R_xi+1,R_yi+1)==0
                R_xi=R_xi+1;R_yi=R_yi+1;
                M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
                direction=6;
                continue;
             end
             if M(R_xi+1,R_yi)==0
                R_xi=R_xi+1;
                M_right(2*num_r+1)=R_xi;M_right(2*num_r+2)=R_yi;
                direction=7;
                continue;             
             end
            R_flat=0;
            break;

        end
        height=height-1;
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
subplot(2, 1, 1); imshow(M);%��ʾͼƬ

subplot(2, 1, 2); imshow(N);

    






        