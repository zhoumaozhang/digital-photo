#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	double gamma = 0.3;
	double lut[256];
	Mat srcMat = imread("D:/2020/课程/数字图像处理/图片/11/图片1.jpg");
	imshow("srcMat", srcMat);

	double temp;//定义gamma表
	for (int i = 0; i <= 255; ++i)
	{
		temp = double(i) / 255;
		temp = pow(temp, gamma);
		lut[i] = unsigned char(temp * 255);
	}

	//三通道像素的处理方法
	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			//归一化
			/*srcMat.at<Vec3b>(j, i)[0] /= 255*255;
			srcMat.at<Vec3b>(j, i)[1] /= 255 * 255;
			srcMat.at<Vec3b>(j, i)[2] /= 255 * 255;*/
			//反归一化
			srcMat.at<Vec3b>(j, i)[0] = lut[srcMat.at<Vec3b>(j, i)[0]];
			srcMat.at<Vec3b>(j, i)[1] = lut[srcMat.at<Vec3b>(j, i)[1]];
			srcMat.at<Vec3b>(j, i)[2] = lut[srcMat.at<Vec3b>(j, i)[2]];
		}

	}
	imshow("srcMat_gamma", srcMat);

	waitKey(0);

	return 0;

}