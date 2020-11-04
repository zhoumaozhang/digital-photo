#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:/2020/课程/数字图像处理/图片/6/1.jpg", 1);
	if (srcMat.empty()) return -1;

	int site_rightdown, site_leftdown, site_rightup;
	for (int i = 0; i < srcMat.cols; i++)//找右下点
	{
		if (srcMat.at<Vec3b>(srcMat.rows - 1, i)[0] != 255 || srcMat.at<Vec3b>(srcMat.rows - 1, i)[1] != 255 || srcMat.at<Vec3b>(srcMat.rows - 1, i)[2] != 255)
			site_rightdown = i;
	}
	for (int j = 0; j < srcMat.rows; j++)//找左下点和右上点
	{
		if (srcMat.at<Vec3b>(j, 0)[0] != 255 || srcMat.at<Vec3b>(j, 0)[1] != 255 || srcMat.at<Vec3b>(j, 0)[2] != 255)
			site_leftdown = j;
		if (srcMat.at<Vec3b>(j, srcMat.cols - 1)[0] != 255 || srcMat.at<Vec3b>(j, srcMat.cols - 1)[1] != 255 || srcMat.at<Vec3b>(j, srcMat.cols - 1)[2] != 255)
			site_rightup = j;
	}


	//变换前的三点坐标
	const cv::Point2f src_pt[] = { cv::Point2f(site_rightdown,srcMat.rows - 1),
									cv::Point2f(0,site_leftdown),
									cv::Point2f(srcMat.cols - 1,site_rightup) };
	//变换后的三点坐标
	const cv::Point2f dst_pt[] = { cv::Point2f(srcMat.cols - 1,srcMat.rows - 1),         //右下
									cv::Point2f(0,srcMat.rows - 1),     //左下
									cv::Point2f(srcMat.cols - 1,0) };  //右上
	//计算仿射矩阵
	const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);

	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());


	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
	return 0;

}