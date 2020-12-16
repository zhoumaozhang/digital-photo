#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	VideoCapture cap;
	cap.open(0);
	cv::Mat frame;
	cv::Mat bgMat;
	cv::Mat subMat;
	cv::Mat bny_Mat;
	int cnt = 0;
	while (1)
	{
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		if (cnt == 0)
		{
			frame.copyTo(bgMat);
			cnt++;
		}
		else
		{
			absdiff(frame, bgMat, subMat);
			threshold(subMat, bny_Mat, 50, 255, CV_THRESH_BINARY);

			imshow("b_subMat", bny_Mat);
			imshow("subMat", subMat);
			waitKey(30);
		}
	}

	return 0;

}