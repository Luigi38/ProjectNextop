#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void set_mask() {
	Mat source = imread("lenna.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);

	if (source.empty() || mask.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	source.setTo(Scalar(0, 255, 255), mask);

	imshow("source", source);
	imshow("mask", mask);

	waitKey();
	destroyAllWindows();
}

void copy_mask() {
	Mat source = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dest = imread("field.bmp", IMREAD_COLOR);

	if (source.empty() || mask.empty() || dest.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	source.copyTo(dest, mask);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

int main() {
	copy_mask();
	return 0;
}