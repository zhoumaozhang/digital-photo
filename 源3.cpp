#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("C:/Users/dell/Pictures/������������/4.jpg", 1);
	if (srcMat.empty()) return -1;

	//�任ǰ���ĵ�����
	const cv::Point2f pst1[] = { cv::Point2f(150,150),
									cv::Point2f(150,230),
									cv::Point2f(350,300),
									cv::Point2f(350,150)};
	//�任����ĵ�����
	const cv::Point2f pst2[] = { cv::Point2f(200,150),
									cv::Point2f(200,300),
									cv::Point2f(340,270),
									cv::Point2f(340,180)};
	//����ͶӰ����
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pst1, pst2);

	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());


	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
	return 0;

}