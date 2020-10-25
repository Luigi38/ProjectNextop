#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void MatOpEx4() {
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i);
		}
	}

	for (int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j);

		for (int i = 0; i < mat1.cols; i++) {
			p[i]++;
		}
	}

	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
		(*it)++;
	}

	cout << "mat1: " << mat1 << endl;
}

void MatOp5() {
	Mat image1 = imread("lenna.bmp");

	cout << "Width: " << image1.cols << endl;
	cout << "Height: " << image1.rows << endl;
	cout << "Channels: " << image1.channels() << endl;

	if (image1.type() == CV_8UC1) {
		cout << "lenna is a grayscale image." << endl;
	}
	else if (image1.type() == CV_8UC3) {
		cout << "lenna is a truecolor image." << endl;
	}

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1: " << mat1 << endl;
}

void MatOp6() {
	float data[] = { 1, 1, 2, 3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat2 = mat1.inv();
	cout << "mat2:\n" << mat2 << endl;

	cout << "mat1.t()\n" << mat1.t() << endl;
	cout << "mat1 + 3:\n" << mat1 + 3 << endl;

	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;
}

void MatOp7() {
	Mat image1 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat image1f;
	image1.convertTo(image1f, CV_32FC1);

	uchar data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	Mat mat1(3, 4, CV_8UC1, data1);
	Mat mat2 = mat1.reshape(0, 1);

	cout << "mat1:\n" << mat1 << endl;
	cout << "mat2:\n" << mat2 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	mat1.push_back(mat3);
	cout << "mat1:\n" << mat1 << endl;

	mat1.resize(6, 100);
	cout << "mat1:\n" << mat1 << endl;
}

int main() {
	MatOp7();
	return 0;
}