#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void sobel_edge() {
	Mat source = imread("lenna.bmp", IMREAD_GRAYSCALE);
	
	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dx, dy;

	Sobel(source, dx, CV_32FC1, 1, 0);
	Sobel(source, dy, CV_32FC1, 0, 1);

	Mat fmag, mag;

	magnitude(dx, dy, fmag);
	fmag.convertTo(mag, CV_8UC1);
	Mat edge = mag > 150;

	imshow("source", source);
	imshow("mag", mag);
	imshow("edge", edge);

	waitKey();
	destroyAllWindows();
}

void canny_edge() {
	Mat source = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dest1, dest2;

	Canny(source, dest1, 50, 100);
	Canny(source, dest2, 50, 150);

	imshow("source", source);
	imshow("dest1", dest1);
	imshow("dest2", dest2);

	waitKey();
	destroyAllWindows();
}

int main() {
	//sobel_edge();
	canny_edge();
	return 0;
}