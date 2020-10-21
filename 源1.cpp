#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat result;
	cv::Mat srcMat = cv::imread("D:/2020/�γ�/����ͼ����/ͼƬ/4/1.jpg", 0);
	threshold(srcMat, result, 90, 255, THRESH_BINARY);//��ֵ��
	cv::imshow("result", result);

	cv::Mat Imglabels, Imgstats, Imgcentriods;
	int Imglabelnum = connectedComponentsWithStats(result, Imglabels, Imgstats, Imgcentriods);
	cout << Imglabelnum - 1;
	cv::Rect rect;
	for (int i = 0; i < Imglabelnum; i++)//statsMat.at< int>(��ͨ�����,״̬)
	{
		Imgstats.at<int>(i, CC_STAT_AREA); //��ͨ������
		double left = Imgstats.at<int>(i, CC_STAT_LEFT); //��ͨ���boundingbox�������
		double top = Imgstats.at<int>(i, CC_STAT_TOP);//��ͨ���boundingbox�����ϱ�
		double width = Imgstats.at<int>(i, CC_STAT_WIDTH);//��ͨ��Ŀ�
		double height = Imgstats.at<int>(i, CC_STAT_HEIGHT);//��ͨ��ĸ�
		rect.x = left;
		rect.y = top;
		rect.width = width;
		rect.height = height;

		rectangle(result, rect, CV_RGB(255, 255, 255), 1, 8, 0);//������
	}
	cv::imshow("result'", result);

	waitKey(0);
	return 0;
}