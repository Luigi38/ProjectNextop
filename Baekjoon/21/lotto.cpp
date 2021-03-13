#define MAX_NUMBER 6
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef struct lotto {
	vector<int> S;
	vector<vector<int>> al;
} lotto;

void loop(const vector<vector<int>>& al, vector<vector<int>>& v, int index = -1, int indent = 0) {
	if (index == -1) index = al.size() - 1;
	if (index > al.size() - 1) {
		return;
	}
	
	for (auto x : al[index]) {
		cout << x << ' ';
		loop(al, v, x - 1, indent + 1);
	}
	cout << '\n';
}

void get_lotto(const int k, const vector<vector<int>>& al) {
	vector<vector<int>> v;
	loop(al, v);
	return;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j];
			if (j != v[i].size() - 1) cout << ' ';
		}
		if (i != v.size() - 1) cout << '\n';
	}
}

int main() {
	vector<lotto> v;

	while (1) {
		int k;
		cin >> k;

		if (k == 0) {
			break;
		}

		v.push_back({vector<int>(), vector<vector<int>>(k - 1, vector<int>())});

		for (int i = 0; i < k; i++) {
			int n;
			
			cin >> n;
			v[v.size() - 1].S.push_back(n);
		}

		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < k; j++) {
				if (i == j) continue;
				v[v.size() - 1].al[i].push_back(j + 1);
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		get_lotto(v[i].S.size(), v[i].al);
		if (i != v.size() - 1) cout << '\n';
	}
	return 0;
}