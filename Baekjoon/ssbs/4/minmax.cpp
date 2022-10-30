#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int value;

		cin >> value;
		v.push_back(value);
	}

	int m = v[0];
	int M = v[0];

	for (int i = 0; i < N; i++) {
		if (v[i] < m) m = v[i];
		if (v[i] > M) M = v[i];
	}

	cout << m << ' ' << M << '\n';
	return 0;
}