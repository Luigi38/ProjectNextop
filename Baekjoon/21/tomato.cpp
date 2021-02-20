#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>

typedef std::pair<int, int> point;
typedef std::vector<std::vector<int>> vectorr;

int get_tomato_date(vectorr &v, const int M, const int N, std::queue<point> &q) {
	vectorr counts(N, std::vector<int>(M));
	point last;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		int dx[] = { 0, 0, -1, 1 };
		int dy[] = { -1, 1, 0, 0 };

		for (int i = 0; i < 4; i++) {
			point next = { now.first + dy[i], now.second + dx[i] };

			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < M) {
				if (v[next.first][next.second] == 0 && counts[next.first][next.second] == 0) {
					counts[next.first][next.second] = counts[now.first][now.second] + 1;
					v[next.first][next.second] = 1;
					q.push(next);

					last = next;
				}
			}
		}
	}

	for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) if (v[y][x] == 0) return -1;
	return counts[last.first][last.second];
}

int main() {
	int M, N;
	std::cin >> M >> N;

	vectorr v(N, std::vector<int>(M));
	std::queue<point> q;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int tomato;
			std::cin >> tomato;

			if (tomato == 1) q.push({ y, x });
			v[y][x] = tomato;
		}
	}

	std::cout << get_tomato_date(v, M, N, q) << '\n';
	return 0;
}