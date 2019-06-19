#include "main.h"

void save_image_test()
{
	Mat img = imread("D:/temp/aaa/a1.png");
	imwrite("D:/temp/aaa/a2.JPEG", img);
	cout << "endl" << endl;
}

void operate_element()
{
	Mat img = imread("D:/dataset/test_image/lena.jpg");
	Mat img2;
	img.copyTo(img2);
	double tt = getTickCount();
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			img2.at<Vec3b>(i, j)[0] /= 2;
			img2.at<Vec3b>(i, j)[1] /= 2;
			img2.at<Vec3b>(i, j)[2] /= 2;
		}
	}
	cout << "time1 : " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;

	img.copyTo(img2);
	tt = getTickCount();
	for (int i = 0; i < img.rows; i++)
	{
		uchar *pointer = img2.ptr<uchar>(i);
		for (int j = 0; j < img.cols; j++)
		{
			pointer[j * 3 + 0] /= 2;
			pointer[j * 3 + 1] /= 2;
			pointer[j * 3 + 2] /= 2;
		}
	}
	cout << "time2 : " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;

	img.copyTo(img2);
	tt = getTickCount();
	uchar *p = (uchar *)img2.data;
	int step = img2.step;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			p[i*step + j * 3 + 0] /= 2;
			p[i*step + j * 3 + 1] /= 2;
			p[i*step + j * 3 + 2] /= 2;
		}
	}
	cout << "time3 : " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;
	/*
	time1 : 18.4394
	time2 : 0.735856
	time3 : 1.30076
	so method 2nd is fastest
	*/
	cout << "endl" << endl;
}

int convert_hwc()
{
	/*
	//create dummy 3 channel float image
	cv::Mat sourceRGB(cv::Size(100, 100), CV_32FC3);
	auto size = sourceRGB.size();
	for (int y = 0; y < size.height; ++y)
	{
		for (int x = 0; x < size.width; ++x)
		{
			float* pxl = sourceRGB.ptr<float>(x, y);
			*pxl = x / 100.0f;
			*(pxl + 1) = y / 100.0f;
			*(pxl + 2) = (y / 100.0f) * (x / 100.0f);
		}
	}
	*/
	cv::Mat sourceRGB = cv::imread("D:/dataset/test_image/lena.jpg");
	sourceRGB.convertTo(sourceRGB, CV_32FC3);
	auto size = sourceRGB.size();
	//cv::imshow("test", sourceRGB);
	//cv::waitKey(0);

	//create single image with all 3 channels one after the other
	cv::Size newsize(size.width, size.height * 3);
	cv::Mat destination(newsize, CV_32FC1);

	//copy the channels from the source image to the destination
	for (int i = 0; i < sourceRGB.channels(); ++i)
	{
		cv::extractChannel(
			sourceRGB,
			cv::Mat(
				size.height,
				size.width,
				CV_32FC1,
				&(destination.at<float>(size.height*size.width*i))),
			i);
	}
	sourceRGB.convertTo(sourceRGB, CV_32FC(512));
	cout << sourceRGB.channels() << endl;
	cout << sourceRGB.rows << endl;
	cout << sourceRGB.cols << endl;
	//cv::imshow("test", destination);
	//cv::waitKey(0);
	return 0;
}

void make_dir(string _dirName)
{

}

int main(int argc, char** argv)
{
	cout << "entry opencv base practice" << endl;
	int index = 6;
	switch (index)
	{
	case 1:save_image_test(); break;
	case 2:operate_element(); break;
	case 3:convert_hwc(); break;
	case 4:opencv_01_base(); break;
	case 5:opencv_02_data_type(); break;
	case 6:opencv_03_array_operations(); break;
	default:break;
	}
	cout << "quit opencv base practice" << endl;
    return 0;
}