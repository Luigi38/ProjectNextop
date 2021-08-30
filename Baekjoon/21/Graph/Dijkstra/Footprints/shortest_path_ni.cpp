#define INF 987654321
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

void dijkstra(const int V, const vector<vector<pi>>& adj, vector<int>& dist, vector<bool>& visited) {
	for (int i = 0; i < V; i++) {
		pi m = { -1, INF + 1 };

		for (int j = 0; j < V; j++) if (!visited[j] && dist[j] < m.second) m = { j, dist[j] };
		visited[m.first] = true;
	
		for (pi now : adj[m.first]) {
			dist[now.first] = min(dist[now.first], dist[m.first] + now.second);
		}
	}
}

int main() {
	int V, E, K;
	cin >> V >> E >> K;

	vector<vector<pi>> adj(V, vector<pi>());
	vector<int> dist(V, INF);
	vector<bool> visited(V, false);

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		adj[u - 1].push_back({ v - 1, w });
	}

	dist[K - 1] = 0;
	dijkstra(V, adj, dist, visited);

	for (int i = 0; i < V; i++) {
		int d = dist[i];
		
		if (d != INF) cout << d << '\n';
		else cout << "INF\n";
	}

	return 0;
}