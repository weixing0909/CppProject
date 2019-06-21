#include "main.h"

void opencv_04_drawing()
{
	cout << "entry opencv_04_drawing " << endl;
	/*
	cv::circle
	cv::clipLine
	cv::ellipse
	cv::ellipse2Poly
	cv::fillConvexPoly
	cv::fillPoly
	cv::line
	cv::rectangle
	cv::polylines
	*/
	int N = 512;
	Mat m(512, 512, CV_8UC3);
	m.setTo(Scalar(255, 255, 255));
	circle(m, Point(N / 4, N / 4), N / 8, Scalar(255, 0, 0), -1, FILLED);
	circle(m, Point(N / 4, N / 2), N / 8, Scalar(255, 0, 0), 2, LINE_AA);
	line(m, Point(N / 4, N / 4), Point(N / 2, N / 2), Scalar(0, 255, 0), 3, LINE_AA);
	rectangle(m, Rect(N / 5, N / 5, N / 2, N / 2), Scalar(0, 0, 255), 2, LINE_8);
	ellipse(m, Point(N / 2, N / 2), Size(N / 3, N / 5), 30, 0, 360, Scalar(0, 0, 255), 2);
	vector<Point> vP2;
	ellipse2Poly(Point(N / 2, N / 2), Size(N / 3, N / 5), 30, 0, 360, 30, vP2);
	polylines(m, vP2, true, Scalar(0, 0, 0), 2, LINE_4);
	vector<Point> vP;
	vP.push_back(Point(200, 300));
	vP.push_back(Point(100, 400));
	vP.push_back(Point(200, 500));
	vP.push_back(Point(300, 450));
	vP.push_back(Point(250, 300));
	polylines(m, vP, true, Scalar(0, 0, 0), 2, LINE_4);
	fillConvexPoly(m, vP, Scalar(0, 200, 0));
	vP.push_back(Point(200, 300));
	vector<vector<Point> > vvP;
	//fillPoly(m, vvP, Scalar(0, 0, 0)); // ???????????????????????????
	//Mat m2;
	//m.copyTo(m2);
	bool b1 = clipLine(Size(10, 20), Point(1, 1), Point(5, 5));
	bool b2 = clipLine(Size(10, 20), Point(1, 1), Point(50, 50));
	bool b3 = clipLine(Size(10, 20), Point(30, 30), Point(50, 50));
	bool b4 = clipLine(Rect(0, 0, 20, 20), Point(10, 10), Point(50, 50));
	bool b5 = clipLine(Rect(0, 0, 20, 20), Point(30, 30), Point(50, 50));

	int fontFace = FONT_HERSHEY_PLAIN;
	double fontScale = 1.0;
	int baseline = 1;
	putText(m, "asdgqfM", Point(N / 2, N / 2), fontFace, fontScale, Scalar(128, 0, 0), 1);
	Size sz = getTextSize("asdgqfM", fontFace, fontScale, 1, &baseline);
	cout << "quit opencv_04_drawing " << endl;
}