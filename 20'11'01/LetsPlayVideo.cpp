#define VIDEO_STOPWATCH "stopwatch.avi"
#define VIDEO_HYPERLAPSE "London - Hyperlapse Film.mp4"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

void video_in() {
	VideoCapture cap;
	cap.open(VIDEO_HYPERLAPSE);

	if (!cap.isOpened()) {
		cerr << "Video open failed." << endl;
		return;
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame count: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;

	int delay = cvRound(1000 / fps);

	Mat frame, inversed;

	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27) break; // ESC key
	}

	destroyAllWindows();
}

int main() {
	video_in();
	return 0;
}