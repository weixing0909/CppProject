#include "main.h"

void make_border_test()
{
	//BORDER_CONSTANT = 0, //!< `iiiiii|abcdefgh|iiiiiii`  with some specified `i`
	//BORDER_REPLICATE = 1, //!< `aaaaaa|abcdefgh|hhhhhhh`
	//BORDER_REFLECT = 2, //!< `fedcba|abcdefgh|hgfedcb`
	//BORDER_WRAP = 3, //!< `cdefgh|abcdefgh|abcdefg`
	//BORDER_REFLECT_101 = 4, //!< `gfedcb|abcdefgh|gfedcba`
	//BORDER_TRANSPARENT = 5, //!< `uvwxyz|abcdefgh|ijklmno`
	//
	//BORDER_REFLECT101 = BORDER_REFLECT_101, //!< same as BORDER_REFLECT_101
	//BORDER_DEFAULT = BORDER_REFLECT_101, //!< same as BORDER_REFLECT_101
	//BORDER_ISOLATED = 16 //!< do not look outside of ROI

	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath);
	int N = 10;
	Mat img2;
	copyMakeBorder(img, img2, N, N, N, N, cv::BORDER_CONSTANT, Scalar(0, 255, 0));
	Mat img3;
	copyMakeBorder(img, img3, N, N, N, N, cv::BORDER_REPLICATE);
	Mat img4;
	copyMakeBorder(img, img4, N, N, N, N, cv::BORDER_REFLECT);
	Mat img5;
	copyMakeBorder(img, img5, N, N, N, N, cv::BORDER_WRAP);
	Mat img6;
	copyMakeBorder(img, img6, N, N, N, N, cv::BORDER_REFLECT_101);
	//Mat img7;
	//copyMakeBorder(img, img7, N, N, N, N, cv::BORDER_TRANSPARENT);

	// cv::borderInterpolate() ???
	cout << endl;
}

void filters_threshold_test()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath);
	Mat imgBinary;
	double a = threshold(img, imgBinary, 128, 255, THRESH_BINARY);
	// THRESH_BINARY
	// THRESH_BINARY_INV
	// THRESH_TRUNC
	// THRESH_TOZERO
	// THRESH_TOZERO_INV
	// THRESH_MASK
	// THRESH_OTSU
	// THRESH_TRIANGLE

	vector<Mat> planes;
	split(img, planes);
	cv::Mat b = planes[0], g = planes[1], r = planes[2], s;
	cv::addWeighted(r, 1. / 3., g, 1. / 3., 0.0, s);
	cv::addWeighted(s, 1., b, 1. / 3., 0.0, s);
	Mat dst;
	cv::threshold(s, dst, 100, 100, cv::THRESH_TRUNC);

	Mat dst2;
	Mat img2;
	cvtColor(img, img2, COLOR_BGR2GRAY);
	double a2 = threshold(img2, dst2, 0, 255, THRESH_OTSU);

	Mat dst3;
	adaptiveThreshold(img2, dst3, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 31, 0);
	cout << endl;
}

void filters_smooth_test()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	Mat dst;
	Size ksize(3, 3);
	blur(img, dst, ksize, Point(-1, -1), BORDER_DEFAULT);
	Mat dst2;
	//boxFilter(img, dst2, -1, ksize, Point(-1, -1), true, BORDER_DEFAULT);
	boxFilter(img, dst2, CV_32F, ksize, Point(-1, -1), true, BORDER_DEFAULT);
	Mat dst3;
	medianBlur(img, dst3, 3);
	Mat dst4;
	GaussianBlur(img, dst4, ksize, 1.0, 0.0, BORDER_DEFAULT);
	Mat dst5;
	bilateralFilter(img, dst5, 3, 1.0, 1.0, BORDER_DEFAULT);
	cout << endl;
}

void filters_gradients_test()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	Mat dst;
	Sobel(img, dst, CV_8U, 1, 0, 3, 1.0, 0.0, BORDER_DEFAULT);
	Mat dst2;
	Sobel(img, dst2, CV_8U, 0, 1, 3, 1.0, 0.0, BORDER_DEFAULT);
	Mat dst3;
	Sobel(img, dst3, CV_8U, 0, 1,-1, 1.0, 0.0, BORDER_DEFAULT);
	Mat dst4;
	Laplacian(img, dst4, CV_8U, 3, 1.0, 0.0, BORDER_DEFAULT);

	cout << endl;
}

void filters_morphology()
{
	/*
	Erosion
	Dilation
	Opening
	Closing
	Grad
	TopHat
	BlackHat
	*/
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	//threshold(img, img, 128, 255, THRESH_BINARY);
	Mat k = getStructuringElement(MORPH_CROSS, Size(5, 5), Point(-1, -1));
	Mat dst;
	erode(img, dst, k, Point(-1, -1), BORDER_DEFAULT); // erode(x,y) = min src(x+i, y+j) (i,j) in kernel
	Mat dst2;
	dilate(img, dst2, k, Point(-1, -1), BORDER_DEFAULT); // erode(x,y) = min src(x+i, y+j) (i,j) in kernel
	Mat dst3;
	morphologyEx(img, dst3, MORPH_OPEN, k);
	Mat dst4;
	morphologyEx(img, dst4, MORPH_CLOSE, k);
	Mat dst5;
	morphologyEx(img, dst5, MORPH_GRADIENT, k);
	Mat dst6;
	morphologyEx(img, dst6, MORPH_TOPHAT, k);
	Mat dst7;
	morphologyEx(img, dst7, MORPH_BLACKHAT, k);
	// MORPH_HITMISS
	cout << endl;
}

void filters_convolution()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	Mat kx, ky;
	getDerivKernels(kx, ky, 2, 1, 7);
	Mat g = getGaussianKernel(5, 10.0);
	Mat k2 = g * g.t();
	Mat dst;
	filter2D(img, dst, CV_8U, k2);
	Mat dst2;
	sepFilter2D(img, dst2, CV_8U, g, g.t());  // 1xn, nx1
	cout << endl;
}

void opencv_06_filters()
{
	cout << "entry opencv_06_filters " << endl;
	int index = 5;
	switch (index)
	{
	case 0:make_border_test(); break;
	case 1:filters_threshold_test(); break;
	case 2:filters_smooth_test(); break;
	case 3:filters_gradients_test(); break;
	case 4:filters_morphology(); break;
	case 5:filters_convolution(); break;
	default:break;
	}
	cout << "quit opencv_06_filters " << endl;
}