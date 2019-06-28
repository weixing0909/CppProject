#include "main.h"

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

int main(int argc, char** argv)
{
	cout << "entry opencv base practice" << endl;
	int index = 9;
	switch (index)
	{
	case 3:convert_hwc(); break;
	case 4:opencv_01_base(); break;
	case 5:opencv_02_data_type(); break;
	case 6:opencv_03_array_operations(); break;
	case 7:opencv_04_drawing(); break;
	case 8:opencv_05_functors(); break;
	case 9:opencv_06_filters(); break;
	default:break;
	}
	cout << "quit opencv base practice" << endl;
    return 0;
}