#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void filter_embossing() {
	Mat source = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	float data[] = { -1, -1, 0, -1, 0, 1, 0, 1, 1 };
	Mat emboss(3, 3, CV_32FC1, data);

	Mat dest;
	filter2D(source, dest, -1, emboss, Point(-1, -1), 128);

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void blurring() {
	Mat source = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	imshow("source", source);

	Mat dest;

	for (int ksize = 3; ksize <= 7; ksize += 2) {
		blur(source, dest, Size(ksize, ksize));

		String desc = format("Mean: %dx%d", ksize, ksize);
		putText(dest, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dest", dest);
		waitKey();
	}

	destroyAllWindows();
}

void blurring_gaussian() {
	Mat source = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	imshow("source", source);
	Mat dest;

	for (int sigma = 1; sigma <= 5; sigma++) {
		GaussianBlur(source, dest, Size(), (double)sigma);

		imshow("dest", dest);
		waitKey();
	}

	destroyAllWindows();
}

void unsharp_mask() {
	Mat source = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	imshow("source", source);

	for (int sigma = 1; sigma <= 5; sigma++) {
		Mat blurred;
		GaussianBlur(source, blurred, Size(), sigma);

		float alpha = 1.f;
		Mat dest = (1 + alpha) * source - alpha * blurred;

		imshow("dest", dest);
		waitKey();
	}

	destroyAllWindows();
}

int main() {
	unsharp_mask();
	return 0;
}