#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	cv::Mat result, result1;
	cv::Mat srcMat = cv::imread("D:/2020/�γ�/����ͼ����/ͼƬ/4/2.jpg", 0);
	threshold(srcMat, result1, 100, 255, THRESH_BINARY);//��ֵ��
	bitwise_not(result1, result);//��ɫ��ת
	cv::imshow("result", result);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	cv::Mat result_open;
	morphologyEx(result, result_open, MORPH_OPEN, element);
	cv::imshow("result_open", result_open);


	cv::Mat Imglabels, Imgstats, Imgcentriods;
	int Imglabelnum = connectedComponentsWithStats(result_open, Imglabels, Imgstats, Imgcentriods);

	int num = 0;
	for (int i = 0; i < Imglabelnum; i++)
	{
		double height = Imgstats.at<int>(i, CC_STAT_HEIGHT);
		cout << height << '\n';

		if (height < 300)
		{
			num++;
		}
	}
	
	//��ͨ��ĸ�
	cout << "����Ϊ" << num;


	waitKey(0);
	return 0;
}