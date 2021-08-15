#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(const int N, const vector<vector<int>>& adj, const vector<vector<int>>& adj2, vector<int>& edges) {
	vector<bool> visited(N, false);
	queue<int> q;

	vector<int> people;
	priority_queue<int, vector<int>, greater<int>> pq;

	int edge_count = 0;

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == 0) {
			q.push(i + 1);
			pq.push(i + 1);
			
			visited[i] = true;
			edge_count++;

		}
	}

	while (!pq.empty()) {
		int person = pq.top();
		pq.pop();

		people.push_back(person);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		vector<int> next = adj[now - 1];

		for (int i = 0; i < next.size(); i++) {
			if (!visited[next[i] - 1] && edges[next[i] - 1] != 0) {
				q.push(next[i]);

				if (--edges[next[i] - 1] == 0) {
					edge_count++;
					visited[next[i] - 1] = true;
					pq.push(next[i]);
				}
			}
			else if (edges[next[i] - 1] == 0) {
				while (!pq.empty()) {
					int person = pq.top();
					pq.pop();

					people.push_back(person);
				}
			}
		}
	}

	return people;
}

int main() {
	int people, n;
	cin >> people >> n;

	vector<vector<int>> adj(people);
	vector<vector<int>> adj2(people);

	vector<int> edges(people);
	
	for (int i = 0; i < n; i++) {
		int key, value;

		cin >> key >> value;

		adj[key - 1].push_back(value);
		adj2[value - 1].push_back(key);

		edges[value - 1]++;
	}

	vector<int> v = bfs(people, adj, adj2, edges);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << (i != v.size() - 1 ? ' ' : '\n');
	}

	return 0;
}