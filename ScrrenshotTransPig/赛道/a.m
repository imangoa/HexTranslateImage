image=imread('S弯出弯.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
BW = imbinarize(image2gray,T);%二值化
imshow(BW);