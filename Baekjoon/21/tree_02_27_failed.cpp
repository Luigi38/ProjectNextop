#include <iostream>
#include <vector>
using namespace std;

int get_parent(vector<vector<int>>& v, int node) {
	if (node == 1) return 0;

	vector<int> nodes = v[node - 1];

	for (size_t i = 0; i < nodes.size(); i++) for (auto x : v[nodes[i] - 1]) if (x == node) return nodes[i];
	return 0;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>());

	for (int i = 0; i < N - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;

		v[node1 - 1].push_back(node2);
		v[node2 - 1].push_back(node1);
	}

	for (int i = 1; i < N; i++) {
		int parent = get_parent(v, i + 1);
		if (parent != 0) cout << parent << '\n';
	}

	return 0;
}