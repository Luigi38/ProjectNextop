#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void drawLines() {
	Mat image(400, 400, CV_8UC3, Scalar(255, 255, 255));

	line(image, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(image, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
	line(image, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);

	line(image, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
	line(image, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), LINE_8);
	line(image, Point(250, 90), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);

	arrowedLine(image, Point(50, 2000), Point(150, 200), Scalar(0, 0, 255));
	arrowedLine(image, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
	arrowedLine(image, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);

	drawMarker(image, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
	drawMarker(image, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
	drawMarker(image, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
	drawMarker(image, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
	drawMarker(image, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
	drawMarker(image, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
	drawMarker(image, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);

	imshow("image", image);
	waitKey();

	destroyAllWindows();
}

int main() {
	drawLines();
	return 0;
}