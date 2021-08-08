#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> get_all_parent_nodes(vector<vector<int>>& v, int N) {
	queue<int> points;
	vector<int> parents(N, 0);

	points.push(1);

	while (!points.empty()) {
		int now = points.front();
		vector<int> nodes = v[now - 1];

		points.pop();

		for (auto x : nodes) {
			if (parents[x - 1] == 0) {
				points.push(x);
				parents[x - 1] = now;
			}
		}
	}

	return parents;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>());
	vector<int> parents;

	for (int i = 0; i < N - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;

		v[node1 - 1].push_back(node2);
		v[node2 - 1].push_back(node1);
	}
	parents = get_all_parent_nodes(v, N);

	for (int i = 1; i < N; i++) {
		int parent = parents[i];
		if (parent != 0) cout << parent << '\n';
	}

	return 0;
}
