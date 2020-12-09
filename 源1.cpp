#include <opencv2/opencv.hpp> 
#include <iostream> 


using namespace std;
using namespace cv;

int main()

{
	double gamma = 0.3;
	double lut[256];
	Mat srcMat = imread("D:/2020/�γ�/����ͼ����/ͼƬ/11/ͼƬ1.jpg");
	imshow("srcMat", srcMat);

	double temp;//����gamma��
	for (int i = 0; i <= 255; ++i)
	{
		temp = double(i) / 255;
		temp = pow(temp, gamma);
		lut[i] = unsigned char(temp * 255);
	}

	//��ͨ�����صĴ�����
	int height = srcMat.rows; //����
	int width = srcMat.cols; //ÿ��Ԫ�ص���Ԫ������
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			//��һ��
			/*srcMat.at<Vec3b>(j, i)[0] /= 255*255;
			srcMat.at<Vec3b>(j, i)[1] /= 255 * 255;
			srcMat.at<Vec3b>(j, i)[2] /= 255 * 255;*/
			//����һ��
			srcMat.at<Vec3b>(j, i)[0] = lut[srcMat.at<Vec3b>(j, i)[0]];
			srcMat.at<Vec3b>(j, i)[1] = lut[srcMat.at<Vec3b>(j, i)[1]];
			srcMat.at<Vec3b>(j, i)[2] = lut[srcMat.at<Vec3b>(j, i)[2]];
		}

	}
	imshow("srcMat_gamma", srcMat);

	waitKey(0);

	return 0;

}