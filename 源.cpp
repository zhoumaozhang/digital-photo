#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	cv::Mat src = imread("D:/2020/数字图像处理/图片/第二节课/1.png");
	std::vector<cv::Mat> channels;
	cv::split(src, channels);
	cv::Mat B = channels.at(0);
	cv::Mat G = channels.at(1);
	cv::Mat R = channels.at(2);
	cv::imshow("red", R);
	cv::imshow("blue", B);
	cv::imshow("green", G);
	cv::imshow("original Mat", src);
	waitKey(0);

	return 0;
}