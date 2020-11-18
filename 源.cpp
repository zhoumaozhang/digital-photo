#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	cv::Mat result, result1;
	cv::Mat srcMat = cv::imread("D:/2020/�γ�/����ͼ����/ͼƬ/8/1.png", 0);
	threshold(srcMat, result1, 100, 255, THRESH_BINARY);//��ֵ��
	bitwise_not(result1, result);//��ɫ��ת
	cv::imshow("result", result);

	Mat element = getStructuringElement(MORPH_RECT, Size(11, 11));
	cv::Mat result_open;
	morphologyEx(result, result_open, MORPH_OPEN, element);
	cv::imshow("result_open", result_open);

	cv::Mat Imglabels, Imgstats, Imgcentriods;
	int Imglabelnum = connectedComponentsWithStats(result_open, Imglabels, Imgstats, Imgcentriods);

	for (int i = 0; i < Imglabelnum; i++)
	{
		double height = Imgstats.at<int>(i, CC_STAT_HEIGHT);
		double width = Imgstats.at<int>(i, CC_STAT_WIDTH);
		double area = Imgstats.at<int>(i, CC_STAT_AREA);
		double round = area / (height * width);
		std::cout << round << endl;

		cv::Rect rect;
		if (round > 0.5)
		{
			double left = Imgstats.at<int>(i, CC_STAT_LEFT); //��ͨ���boundingbox�������
			double top = Imgstats.at<int>(i, CC_STAT_TOP);//��ͨ���boundingbox�����ϱ�
			rect.x = left;
			rect.y = top;
			rect.width = width;
			rect.height = height;

			rectangle(result, rect, CV_RGB(255, 255, 255), 1, 8, 0);//������
		}

	}
	waitKey(0);
	return 0;
}
/*Imgstats.at<int>(i, CC_STAT_AREA); //��ͨ������
double left = Imgstats.at<int>(i, CC_STAT_LEFT); //��ͨ���boundingbox�������
double top = Imgstats.at<int>(i, CC_STAT_TOP);//��ͨ���boundingbox�����ϱ�
double width = Imgstats.at<int>(i, CC_STAT_WIDTH);//��ͨ��Ŀ�
double height = Imgstats.at<int>(i, CC_STAT_HEIGHT);//��ͨ��ĸ�*/