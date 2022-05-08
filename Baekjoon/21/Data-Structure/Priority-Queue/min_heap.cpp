#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.empty()) {
				v.push_back(0);
				continue;
			}

			int out = pq.top();
			pq.pop();

			v.push_back(out);
		}
		else {
			pq.push(x);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
