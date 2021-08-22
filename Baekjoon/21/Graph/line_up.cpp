#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(const int N, const vector<vector<int>>& adj, vector<int>& edges) {
	queue<int> q;
	//priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> line_up;

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == 0) {
			q.push(i + 1);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		vector<int> v = adj[now - 1];
		
		q.pop();
		line_up.push_back(now);

		for (int next : v) {
			if (--edges[next - 1] == 0) {
				q.push(next);
			}
		}
	}

	return line_up;
}

int main() {
	int N, M;

	cin >> N >> M;

	vector<vector<int>> adj(N, vector<int>());
	vector<int> edges(N, 0);

	for (int i = 0; i < M; i++) {
		int A, B;

		cin >> A >> B;

		adj[A - 1].push_back(B);
		edges[B - 1]++;
	}

	vector<int> line_up = bfs(N, adj, edges);

	for (int i = 0; i < line_up.size(); i++) {
		cout << line_up[i] << (i != line_up.size() - 1 ? ' ' : '\n');
	}

	return 0;
}