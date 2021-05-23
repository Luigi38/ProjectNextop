#include <iostream>
#include <vector>
using namespace std;

struct point {
	int x;
	int y;
};

struct square {
	bool is_blocked;

	bool is_base;
	int handler;
};
typedef vector<vector<square>> chess;

struct QueenOption {
	vector<bool> result;
	vector<int> result_indicies;
	chess result_confirmed;

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

void record(const point p, const int N, const bool select, const int handler, chess& confirmed) { // O(N)
	if (select && confirmed[p.y][p.x].is_blocked) {
		return;
	}
	confirmed[p.y][p.x].is_base = select;

	int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
	int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

	for (int i = 0; i < 8; i++) {
		int x = p.x;
		int y = p.y;

		while (!out_of_box(x, y, N)) {
			if (confirmed[y][x].is_blocked != select && (confirmed[y][x].handler == -1 || confirmed[y][x].handler == handler)) {
				confirmed[y][x].is_blocked = select;
				confirmed[y][x].handler = select ? handler : -1;
			}

			x += dx[i];
			y += dy[i];
		}
	}
}

void dfs(const int N, const bool select, const int index, vector<point>& S, QueenOption& option) {
	point p = S[index];

	if (select) {
		option.result_indicies.push_back(index);
	}
	option.result.push_back(select);

	if (select) { //backtracking
		if (!option.result_confirmed[p.y][p.x].is_blocked) {
			record(p, N, true, index, option.result_confirmed);
		}
		else {
			if (option.result.back()) {
				option.result_indicies.pop_back();

				if (option.result_confirmed[p.y][p.x].is_base) {
					record(S[index], N, false, index, option.result_confirmed);
				}
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

			if (option.result_confirmed[p.y][p.x].is_base) {
				record(S[index], N, false, index, option.result_confirmed);
			}
		}
		option.result.pop_back();
		return;
	}

	dfs(N, false, index + 1, S, option);
	dfs(N, true, index + 1, S, option);

	if (option.result.back()) {
		option.result_indicies.pop_back();

		if (option.result_confirmed[p.y][p.x].is_base) {
			record(S[index], N, false, index, option.result_confirmed);
		}
	}
	option.result.pop_back();
}

/*
dfs() - 칸 별로 가는게 아닌 줄 별로 재귀호출 (index -> line)
*/

int main() { // O(N*8*N^196)
	int N;
	vector<point> points;
	QueenOption option;
	chess confirmed_default;

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			points.push_back({ x, y });
		}
	}
	confirmed_default = chess(N, vector<square>(N, { false, false, -1 }));

	option = { vector<bool>(), vector<int>(), chess(confirmed_default.begin(), confirmed_default.end()), vector<vector<int>>() };
	dfs(N, false, 0, points, option);

	option = { vector<bool>(), vector<int>(), chess(confirmed_default.begin(), confirmed_default.end()), option.indicies };
	dfs(N, true, 0, points, option);

	cout << option.indicies.size() << '\n';
	return 0;
}
