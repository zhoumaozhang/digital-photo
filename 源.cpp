#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = cv::imread("D:/2020/课程/数字图像处理/图片/4/1.jpg",0);

	cv::Mat result,result_erode,result_dilate;
	threshold(srcMat, result, 85, 255, THRESH_BINARY);//二值化
	cv::imshow("result", result);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));//形状，尺寸
	erode(result, result_erode, element);//输入，输出，结构元素
	dilate(result, result_dilate, element);
	cv::imshow("result_erode", result_erode);
	cv::imshow("result_dilate", result_dilate);

	cv::Mat result_kai, result_bi;
	morphologyEx(result, result_kai, MORPH_OPEN, element);
	morphologyEx(result, result_bi, MORPH_CLOSE, element);
	cv::imshow("result_kai", result_kai);
	cv::imshow("result_bi", result_bi);


	waitKey(0);
	return 0;
}
