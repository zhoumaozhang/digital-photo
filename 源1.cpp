#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap;
	cap.open(0);
	cv::Mat frame;

	int n = 2;//��ȡǰn֡
	while (1)
	{
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		int height = frame.rows; //����
		int width = frame.cols; //ÿ��Ԫ�ص���Ԫ������
		cout << height << endl << width;//���ͼ���С
		int junzhi[480][640] = { 0 };
		int fangcha[480][640] = { 0 };
		int fa[480][640][10];
		for (int c = 0; c < n; c++)
		{
			for (int j = 0; j < height; j++)
			{
				for (int i = 0; i < width; i++)
				{
					//����ǰ10֡ͼƬ������ֵ
					fa[j][i][c] = frame.at<uchar>(j, i);
				}
			}
		}
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				for (int c = 0; c < n; c++)
				{
					junzhi[j][i] += frame.at<uchar>(j, i);//�����ֵ
					fangcha[j][i] += (fa[j][i][c] - junzhi[j][i]) ^ 2;//�󷽲�
				}
				fangcha[j][i] /= n;
				junzhi[j][i] /= n;
			}
		}
		cv::Mat result = Mat::zeros(frame.size(), frame.type());
		int TH = 50;
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				if (abs(frame.at<uchar>(j, i) - junzhi[j][i]) > TH * fangcha[j][i])
				{
					result.at<uchar>(j, i) = 1;
				}
			}
		}
		imshow("result", result);
		waitKey(30);
	}
	return 0;
}