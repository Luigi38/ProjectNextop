#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A;
	stack<int> B_LEFT;
	vector<int> B_RIGHT;

	int index_start = 0;
	int index_end = N - 1;

	for (int i = 0; i < N; i++) {
		int value;

		cin >> value;
		A.push_back(value);
	}

	while (1) {
		if (index_start == index_end) {
			B_LEFT.push(A[index_start]);
			break;
		}

		if (A[index_start] < A[index_end]) B_LEFT.push(A[index_start++]);
		else B_RIGHT.push_back(A[index_end--]);
	}

	while (!B_LEFT.empty()) {
		int left = B_LEFT.top();
		B_LEFT.pop();

		cout << left << ' ';
	}
	for (int right : B_RIGHT) cout << right << ' ';

	return 0;
}