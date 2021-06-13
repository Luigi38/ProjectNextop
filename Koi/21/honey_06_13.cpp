#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct MaxResult {
	int value;

	int x1;
	int x2;
};

MaxResult get_max(const MaxResult& value1, const MaxResult& value2) {
	int k = max(value1.value, value2.value);
	return k == value1.value ? value1 : value2;
}

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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int honey;
		cin >> honey;

		S.push_back(honey);
	}

	int h = 0;

	MaxResult mr1 = { 0, 0, 0 };
	MaxResult mr2 = { 0, 0, 0 };

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

	for (int x2 = 1; x2 < N - 1; x2++) {
		int k = fly(0, x2, N - 1, N, S, max_v, max_v_rev);
		mr1 = get_max(mr1, { k, 0, x2 });
	}

	for (int x2 = N - 2; x2 >= 0; x2--) {
		int k = fly(N - 1, x2, 0, N, S, max_v, max_v_rev);
		mr2 = get_max(mr2, { k, N - 1, x2 });
	}

	for (int x3 = 0; x3 < N; x3++) {
		int k = 0;

		k = fly(mr1.x1, mr1.x2, x3, N, S, max_v, max_v_rev);
		h = max(h, k);

		k = fly(mr2.x1, mr2.x2, x3, N, S, max_v, max_v_rev);
		h = max(h, k);

		if (x3 == 0) { //because of x1 (x2 is skipped)
			continue;
		}
		if (N % 2 == 0 && x3 > N / 2) { //even
			continue;
		}
		else if (N % 2 == 1 && x3 > N / 2 + 1) { //odd
			continue;
		}

		k = fly(0, N - 1, x3, N, S, max_v, max_v_rev);
		h = max(h, k);
	}

	cout << h << '\n';
	return 0;
}