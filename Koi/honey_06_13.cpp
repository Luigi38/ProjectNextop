#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int fly(const int x1, const int x2, const int x3, const int N, const vector<int>& S, const vector<int>& max_v, const vector<int>& max_v_rev) {
	// x1: bee 1
	// x2: bee 2
	// x3: barrel
	
	int h = 0;

	if (x1 < x3) {
		h += max_v[x3] - max_v[x1];

		if (x2 < x3) {
			h -= S[x2];
		}
	}
	else {
		h += max_v_rev[x3] - max_v_rev[x1];

		if (x2 > x3) {
			h -= S[x2];
		}
	}

	// i + 1 => k ( k - i )
	// j + 1 => k ( k - j )

	// i - 1 => k ( k - i )
	// j - 1 => k ( k - j )

	if (x2 < x3) {
		h += max_v[x3] - max_v[x2];
	}
	else {
		h += max_v_rev[x3] - max_v_rev[x2];
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

	int h = 0;

	vector<int> max_v;
	vector<int> max_v_rev;

	for (int i = 0; i < N; i++) {
		h += S[i];
		max_v.push_back(h);
	}

	h = 0;

	for (int i = N - 1; i >= 0; i--) {
		h += S[i];
		max_v_rev.push_back(h);
	}
	reverse(max_v_rev.begin(), max_v_rev.end());

	h = 0;

	for (int x3 = 0; x3 < N; x3++) {
		for (int x2 = 1; x2 < N; x2++) {
			if (x3 == 0) {
				break;
			}
			if (x2 == x3) {
				continue;
			}

			int k = fly(0, x2, x3, N, S, max_v, max_v_rev);
			h = max(h, k);
		}

		for (int x2 = N - 2; x2 >= 0; x2--) {
			if (x3 == N - 1) {
				break;
			}
			if (x2 == x3) {
				continue;
			}

			int k = fly(N - 1, x2, x3, N, S, max_v, max_v_rev);
			h = max(h, k);
		}

		if (x3 == 0 || x3 == N - 1) {
			continue;
		}

		int k = fly(0, N - 1, x3, N, S, max_v, max_v_rev);
		h = max(h, k);
	}

	cout << h << '\n';
	return 0;
}