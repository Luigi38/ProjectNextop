#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat source1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
	Mat source2 = imread("square.bmp", IMREAD_GRAYSCALE);

	if (source1.empty() || source2.empty()) {
		cerr << "Image load failed." << endl;
		return -1;
	}

	imshow("source1", source1);
	imshow("source2", source2);

	Mat dest1, dest2, dest3, dest4;

	bitwise_and(source1, source2, dest1);
	bitwise_or(source1, source2, dest2);
	bitwise_xor(source1, source2, dest3);
	bitwise_not(source1, dest4);

	imshow("dest1", dest1);
	imshow("dest2", dest2);
	imshow("dest3", dest3);
	imshow("dest4", dest4);

	waitKey();
	return 0;
}