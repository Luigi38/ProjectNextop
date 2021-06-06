#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int fly(const int x1, const int x2, const int x3, const int N, vector<int>& S) {
	// x1: bee 1
	// x2: bee 2
	// x3: barrel

	int sw = x1 < x3 ? 1 : - 1;
	int x = x1 + sw;

	int h = 0;

	while (x >= 0 && x < N) { //x1
		if (x == x1 || x == x2) {
			continue;
		}

		h += S[x];

		if (x == x3) {
			break;
		}

		x += sw;
	}

	sw = x2 < x3 ? 1 : -1;
	x = x2 + sw;

	while (x >= 0 && x < N) { //x2
		if (x == x1 || x == x2) {
			continue;
		}

		h += S[x];

		if (x == x3) {
			break;
		}

		x += sw;
	}

	return h;
}

int main() {
	int N;
	vector<int> S;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int honey;
		cin >> honey;

		S.push_back(honey);
	}

	int dog_honey = 0;
	vector<int> max_v;

	int h = 0;

	for (int i = 0; i < N; i++) {
		h += S[i];
		max_v.push_back(h);
	}

	h = 0;

	for (int i = 1; i < N; i++) {
		int k = fly(0, i, N - 1, N, S);
		h = max(h, k);
	}

	for (int i = N - 2; i >= 0; i--) {
		int k = fly(N - 1, i, 0, N, S);
		h = max(h, k);
	}

	for (int i = 1; i < N - 1; i++) {
		int k = fly(0, N - 1, i, N, S);
		h = max(h, k);
	}

	cout << h << '\n';
	return 0;
}