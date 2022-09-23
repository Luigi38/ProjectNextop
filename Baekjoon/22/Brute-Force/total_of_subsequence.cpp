#include <iostream>
#include <vector>
using namespace std;

struct option {
	vector<bool> result;
	int result_true_size;
	int total;
	int count;
};

void dfs(const bool select, const int index, const int N, const int S, const vector<int>& sequence, option& op) {
	if (select) {
		op.total += sequence[index];
		op.result_true_size++;
	}
	op.result.push_back(select);

	if (index == N - 1) {
		if (op.total == S && op.result_true_size > 0) {
			op.count++;
		}
	}
	else {
		dfs(false, index + 1, N, S, sequence, op);
		dfs(true, index + 1, N, S, sequence, op);
	}

	if (select) {
		op.total -= sequence[index];
		op.result_true_size--;
	}
	op.result.pop_back();
}

int main() {
	int N, S;
	vector<int> sequence;

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int number;

		cin >> number;
		sequence.push_back(number);
	}

	option op = { vector<bool>(), 0, 0, 0 };
	dfs(false, 0, N, S, sequence, op);

	op = { vector<bool>(), 0, 0, op.count };
	dfs(true, 0, N, S, sequence, op);

	cout << op.count << '\n';
	return 0;
}