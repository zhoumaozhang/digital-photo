#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat result;
	cv::Mat srcMat = cv::imread("D:/2020/课程/数字图像处理/图片/4/1.jpg", 0);
	threshold(srcMat, result, 90, 255, THRESH_BINARY);//二值化
	cv::imshow("result", result);

	cv::Mat Imglabels, Imgstats, Imgcentriods;
	int Imglabelnum = connectedComponentsWithStats(result, Imglabels, Imgstats, Imgcentriods);
	cout << Imglabelnum - 1;
	cv::Rect rect;
	for (int i = 0; i < Imglabelnum; i++)//statsMat.at< int>(连通域序号,状态)
	{
		Imgstats.at<int>(i, CC_STAT_AREA); //连通域的面积
		double left = Imgstats.at<int>(i, CC_STAT_LEFT); //连通域的boundingbox的最左边
		double top = Imgstats.at<int>(i, CC_STAT_TOP);//连通域的boundingbox的最上边
		double width = Imgstats.at<int>(i, CC_STAT_WIDTH);//连通域的宽
		double height = Imgstats.at<int>(i, CC_STAT_HEIGHT);//连通域的高
		rect.x = left;
		rect.y = top;
		rect.width = width;
		rect.height = height;

		rectangle(result, rect, CV_RGB(255, 255, 255), 1, 8, 0);//画矩形
	}
	cv::imshow("result'", result);

	waitKey(0);
	return 0;
}