#include "main.h"

void transforms1()
{
	/*
	stretch
	shrink
	warp
	rotate
	*/
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	img.convertTo(img, CV_32FC1);
	Mat dst;
	resize(img, dst, Size(img.cols / 2, img.rows / 4), 0, 0, INTER_LINEAR);
	Mat dst2;
	pyrDown(img, dst2);
	vector<Mat> dst2s;
	buildPyramid(img, dst2s, 4);
	Mat dst3;
	pyrUp(dst2, dst3);
	Mat dst4;
	dst4 = img - dst3;
	cout << endl;
}

void transforms_mappings()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	cv::Point2f srcTri[] = {
		cv::Point2f(0,0), // src Top left
		cv::Point2f(img.cols - 1, 0), // src Top right
		cv::Point2f(0, img.rows - 1) // src Bottom left
	};
	cv::Point2f dstTri[] = {
		cv::Point2f(img.cols*0.f, img.rows*0.33f), // dst Top left
		cv::Point2f(img.cols*0.85f, img.rows*0.25f), // dst Top right
		cv::Point2f(img.cols*0.15f, img.rows*0.7f) // dst Bottom left
	};
	Mat m = getAffineTransform(srcTri, dstTri);
	Mat dst;
	warpAffine(img, dst, m, img.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(128));

	cv::Point2f center(img.cols*0.5f, img.rows*0.5f);
	double angle = 45, scale = (cos((angle - 60)* CV_PI / 180) + 1.05)*0.8;
	Mat m2 = getRotationMatrix2D(center, angle, scale);
	Mat dst2;
	warpAffine(img, dst2, m2, img.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(128));

	// cv::transform() : sparse affine transformations

	Mat m3;
	invertAffineTransform(m, m3);
	Mat dst3;
	warpAffine(dst, dst3, m3, dst.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(128));

	cv::Point2f srcQuad[] = {
		cv::Point2f(0, 0), // src Top left
		cv::Point2f(img.cols - 1, 0), // src Top right
		cv::Point2f(img.cols - 1, img.rows - 1), // src Bottom right
		cv::Point2f(0, img.rows - 1) // src Bottom left
	};
	cv::Point2f dstQuad[] = {
	cv::Point2f(img.cols*0.05f, img.rows*0.33f),
	cv::Point2f(img.cols*0.9f, img.rows*0.25f),
	cv::Point2f(img.cols*0.8f, img.rows*0.9f),
	cv::Point2f(img.cols*0.2f, img.rows*0.7f)
	};
	Mat m4 = getPerspectiveTransform(srcQuad, dstQuad);
	Mat dst4;
	warpPerspective(img, dst4, m4, img.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(128));
	// cv::perspectiveTransform(): Sparse perspective transformations
	
	Mat sobelX, sobelY;
	Sobel(img, sobelX, CV_32F, 1, 0, 3, 1.0, 0.0, BORDER_DEFAULT);
	Sobel(img, sobelY, CV_32F, 0, 1, 3, 1.0, 0.0, BORDER_DEFAULT);
	Mat imgMagnitude, imgAngle;
	cartToPolar(sobelX, sobelY, imgMagnitude, imgAngle);
	Mat sobelX2, sobelY2;
	polarToCart(imgMagnitude, imgAngle, sobelX2, sobelY2);

	Mat dst5;
	logPolar(img, dst5, Point2f(img.cols / 2.0, img.rows / 2.0), 1.0, INTER_LINEAR || WARP_FILL_OUTLIERS); // ???

	// arbitrary mappings
	// cv::remap()

	cout << endl;
}

void image_repair()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath);
	Mat inpaintMask = Mat::zeros(img.size(), CV_8U);//mask;
	Mat inpainted;
	line(inpaintMask, Point(img.cols / 4, img.rows / 2), Point(img.cols-1, img.rows / 2), Scalar::all(255), 5, 8, 0);//mask
	line(img, Point(img.cols / 4, img.rows/2), Point(img.cols-1, img.rows / 2), Scalar::all(255), 5, 8, 0);//mask
	inpaint(img, inpaintMask, inpainted, 3, INPAINT_TELEA);

	// cv::fastNlMeansDenoising()
	// cv::fastNlMeansDenoisingColored()
	Mat dst;
	fastNlMeansDenoisingColored(img, dst); // take very much time

	cout << endl;
}

void histogram_equalization()
{
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath, 0);
	Mat dst;
	equalizeHist(img, dst);
	cout << endl;
}

void opencv_07_transforms()
{
	cout << "entry opencv_07_transforms " << endl;
	int index = 3;
	switch (index)
	{
	case 0: transforms1(); break;
	case 1: transforms_mappings(); break;
	case 2: image_repair(); break;
	case 3: histogram_equalization(); break;
	default:break;
	}
	cout << "quit opencv_07_transforms " << endl;
}