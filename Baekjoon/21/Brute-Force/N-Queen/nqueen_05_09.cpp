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

struct QueenOption {
	vector<bool> result;
	vector<vector<int>> indicies;
	int rc;
};

void dfs(const int N, const bool select, const int index, vector<point>& S, QueenOption& option) {
	if (select) {
		option.rc++;
	}
	option.result.push_back(select);

	if (index >= S.size() - 1) {
		if (option.rc == N) {
			option.indicies.push_back(vector<int>());
			int index = option.indicies.size() - 1;

			for (int i = 0; i < S.size(); i++) {
				if (option.result[i]) {
					option.indicies[index].push_back(i);
				}
			}
		}

		if (option.result.back()) {
			option.rc--;
		}
		option.result.pop_back();
		return;
	}

	dfs(N, false, index + 1, S, option);
	dfs(N, true, index + 1, S, option);

	if (option.result.back()) {
		option.rc--;
	}
	option.result.pop_back();
}

bool diagonal(const point& p1, const point& p2) {
	return abs(p2.x - p1.x) == abs(p2.y - p1.y);
}

bool attack(const point& p1, const point& p2) {
	return p1.x == p2.x || p1.y == p2.y || diagonal(p1, p2);
}

int bohemian_rhapsody(vector<point>& points, vector<vector<int>>& indicies) {
	int count = 0;
	
	for (int i = 0; i < indicies.size(); i++) {
		vector<int> inddex = indicies[i];
		bool isParadox = false;

		for (int j = 0; j < inddex.size(); j++) {
			for (int k = j + 1; k < inddex.size(); k++) {
				if (j == k) {
					continue;
				}

				point p1 = points[inddex[j]];
				point p2 = points[inddex[k]];

				if (attack(p1, p2)) {
					isParadox = true;
					break;
				}
			}

			if (isParadox) {
				break;
			}
		}

		if (!isParadox) {
			count++;
		}
	}

	return count;
}

int main() {
	int N;
	vector<point> points;
	QueenOption option = { vector<bool>(), vector<vector<int>>(), 0 };

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			points.push_back({ x, y });
		}
	}

	dfs(N, false, 0, points, option);
	option = { vector<bool>(), option.indicies, 0 };
	dfs(N, true, 0, points, option);

	cout << bohemian_rhapsody(points, option.indicies) << '\n';
	return 0;
}
