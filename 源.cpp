#include <opencv2/opencv.hpp>
#include "opencv2/features2d.hpp"
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <time.h>
#include <math.h>  
//#include "My_ImageProssing_base.h"
#define WINDOW_NAME1 "�����򴰿�1��"			
#define WINDOW_NAME2 "�����򴰿�2��"	
using namespace cv;
using namespace std;
RNG g_rng(12345);

Mat src_image;
Mat img1;
Mat img2;

//*--------------------------�ֶ�ʵ��HOG������-------------------------------------*/
int angle_lianghua(float angle)
{
	int result = angle / 45;
	return result;
}
int main()
{
	//�ı����̨������ɫ
	system("color 02");

	//��ȡͼ��
	src_image = imread("D:\\opencv_picture_test\\HOG���˼��\\hogTemplate.jpg");
	img1 = imread("D:\\opencv_picture_test\\HOG���˼��\\img1.jpg");
	img2 = imread("D:\\opencv_picture_test\\HOG���˼��\\img2.jpg");
	//�����ж�
	if (!(src_image.data || img1.data || img2.data))
	{
		cout << "image load failed!" << endl;
		return -1;
	}
	//��1������hogTemplate
	//�������ؼ����ݶȺͽǶȷ���
	Mat gx, gy;
	Mat mag, angle;	//��ֵ�ͽǶ�
	Sobel(src_image, gx, CV_32F, 1, 0, 1);
	Sobel(src_image, gy, CV_32F, 0, 1, 1);
	cartToPolar(gx, gy, mag, angle, false);		//false��õ��ǽǶ�

	int cellSize = 16;		//ÿ��cell�Ĵ�С
	int nx = src_image.cols / cellSize;	//ÿ���м���
	int ny = src_image.rows / cellSize;	//ÿ���м���
	int cellnums = nx * ny;	//�м���cell
	int bins = cellnums * 8;
	float* ref_hist = new float[bins];
	memset(ref_hist, 0, sizeof(float) * bins);
	int binnum = 0;
	//����һ��ͼ
	for (int j = 0; j < ny; j++)
	{
		for (int i = 0; i < nx; i++)
		{
			//����ÿ��cell��ֱ��ͼ
			for (int y = j * cellSize; y < (j + 1) * cellSize; y++)
			{
				for (int x = i * cellSize; x < (i + 1) * cellSize; x++)
				{
					//�ԽǶȽ�������
					int tempangle1 = 0;
					float tempangle2 = angle.at<float>(y, x);	//��ǰ���صĽǶ�ֵ
					tempangle1 = angle_lianghua(tempangle2);	//��ǰcell�ĽǶȷ���
					float magnitude = mag.at<float>(y, x);		//��ǰ���صķ���ֵ
					ref_hist[tempangle1 + binnum * 8] += magnitude;				//�������м��ϵ�ǰ��
				}
			}
			binnum++;	//cell��Ŀ+1
		}
	}
	//��2������img1
		//�������ؼ����ݶȺͽǶȷ���
	Mat gx_img1, gy_img1;
	Mat mag_img1, angle_img1;	//��ֵ�ͽǶ�
	Sobel(img1, gx_img1, CV_32F, 1, 0, 1);
	Sobel(img1, gy_img1, CV_32F, 0, 1, 1);
	cartToPolar(gx_img1, gy_img1, mag_img1, angle_img1, false);		//false��õ��ǽǶ�
	nx = img1.cols / cellSize;	//ÿ���м���
	ny = img1.rows / cellSize;	//ÿ���м���
	cellnums = nx * ny;	//�м���cell
	bins = cellnums * 8;
	float* ref_hist_img1 = new float[bins];
	memset(ref_hist_img1, 0, sizeof(float) * bins);
	binnum = 0;
	//����һ��ͼ
	for (int j = 0; j < ny; j++)
	{
		for (int i = 0; i < nx; i++)
		{
			//����ÿ��cell��ֱ��ͼ
			for (int y = j * cellSize; y < (j + 1) * cellSize; y++)
			{
				for (int x = i * cellSize; x < (i + 1) * cellSize; x++)
				{
					//�ԽǶȽ�������
					int tempangle1 = 0;
					float tempangle2 = angle_img1.at<float>(y, x);	//��ǰ���صĽǶ�ֵ
					tempangle1 = angle_lianghua(tempangle2);	//��ǰcell�ĽǶȷ���
					float magnitude = mag_img1.at<float>(y, x);		//��ǰ���صķ���ֵ
					ref_hist_img1[tempangle1 + binnum * 8] += magnitude;				//�������м��ϵ�ǰ��
				}
			}
			binnum++;	//cell��Ŀ+1
		}
	}
	//��3������img2
	//�������ؼ����ݶȺͽǶȷ���
	Mat gx_img2, gy_img2;
	Mat mag_img2, angle_img2;	//��ֵ�ͽǶ�
	Sobel(img2, gx_img2, CV_32F, 1, 0, 1);
	Sobel(img2, gy_img2, CV_32F, 0, 1, 1);
	cartToPolar(gx_img2, gy_img2, mag_img2, angle_img2, false);		//false��õ��ǽǶ�
	nx = img2.cols / cellSize;	//ÿ���м���
	ny = img2.rows / cellSize;	//ÿ���м���
	cellnums = nx * ny;	//�м���cell
	bins = cellnums * 8;
	float* ref_hist_img2 = new float[bins];
	memset(ref_hist_img2, 0, sizeof(float) * bins);
	binnum = 0;
	//����һ��ͼ
	for (int j = 0; j < ny; j++)
	{
		for (int i = 0; i < nx; i++)
		{
			//����ÿ��cell��ֱ��ͼ
			for (int y = j * cellSize; y < (j + 1) * cellSize; y++)
			{
				for (int x = i * cellSize; x < (i + 1) * cellSize; x++)
				{
					//�ԽǶȽ�������
					int tempangle1 = 0;
					float tempangle2 = angle_img2.at<float>(y, x);	//��ǰ���صĽǶ�ֵ
					tempangle1 = angle_lianghua(tempangle2);	//��ǰ���صĽǶȷ���
					float magnitude = mag_img2.at<float>(y, x);		//��ǰ���صķ���ֵ
					ref_hist_img2[tempangle1 + binnum * 8] += magnitude;				//�������м��ϵ�ǰ��
				}
			}
			binnum++;	//cell��Ŀ+1
		}
	}
	//��4���ֱ����ref_hist_img1��ref_hist\ref_hist_img2��ref_hist�ľ�
	int result1 = 0;
	int result2 = 0;
	for (int i = 0; i < bins; i++)
	{
		//��������㣬������ƽ����,���Ǽ���abs
		result1 += abs(ref_hist[i] - ref_hist_img1[i]);
		result2 += abs(ref_hist[i] - ref_hist_img2[i]);
	}
	cout << result1 << endl;
	cout << result2 << endl;
	if (result1 < result2)
	{
		cout << "img1����ԭͼ����" << endl;
	}
	else
		cout << "img2����ԭͼ����" << endl;
	waitKey(0);
	delete[] ref_hist;
	delete[] ref_hist_img1;
	delete[] ref_hist_img2;
	return 0;
}
