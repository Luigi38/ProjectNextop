#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, X;
	vector<int> A;

	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		int a;

		cin >> a;
		if (a < X) A.push_back(a);
	}

	for (int i = 0; i < A.size(); i++) cout << A[i] << (i != A.size() - 1 ? ' ' : '\n');
	return 0;
}