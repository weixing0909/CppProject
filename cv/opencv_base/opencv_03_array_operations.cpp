#include "main.h"

void array_op_abs()
{
	int N = 32;
	Mat m(N, N, CV_32FC1);
	randu(m, -128.0f, 128.0f);
	Mat mr = abs(m);
    cout << endl;
}

void array_op_absdiff()
{
	int N = 4;
	Mat m1(N, N, CV_32FC1);
	randu(m1, -128.0f, 128.0f);
	Mat m2(N, N, CV_32FC1);
	randu(m2, -128.0f, 128.0f);
	Mat mr;
	absdiff(m1, m2, mr);
	cout << endl;
}

void array_op_add()
{
	int N = 4;
	Mat m1(N, N, CV_32FC1);
	randu(m1, -128.0f, 128.0f);
	Mat m2(N, N, CV_32FC1);
	randu(m2, -128.0f, 128.0f);
	Mat mr;
	add(m1, m2, mr);
	cout << endl;
}

void array_op_addWeighted() {}
void array_op_bitwise_and() {}
void array_op_bitwise_not() {}
void array_op_bitwise_or() {}
void array_op_bitwise_xor() {}
void array_op_calcCovarMatrix() {}
void array_op_cartToPolar() {}
void array_op_checkRange() {}
void array_op_compare() {}
void array_op_completeSymm() {}
void array_op_convertScaleAbs() {}
void array_op_countNonZeros() {}
void array_op_arrToMat() {}
void array_op_dct() {}
void array_op_determinant() {}
void array_op_dft() {}
void array_op_divide() {}
void array_op_eigen() {}
void array_op_exp() {}
void array_op_extractImageCOI() {}
void array_op_flip() {}
void array_op_gemm() {}
void array_op_getConvertElem() {}
void array_op_gettConvertScaleElem() {}
void array_op_idct() {}
void array_op_idft() {}
void array_op_inRange() {}
void array_op_invert() {}
void array_op_log() {}
void array_op_magnitude() {}
void array_op_LUT() {}
void array_op_Mahalanobis() {}
void array_op_max() {}
void array_op_mean() {}
void array_op_meanStdDev() {}
void array_op_merge() {}
void array_op_min() {}
void array_op_minMaxLoc() {}
void array_op_mixChannels() {}
void array_op_mulSpectrums() {}
void array_op_multiply() {}
void array_op_mulTransposed() {}
void array_op_norm() {}
void array_op_normalize() {}
void array_op_perspectiveTransform() {}
void array_op_phase() {}
void array_op_polarToCart() {}
void array_op_pow() {}
void array_op_randu() {}
void array_op_randn() {}
void array_op_randShuffle() {}
void array_op_reduce() {}
void array_op_repeat() {}
void array_op_saturate_cast() {}
void array_op_scaleAdd() {}
void array_op_setIdentity() {}
void array_op_solve() {}
void array_op_solveCubic() {}
void array_op_solvePoly() {}
void array_op_sort() {}
void array_op_sortIdx() {}
void array_op_split() {}
void array_op_sqrt() {}
void array_op_subtract() {}
void array_op_sum() {}
void array_op_theRNG() {}
void array_op_trace() {}
void array_op_transform() {}
void array_op_transpose() {}
void array_op_() {}

void opencv_03_array_operations()
{
	cout << "entry opencv_03_array_operations " << endl;
	int index = 2;
	switch (index)
	{
	case 0:array_op_abs(); break;
	case 1:array_op_absdiff(); break;
	case 2:array_op_add(); break;
	default:break;
	}
	cout << "quit opencv_03_array_operations " << endl;
}