#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


string window_name = "binaryMat";

void threshod_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);

	Mat dst;
	//二值化
	threshold(src, dst, th, 255, 0);

	imshow(window_name, dst);

}

int main()
{
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;

	srcMat = imread("C:/Users/dell/Pictures/哔哩哔哩动画/4.jpg");
	if (!srcMat.data)//判断图像是否载入
	{
		cout << "图像载入失败" << endl;
		return 0;
	}
	// imshow(window_name,Image);
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);//转换成灰度图
	imshow(window_name, gryMat);
	createTrackbar("threshold",//滑动条名称
		window_name,//窗口名称
		&lowTh,//默认初始值
		maxTh,//最大值
		threshod_Mat,//回调函数名
		&gryMat);//传入函数的数据
	waitKey(0);


	return 0;
}