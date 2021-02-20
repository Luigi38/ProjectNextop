#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void MatOp2() {
	Mat image1 = imread("dog.bmp");

	Mat image2 = image1;
	Mat image3;
	image3 = image1;

	Mat image4 = image1.clone();
	Mat image5;
	image1.copyTo(image5);

	image1.setTo(Scalar(0, 255, 255)); //yellow

	imshow("image1", image1);
	imshow("image2", image2);
	imshow("image3", image3);
	imshow("image4", image4);
	imshow("image5", image5);

	waitKey();
	destroyAllWindows();
}

void MatOp3() {
	Mat image1 = imread("cat.bmp");

	if (image1.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	Mat image2 = image1(Rect(220, 120, 340, 240));
	Mat image3 = image1(Rect(220, 120, 340, 240)).clone();

	image2 = ~image2;

	imshow("image1", image1);
	imshow("image2", image2);
	imshow("image3", image3);

	waitKey();
	destroyAllWindows();
}

int main() {
	MatOp3();
	return 0;
}