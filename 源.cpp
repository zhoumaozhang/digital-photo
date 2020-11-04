#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	cv::Mat edg_Mat;
	cv::Mat src_Mat = cv::imread("C:/Users/dell/Pictures/ﬂŸ¡®ﬂŸ¡®∂Øª≠/4.jpg",1);

	Canny(src_Mat, edg_Mat, 50, 150);

	cv::imshow("src_Mat", src_Mat);
	cv::imshow("edg_Mat", edg_Mat);
	cv::waitKey(0);

	return 0;

}