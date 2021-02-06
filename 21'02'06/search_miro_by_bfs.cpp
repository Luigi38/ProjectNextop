#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;

int main() {
	vector<string> v;
	map<pair<int, int>, int> counts;
	queue<pair<int, int>> q;

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		v.push_back(str);
	}

	counts[{0, 0}] = 1;
	q.push({0, 0});

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		int dx[4] = { 0, 0, -1, 1 };
		int dy[4] = { -1, 1, 0, 0 };

		for (int i = 0; i < 4; i++) {
			int x = now.second + dx[i];
			int y = now.first + dy[i];

			pair<int, int> next = { y, x };

			if (x >= 0 && x < M && y >= 0 && y < N) {
				if (v[y][x] == '1' && counts[next] == 0) {
					counts[next] = counts[now] + 1;
					q.push(next);
				}
			}
		}
	}

	cout << counts[{N - 1, M - 1}] << endl;
}