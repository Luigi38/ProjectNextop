#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main() {
	cout << "Hello, OpenCV! " << CV_VERSION << endl;

	cv::Mat image;
	image = cv::imread("lenna.bmp");

	if (image.empty()) {
		cerr << "Image load failed" << endl;
		return -1;
	}

	cv::namedWindow("image");
	cv::imshow("image", image);

	cv::waitKey();
	return 0;
}