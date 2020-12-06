#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void noise_gaussian() {
	Mat source = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	for (int stddev = 10; stddev <= 30; stddev += 10) {
		Mat noise(source.size(), CV_8U);
		randn(noise, 0, stddev);

		Mat dest;
		add(source, noise, dest, Mat(), CV_8U);

		imshow("dest", dest);
		waitKey();
	}

	destroyAllWindows();
}

void filter_bilateral() {
	Mat source = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}
	
	Mat noise(source.size(), CV_32SC1);
	randn(noise, 0, 5);

	Mat dest1;
	GaussianBlur(source, dest1, Size(), 5);

	Mat dest2;
	bilateralFilter(source, dest2, -1, 10, 5);

	imshow("source", source);
	imshow("dest1", dest1);
	imshow("dest2", dest2);

	waitKey();
	destroyAllWindows();
}

void filter_median() {
	Mat source = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	int num = (int)(source.total() * 0.1);
	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		int x = rand() % source.cols;
		int y = rand() % source.rows;

		source.at<uchar>(y, x) = (i % 2) * 255;
	}

	Mat dest1;
	GaussianBlur(source, dest1, Size(), 1);

	Mat dest2;
	medianBlur(source, dest2, 3);

	imshow("source", source);
	imshow("dest1", dest1);
	imshow("dest2", dest2);

	waitKey();
	destroyAllWindows();
}

int main() {
	filter_median();
	return 0;
}