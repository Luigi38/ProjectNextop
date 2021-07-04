#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int worm(const int start, vector<vector<int>>& adj) {
	queue<int> q;
	vector<bool> visited(adj.size(), false);

	int count = 0;

	q.push(start);
	visited[start - 1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		vector<int> v = adj[now - 1];

		for (auto i = 0; i < v.size(); i++) {
			int next = v[i];

			if (!visited[next - 1]) {
				visited[next - 1] = true;
				count++; //addicted worm virus

				q.push(next);
			}
		}
	}

	return count;
}

int main() {
	int N;
	int M; //M == adj.size()

	cin >> N >> M;

	vector<vector<int>> adj(N, vector<int>());

	for (int i = 0; i < M; i++) {
		int in;
		int out;

		cin >> in >> out;

		adj[in - 1].push_back(out);
		adj[out - 1].push_back(in);
	}

	cout << worm(1, adj) << '\n';
	return 0;
}