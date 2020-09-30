#include <opencv2/opencv.hpp>


using namespace cv;

int main() {
	cv::Mat srcM = cv::imread("C:/Users/dell/Pictures/ﬂŸ¡®ﬂŸ¡®∂Øª≠/4.jpg");
	cv::Mat deepMat;
	cv::Mat shallowMat;
	srcM.copyTo(deepMat);
	shallowMat = srcM;

	int height = srcM.rows;
	int width = srcM.cols;
	uchar threshold = 100;

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar a = (srcM.at<Vec3b>(j, i)[0] + srcM.at<Vec3b>(j, i)[1] + srcM.at<Vec3b>(j, i)[2]) / 3;
			if (a > threshold)
			{
				a = 255;
			}
			else
			{
				a = 0;
			}
			srcM.at<Vec3b>(j, i)[0] = a;
			srcM.at<Vec3b>(j, i)[1] = a;
			srcM.at<Vec3b>(j, i)[2] = a;
		}
	}

	cv::imshow("deepMat", deepMat);
	waitKey(0);
	cv::imshow("shallowMat", shallowMat);
	waitKey(0);
}