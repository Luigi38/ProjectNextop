#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void bright1(InputArray source) {
	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dest = source.getMat() + 100;

	imshow("source", source);
	imshow("dest", dest);
}

void bright2(InputArray source) {
	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dest(source.getMat().rows, source.getMat().cols, source.type());

	for (int y = 0; y < source.getMat().rows; y++) {
		for (int x = 0; x < source.getMat().cols; x++) {
			dest.at<uchar>(y, x) = source.getMat().at<uchar>(y, x) + 100;
		}
	}

	imshow("source", source);
	imshow("dest", dest);
}

void bright3(InputArray source) {
	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dest(source.rows(), source.cols(), source.getMat().type());

	for (int y = 0; y < source.rows(); y++) {
		for (int x = 0; x < source.cols(); x++) {
			dest.at<uchar>(y, x) = saturate_cast<uchar>(source.getMat().at<uchar>(y, x) + 100);
		}
	}

	imshow("source", source);
	imshow("dest", dest);
}

void on_bright(int pos, void* userdata);

void bright4(InputArray source) {
	
}

void on_bright(int pos, void* userdata) {
	Mat source = *(Mat*)userdata;
	Mat dest = source + pos;

	imshow("dest", dest);
}

int main() {
	VideoCapture cap;
	cap.open(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed." << endl;
		return -1;
	}

	Mat lenna = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat webcam, webcam_grayscale;

	cap >> webcam;
	cvtColor(webcam, webcam_grayscale, COLOR_BGR2GRAY);

	if (webcam_grayscale.empty()) {
		cerr << "Image load failed." << endl;
		return -1;
	}

	namedWindow("dest");
	createTrackbar("Brightness", "dest", 0, 100, on_bright, (void*)&webcam_grayscale);
	on_bright(0, (void*)&webcam_grayscale);

	while (true) {
		cap >> webcam;
		cvtColor(webcam, webcam_grayscale, COLOR_BGR2GRAY);

		//bright4(webcam_grayscale);

		if (waitKey(16) == 27) break;
	}

	destroyAllWindows();
	return 0;
}