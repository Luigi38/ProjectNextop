#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void contrast1() {
	Mat source = imread("lenna.bmp", IMREAD_GRAYSCALE);
	
	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	float s = 2.f;
	Mat dest = s * source;

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void contrast2() {
	Mat source = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	float alpha = 1.f;
	Mat dest = source + (source - 128) * alpha;

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

int main() {
	contrast2();
	return 0;
}