#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct option {
	vector<int> result;
	set<int> except;
	int mv;
};

int calculate(const vector<int>& result, const vector<int>& A) {
	int value = 0;

	for (int i = 0; i < result.size() - 1; i++) value += abs(A[result[i]] - A[result[i + 1]]);
	return value;
}

void dfs(const int select, const int index, const int N, const vector<int>& A, option& op) {
	op.except.insert(select);
	op.result.push_back(select);

	if (index == N - 1) {
		int value = calculate(op.result, A);
		op.mv = max(op.mv, value);
	}
	else {
		for (int i = 0; i < N; i++) {
			if (op.except.find(i) != op.except.end()) continue;
			dfs(i, index + 1, N, A, op);
		}
	}

	op.except.erase(select);
	op.result.pop_back();
}

int main() {
	int N;
	vector<int> A;
	option op = { vector<int>(), set<int>(), 0 };

	cin >> N;
	for (int i = 0; i < N; i++) {
		int Ai;

		cin >> Ai;
		A.push_back(Ai);
	}

	for (int i = 0; i < N; i++) {
		dfs(i, 0, N, A, op);
		op = { vector<int>(), set<int>(), op.mv };
	}

	cout << op.mv << '\n';
	return 0;
}