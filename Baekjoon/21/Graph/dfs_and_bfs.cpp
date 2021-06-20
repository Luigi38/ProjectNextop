#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct option {
	int N;
	int M;
	int V;
	vector<vector<int>> adj;
};

/*
N - 정점의 개수 (최대)
M - 간선의 개수
V - 시작할 정점 번호
*/

void bfs(const option& o, vector<int>& result) {
	queue<int> q;
	q.push(o.V);

	vector<bool> removal(o.N, false);

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (removal[now - 1]) {
			continue;
		}

		removal[now - 1] = true;
		result.push_back(now);

		vector<int> nodes = o.adj[now - 1];

		for (auto x : nodes) {
			if (!removal[x - 1] && x != now) {
				q.push(x);
			}
		}
	}
}

void dfs(const int number, const option& o, vector<bool> &removal, vector<int>& result) {
	if (removal[number - 1]) {
		return;
	}

	result.push_back(number);
	removal[number - 1] = true;

	vector<int> nodes = o.adj[number - 1];

	for (auto x : nodes) {
		if (!removal[x - 1] && x != number) {
			dfs(x, o, removal, result);
		}
	}
}

void print_vector(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << (i != v.size() - 1 ? ' ' : '\n');
	}
}

int main() {
	option o = { 0, 0, 0, vector<vector<int>>() };

	vector<int> rd;
	vector<int> rb;

	vector<bool> r4d;

	cin >> o.N >> o.M >> o.V;

	o.adj = vector<vector<int>>(o.N, vector<int>());
	r4d = vector<bool>(o.N, false);

	for (int i = 0; i < o.M; i++) { //start from 1
		int node1, node2;
		cin >> node1 >> node2;

		o.adj[node1 - 1].push_back(node2);
		o.adj[node2 - 1].push_back(node1);
	}

	for (int i = 0; i < o.N; i++) {
		sort(o.adj[i].begin(), o.adj[i].end());
	}

	dfs(o.V, o, r4d, rd);
	bfs(o, rb);

	print_vector(rd);
	print_vector(rb);

	return 0;
}
