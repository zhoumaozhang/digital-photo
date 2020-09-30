#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	cv::Mat src = imread("D:/2020/数字图像处理/图片/第二节课/1.png");
	cv::Point pt;
	pt.x = 10;
	pt.y = 10;
	circle(src, pt, 50, CV_RGB(255, 0, 0), -1, 8, 0);

	cv::Point pt1, pt2;
	pt1.x = 50;
	pt1.y = 50;
	pt2.x = 80;
	pt2.y = 80;
	line(src,pt1,pt2, CV_RGB(255, 0, 0), 1, 8, 0);

	cv::Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.width = 100;
	rect.height = 50;
	rectangle(src, rect, CV_RGB(255, 0, 0), 1, 8, 0);

	cv::imshow("src", src);
	waitKey(0);


	return 0;
}