#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(const int N, const vector<vector<int>>& adj, vector<int>& edges) {
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> people;

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == 0) {
			pq.push(i + 1);
		}
	}

	while (!pq.empty()) {
		int now = pq.top();
		vector<int> v = adj[now - 1];

		pq.pop();
		people.push_back(now);

		for (int next : v) {
			if (--edges[next - 1] == 0) {
				pq.push(next);
			}
		}
	}

	while (!pq.empty()) {
		int person = pq.top();
		pq.pop();

		people.push_back(person);
	}

	return people;
}

int main() {
	int people, n;
	cin >> people >> n;

	vector<vector<int>> adj(people);
	vector<int> edges(people);
	
	for (int i = 0; i < n; i++) {
		int key, value;
		cin >> key >> value;

		adj[key - 1].push_back(value);
		edges[value - 1]++;
	}

	vector<int> v = bfs(people, adj, edges);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << (i != v.size() - 1 ? ' ' : '\n');
	}

	return 0;
}