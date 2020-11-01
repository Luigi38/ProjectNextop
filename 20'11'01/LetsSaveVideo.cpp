#define FPS 60
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

void camera_in_video_out() {
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed." << endl;
		return;
	}

	int width = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int height = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / FPS);

	VideoWriter outputVideo("output2.avi", fourcc, FPS, Size(width, height));

	Mat frame, inversed;

	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		inversed = ~frame;
		outputVideo << inversed;
		
		imshow("frame", frame);

		if (waitKey(delay) == 27) break;
	}

	destroyAllWindows();
}

int main() {
	camera_in_video_out();
	return 0;
}