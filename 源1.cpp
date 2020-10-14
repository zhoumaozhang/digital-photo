#include <iostream>//头文件和命名空间
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main()
{
	cv::Mat srcMat;
	cv::Mat result,result1,result2;

	srcMat = cv::imread("C:/Users/dell/Pictures/哔哩哔哩动画/4.jpg",0);

	threshold(srcMat, result, 100, 255, THRESH_BINARY);//二值化算法
	threshold(srcMat, result1, 100, 255, THRESH_OTSU);//大津法
	adaptiveThreshold(srcMat, result2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 10);//局部自适应二值化

	cv::imshow("srcMat", srcMat);
	cv::imshow("BINARY", result);
	cv::imshow("OTSU", result1);
	cv::imshow("adaptive", result2);

	waitKey();

	return 0;
}