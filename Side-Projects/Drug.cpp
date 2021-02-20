#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

void eat_drug() {
	Mat original = imread("drug.jpg");
    int color = 0;
	Mat drug = original.clone();

	int sw = 1;

	while (true) {
		cvtColor(original, drug, COLOR_BGR2HSV);

		for (int y = 0; y < drug.cols; y++) {
			for (int x = 0; x < drug.rows; x++) {
				Vec3b& hsv = drug.at<Vec3b>(x, y);
				hsv[0] = color;
				hsv[1] = color;
			}
		}

		if (color <= 0) {
			sw = 1;
		}
		if (color >= 235) {
			sw = -1;
		}

		color += 20 * sw;

		imshow("drug", drug);
		if (waitKey(1) == 27) break;
	}
}

int main() {
	eat_drug();
	return 0;
}