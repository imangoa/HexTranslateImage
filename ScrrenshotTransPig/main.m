%����ÿ�����ؿ�Ĵ�С����һ�����Ǹ�������ʵ�ֲ��˵ġ�����������Ҳ���õ�Ե�Ĵ������Կ�������ps����ͼƬתΪ160*63�ģ�Ȼ����ȡ60�С�

image=imread('160/S��ǰ.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);%��ֵ��
C1=reshape(M,1,[]);
writematrix(C1);


