#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	VideoCapture cap;

	cap.open(0);

	if (!cap.isOpened())
	{
		std::cout << "���ܴ������ļ�" << std::endl;
		return-1;
	}


	while (1)
	{
		cv::Mat frame, dstMat_blur, dstMat_median, dstMat_G, dx, dy;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ������ļ��ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			blur(frame, dstMat_blur, Size(5, 5));//��ֵ�˲�
			GaussianBlur(frame, dstMat_G, Size(5, 5), 1, 1);//��˹�˲�
			medianBlur(frame, dstMat_median, 5);//��ֵ�˲�

			//��Ե��ȡ
			Sobel(frame, dx, CV_16SC1, 1, 0, 3);
			Sobel(frame, dy, CV_16SC1, 0, 1, 3);

			cv::imshow("frame", frame);
			cv::imshow("dstMat_blur", dstMat_blur);
			cv::imshow("dstMat_median", dstMat_median);
			cv::imshow("dstMat_G", dstMat_G);


		}
		waitKey(30);
	}

	return 0;

}