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
	mv = vector<vector<int>>(height);

	for (int y = 0; y < height; y++) {
		int total = 0;

		for (int x = 0; x < width; x++) {
			int n;

			cin >> n;
			total += n;

			v[y].push_back(n);
			mv[y].push_back(total);
		}
	}

	cin >> questions;

	for (int i = 0; i < questions; i++) {
		point2 pin = { { 0, 0 }, { 0, 0 } };
		
		cin >> pin.p1.y >> pin.p1.x >> pin.p2.y >> pin.p2.x;
		
		pin.p1.x--;
		pin.p1.y--;

		pin.p2.x--;
		pin.p2.y--;

		p.push_back(pin);
	}

	for (int t = 0; t < questions; t++) {
		point2 pin = p[t];
		int total = 0;
		
		for (int y = pin.p1.y; y <= pin.p2.y; y++) {
			int start = pin.p1.x != 0 ? mv[y][pin.p1.x - 1] : 0;
			int end = mv[y][pin.p2.x];

			int length = end - start;
			total += length;
		}

		cout << total << '\n';
	}

	return 0;
}