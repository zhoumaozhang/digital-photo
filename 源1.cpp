#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap;
	cap.open(0);
	cv::Mat frame;

	int n = 2;//读取前n帧
	while (1)
	{
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		int height = frame.rows; //行数
		int width = frame.cols; //每行元素的总元素数量
		cout << height << endl << width;//获得图像大小
		int junzhi[480][640] = { 0 };
		int fangcha[480][640] = { 0 };
		int fa[480][640][10];
		for (int c = 0; c < n; c++)
		{
			for (int j = 0; j < height; j++)
			{
				for (int i = 0; i < width; i++)
				{
					//保存前10帧图片各像素值
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
					junzhi[j][i] += frame.at<uchar>(j, i);//计算均值
					fangcha[j][i] += (fa[j][i][c] - junzhi[j][i]) ^ 2;//求方差
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