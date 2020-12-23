#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()//画一个矩形，实现模板匹配

{
	
	VideoCapture cap;//实例化一个VideoCapture类，名称为cap
	cap.open(0);
	int cnt = 0;
	cv::Mat tempMat, refMat, resultMat;
	while (1)
	{
		cv::Mat frame;
		cap >> frame;
		if (cnt == 0)
		{
			cnt++;
			Rect2d r;
			r = selectROI(frame, true);
			tempMat = frame(r);
			tempMat.copyTo(refMat);
			destroyAllWindows();
		}

		int match_method = 0;
		matchTemplate(frame, refMat, resultMat, match_method);

		normalize(resultMat, resultMat, 0, 1, NORM_MINMAX, -1, Mat());//归一化

		double minVal,maxVal;
		Point minLoc, maxLoc, matchLoc;

		minMaxLoc(resultMat, &minVal, &maxVal, &minLoc, &maxLoc, Mat());//寻找极值

		//画矩形
		cv::Rect rect;
		rect.x = minLoc.x;
		rect.y = minLoc.y;
		rect.width = refMat.cols;
		rect.height = refMat.rows;
		rectangle(frame, rect, CV_RGB(255, 0, 0), 1, 8, 0);

		imshow("result", frame);
		waitKey(30);
	}




	return 0;

}