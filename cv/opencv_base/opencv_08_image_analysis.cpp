#include "main.h"

void convolveDFT(Mat A, Mat B, Mat& C)
{
	// reallocate the output array if needed
	C.create(abs(A.rows - B.rows) + 1, abs(A.cols - B.cols) + 1, A.type());
	Size dftSize;
	// calculate the size of DFT transform
	dftSize.width = getOptimalDFTSize(A.cols + B.cols - 1);
	dftSize.height = getOptimalDFTSize(A.rows + B.rows - 1);

	// allocate temporary buffers and initialize them with 0's
	Mat tempA(dftSize, A.type(), Scalar::all(0));//initial 0
	Mat tempB(dftSize, B.type(), Scalar::all(0));

	// copy A and B to the top-left corners of tempA and tempB, respectively
	Mat roiA(tempA, Rect(0, 0, A.cols, A.rows));
	A.copyTo(roiA);
	Mat roiB(tempB, Rect(0, 0, B.cols, B.rows));
	B.copyTo(roiB);

	// now transform the padded A & B in-place;
	// use "nonzeroRows" hint for faster processing
	dft(tempA, tempA, 0, A.rows);
	dft(tempB, tempB, 0, B.rows);

	// multiply the spectrums;
	// the function handles packed spectrum representations well
	mulSpectrums(tempA, tempB, tempA, DFT_COMPLEX_OUTPUT);
	//mulSpectrums(tempA, tempB, tempA, DFT_REAL_OUTPUT);

	// transform the product back from the frequency domain.
	// Even though all the result rows will be non-zero,
	// you need only the first C.rows of them, and thus you
	// pass nonzeroRows == C.rows
	dft(tempA, tempA, DFT_INVERSE + DFT_SCALE, C.rows);

	// now copy the result back to C.
	tempA(Rect(0, 0, C.cols, C.rows)).copyTo(C);

	// all the temporary buffers will be deallocated automatically
}

void dft_test()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	img.convertTo(img, CV_64F);
	int64 tt = getTickCount();
	Mat dst;
	dft(img, dst);
	int range = 2;
	//dst(Rect(0, 0, dst.cols / 40, dst.rows / 40)).setTo(Scalar(0));
	dst(Rect(dst.cols - dst.cols / range, dst.rows - dst.rows / range, dst.cols / range, dst.rows / range)).setTo(Scalar(0));
	Mat src;
	idft(dst, src);

	Mat k = (Mat_<float>(3, 3) << -1, 0, 1, -1, 0, 1, -1, 0, 1);
	Mat k2;
	dft(k, k2);
	Mat floatI = Mat_<float>(img);
	Mat filteredI;
	convolveDFT(floatI, k, filteredI);

	Mat dst2;
	dct(img, dst2);
	Mat src2;
	idct(dst2, src2);

	cout << "time: " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;
	cout << endl;
}
void integral_test()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	Mat dst;
	integral(img, dst);
	// cv::integral for standard summation integral
	// cv::integral for squared summation integral
	// cv::integral for tilted summation integral
	cout << endl;
}

void canny_test()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	Mat dst1;
	Canny(img, dst1, 15, 45);
	Mat dst2;
	Canny(img, dst2, 30, 90);
	Mat dst3;
	Canny(img, dst3, 30, 90, 5);
	cout << endl;
}

void hough_test()
{
	string imagePath = "D:\\dataset\\test_image/street.jpg";
	Mat image = imread(imagePath);
	Mat img;
	cvtColor(image, img, COLOR_BGR2GRAY);
	Mat dst1;
	Canny(img, dst1, 50, 200);
	vector<Vec2f> lines;
	HoughLines(dst1, lines, 1, CV_PI / 180, 300, 0, 0);
	// cv::HoughLinesP() the progreassive probabilistic hough transform 
	Mat img2;
	image.copyTo(img2);
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(img2, pt1, pt2, Scalar(0, 255, 0), 1);
	}

	string imagePath2 = "D:\\dataset\\test_image/circle.jpg";
	Mat image3 = imread(imagePath2);
	Mat img3;
	cvtColor(image3, img3, COLOR_BGR2GRAY);
	cv::GaussianBlur(img3, img3, Size(5, 5), 0, 0);
	//Mat dst3;
	//Canny(img3, dst3, 40, 60);
	vector<Vec3f> circles;
	HoughCircles(img3, circles, HOUGH_GRADIENT, 1, img3.rows / 10, 100, 60, 0, 0);
	Mat img4;
	image3.copyTo(img4);
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(img4, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		circle(img4, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}
	cout << endl;
}

void segmentation_test()
{
	string imagePath = "D:\\dataset\\test_image/star.jpg";
	Mat image = imread(imagePath);
	Mat imageGray;
	cvtColor(image, imageGray, COLOR_BGR2GRAY);
	imageGray = ~imageGray;
	Mat dst;
	distanceTransform(imageGray, dst, DIST_L2, 5);
	normalize(dst, dst, 0, 255, NORM_MINMAX);

	// cv::floodFill
	// cv::watershed
	// cv::grabCut
	// cv::pyrMeanShiftFiltering
	string imagePath2 = "D:\\dataset\\test_image/201907081015.jpg";
	Mat image2 = imread(imagePath2);
	Mat img3 = image2.clone();
	Rect rect;
	floodFill(img3, Point(20, 20), Scalar(255, 0, 0), &rect, Scalar(10, 10, 10), Scalar(10, 10, 10));
	//Mat mask1(img3.rows + 2, img3.cols + 2, CV_8UC1);
	//floodFill(image2, mask1, Point(20, 20), Scalar(255, 0, 0), &rect, Scalar(10, 10, 10), Scalar(10, 10, 10));
	Mat img4 = image2.clone();
	line(img4, Point(344, 128), Point(438, 224), Scalar(255, 255, 255), 10);
	Mat mask2 = Mat(img4.size(), CV_32S);
	mask2 = Scalar::all(0);
	watershed(image2, mask2);
	
	cout << endl;
}

void opencv_08_image_analysis()
{
	cout << "entry opencv_08_image_analysis " << endl;
	int index = 4;
	switch (index)
	{
	case 0:dft_test(); break;
	case 1:integral_test(); break;
	case 2:canny_test(); break;
	case 3:hough_test(); break;
	case 4:segmentation_test(); break;
	default:break;
	}
	cout << "quit opencv_08_image_analysis " << endl;
}