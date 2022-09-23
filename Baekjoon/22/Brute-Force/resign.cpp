#include <iostream>
#include <vector>
using namespace std;

struct option {
	vector<bool> result;
	vector<int> period;
	int profit;
};

int get_period(const int index, const vector<pair<int, int>>& consult) {
	return index + consult[index].first;
}

void dfs(const bool select, const int index, const int N, const vector<pair<int, int>>& consult, option& op) {
	if (select) op.period.push_back(get_period(index, consult));
	op.result.push_back(select);

	if (index == N - 1) {
		int reward = 0;

		for (int i = 0; i < N; i++) if (op.result[i]) reward += consult[i].second;
		op.profit = max(op.profit, reward);
	}
	else {
		dfs(false, index + 1, N, consult, op);
		if (op.period.back() < index + 2 && get_period(index + 1, consult) <= N) dfs(true, index + 1, N, consult, op);
	}

	if (select) op.period.pop_back();
	op.result.pop_back();
}

int main() {
	int N;
	vector<pair<int, int>> consult; //T : period, P : reward

	cin >> N;

	for (int i = 0; i < N; i++) {
		int T, P;

		cin >> T >> P;
		consult.push_back({ T, P });
	}

	option op = { vector<bool>(), vector<int>(1, 0), 0};
	dfs(false, 0, N, consult, op);

	op = { vector<bool>(), vector<int>(1, 0), op.profit };
	if (get_period(0, consult) <= N) dfs(true, 0, N, consult, op);

	cout << op.profit << '\n';
	return 0;
}