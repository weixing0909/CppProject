#include "main.h"

int image_io_test()
{
	cout << "entry image_io_test " << endl;
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath);
	if (img.empty())
	{
		cout << "image is empty" << endl;
		return -1;
	}
	imshow("win", img);
	Mat imgGray = imread(imagePath, IMREAD_COLOR); //IMREAD_COLOR:1, IMREAD_GRAYSCALE:0
	namedWindow("win2", WINDOW_NORMAL); //WINDOW_AUTOSIZE:1, WINDOW_NORMAL:0
	imshow("win2", imgGray);
	imwrite("result/r1.jpg", img);
	waitKey(0);
	destroyAllWindows();
	return 0;
	cout << "quit image_io_test " << endl;
}

void create_save_image()
{
	cout << "entry create_save_image " << endl;
	int imgW = 256;
	int imgH = 128;
	Mat img = Mat::zeros(Size(imgW, imgH), CV_8UC3);
	Mat img2 = Mat::ones(imgH, imgW, CV_8UC4);
	circle(img2, Point(imgW / 2, imgH / 2), imgH / 2, Scalar(255, 0, 255, 128), imgH / 4);
	Mat img3;
	img3.create(64, 128, CV_32FC1);
	Mat img4(imgH, imgW, CV_64FC4, Scalar(0, 0, 255, 128));
	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION); //PNG格式图片的压缩级别  
	compression_params.push_back(9);  //这里设置保存的图像质量级别
	imwrite("result/r2.png", img4, compression_params);
	Mat img5 = img2.row(0).clone();
	cout << "quit create_save_image " << endl;
}

int video_io_test()
{
	cout << "entry video_io_test " << endl;
	string videoPath = "D:\\dataset\\test_image/test.avi";
	VideoCapture cap;
	cap.open(videoPath);
	if (!cap.isOpened())
	{
		return 0;
	}
	cout << "cap: " << cap.get(CAP_PROP_FPS) << endl;
	for (int i = 0; i < CV__CAP_PROP_LATEST; i++)
	{
		cout << "cap: " << i << ": " << cap.get(i) << endl;
	}
	namedWindow("video", WINDOW_NORMAL);
	namedWindow("win", WINDOW_NORMAL);
	Mat frame;
	while (false)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
		imshow("win", frame);
		waitKey(30);
	}
	double fps = cap.get(CAP_PROP_FPS);
	Size size(int(cap.get(CAP_PROP_FRAME_WIDTH)), int(cap.get(CAP_PROP_FRAME_HEIGHT)));
	VideoWriter writer;
	writer.open("result/v1.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

	int frames = cap.get(CAP_PROP_FRAME_COUNT);
	createTrackbar("time", "video", 0, frames);
	int loop_flag = 0;
	cap.set(CAP_PROP_POS_FRAMES, 0);
	loop_flag = int(cap.get(CAP_PROP_POS_FRAMES));
	int pos = loop_flag;
	while (true)
	{
		if (loop_flag == pos)
		{
			loop_flag = loop_flag + 1;
			cap >> frame;
			setTrackbarPos("time", "video", loop_flag);
		}
		else
		{
			pos = getTrackbarPos("time", "video");
			loop_flag = pos;
			cap.set(CAP_PROP_POS_FRAMES, pos);
			continue;
		}
		if (frame.empty())
		{
			break;
		}
		writer << frame;
		imshow("win", frame);
		char c = waitKey(30);
		if (c == 'q')
		{
			break;
		}
	}
	writer.release();
	cap.release();
	destroyAllWindows();
	cout << "quit video_io_test " << endl;
	return 0;
}

void Mat_property_and_function()
{
	cout << "entry Mat_property_and_function " << endl;
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath);
	cout << "img.empty() " << img.empty() << endl;
	cout << "img.size() " << img.size() << endl;
	cout << "img.channels() " << img.channels() << endl;
	cout << "img.depth() " << img.depth() << endl;
	cout << "img.type() " << img.type() << endl;
	cout << "img.elemSize() " << img.elemSize() << endl;//one pixel
	cout << "img.elemSize1() " << img.elemSize1() << endl;//one channel of one pixel, uchar:1, float:4
	cout << "img.step " << img.step << endl;
	cout << "img.cols " << img.cols << endl;
	cout << "img.rows " << img.rows << endl;
	cout << "img.data " << &img.data << endl;
	cout << "img.dims " << img.dims << endl;
	Mat img2 = img(Rect(img.cols / 4, img.rows / 4, img.cols / 2, img.rows / 2));
	Size size;
	Point p;
	img2.locateROI(size, p);
	img2.adjustROI(p.y, size.height - p.y - img2.rows, p.x, size.width - p.x - img2.cols);
	Mat img3;
	img2.convertTo(img3, CV_32FC4);//equal CV_32FC3
	cout << "img3.elemSize1() " << img3.elemSize1() << endl;
	img.release();
	cout << "quit Mat_property_and_function " << endl;
}

void operate_pixel()
{
	cout << "entry operate_pixel " << endl;
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath);
	int w = img.cols;
	int h = img.rows;
	int step = img.step;
	img.at<Vec3b>(1, 0) = Vec3b(0, 0, 255); //at<type>(y,x)
	img.data[2 * step + 1 * 3 + 0] = 0;
	img.data[2 * step + 1 * 3 + 1] = 255;
	img.data[2 * step + 1 * 3 + 2] = 0;
	uchar *dataRow = img.data + 3 * step;
	dataRow[2 * 3 + 0] = 0;
	dataRow[2 * 3 + 1] = 255;
	dataRow[2 * 3 + 2] = 0;

	cout << "quit operate_pixel " << endl;
}

void calculate_time()
{
	cout << "entry calculate_time " << endl;
	int64 tt = getTickCount();
	for (int i = 0; i < 10; i++)
	{
		tt = getTickCount();
		cout << "time: " << tt << endl;
	}
	double fre = getTickFrequency();
	cout << "time: " << (getTickCount() - tt) / fre * 1000 << endl;
	cout << "time: " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;
	cout << "quit calculate_time " << endl;
}

void copy_test(Mat _img)
{
	cout << _img.u->refcount << endl;
	Rect r(0, 0, _img.cols / 2, _img.rows / 2);
	_img = _img(r);
	//_img.release();
	cout << _img.u->refcount << endl;
	cout << "quit copy_test " << endl;
}

void copy_test2()
{
	cout << "entry copy_test2 " << endl;
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath);
	cout << img.u->refcount << endl;
	copy_test(img);
	cout << img.u->refcount << endl;
	cout << "quit copy_test2 " << endl;
}

void imencode_imdecode()
{
	cout << "entry imencode_imdecode " << endl;
	string imagePath = "D:\\dataset\\test_image/lena.jpg";
	Mat img = imread(imagePath);
	//int N = 3;
	//Mat img = Mat::zeros(N, N, CV_8UC1);
	vector<uchar> data_encode;
	imencode(".png", img, data_encode);
	string str_encode(data_encode.begin(), data_encode.end());
	int N2 = 1;
	Mat img2 = Mat::zeros(N2, N2, CV_8UC1);
	vector<uchar> data_encode2;
	imencode(".png", img2, data_encode2);

	vector<uchar> data_decode(str_encode.begin(), str_encode.end());
	Mat img_decode = imdecode(data_decode, IMREAD_COLOR);

	ifstream fin(imagePath, ios::in | ios::binary);
	//ifstream fin(imagePath, ios::in);
	if (!fin)
	{
		cout << "no file: " << imagePath << endl;
	}
	string s;
	for (int i = 0; i < 100; i++)
	{
		//fin >> s;
	}
	std::stringstream buffer;
	buffer << fin.rdbuf();
	std::string s2(buffer.str());
	vector<uchar> data_decode2(s2.begin(), s2.end());
	Mat img_decode2 = imdecode(data_decode2, IMREAD_COLOR);

	cout << "quit imencode_imdecode " << endl;
}

void opencv_01_base()
{
	cout << "entry opencv_01_base " << endl;
	int index = 7;
	switch (index)
	{
	case 0:image_io_test(); break;
	case 1:create_save_image(); break;
	case 2:video_io_test(); break;
	case 3:Mat_property_and_function(); break;
	case 4:operate_pixel(); break;
	case 5:calculate_time(); break;
	case 6:copy_test2(); break;
	case 7:imencode_imdecode(); break;
	default:break;
	}
	cout << "quit opencv_01_base " << endl;
}