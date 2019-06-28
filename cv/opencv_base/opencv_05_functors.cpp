#include "main.h"

Mat norm_0_255(const Mat& src)
{
	Mat dst;
	switch (src.channels())
	{
	case 1:
		cv::normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
		break;
	case 3:
		cv::normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
		break;
	default:
		src.copyTo(dst);
		break;
	}
	return dst;
}

//ת��������ͼ��Ϊ�о���
Mat asRowMatrix(const vector<Mat>& src, int rtype, double alpha = 1, double beta = 0)
{
	//��������
	size_t n = src.size();
	//���û�����������ؿվ���
	if (n == 0)
		return Mat();
	//������ά��
	size_t d = src[0].total();

	Mat data(n, d, rtype);
	//��������
	for (int i = 0; i < n; i++)
	{

		if (src[i].empty())
		{
			string error_message = format("Image number %d was empty, please check your input data.", i);
			CV_Error(Error::StsBadArg, error_message);
		}
		// ȷ�������ܱ�reshape
		if (src[i].total() != d)
		{
			string error_message = format("Wrong number of elements in matrix #%d! Expected %d was %d.", i, d, src[i].total());
			CV_Error(Error::StsBadArg, error_message);
		}
		Mat xi = data.row(i);
		//ת��Ϊ1�У�n�еĸ�ʽ
		if (src[i].isContinuous())
		{
			src[i].reshape(1, 1).convertTo(xi, rtype, alpha, beta);
		}
		else {
			src[i].clone().reshape(1, 1).convertTo(xi, rtype, alpha, beta);
		}
	}
	return data;
}

void functors_PCA()
{
	cout << "entry functors_PCA " << endl;
	vector<Mat> db;

	string prefix = "D:\\dataset\\test_image\\pca/";

	db.push_back(imread(prefix + "faces1.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces2.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces3.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces4.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces5.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces6.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces7.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces8.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces9.png", IMREAD_GRAYSCALE));
	db.push_back(imread(prefix + "faces10.png", IMREAD_GRAYSCALE));

	// Build a matrix with the observations in row:
	Mat data = asRowMatrix(db, CV_32FC1);

	// PCA�㷨����5���ɷַ���
	int num_components = 10;

	//ִ��pca�㷨
	PCA pca(data, Mat(), PCA::DATA_AS_ROW, num_components);
	//PCA pca(data, Mat(), PCA::DATA_AS_COL, num_components);

	//copy  pca�㷨���
	Mat mean = pca.mean.clone();
	Mat eigenvalues = pca.eigenvalues.clone();
	Mat eigenvectors = pca.eigenvectors.clone();

	Mat imgAvg = norm_0_255(mean.reshape(1, db[0].rows));
	Mat imgPC1 = norm_0_255(pca.eigenvectors.row(0)).reshape(1, db[0].rows);
	Mat imgPC2 = norm_0_255(pca.eigenvectors.row(1)).reshape(1, db[0].rows);
	Mat imgPC3 = norm_0_255(pca.eigenvectors.row(2)).reshape(1, db[0].rows);
	Mat imgPC4 = norm_0_255(pca.eigenvectors.row(3)).reshape(1, db[0].rows);
	Mat imgPC5 = norm_0_255(pca.eigenvectors.row(4)).reshape(1, db[0].rows);
	Mat imgPC6 = norm_0_255(pca.eigenvectors.row(5)).reshape(1, db[0].rows);
	Mat imgPC7 = norm_0_255(pca.eigenvectors.row(6)).reshape(1, db[0].rows);
	Mat imgPC8 = norm_0_255(pca.eigenvectors.row(7)).reshape(1, db[0].rows);
	Mat imgPC9 = norm_0_255(pca.eigenvectors.row(8)).reshape(1, db[0].rows);
	Mat imgPC10 = norm_0_255(pca.eigenvectors.row(9)).reshape(1, db[0].rows);
	//��ֵ��
	imshow("avg", norm_0_255(mean.reshape(1, db[0].rows)));

	//���������
	imshow("pc1", norm_0_255(pca.eigenvectors.row(0)).reshape(1, db[0].rows));
	imshow("pc2", norm_0_255(pca.eigenvectors.row(1)).reshape(1, db[0].rows));
	imshow("pc3", norm_0_255(pca.eigenvectors.row(2)).reshape(1, db[0].rows));
	imshow("pc4", norm_0_255(pca.eigenvectors.row(3)).reshape(1, db[0].rows));
	imshow("pc5", norm_0_255(pca.eigenvectors.row(4)).reshape(1, db[0].rows));

	waitKey(0);

	cout << "quit functors_PCA " << endl;
}

void functors_PCA2()
{
	cout << "entry functors_PCA2 " << endl;
	Mat frame = imread("D:\\dataset\\test_image\\pca/qiong.png", IMREAD_GRAYSCALE);

	//cvtColor(frame, frame, CV_RGB2GRAY);
	//	double ��ֵ = 99.999999999999 / 100.0;
	//	PCA pca(frame, Mat(), CV_PCA_DATA_AS_COL, ��ֵ);
	/*
	#define CV_PCA_DATA_AS_ROW 0
	#define CV_PCA_DATA_AS_COL 1
	#define CV_PCA_USE_AVG 2
	*/
	int a = 80; //����
	PCA pca(frame, Mat(), PCA::DATA_AS_COL, a);
	//ͼƬ��СΪ400*362
	//���ﰴCOL�ķ�ʽ��ά����֤�������㣬�������͵�120��
	//���Կ��Է��ִ�ӡ�ľ�ֵ�Ĺ��Ϊ1*362
	cout << "��ֵ�Ĺ��" << pca.mean.size() << endl;//��ֵ
	cout << "����ֵ�Ĺ��" << pca.eigenvalues.size() << endl;//����ֵ
	cout << "���������Ĺ��" << pca.eigenvectors.size() << endl;//��������

	Mat dst = pca.project(frame);//ӳ���¿ռ�
	Mat src = pca.backProject(dst);//��ӳ�����

	cout << "quit functors_PCA2 " << endl;
}

// Singular Value Decomposition
void functors_SVD()
{
	cout << "entry functors_SVD " << endl;
	
	//Mat img = imread("D:\\dataset\\test_image\\pca/qiong.png", IMREAD_GRAYSCALE);
	//Mat img2;
	//img.convertTo(img2, CV_32FC1);
	int N = 3;
	Mat img2(N, N*3, CV_32FC1);
	randu(img2, -1.0f, 1.0f);
	Mat U, W, V;
	SVD::compute(img2, W, U, V);
	Mat W2 = Mat::zeros(N, N, CV_32FC1);
	W2.at<float>(0, 0) = W.at<float>(0, 0);
	W2.at<float>(1, 1) = W.at<float>(1, 0);
	W2.at<float>(2, 2) = W.at<float>(2, 0);
	Mat m = U*W2*V;
	//Mat m1 = Mat::zeros(1, N, CV_32FC1);
	//m1.at<float>(0, 0) = 1.0;
	//m1.at<float>(0, 1) = 1.0;
	//m1.at<float>(0, 2) = 1.0;
	//Mat m2 = Mat::zeros(3, 1, CV_32FC1);
	//m2.at<float>(0, 0) = 1.0;
	//m2.at<float>(1, 0) = 1.0;
	//m2.at<float>(2, 0) = 1.0;
	//Mat m3 = m1 * m2;
	
	// cv::SVD()
	// cv::SVD::operator()()
	// cv::SVD::compute()
	// cv::SVD::solveZ()
	// cv::SVD::backSubst()

	
	cout << "quit functors_SVD " << endl;
}

// Random Number Generator
void functors_RNG()
{
	cout << "entry functors_RNG " << endl;
	RNG rng = theRNG();
	for (int i = 0; i < 5; i++)
	{
		cout << (int)rng << endl;
		cout << int(rng) << endl;
		cout << (float)rng << endl;
		cout << float(rng) << endl;
	}
	RNG r;
	cout << r() << endl;
	cout << r(10) << endl;
	cout << r.uniform(10, 20) << endl;
	cout << r.uniform(10.0f, 20.0f) << endl;
	cout << r.uniform(100.0, 200.0) << endl;
	cout << r.gaussian(1.0) << endl;
	int N = 99;
	Mat m(N, N, CV_32FC1);
	r.fill(m, RNG::NORMAL, 0, 1.0);
	Mat m2(N, N, CV_32FC1);
	r.fill(m2, RNG::UNIFORM, 0, 1.0);
	cout << "quit functors_RNG " << endl;
}

void opencv_05_functors()
{
	cout << "entry opencv_05_functors " << endl;
	int index = 3;
	switch (index)
	{
	case 0:functors_PCA(); break;
	case 1:functors_PCA2(); break;
	case 2:functors_SVD(); break;
	case 3:functors_RNG(); break;
	default:break;
	}
	cout << "quit opencv_05_functors " << endl;
}