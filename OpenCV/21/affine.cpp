#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void affine_transform() {
	Mat source = imread("tekapo.bmp");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Point2f sourcePoints[3] = {Point2f(0, 0), Point2f(source.cols - 1, 0), Point2f(source.cols - 1, source.rows - 1)};
	Point2f destinationPoints[3] = {Point2f(50, 50), Point2f(source.cols - 100, 100), Point2f(source.cols - 50, source.rows - 50)};

	Mat m = getAffineTransform(sourcePoints, destinationPoints);

	Mat dest;
	warpAffine(source, dest, m, Size());

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void affine_translation() {
	Mat source = imread("tekapo.bmp");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat m = Mat_<double>({ 2, 3 }, { 1, 0, 150, 0, 1, 100 });

	Mat dest;
	warpAffine(source, dest, m, Size());

	imshow("source", source);
	imshow("destination", dest);

	waitKey();
	destroyAllWindows();
}

void affine_shear() {
	Mat source = imread("tekapo.bmp");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	double mx = 0.3;
	Mat m = Mat_<double>({ 2, 3 }, { 1, mx, 0, 0, 1, 0 });

	Mat dest;
	warpAffine(source, dest, m, Size(cvRound(source.cols + source.rows * mx), source.rows));

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void affine_scale() {
	Mat source = imread("rose.bmp");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dest1, dest2, dest3, dest4;

	resize(source, dest1, Size(), 4, 4, INTER_NEAREST);
	resize(source, dest2, Size(1920, 1280));
	resize(source, dest3, Size(1920, 1280), 0, 0, INTER_CUBIC);
	resize(source, dest4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);

	Rect rectangle = Rect(400, 500, 400, 400);

	imshow("source", source);

	imshow("dest1", dest1(rectangle));
	imshow("dest2", dest2(rectangle));
	imshow("dest3", dest3(rectangle));
	imshow("dest4", dest4(rectangle));

	waitKey();
	destroyAllWindows();
}

void affine_rotation() {
	Mat source = imread("tekapo.bmp");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Point2f cp(source.cols / 2.f, source.rows / 2.f);
	Mat m = getRotationMatrix2D(cp, 20, 1);

	Mat dest;
	warpAffine(source, dest, m, Size());

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void affine_flip() {
	Mat source = imread("eastsea.bmp");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	imshow("source", source);

	Mat dest;
	int flipCode[] = { 1, 0, -1 };

	for (int i = 0; i < 3; i++) {
		flip(source, dest, flipCode[i]);
		imshow("dest", dest);
		waitKey();
	}

	destroyAllWindows();
}

Mat source;
Point2f sourceQuad[4], destQuad[4];

void on_mouse(int event, int x, int y, int flags, void* userdata);

int main() {
	//affine_transform();
	//affine_translation();
	//affine_shear();
	//affine_scale();
	//affine_rotation();
	//affine_flip();

	source = imread("card.bmp");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return -1;
	}

	namedWindow("source");
	setMouseCallback("source", on_mouse);

	imshow("source", source);
	waitKey();

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) {
	static int count = 0;

	if (event == EVENT_LBUTTONDOWN) {
		if (count < 4) {
			sourceQuad[count++] = Point2f(x, y);

			circle(source, Point(x, y), 5, Scalar(0, 0, 255), -1);
			imshow("source", source);

			if (count == 4) {
				int w = 200, h = 300;

				destQuad[0] = Point2f(0, 0);
				destQuad[1] = Point2f(w - 1, 0);
				destQuad[2] = Point2f(w - 1, h - 1);
				destQuad[3] = Point2f(0, h - 1);

				Mat pers = getPerspectiveTransform(sourceQuad, destQuad);

				Mat dest;
				warpPerspective(source, dest, pers, Size(w, h));

				imshow("dest", dest);
			}
		}
	}
}