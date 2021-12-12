#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int N, M;

	vector<int> A;
	vector<int> B;

	set<int> intersection;
	set<int> un;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int value;

		cin >> value;
		A.push_back(value);
		un.insert(value);
	}

	for (int i = 0; i < M; i++) {
		int value;

		cin >> value;
		B.push_back(value);
		un.insert(value);
	}

	for (int i = 0; i < N; i++) {
		auto it = lower_bound(B.begin(), B.end(), A[i]);
		if ((*it) == A[i]) intersection.insert(A[i]);
	}

	if (!intersection.empty()) for (int value : intersection) cout << value << ' ';
	else cout << 'X';
	cout << '\n';
	for (int value : un) cout << value << ' ';

	return 0;
}