#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int x;
	int y;
};

bool is_not_out_of_box(const point& p, const int N) {
	return p.x >= 0 && p.x < N && p.y >= 0 && p.y < N;
}

int identify_complex(const point& start, const int N, const vector<string>& map, vector<vector<bool>>& visited) {
	queue<point> q;

	visited[start.y][start.x] = true;
	q.push(start);

	int count = 1;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };

	while (!q.empty()) {
		point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			point next = { now.x + dx[i], now.y + dy[i] };

			if (is_not_out_of_box(next, N) && map[next.y][next.x] == '1' && !visited[next.y][next.x]) {
				visited[next.y][next.x] = true;
				count++;

				q.push(next);
			}
		}
	}

	return count;
}

point is_still_complex(const vector<string>& map, const vector<vector<bool>>& visited) {
	for (int y = 0; y < visited.size(); y++) {
		for (int x = 0; x < visited[y].size(); x++) {
			if (!visited[y][x] && map[y][x] == '1') {
				return { x, y };
			}
		}
	}

	return { -1, -1 };
}

point find_start_point(const vector<string>& map) {
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if (map[y][x] == '0') {
				return { x, y };
			}
		}
	}

	return { -1, -1 };
}

vector<int> bfs(const int N, const vector<string>& map) {
	queue<point> q;
	vector<vector<bool>> visited(N, vector<bool>(N, false));

	vector<int> result;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };

	point start = find_start_point(map);

	if (start.x != -1 && start.y != -1) {
		visited[start.y][start.x] = true;
		q.push(start);

		while (!q.empty()) {
			point now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				point next = { now.x + dx[i], now.y + dy[i] };

				if (is_not_out_of_box(next, N) && map[next.y][next.x] == '0' && !visited[next.y][next.x]) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}
	}

	while (true) {
		point start = is_still_complex(map, visited);

		if (start.x == -1 && start.y == -1) {
			break;
		}

		int count = identify_complex(start, N, map, visited);
		result.push_back(count);
	}

	return result;
}

int main() {
	int N;
	vector<string> map;
	vector<vector<bool>> visited;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string jul;
		cin >> jul;

		map.push_back(jul);
	}

	vector<int> result = bfs(N, map);
	sort(result.begin(), result.end());

	cout << result.size() << '\n';

	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << '\n';
		}
	}

	return 0;
}