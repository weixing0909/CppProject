/*****************************************************************************
*  xueshan similarity judge library                                          *
*  Copyright (C) 2050 Holaverse                                              *
*                                                                            *
*  @file     hv8bp_line.h                                                    *
*  @brief    lengthen line header file                                       *
*  @author   weixing                                                         *
*  @email    xing.wei@holaverse.com                                          *
*  @version  0.0.1.0                                                         *
*  @date     2020/03/20                                                     *
*                                                                            *
*----------------------------------------------------------------------------*
*  2020/03/20 | 0.1.0.0   | weixing      | Create file                       *
*****************************************************************************/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	string template_path = "E:/prj_data/hv_sics_integrated_test_2/t1/resource/191223810000383750.png";
	Mat tmpl_origin = imread(template_path, IMREAD_UNCHANGED);
	vector<Mat> channels;
	split(tmpl_origin, channels);
	Mat tmpl_mask;
	channels[3].copyTo(tmpl_mask);
	vector<Mat> channels_mask;
	Mat tmpl;
	channels.pop_back();
	merge(channels, tmpl);

	string image_path = "E:/dataset/hv_cod/image_c/cod_page_c_detect_test.mp4_20200320_152540.828.png";
	Mat image = imread(image_path);
	cvtColor(image, image, COLOR_BGR2GRAY);
	cvtColor(tmpl, tmpl, COLOR_BGR2GRAY);

	double minVal = -1;
	double maxVal;
	Point maxLoc;
	Point minLoc;
	Mat rst;
	matchTemplate(image, tmpl, rst, TM_CCORR_NORMED);// , tmpl_mask);
	minMaxLoc(rst, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	return 0;
}