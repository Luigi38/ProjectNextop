#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void hough_lines() {
	Mat source = imread("building.jpg", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat edge;
	Canny(source, edge, 50, 150);

	vector<Vec2f> lines;
	HoughLines(edge, lines, 1, CV_PI / 180, 250);

	Mat dest;
	cvtColor(edge, dest, COLOR_GRAY2BGR);

	for (size_t i = 0; i < lines.size(); i++) {
		float r = lines[i][0];
		float t = lines[i][1];

		double cos_t = cos(t);
		double sin_t = sin(t);

		double x0 = r * cos_t;
		double y0 = r * sin_t;
		double alpha = 1000;

		Point point1(cvRound(x0 + alpha * (-sin_t)), cvRound(y0 + alpha * cos_t));
		Point point2(cvRound(x0 - alpha * (-sin_t)), cvRound(y0 - alpha * cos_t));
		line(dest, point1, point2, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void hough_line_segments() {
	Mat source = imread("building.jpg", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	Mat edge;
	Canny(source, edge, 50, 150);

	vector<Vec4i> lines;
	HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);

	Mat dest;
	cvtColor(edge, dest, COLOR_GRAY2BGR);

	for (Vec4i l : lines) {
		line(dest, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void hough_circles() {
	Mat source = imread("coins.png", IMREAD_GRAYSCALE);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat blurred;
	blur(source, blurred, Size(3, 3));
	
	vector<Vec3f> circles;
	HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);

	Mat dest;
	cvtColor(source, dest, COLOR_GRAY2BGR);

	for (Vec3f c : circles) {
		Point center(cvRound(c[0]), cvRound(c[1]));
		int radius = cvRound(c[2]);
		circle(dest, center, radius, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

int main() {
	//hough_lines();
	//hough_line_segments();
	hough_circles();
	return 0;
}