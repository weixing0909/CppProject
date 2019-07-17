#include "main.h"

void find_contours()
{
	string imagePath = "D:\\dataset\\test_image/star.jpg";
	Mat img = imread(imagePath, 0);

	Mat dst;
	threshold(img, dst, 128, 255, THRESH_BINARY_INV);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	/*
	RETR_EXTERNAL
	RETR_LIST
	RETR_CCOMP
	RETR_TREE
	*/
	//findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	findContours(dst, contours, cv::noArray(), RETR_TREE, CHAIN_APPROX_SIMPLE);
	//findContours(dst, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
	Mat img2 = img.clone();
	drawContours(img2, contours, -1, Scalar::all(180));

	string imagePath3 = "D:\\dataset\\test_image\\LO3/HandIndoorColor.jpg";
	Mat img3 = imread(imagePath3, IMREAD_GRAYSCALE);
	Mat img_edge;
	threshold(img3, img_edge, 128, 255, THRESH_BINARY);
	Mat labels, centroids, img_color, stats;
	//int i, nccomps = cv::connectedComponents(img_edge, labels);
	int i, nccomps = cv::connectedComponentsWithStats(
		img_edge,
		labels,
		stats,
		centroids
	);
	vector<cv::Vec3b> colors(nccomps + 1);
	colors[0] = cv::Vec3b(0, 0, 0); // background pixels remain black.
	for (i = 1; i <= nccomps; i++) 
	{
		colors[i] = cv::Vec3b(rand() % 256, rand() % 256, rand() % 256);
		if (stats.at<int>(i - 1, cv::CC_STAT_AREA) < 100)
			colors[i] = cv::Vec3b(0, 0, 0); // small regions are painted with black too.
	}
	img_color = cv::Mat::zeros(img3.size(), CV_8UC3);
	for (int y = 0; y < img_color.rows; y++)
	{
		for (int x = 0; x < img_color.cols; x++)
		{
			int label = labels.at<int>(y, x);
			CV_Assert(0 <= label && label <= nccomps);
			img_color.at<cv::Vec3b>(y, x) = colors[label];
		}
	}
	cout << endl;
}

void contours2()
{
	string imagePath3 = "D:\\dataset\\test_image\\LO3/HandIndoorColor.jpg";
	Mat image = imread(imagePath3);
	Mat img;
	cvtColor(image, img, COLOR_BGR2GRAY);
	threshold(img, img, 128, 255, THRESH_BINARY);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarcy;
	findContours(img, contours, hierarcy, RETR_TREE, CHAIN_APPROX_NONE);
	vector<vector<Point>> contours_poly(contours.size());//用于存放折线点集
	Mat drawImg = image.clone();
	for (int i = 0; i < contours.size(); i++)
	{
		if (contours[i].size() < 100)
		{
			continue;
		}
		approxPolyDP(Mat(contours[i]), contours_poly[i], 15, true);

		drawContours(drawImg, contours, i, Scalar(0, 0, 255), 1, 8);  //绘制
		drawContours(drawImg, contours_poly, i, Scalar(0, 255, 0), 1, 8);  //绘制
	}
	double r = arcLength(contours[65], true);
	drawContours(drawImg, contours, 65, Scalar(255, 0, 0));
	Rect r2 = boundingRect(contours[65]);
	rectangle(drawImg, r2, Scalar(0, 255, 0));
	RotatedRect r3 = minAreaRect(contours[65]);
	Point2f p;
	float radius;
	minEnclosingCircle(contours[65], p, radius);
	circle(drawImg, p, radius, Scalar(0, 0, 255));
	RotatedRect r4 = fitEllipse(contours[65]);

	Mat drawImg2 = Mat::zeros(100, 100, CV_8UC3);
	vector<Point> pts;
	for (int i = 0; i < 10; i++)
	{
		Point tmpPt;
		tmpPt.x = i * 10 + rand() % 9 - 4;
		tmpPt.y = i * 10 + rand() % 9 - 4;
		circle(drawImg2, tmpPt, 2, Scalar(0, 0, 255));
		pts.push_back(tmpPt);
	}
	cv::Vec4f line_para;
	cv::fitLine(pts, line_para, cv::DIST_L2, 0, 1e-2, 1e-2);
	cv::Point point0;
	point0.x = line_para[2];
	point0.y = line_para[3];
	double k = line_para[1] / line_para[0]; 
	cv::Point point1, point2;
	point1.x = 0;
	point1.y = k * (0 - point0.x) + point0.y;
	point2.x = 640;
	point2.y = k * (640 - point0.x) + point0.y;
	cv::line(drawImg2, point1, point2, cv::Scalar(0, 255, 0), 1, 8, 0);

	vector<vector<Point> > pts2(1);
	convexHull(contours[65], pts2[0]);
	drawContours(drawImg, pts2, -1, Scalar(0, 0, 255), 1, 8);

	double r5 = pointPolygonTest(contours[65], Point2f(0.0f, 0.0f), true);
	double r6 = pointPolygonTest(contours[65], Point2f(0.0f, 0.0f), false);
	bool r7 = isContourConvex(contours[65]);
	bool r8 = isContourConvex(pts2[0]);
	cout << endl;
}

static vector<Point> sampleContour(const Mat& image, int n = 300) {

	vector<vector<Point> > _contours;
	vector<Point> all_points;
	findContours(image, _contours, RETR_LIST, CHAIN_APPROX_NONE);
	for (size_t i = 0; i < _contours.size(); i++) {
		for (size_t j = 0; j < _contours[i].size(); j++)
			all_points.push_back(_contours[i][j]);

		// If too little points, replicate them
		//
		int dummy = 0;
		for (int add = (int)all_points.size(); add < n; add++)
			all_points.push_back(all_points[dummy++]);

		// Sample uniformly
		random_shuffle(all_points.begin(), all_points.end());
		vector<Point> sampled;
		for (int i = 0; i < n; i++)
			sampled.push_back(all_points[i]);
		return sampled;
	}
}

void matching_contours()
{
	string imagePath = "D:\\dataset\\test_image/star.jpg";
	Mat image = imread(imagePath);
	Mat img;
	cvtColor(image, img, COLOR_BGR2GRAY);
	threshold(img, img, 128, 255, THRESH_BINARY_INV);

	Moments r = moments(img, true);

	Ptr<ShapeContextDistanceExtractor> mysc = createShapeContextDistanceExtractor();
	Mat img3, img4;
	cvtColor(image, img3, COLOR_BGR2GRAY);
	resize(img3, img4, Size(img3.cols / 2, img3.rows / 2));
	vector<Point> c1 = sampleContour(img3);
	vector<Point> c2 = sampleContour(img4);
	float dis = mysc->computeDistance(c1, c2);
	Mat img5 = Mat::zeros(img4.size(), CV_8UC1);
	circle(img5, Point(img5.cols / 2, img5.rows / 2), img5.rows / 4, Scalar(255), -1);
	vector<Point> c3 = sampleContour(img5);
	float dis2 = mysc->computeDistance(c1, c3);

	cv::Ptr<cv::HausdorffDistanceExtractor> ext = createHausdorffDistanceExtractor();
	cout << endl;
}

void opencv_10_contours()
{
	cout << "entry opencv_10_contours " << endl;
	int index = 2;
	switch (index)
	{
	case 0: find_contours(); break;
	case 1: contours2(); break;
	case 2: matching_contours(); break;
	default:break;
	}
    #include "main.h"
	cout << "quit opencv_10_contours " << endl;
}
