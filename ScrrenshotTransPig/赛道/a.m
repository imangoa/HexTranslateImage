image=imread('S�����.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
BW = imbinarize(image2gray,T);%��ֵ��
imshow(BW);