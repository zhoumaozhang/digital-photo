#include <iostream>//头文件和命名空间
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);//调用摄像头，并对摄像头取得的帧进行缩放

	double scale = 1;

	//0-180
	//肤色
	double i_minH = 0;
	double i_maxH = 20;
	//0-255
	double i_minS = 43;
	double i_maxS = 255;
	//0-255
	double i_minV = 55;
	double i_maxV = 255;

	while (1)
	{
		Mat frame;
		Mat hsvMat;
		Mat detectMat;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols * scale, frame.rows * scale);//结构体
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);//输入，输出，大小，线性插值

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);//利用cvtColor函数，将原图转换成hsv格式。

		rFrame.copyTo(detectMat);

		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);

		imshow("whie: in the range", detectMat);
		imshow("frame", rFrame);

		waitKey(30);

	}

	return 0;
}