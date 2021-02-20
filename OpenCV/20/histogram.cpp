#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& image) {
	CV_Assert(image.type() == CV_8UC1);

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float grayLevel[] = { 0, 256 };
	const float* ranges[] = { grayLevel };

	calcHist(&image, 1, channels, noArray(), hist, dims, histSize, ranges);
	return hist;
}

Mat getGrayHistImage(const Mat& hist) {
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imageHist(100, 256, CV_8UC1, Scalar(255));

	for (int i = 0; i < 256; i++) {
		line(imageHist, Point(i, 100),
			Point(i, 100 - cvRound((double)(hist.at<float>(i, 0) * 100.0f) / histMax)), Scalar(0));
	}

	return imageHist;
}


void stretch_histogram() {
	Mat source = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	double gmin, gmax;
	minMaxLoc(source, &gmin, &gmax);

	Mat dest = (source - gmin) * 255 / (gmax - gmin);

	imshow("source", source);
	imshow("sourceHist", getGrayHistImage(calcGrayHist(source)));

	imshow("dest", dest);
	imshow("destHist", getGrayHistImage(calcGrayHist(dest)));

	waitKey();
	destroyAllWindows();
}

void equalize_histogram() {
	Mat source = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dest;
	equalizeHist(source, dest);

	imshow("source", source);
	imshow("sourceHist", getGrayHistImage(calcGrayHist(source)));

	imshow("dest", dest);
	imshow("destHist", getGrayHistImage(calcGrayHist(dest)));

	waitKey();
	destroyAllWindows();
}

int main() {
	stretch_histogram();
	return 0;
}