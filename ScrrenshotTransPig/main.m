%由于每个像素块的大小并不一样，那个方法是实现不了的。不过，我们也不用点对点的处理，所以可以先用ps，把图片转为160*63的，然后再取60行。

image=imread('160/直角弯入弯.png');
image2gray=rgb2gray(image);
T = graythresh(image2gray);
M = imbinarize(image2gray,T);%二值化
writematrix(M);

