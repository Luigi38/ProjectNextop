#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int lower_hue = 40;
int upper_hue = 80;

Mat source;
Mat source_hsv;
Mat mask;

void on_hue_changed(int, void*);

int main(int argc, char* argv[]) {
	source = imread("candies.png", IMREAD_COLOR);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return -1;
	}

	cvtColor(source, source_hsv, COLOR_BGR2HSV);
	imshow("source", source);

	namedWindow("mask");
	createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
	createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed);
	on_hue_changed(0, 0);

	waitKey();
	return 0;
}

void on_hue_changed(int, void*) {
	Scalar lowerb(lower_hue, 100, 0);
	Scalar upperb(upper_hue, 255, 255);

	inRange(source_hsv, lowerb, upperb, mask);
	imshow("mask", mask);
}