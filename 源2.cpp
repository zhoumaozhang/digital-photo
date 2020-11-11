#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	cv::Mat src = cv::imread("D:/2020/课程/数字图像处理/图片/7/1.jpg", 1);
	cv::Mat dst;

	std::vector<cv::Vec4i> lines;
	cv::Mat canny;
	Canny(src, canny, 100, 200);
	cv::HoughLinesP(canny, lines, 1, CV_PI / 180, 30, 0, 20);

	std::vector<cv::Vec4i>::iterator it = lines.begin();
	int i = 0;
	for (; it != lines.end(); ++it)
	{
		cv::Point pt1, pt2;

		pt1.x = lines[i][0];
		pt1.y = lines[i][1];
		pt2.x = lines[i][2];
		pt2.y = lines[i][3];
		i++;
		cv::line(src, pt1, pt2, cv::Scalar(0, 0, 255), 1, CV_AA);

	}

	cv::imshow("canny", canny);
	cv::imshow("src", src);

	waitKey(0);
	return 0;
}