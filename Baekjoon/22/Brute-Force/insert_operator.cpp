#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct option {
	vector<int> result; //0 ~ 3
	vector<int> v;
};

int calculate(const int a, const int b, const int asmd) {
	if (asmd == 0) return a + b;
	if (asmd == 1) return a - b;
	if (asmd == 2) return a * b;
	if (asmd == 3) return a / b;
}

void dfs(const int select, const int index, const int N, const vector<int>& A, vector<int>& asmd, option& op) {
	op.result.push_back(select);
	asmd[select]--;

	if (index == N - 2) {
		int result = A[0];

		for (int i = 0; i < N - 1; i++) result = calculate(result, A[i + 1], op.result[i]);
		op.v.push_back(result);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (asmd[i] == 0) continue;
			dfs(i, index + 1, N, A, asmd, op);
		}
	}

	op.result.pop_back();
	asmd[select]++;
}

int main() {
	int N;
	vector<int> A;
	vector<int> asmd;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int Ai;

		cin >> Ai;
		A.push_back(Ai);
	}
	for (int i = 0; i < 4; i++) {
		int asmdi;

		cin >> asmdi;
		asmd.push_back(asmdi);
	}

	option op = { vector<int>(), vector<int>() };

	for (int i = 0; i < 4; i++) {
		if (asmd[i] == 0) continue;

		dfs(i, 0, N, A, asmd, op);
		op = { vector<int>(), op.v };
	}

	int M = op.v[0];
	int m = op.v[0];

	for (int i = 1; i < op.v.size(); i++) {
		M = max(M, op.v[i]);
		m = min(m, op.v[i]);
	}

	cout << M << '\n' << m << '\n';
	return 0;
}