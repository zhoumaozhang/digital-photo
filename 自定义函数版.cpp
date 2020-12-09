#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

void bianhuan(Mat srcMat, int n)
{
	double max[3] = { 0,0,0 };
	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (srcMat.at<Vec3b>(j, i)[k] > max[k])
				{
					max[k] = srcMat.at<Vec3b>(j, i)[k];
				}
			}
		}
	}
	double mid;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				mid = srcMat.at<Vec3b>(j, i)[k];
				mid /= max[k];
				srcMat.at<Vec3b>(j, i)[k] = mid * n;
			}
		}
	}
}

void Gamma(Mat srcMat, double gamma)
{
	double temp;//定义gamma表
	double lut[256];
	for (int i = 0; i <= 255; ++i)
	{
		temp = double(i) / 255;
		temp = pow(temp, gamma);
		lut[i] = unsigned char(temp * 255);
	}
	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			srcMat.at<Vec3b>(j, i)[0] = lut[srcMat.at<Vec3b>(j, i)[0]];
			srcMat.at<Vec3b>(j, i)[1] = lut[srcMat.at<Vec3b>(j, i)[1]];
			srcMat.at<Vec3b>(j, i)[2] = lut[srcMat.at<Vec3b>(j, i)[2]];
		}
	}
}

int main()

{
	Mat srcMat = imread("D:/2020/课程/数字图像处理/图片/11/图片1.jpg");
	imshow("srcMat", srcMat);
	bianhuan(srcMat, 255);
	Gamma(srcMat, 0.3);
	imshow("srcMat_gamma", srcMat);

	waitKey(0);

	return 0;

}