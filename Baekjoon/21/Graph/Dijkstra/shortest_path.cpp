#define INF 987654321
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

void dijkstra(const int V, const int K, const vector<vector<pi>>& adj, vector<int>& dist) {
	priority_queue<pi, vector<pi>, greater<pi>> pq; //{ distance, index }
	pq.push({ dist[K - 1], K - 1 });

	while (!pq.empty()) {
		pi node = pq.top();
		pq.pop();

		if (node.first != dist[node.second]) continue; //not updated

		for (pi now : adj[node.second]) {
			int updated = dist[node.second] + now.second;
			
			dist[now.first] = min(dist[now.first], updated);
			if (dist[now.first] == updated) pq.push({ dist[now.first], now.first });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	cin >> V >> E >> K;

	vector<vector<pi>> adj(V, vector<pi>());
	vector<int> dist(V, INF);

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		adj[u - 1].push_back({ v - 1, w });
	}

	dist[K - 1] = 0;
	dijkstra(V, K, adj, dist);

	for (int i = 0; i < V; i++) {
		int d = dist[i];

		if (d != INF) cout << d << '\n';
		else cout << "INF\n";
	}

	return 0;
}