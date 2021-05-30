#include <iostream>
#include <vector>
using namespace std;

struct chess {
	vector<bool> horizontal; //가로
	vector<bool> vertical; //세로
	vector<bool> diagonal1; //대각선 (아왼-위오)
	vector<bool> diagonal2; //대각선 (위왼-아오)
};

struct QueenOption {
	chess confirmed;
	int indicies;
};

void dfs(const int N, const int y, const int x, QueenOption& option) {
	auto b1 = option.confirmed.horizontal[y];
	auto b2 = option.confirmed.vertical[x];
	auto b3 = option.confirmed.diagonal1[y + x];
	auto b4 = option.confirmed.diagonal2[y - x + N - 1];

	if (b1 || b2 || b3 || b4) {
		return;
	}

	if (y == N - 1) {
		option.indicies++;
		return;
	}

	option.confirmed.horizontal[y] = true;
	option.confirmed.vertical[x] = true;
	option.confirmed.diagonal1[y + x] = true;
	option.confirmed.diagonal2[y - x + N - 1] = true;

	for (int i = 0; i < N; i++) {
		dfs(N, y + 1, i, option);
	}

	option.confirmed.horizontal[y] = false;
	option.confirmed.vertical[x] = false;
	option.confirmed.diagonal1[y + x] = false;
	option.confirmed.diagonal2[y - x + N - 1] = false;
}

int main() {
	int N;
	QueenOption option;

	cin >> N;

	option = { { vector<bool>(N, false), vector<bool>(N, false), vector<bool>(N * 3 - 1, false), vector<bool>(N * 3 - 1, false) }, 0 };

	for (int i = 0; i < N; i++) {
		dfs(N, 0, i, option);
	}

	cout << option.indicies << '\n';
	return 0;
}