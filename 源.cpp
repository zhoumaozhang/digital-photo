#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	cv::Mat src = cv::imread("D:/2020/�γ�/����ͼ����/ͼƬ/6/1.jpg", 1);
	cv::Mat dst;
	
	float  angle = -10, scale = 1;
	cv::Point2f center(src.cols / 2, src.rows / 2);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, scale);
	//��ȡ����ı���
	cv::Rect bbox = cv::RotatedRect(center, src.size(), angle).boundingRect();
	//��������������
	rot.at<double>(0, 2) += bbox.width / 2 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2 - center.y;
	//����任
	cv::warpAffine(src, dst, rot, bbox.size());
	cv::imshow("dst",dst);



	waitKey(0);

	return 0;

}