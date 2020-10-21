#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	cv::Mat result, result1;
	cv::Mat srcMat = cv::imread("D:/2020/课程/数字图像处理/图片/4/3.jpg", 0);
	threshold(srcMat, result1, 90, 255, THRESH_OTSU);//二值化
	bitwise_not(result1, result);//颜色反转
	cv::imshow("result", result);

	Mat element = getStructuringElement(MORPH_RECT, Size(20, 20));
	
	cv::Mat result_open;
	morphologyEx(result, result_open, MORPH_OPEN, element);
	cv::imshow("result_open", result_open);

	cv::Mat Imglabels, Imgstats, Imgcentriods;
	int Imglabelnum = connectedComponentsWithStats(result_open, Imglabels, Imgstats, Imgcentriods);
	cout << Imglabelnum - 1;



	waitKey(0);
	return 0;
}