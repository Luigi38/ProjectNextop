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
	vector<int> result_indicies;
	vector<vector<vector<bool>>> result_confirmed;

	vector<vector<int>> indicies;
};

bool vertical(const point& p1, const point& p2) {
	return p1.x == p2.x;
}

bool horizontal(const point& p1, const point& p2) {
	return p1.y == p2.y;
}

bool diagonal(const point& p1, const point& p2) {
	return abs(p2.x - p1.x) == abs(p2.y - p1.y);
}

bool out_of_box(const int x, const int y, const int N) {
	return x < 0 || y < 0 || x + 1 > N || y + 1 > N;
}

bool attack(const point& p1, const point& p2) {
	return vertical(p1, p2) || horizontal(p1, p2) || diagonal(p1, p2);
}

void record(point p, const int N, vector<vector<bool>>& confirmed) {
	if (confirmed[p.y][p.x]) {
		return;
	}

	int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
	int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

	for (int i = 0; i < 8; i++) {
		int x = p.x;
		int y = p.y;

		while (!out_of_box(x, y, N)) {
			confirmed[y][x] = true;

			x += dx[i];
			y += dy[i];
		}
	}
}

void dfs(const int N, const bool select, const int index, vector<point>& S, QueenOption& option) {
	if (select) {
		int ci = option.result_confirmed.size() - 1;

		option.result_indicies.push_back(index);
		option.result_confirmed.push_back(vector<vector<bool>>(option.result_confirmed[ci].begin(), option.result_confirmed[ci].end()));
	}
	option.result.push_back(select);
	
	if (select) {
		int ci = option.result_confirmed.size() - 1;
		point p = S[index];

		if (!option.result_confirmed[ci][p.y][p.x]) {
			record(p, N, option.result_confirmed[ci]);
		}
		else {
			if (option.result.back()) {
				option.result_indicies.pop_back();
				option.result_confirmed.pop_back();
			}
			option.result.pop_back();
			return;
		}
	}

	if (index >= S.size() - 1) {
		if (option.result_indicies.size() == N) {
			option.indicies.push_back(option.result_indicies);
		}

		if (option.result.back()) {
			option.result_indicies.pop_back();
			option.result_confirmed.pop_back();
		}
		option.result.pop_back();
		return;
	}

	dfs(N, false, index + 1, S, option);
	dfs(N, true, index + 1, S, option);

	if (option.result.back()) {
		option.result_indicies.pop_back();
		option.result_confirmed.pop_back();
	}
	option.result.pop_back();
}

int main() {
	int N;
	vector<point> points;
	QueenOption option;
	vector<vector<bool>> confirmed_default;

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			points.push_back({ x, y });
		}
	}
	confirmed_default = vector<vector<bool>>(N, vector<bool>(N, false));

	option = { vector<bool>(), vector<int>(), vector<vector<vector<bool>>>(), vector<vector<int>>() };
	option.result_confirmed.push_back(vector<vector<bool>>(confirmed_default.begin(), confirmed_default.end()));

	dfs(N, false, 0, points, option);

	option = { vector<bool>(), vector<int>(), vector<vector<vector<bool>>>(), option.indicies };
	option.result_confirmed.push_back(vector<vector<bool>>(confirmed_default.begin(), confirmed_default.end()));

	dfs(N, true, 0, points, option);

	cout << option.indicies.size() << '\n';
	return 0;
}