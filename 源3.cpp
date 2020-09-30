#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	float histgram[256] = { 0 };

	cv::Mat M1 = imread("D:/2020/数字图像处理/图片/第二节课/1.png");

	int height = M1.rows;
	int width = M1.cols;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			histgram[M1.at<Vec3b>(i, j)[1]] += 1;
		}
	}
	
	for (int k = 0; k < 256; k++)
	{
		histgram[k] /= 100;
	}

	cv::Mat blank(500, 256, CV_8UC3, Scalar(255, 255, 255));

	cv::Point pt1, pt2;
	pt1.x = 0;
	pt1.y = 500;
	pt2.x = 0;

	for (int k = 0; k < 256; k++)
	{
		pt2.y =  500 - histgram[k];
		line(blank, pt1, pt2, CV_RGB(0, 0, 0), 1, 8, 0);
		pt1.x += 1;
		pt2.x += 1;
	}

	

	cv::imshow("zhifangtu", blank);
	waitKey(0);

	return 0;
}