#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
	vector<int> max_v_rev;

	int h = 0;

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

	int bee1 = 0;
	int bee2 = N - 1;

	h = 0;

	for (int i = 0; i < N; i++) { //honey barrel
		int to_start = max_v[i];
		int to_end = max_v[N - 1] - max_v[i];

		if (to_start > to_end) {
			bee1 = i != 0 ? 0 : 1;
			bee2 = max_v[i] - max_v[1] > max_v[i] - max_v[2] ? 1 : 2;

			if (bee2 == i) {
				bee2 = bee2 != 1 ? 1 : 2;
			}
			if (bee1 == bee2) {
				bee2 = 2;
			}
		}
		else {
			bee1 = i != N - 1 ? N - 1 : N - 2;
			bee2 = to_end - max_v[N - 2] > to_end - max_v[N - 3] ? N - 2 : N - 3;

			if (bee2 == i) {
				bee2 = bee2 != N - 2 ? N - 2 : N - 3;
			}
			if (bee1 == bee2) {
				bee2 = N - 3;
			}
		}

		int bee1_fp = bee1 < i ? max_v[i] - max_v[bee2] : max_v_rev[i] - max_v_rev[bee2];
		int bee2_fp = bee2 < i ? max_v[i] - max_v[bee2] : max_v_rev[i] - max_v_rev[bee2];

		h = max(h, bee1_fp + bee2_fp);
		
		if (i != 0 && i != N - 1) {
			h = max(h, max_v[i] - max_v[0] + max_v[N - 2] - max_v[i - 1]);
		}
	}

	cout << h << '\n';
	return 0;
}