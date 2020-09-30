#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {

	cv::Mat srcImge = cv::imread("C:/Users/dell/Pictures/������������/4.jpg");
	cv::imshow("yuan", srcImge);
	waitKey(0);

	int height = srcImge.rows;
	int width = srcImge.cols;
	uchar threshold = 100;//��ֵԽ�ߣ�ͼƬ�а�ɫ����Խ��

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar a = (srcImge.at<Vec3b>(j, i)[0] + srcImge.at<Vec3b>(j, i)[1] + srcImge.at<Vec3b>(j, i)[2]) / 3;
			if (a > threshold)
			{
				a = 255;
			}
			else
			{
				a = 0;
			}
			srcImge.at<Vec3b>(j, i)[0] = a;
			srcImge.at<Vec3b>(j, i)[1] = a;
			srcImge.at<Vec3b>(j, i)[2] = a;
		}
	}
	cv::imshow("gai", srcImge);
	waitKey(0);


	return 0;
}