#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct point {
	int x;
	int y;
};

vector<point> v;
vector<vector<int>> counts;

void Attack(const int N, const int x, const int y, int& cases) {
	for (int i = 0; i < 4; i++) {
		if (counts[y][x] != 1) {
			v.push_back({ x, y });

		}
	}

	v.push_back({ x, y });

	if (x < 0 || y < 0 || x >= N || y >= N) {
		if (v.size() == 4) {
			cases++;
			
			v.pop_back();
		}
		return;
	}

	int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
	int dy[] = { 0, 0, -1, 1, -1, 1, 1, -1 };

	for (int i = 0; i < 8; i++) {
		Attack(N, x + dx[i], y + dy[i], cases);
	}
}

void Attack(const int N, const point p, int& cases) {
	Attack(N, p.x, p.y, cases);
}

int main() {
	int N;
	cin >> N;

	int cases = 0;

	Attack(N, 0, 0, cases);
	cout << cases << '\n';

	return 0;
}