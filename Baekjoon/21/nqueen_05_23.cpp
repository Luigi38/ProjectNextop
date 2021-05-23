#include <iostream>
#include <vector>
using namespace std;

struct point {
	int x;
	int y;
};

struct chess {
	vector<bool> horizontal; //가로
	vector<bool> vertical; //세로
	vector<bool> diagonal1; //대각선 (아왼-위오)
	vector<bool> diagonal2; //대각선 (위왼-아오)
};

struct QueenOption {
	vector<bool> result;
	vector<int> result_indicies;
	chess confirmed;

	vector<vector<int>> indicies;
};

bool vertical(const point& p1, const point& p2) { // O(1)
	return p1.x == p2.x;
}

bool horizontal(const point& p1, const point& p2) { // O(1)
	return p1.y == p2.y;
}

bool diagonal(const point& p1, const point& p2) { // O(1)
	return abs(p2.x - p1.x) == abs(p2.y - p1.y);
}

bool out_of_box(const int x, const int y, const int N) { // O(1)
	return x < 0 || y < 0 || x + 1 > N || y + 1 > N;
}

bool attack(const point& p1, const point& p2) { // O(1)
	return vertical(p1, p2) || horizontal(p1, p2) || diagonal(p1, p2);
}

bool is_blocked(const point p, const int N, const chess& confirmed) { // O(1)
	return confirmed.horizontal[p.y] || confirmed.vertical[p.x] || confirmed.diagonal1[p.y + p.x] || confirmed.diagonal2[p.y - p.x + N];
}

void record(const point p, const int N, const bool select, chess& confirmed) { // O(1)
	if (select && is_blocked(p, N, confirmed)) {
		return;
	}

	confirmed.horizontal[p.y] = select;
	confirmed.vertical[p.x] = select;
	confirmed.diagonal1[p.y + p.x] = select;
	confirmed.diagonal2[p.y - p.x + N] = select;
}

void dfs(const int N, const bool select, const int index, vector<point>& S, QueenOption& option) {
	if (select) {
		option.result_indicies.push_back(index);
	}
	option.result.push_back(select);

	if (select) {
		if (!is_blocked(S[index], N, option.confirmed)) {
			record(S[index], N, true, option.confirmed);
		}
		else {
			if (select) {
				option.result_indicies.pop_back();
			}
			option.result.pop_back();
			return;
		}
	}

	if (index >= S.size() - 1) {
		if (option.result_indicies.size() == N) {
			option.indicies.push_back(vector<int>(option.result_indicies.begin(), option.result_indicies.end()));
		}

		if (option.result.back()) {
			record(S[index], N, false, option.confirmed);
			option.result_indicies.pop_back();
		}
		option.result.pop_back();
		return;
	}

	dfs(N, false, index + 1, S, option);
	dfs(N, true, index + 1, S, option);

	if (select) {
		record(S[index], N, false, option.confirmed);
		option.result_indicies.pop_back();
	}
	option.result.pop_back();
}

int main() {
	int N;
	vector<point> points;
	QueenOption option;

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			points.push_back({ x, y });
		}
	}

	option = { vector<bool>(), vector<int>(), { vector<bool>(N, false), vector<bool>(N, false), vector<bool>(N * 3 - 1, false), vector<bool>(N * 3 - 1, false) }, vector<vector<int>>() };
	dfs(N, false, 0, points, option);

	option = { vector<bool>(), vector<int>(), { vector<bool>(N, false), vector<bool>(N, false), vector<bool>(N * 3 - 1, false), vector<bool>(N * 3 - 1, false) }, option.indicies };
	dfs(N, true, 0, points, option);

	cout << option.indicies.size() << '\n';
	return 0;
}