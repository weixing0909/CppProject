#include "main.h"

void histogram_test()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat image = imread(imagePath);

	vector<Mat> rgb_planes;
	split(image, rgb_planes);
	int histSize = 255;
	float range[] = { 0, 255 };
	const float* histRange = { range };
	bool uniform = true; bool accumulate = false;
	Mat r_hist, g_hist, b_hist;
	calcHist(&rgb_planes[0], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&rgb_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&rgb_planes[2], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);

	Mat img2;
	image.convertTo(img2, CV_32F);
	Mat dst;
	normalize(img2, dst, 255, NORM_L2);

	// cv::threshold
	// cv::minMaxLoc
	// cv::minMaxIdx
	// cv::compareHist
	

	cout << endl;
}

void sophisticated_histograms_methods()
{
	// cv::EMD
	// cv::calcBackProject
	cout << endl;
}

void template_matching()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat image = imread(imagePath);
	Mat templ = image(Rect(226, 234, 125, 135)).clone();
	Mat dst;
	matchTemplate(image, templ, dst, TM_SQDIFF);
	cv::normalize(dst, dst, 1, 0, NORM_MINMAX);
	cout << endl;
}


void opencv_09_histogram()
{
	cout << "entry opencv_09_histogram " << endl;
	int index = 2;
	switch (index)
	{
	case 0: histogram_test(); break;
	case 1: sophisticated_histograms_methods(); break;
	case 2: template_matching(); break;
	default:break;
	}
	cout << "quit opencv_09_histogram " << endl;
}