#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

struct option {
	set<int> except;
	vector<int> result;
	vector<vector<int>> v;
};

void dfs(const int select, const int index, const int N, option& op) {
	op.result.push_back(select);
	op.except.insert(select);

	if (index == N - 1) {
		op.v.push_back(op.result);
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (op.except.find(i) != op.except.end()) continue;
			dfs(i, index + 1, N, op);
		}
	}

	op.result.pop_back();
	op.except.erase(select);
}

int main() {
	int N;
	option op;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	op = { set<int>(), vector<int>(), vector<vector<int>>() };

	for (int i = 1; i <= N; i++) {
		dfs(i, 0, N, op);
		op = { set<int>(), vector<int>(), op.v };
	}
	sort(op.v.begin(), op.v.end());

	for (int i = 0; i < op.v.size(); i++) for (int j = 0; j < op.v[i].size(); j++) cout << op.v[i][j] << (j != op.v[i].size() - 1 ? ' ' : '\n');
	return 0;
}