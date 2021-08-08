#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int x;
	int y;
};

struct point2 {
	point p1;
	point p2;
};

int main() {
	int width, height;
	int questions;

	vector<vector<int>> v;
	vector<vector<int>> mv;

	vector<point2> p;

	cin >> height >> width;

	v = vector<vector<int>>(height);
	mv = vector<vector<int>>(height + 1, vector<int>(width + 1, 0));

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int n;

			cin >> n;
			v[y].push_back(n);
		}
	}

	mv[1][1] = v[0][0];

	for (int x = 2; x <= width; x++) {
		mv[1][x] = mv[1][x - 1] + v[0][x - 1];
	}
	for (int y = 2; y <= height; y++) {
		mv[y][1] = mv[y - 1][1] + v[y - 1][0];
	}

	for (int y = 2; y <= height; y++) {
		for (int x = 2; x <= width; x++) {
			mv[y][x] = mv[y][x - 1] + mv[y - 1][x] - mv[y - 1][x - 1] + v[y - 1][x - 1];
		}
	}

	cin >> questions;

	for (int i = 0; i < questions; i++) {
		point2 pin = { { 0, 0 }, { 0, 0 } };
		
		cin >> pin.p1.y >> pin.p1.x >> pin.p2.y >> pin.p2.x;
		p.push_back(pin);
	}

	for (int t = 0; t < questions; t++) {
		point2 pin = p[t];
		int total = 0;

		int rect1 = mv[pin.p1.y - 1][pin.p1.x - 1];
		int rect2 = mv[pin.p1.y - 1][pin.p2.x];
		int rect3 = mv[pin.p2.y][pin.p1.x - 1];
		int rect4 = mv[pin.p2.y][pin.p2.x];
		total = rect4 - (rect2 + rect3 - rect1);

		cout << total << '\n';
	}

	return 0;
}