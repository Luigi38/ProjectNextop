#include <iostream>
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

bool attack(const int N, const point& p1, const point& p2) {

}

int bohemian_rhapsody(const int N, vector<point2>& indicies) {
	int count = 0;
	
	for (int i = 0; i < indicies.size(); i++) {
		point2 p = indicies[i];

		if (!attack(N, p.p1, p.p2)) {
			count++;
		}
	}
}

int main() {
	int N;
	vector<point> points;
	vector<vector<int>> indicies;

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			points.push_back({ x, y });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (i == j) {
				continue;
			}

			indicies.push_back({ i, j });
		}
	}

	cout << bohemian_rhapsody(N, points, indicies) << '\n';
	return 0;
}
