#include "main.h"

/*
cv::Vec, Vec2i, Vec3i, Vec4d
cv::Point
cv::Scalar
cv::Size
cv::Rect
*/

void data_type_point()
{
	cout << "entry data_type_point " << endl;
	Point p1;
	p1.x = 3;
	p1.y = 4;
	Point2i p2(p1);
	Point3d p3(1, 2, 3);
	Vec3d p4 = (Vec3d)p3;
	int x1 = p1.dot(p2);
	double x2 = p1.ddot(p2);
	Point3d p5(1, 0, 0);
	Point3d p6(1, 2, 0);
	Point3d x3 = p5.cross(p6);
	Rect r(0, 0, 20, 20);
	bool b = p1.inside(r);
	cout << "quit data_type_point " << endl;
}

void data_type_scalar()
{
	cout << "entry data_type_scalar " << endl;
	Scalar s;
	s[0] = 1.0;
	s[1] = 2.0;
	s[2] = 3.0;
	s[3] = 4.0;
	Scalar s2(s);
	Scalar s3 = s;
	Scalar s4 = s.mul(s2);
	Scalar s5 = s.conj();
	bool b = s.isReal();
	cout << "quit data_type_scalar " << endl;
}

void data_type_size()
{
	cout << "entry data_type_size " << endl;
	Size sz;
	sz.width = 3;
	sz.height = 4;
	Size sz2(sz);
	Size2f sz3 = sz;
	double a1 = sz.area();
	double a2 = sz.aspectRatio();
	cout << "quit data_type_size " << endl;
}

void data_type_rect()
{
	cout << "entry data_type_rect " << endl;
	Rect r(0, 10, 20, 30);
	Rect r2(r);
	Rect r3(Point(5, 10), Size(10, 20));
	auto a = r.area();
	cout << typeid(a).name() << endl;
	Point tl = r.tl();
	Point br = r.br();
	bool b = r.contains(Point(10, 20));
	Rect r4 = r & r3;
	Rect r5 = r | r3;
	Rect r6 = r + Point(1, 1);
	Rect r7 = r + Size(1,1);
	cout << "quit data_type_rect " << endl;
}

void data_type_rotateRect()
{
	cout << "entry data_type_rotateRect " << endl;
	RotatedRect rr(Point(0, 0), Size(1, 1), 45);
	Rect r = rr.boundingRect();
	Rect_<float> r2 = rr.boundingRect2f();
	Point2f pts[4];
	rr.points(pts);
	float angle = rr.angle;
	cout << "quit data_type_rotateRect " << endl;
}

void data_type_matrix()
{
	cout << "entry data_type_matrix " << endl;
	Matx33f m33f;
	Matx43d m43d;
	Matx32f m32f = Matx32f::all(1);
	Matx32f m32f2(m32f);
	Matx44d m44d = Matx44d::eye();
	Matx21f m21f(1, 2);
	Matx33f m33f2 = Matx33f::randu(-1, 1);
	Matx33f m33f3 = Matx33f::randn(-1,1);
	auto m1 = m33f2;
	auto m2 = m33f2 + m33f3;
	auto m3 = m33f2 - m33f3;
	auto m4 = m33f2 * m33f3;
	//typedef Matx<float, 6, 6> Matx66f;
	//typedef Matx<double, 6, 6> Matx66d;
	//Matx91f m91f = m33f2.reshape<9, 1>();
	auto d = m33f2.diag();
	auto m6 = m33f2.t();
	auto m7 = m33f2.inv();
	Matx31f m31f(1, 3, 7);
	auto m8 = m33f2.solve(m31f);
	auto m9 = Matx33f::all(2).dot(Matx33f::all(3));
	auto m10 = Matx33f::all(2).mul(Matx33f::all(3));
	cout << m10 << endl;
	float a = m10(0, 0);
	cout << "quit data_type_matrix " << endl;
}

void data_type_fixedVector()
{
	cout << "entry data_type_fixedVector " << endl;
	//typedef Vec<uchar, 3> Vec3b;
	Vec3b v(1, 2, 3);
	cout << v << endl;
	uchar a = v(0);
	Vec3f v2 = v;
	auto v3 = v2.cross(v2);
	cout << "quit data_type_fixedVector " << endl;
}

void data_type_complex()
{
	cout << "entry data_type_complex " << endl;
	Complexf z(1, 2);
	float re = z.re;
	float im = z.im;
	Complexf z2 = z.conj();
	cout << "quit data_type_complex " << endl;
}

// Helper Objects
void data_type_helper_objects()
{
	cout << "entry data_type_helper_objects " << endl;
	// temination criteria
	TermCriteria tc(TermCriteria::COUNT, 100, 0.1);
	// cv::Range
	Range r(0, 10);
	Mat m1 = Mat::eye(10, 10, CV_8UC1);
	Mat m2 = m1(Range::all(), Range(1, 3));
	Mat m3 = m1(Range(1, 3), Range::all());
	// cv::Ptr
	Ptr<Matx33f> p = makePtr<Matx33f>();
	Ptr<int> p2(new int);
	cout << *p2 << endl;
	// cv::Exception
	Exception e;
	//CV_Error(1);
	//CV_Error_(1);
	//CV_Assert(1);
	// cv::DataType<>
	//DataType<int> a;
	// cv::InputArray and cv::OutputArray
	InputArray i(m1);
	OutputArray o(m1);

	cout << "quit data_type_helper_objects " << endl;
}

// Utility Functions
void data_type_utility_functions()
{
	cout << "entry data_type_utility_functions " << endl;
	// cv::alignPtr()
	// cv::alignSize()
	// cv::allocate()
	int a = cvCeil(3.56);
	int a2 = cvFloor(3.56);
	int a3 = cvRound(3.56);
	int a4 = cvRound(3.46);
	int a5 = cvRound(3.5);
	double a6 = cubeRoot(27.0);
	// cv::CV_Assert()
	// CV_Error()
	// CV_Error_()
	// cv::deallocate()
	// cv::error()
	// cv::fastAtan2()
	// cv::fastFree()
	// cv::fastMalloc()
	// cv::format()
	int64 a7 = getCPUTickCount();
	int a8 = getNumThreads();
	int a9 = getThreadNum();
	// cv::getOptimalDFTSize()
	int64 a10 = getTickCount();
	double a11 = getTickFrequency();
	float f = 0.111f;
	int a12 = cvIsInf(f);
	int a13 = cvIsNaN(f);
	// cv::setNumThreads()
	// cv::setUseOptimized()
	// cv::useOptimized()

	cout << "quit data_type_utility_functions " << endl;
}

// The Templates Structures
void data_type_templates()
{
	cout << "entry data_type_templates " << endl;
	// cv::Point_<Type T>
	Point_<int> p(1, 2);
	// cv::Rect_<Type T>
	// cv::Vec<Type T, int H>
	// cv::Matx<Type T, int H, int W>
	// cv::Scalar_<Type T>
	cout << "quit data_type_templates " << endl;
}

void data_type_Mat()
{
	cout << "entry data_type_Mat " << endl;
	Mat m;
	m.create(3, 10, CV_32FC3);
	m.setTo(Scalar(1.0f, 1.0f, 1.0f));
	Mat m2(3, 10, CV_32FC3, Scalar(1.0f, 1.0f, 1.0f));
	Mat m3(3, 10, CV_32FC3, m2.data); // row, col, 
	Mat m4(Size(10, 3), CV_32FC3); // Size(width, height)
	Mat m5(Size(10, 3), CV_32FC3, Scalar(1.0f, 2.0f, 3.0f));
	int a[4] = { 2,3,4,5 };
	Mat m6(4, a, CV_32FC3);
	cout << m6.data[0] << endl;
	Mat m7(m);
	m7.at<Vec3f>(0, 0)[1] = 12;
	Mat m8(m, Range(0, 2), Range(0, 4));
	Mat m9(m, Range::all(), Range(0, 4));
	Mat m10(m, Rect(0,0,5,3));
	// cv::Mat(const Mat& mat, const cv::Range* ranges);
	// cv::Mat(const cv::MatExpr& expr);
	MatExpr e;
	e = m * 3;
	Mat m11(e);
	const Vec<float, 3> v(3.0f, 4.0f, 5.0f);
	Mat m12(v);
	// cv::Mat(const cv::Matx<T,m,n>& vec, bool copyData=true);
	int arr[7] = { 0,1,2,3,4,5,6 };
	vector<int> v2(begin(arr), end(arr));
	Mat m13(v2);
	Mat m14 = Mat::zeros(3, 4, CV_8UC1);
	Mat m15 = Mat::ones(3, 4, CV_8UC1);
	Mat m16 = Mat::eye(3, 4, CV_8UC1);
	cout << "quit data_type_Mat " << endl;
}

void accessing_array_elements()
{
	cout << "entry accessing_array_elements " << endl;
	cv::Mat m = cv::Mat::eye(10, 10, CV_32FC1);
	cout << m.at<float>(3, 3) << endl;
	cv::Mat m2 = cv::Mat::eye(10, 10, CV_32FC2);
	cout << m2.at<Vec2f>(3, 3) << endl;
	//cv::Mat m3 = cv::Mat::eye(10, 10, cv::DataType<cv::Complexf>::channel_type);
	float *p = m.ptr<float>(3);
	cout << p[3] << endl;
	cv::Mat m4(2, 2, CV_32FC3);
	randu(m4, -1.0f, 1.0f);
	MatConstIterator_<Vec3f> it = m4.begin<Vec3f>();
	while (it != m4.end<Vec3f>())
	{
		cout << (*it)[0]* (*it)[0]+ (*it)[1] * (*it)[1] + (*it)[2] * (*it)[2] << endl;
		it++;
	}
	float * p2 = (float *)(m4.data);
	cout << "aaa: " << p2[0] << endl;
	
	Mat bigImg(512, 512, CV_32FC3);
	//randu(bigImg, 0.0f, 255.0f);
	bigImg.setTo(Scalar(1.0f, 2.0f, 3.0f));
	int N = 1;
	float sum = 0.0f;
	int64 tt;
	tt = getTickCount();
	for (int n = 0; n < N; n++)
	{
		sum = 0.0f;
		for (int i = 0; i < bigImg.rows; i++)
		{
			for (int j = 0; j < bigImg.cols; j++)
			{
				sum += bigImg.at<Vec3f>(i, j)[0];
				sum += bigImg.at<Vec3f>(i, j)[1];
				sum += bigImg.at<Vec3f>(i, j)[2];
			}
		}
	}
	cout << "sum: " << sum << " , time: " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;

	tt = getTickCount();
	for (int n = 0; n < N; n++)
	{
		sum = 0.0f;
		for (int i = 0; i < bigImg.rows; i++)
		{
			Vec3f *p = bigImg.ptr<Vec3f>(i);
			for (int j = 0; j < bigImg.cols; j++)
			{
				sum += p[j][0];
				sum += p[j][1];
				sum += p[j][2];
			}
		}
	}
	cout << "sum: " << sum << " , time: " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;
	bool b = bigImg.isContinuous();
	int step = bigImg.step;
	int es = bigImg.elemSize1();

	tt = getTickCount();
	float *pp2 = (float *)(bigImg.data);
	for (int n = 0; n < N; n++)
	{
		sum = 0.0f;
		for (int i = 0; i < bigImg.rows; i++)
		{
			for (int j = 0; j < bigImg.cols; j++)
			{
				sum += pp2[i * bigImg.step / es + j * 3 + 0];
				sum += pp2[i * bigImg.step / es + j * 3 + 1];
				sum += pp2[i * bigImg.step / es + j * 3 + 2];
			}
		}
	}
	cout << "sum: " << sum << " , time: " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;

	tt = getTickCount();
	for (int n = 0; n < N; n++)
	{
		sum = 0.0f;
		for (int i = 0; i < bigImg.rows; i++)
		{
			float *pp = (float *)(bigImg.data + i * bigImg.step);
			for (int j = 0; j < bigImg.cols; j++)
			{
				sum += pp[j * 3 + 0];
				sum += pp[j * 3 + 1];
				sum += pp[j * 3 + 2];
			}
		}
	}
	cout << "sum: " << sum << " , time: " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;

	tt = getTickCount();
	MatConstIterator_<Vec3f> it2 = bigImg.begin<Vec3f>();
	for (int n = 0; n < N; n++)
	{
		sum = 0.0f;
		while (it2 != bigImg.end<Vec3f>())
		{
			sum += (*it2)[0];
			sum += (*it2)[1];
			sum += (*it2)[2];
			it2++;
		}
	}

	cout << "sum: " << sum << " , time: " << (getTickCount() - tt) / getTickFrequency() * 1000 << endl;

	cout << "quit accessing_array_elements " << endl;
}

// N-Dimension
void nary_array_iterator()
{
	cout << "entry nary_array_iterator " << endl;
	cout << "quit nary_array_iterator " << endl;
}

void accessing_array_block()
{
	cout << "entry accessing_array_block " << endl;
	Mat m(128, 128, CV_32FC3);
	randu(m, 0.0f, 255.0f);
	Mat m1 = m.row(0);
	Mat m2 = m.col(0);
	Mat m3 = m.rowRange(0, 4);
	Mat m4 = m.rowRange(Range(0, 4));
	Mat m5 = m.colRange(0, 4);
	Mat m6 = m.colRange(Range(0, 4));
	m6.at<Vec3f>(0, 0)[0] = 255.0f;
	Mat m7 = m.diag(0);
	Mat m8 = m.diag(-1);
	Mat m9 = m.diag(2); // diag is deep copy, others is simple  copy
	m9.at<Vec3f>(0, 0)[0] = 255.0f;
	Mat m10 = m(Range(0, 4), Range(0, 4));
	Mat m11 = m(Rect(0, 0, 4, 4));
	// m(ranges)

	cout << "quit accessing_array_block " << endl;
}

void matrix_expression()
{
	cout << "entry matrix_expression " << endl;
	cout << "quit matrix_expression " << endl;
}

// Satuation Casting
void satuation_casting()
{
	cout << "entry satuation_casting " << endl;
	Vec3b v(100, 150, 200);
	uchar a = saturate_cast<uchar>(v[0] + v[1] + v[2]);
	cout << "quit satuation_casting " << endl;
}

void mat_operation()
{
	cout << "entry mat_operation " << endl;
	int N = 32;
	Mat m(N, N, CV_32FC3);
	randu(m, 0.0f, 255.0f);
	Mat m2 = m.clone();
	Mat m3;
	m.copyTo(m3);
	Mat mask = Mat::zeros(N, N, CV_8UC1);
	Mat mask2 = mask(Rect(0, 0, N / 2, N / 2));
	mask2.setTo(Scalar(1, 1, 1));
	Mat m4;
	m.copyTo(m4, mask);
	Mat m5;
	m.convertTo(m5, CV_8UC3, 0.5);
	Mat m6;
	m.assignTo(m6, CV_8UC3);
	// m.reshape(chan, rows)
	// m.push_back(s)
	m.push_back(m2);
	m.pop_back(N);
	Size sz;
	Point os;
	m.locateROI(sz, os);
	size_t a = m.total();
	bool b = m.isContinuous();
	size_t a2 = m.elemSize();
	size_t a3 = m.elemSize1();
	int a4 = m.type();
	int a5 = m.depth();
	int a6 = m.channels();
	Size a7 = m.size();
	bool a8 = m.empty();
	cout << "quit mat_operation " << endl;
}

// SparseMat
// accessing sparse array elements
// functions unique to sparse arrays
// template structures for large array types
void sparse_matrix()
{
	cout << "entry sparse_matrix " << endl;
	int size[] = { 10, 10 };
	SparseMat sm(2, size, CV_32F);
	for (int i = 0; i < 10; i++)
	{
		int idx[2];
		idx[0] = size[0] * rand();
		idx[1] = size[1] * rand();
		sm.ref<float>(idx) += 1.0f;
	}
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			size_t h = sm.hash(i, j);
			float v = sm.value<float>(i, j);
			cout << i << "," << j << ": h:" << h << ", v: " << v << endl;
		}
	}
	
	SparseMatConstIterator_<float> it = sm.begin<float>();
	for (; it != sm.end<float>(); ++it)
	{
		const SparseMat::Node* node = it.node();
		cout << node->idx[0] << "," << node->idx[1] << ": " << *it << endl;
	}
	cout << "quit sparse_matrix " << endl;
}

void opencv_02_data_type()
{
	cout << "entry opencv_02_data_type " << endl;
	int index = 17;
	switch (index)
	{
	case 0:data_type_point(); break;
	case 1:data_type_scalar(); break;
	case 2:data_type_size(); break;
	case 3:data_type_rect(); break;
	case 4:data_type_rotateRect(); break;
	case 5:data_type_matrix(); break;
	case 6:data_type_fixedVector(); break;
	case 7:data_type_complex(); break;
	case 8:data_type_helper_objects(); break;
	case 9:data_type_utility_functions(); break;
	case 10:data_type_templates(); break;
	case 11:data_type_Mat(); break;
	case 12:accessing_array_elements(); break;
	case 13:nary_array_iterator(); break;
	case 14:accessing_array_block(); break;
	case 15:satuation_casting(); break;
	case 16:mat_operation(); break;
	case 17:sparse_matrix(); break;
	default:break;
	}
	cout << "quit opencv_02_data_type " << endl;
}
