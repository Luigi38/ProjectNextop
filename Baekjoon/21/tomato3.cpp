#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef struct point {
	int x;
	int y;
	int z;
} point;
typedef vector<vector<int>> box;

int get_tomato_date(const int M, const int N, const int H, vector<box> &boxes, queue<point> &points, vector<box>& counts, bool already_riped);
bool is_tomato_in_bounds(const point p, const int M, const int N, const int H);

int get_tomato_date(const int M, const int N, const int H, vector<box>& boxes, queue<point>& points, vector<box>& counts, bool already_riped) {
	if (already_riped) return 0;

	point last_point = { -1, -1, -1 };

	int dx[] = { 0, 0, -1, 1, 0, 0 }; //가로
	int dy[] = { 1, -1, 0, 0, 0, 0 }; //세로
	int dz[] = { 0, 0, 0, 0, 1, -1 }; //높이

	while (!points.empty()) {
		point now = points.front();
		points.pop();

		for (int i = 0; i < 6; i++) {
			point next = { now.x + dx[i], now.y + dy[i], now.z + dz[i] };

			if (is_tomato_in_bounds(next, M, N, H) && boxes[next.z][next.y][next.x] == 0 && counts[next.z][next.y][next.x] == 0) {
				counts[next.z][next.y][next.x] = counts[now.z][now.y][now.x] + 1;
				boxes[next.z][next.y][next.x] = 1;

				last_point = next;
				points.push(next);
			}
		}
	}

	if (last_point.x == -1 && last_point.y == -1 && last_point.z == -1) return -1; //초기값
	for (int z = 0; z < H; z++) for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) if (boxes[z][y][x] == 0) return -1;

	return counts[last_point.z][last_point.y][last_point.x];
}

bool is_tomato_in_bounds(const point p, const int M, const int N, const int H) {
	return p.x >= 0 && p.x < M && p.y >= 0 && p.y < N && p.z >= 0 && p.z < H;
}

int main() {
	int M, N, H; //가로, 세로, 높이
	cin >> M >> N >> H;

	vector<box> boxes; //입력 순서는 반대로
	vector<box> counts;
	queue<point> riped_boxes;

	bool already_riped = true;

	for (int i = 0; i < H; i++) { //토마토 데이터 입력
		boxes.push_back(box());
		counts.push_back(box());

		for (int j = 0; j < N; j++) {
			boxes[i].push_back(vector<int>());
			counts[i].push_back(vector<int>());

			for (int k = 0; k < M; k++) {
				int riped;

				cin >> riped;
				boxes[i][j].push_back(riped);
				counts[i][j].push_back(0);

				if (riped == 1) riped_boxes.push({ k, j, i });
				if (riped == 0 && already_riped) already_riped = false;
			}
		}
	}

	cout << get_tomato_date(M, N, H, boxes, riped_boxes, counts, already_riped) << '\n';
	return 0;
}