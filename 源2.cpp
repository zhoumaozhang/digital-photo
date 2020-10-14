#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


string window_name = "binaryMat";

void threshod_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);

	Mat dst;
	//��ֵ��
	threshold(src, dst, th, 255, 0);

	imshow(window_name, dst);

}

int main()
{
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;

	srcMat = imread("C:/Users/dell/Pictures/������������/4.jpg");
	if (!srcMat.data)//�ж�ͼ���Ƿ�����
	{
		cout << "ͼ������ʧ��" << endl;
		return 0;
	}
	// imshow(window_name,Image);
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);//ת���ɻҶ�ͼ
	imshow(window_name, gryMat);
	createTrackbar("threshold",//����������
		window_name,//��������
		&lowTh,//Ĭ�ϳ�ʼֵ
		maxTh,//���ֵ
		threshod_Mat,//�ص�������
		&gryMat);//���뺯��������
	waitKey(0);


	return 0;
}