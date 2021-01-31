#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void color_inverse() {
	Mat source = imread("butterfly.jpg", IMREAD_COLOR);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dest(source.rows, source.cols, source.type());

	for (int j = 0; j < source.rows; j++) {
		for (int i = 0; i < source.cols; i++) {
			Vec3b& p1 = source.at<Vec3b>(j, i);
			Vec3b& p2 = dest.at<Vec3b>(j, i);

			p2[0] = 255 - p1[0]; //B
			p2[1] = 255 - p1[1]; //G
			p2[2] = 255 - p1[2]; //R
		}
	}

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void color_grayscale() {
	Mat source = imread("butterfly.jpg");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat dest;
	cvtColor(source, dest, COLOR_BGR2GRAY);

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

void color_split() {
	Mat source = imread("candies.png");

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	vector<Mat> bgr_planes;
	split(source, bgr_planes);

	imshow("source", source);
	imshow("B_plane", bgr_planes[0]);
	imshow("G_plane", bgr_planes[1]);
	imshow("R_plane", bgr_planes[2]);

	waitKey();
	destroyAllWindows();
}

void pepper_is_yummy() {
	Mat source = imread("pepper.bmp", IMREAD_COLOR);

	if (source.empty()) {
		cerr << "Image load failed." << endl;
		return;
	}

	Mat source_ycrcb;
	cvtColor(source, source_ycrcb, COLOR_BGR2YCrCb);

	vector<Mat> ycrcb_planes;
	split(source_ycrcb, ycrcb_planes);

	equalizeHist(ycrcb_planes[0], ycrcb_planes[0]); // Y channel

	Mat dest_ycrcb;
	merge(ycrcb_planes, dest_ycrcb);

	Mat dest;
	cvtColor(dest_ycrcb, dest, COLOR_YCrCb2BGR);

	imshow("source", source);
	imshow("dest", dest);

	waitKey();
	destroyAllWindows();
}

int main() {
	//color_inverse();
	//color_grayscale();
	//color_split();
	pepper_is_yummy();

	return 0;
}