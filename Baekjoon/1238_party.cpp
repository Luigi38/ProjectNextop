#define INF 1111111111
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> adj;

int dijkstra(const int student, const int X, const int N) {
	vector<int> d(N, INF);
	vector<bool> visited(N, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	d[student] = 0;
	pq.push({ 0, student });

	while (!pq.empty()) {
		int index = pq.top().second;
		pq.pop();
		
		visited[index] = true;

		vector<pair<int, int>> nodes = adj[index];

		for (auto node : nodes) {
			int end = node.first;
			int t = node.second;

			if (visited[end]) continue;
			if (d[index] + t < d[end]) {
				d[end] = d[index] + t;
				pq.push({ d[end], end });
			}
		}
	}
	
	return d[X];
}

int main() {
	int N, M, X;
	
	cin >> N >> M >> X;
	adj = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>());

	for (int i = 0; i < M; i++) {
		int a, b, t;

		cin >> a >> b >> t;
		adj[a - 1].push_back({ b - 1, t });
	}

	vector<int> dv;

	for (int i = 0; i < N; i++) {
		int d1 = dijkstra(i, X - 1, N);
		int d2 = dijkstra(X - 1, i, N);

		dv.push_back(d1 + d2);
	}
	sort(dv.begin(), dv.end());
	cout << dv.back() << '\n';

	return 0;
}