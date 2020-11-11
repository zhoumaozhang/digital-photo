#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	cv::Mat src = cv::imread("D:/2020/课程/数字图像处理/图片/7/1.jpg", 0);
	cv::Mat dst;

	std::vector<cv::Vec2f> lines;
	cv::Mat canny;
	Canny(src, canny, 100, 200);
	cv::HoughLines(canny, lines, 1, CV_PI / 180, 100);

	std::vector<cv::Vec2f>::iterator it = lines.begin();
	for (; it != lines.end(); ++it)
	{
		float rho = (*it)[0], theta = (*it)[1];
		cv::Point pt1, pt2;
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a * rho;
		double y0 = b * rho;
		pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
		pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
		pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
		pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
		cv::line(src, pt1, pt2, cv::Scalar(255, 255, 255), 1, CV_AA);

	}

	cv::imshow("canny", canny);
	cv::imshow("src", src);

	waitKey(0);
	return 0;
}