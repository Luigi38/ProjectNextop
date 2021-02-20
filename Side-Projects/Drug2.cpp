#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat image = imread("lenna.bmp");

	if (image.empty()) {
		cerr << "Image open failed." << endl;
		return -1;
	}

	namedWindow("image");
	imshow("image", image);

	while (true) {
		int key_code = waitKey();

		if (key_code == 'i' || key_code == 'I') {
			image = ~image;
			imshow("image", image);
		}
		else if (key_code == 27 || key_code == 'q' || key_code == 'Q') {
			break;
		}
	}

	return 0;
}