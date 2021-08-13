#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct test_case {
	int k;
	vector<int> S;
	vector<bool> result;
	int result_true_count;
	vector<vector<int>> out_v;
} test_case;

void get_lotto_ball(const int index, const bool select, test_case& tc) {
	tc.result.push_back(select);
	if (select) {
		tc.result_true_count++;
	}

	if (index >= tc.k - 1) {
		if (tc.result_true_count == 6) {
			tc.out_v.push_back(vector<int>());

			for (int i = 0; i < tc.k; i++) {
				if (tc.result[i]) {
					tc.out_v[tc.out_v.size() - 1].push_back(tc.S[i]);
				}
			}
		}

		if (tc.result.back()) {
			tc.result_true_count--;
		}
		tc.result.pop_back();
		return;
	}

	get_lotto_ball(index + 1, false, tc);
	get_lotto_ball(index + 1, true, tc);

	if (tc.result.back()) {
		tc.result_true_count--;
	}
	tc.result.pop_back();
}

int main() {
	vector<test_case> v;

	while (1) {
		int k;
		vector<int> S;
		vector<bool> result;

		cin >> k;

		if (k == 0) {
			break;
		}

		for (int i = 0; i < k; i++) {
			int n;

			cin >> n;
			S.push_back(n);
		}

		v.push_back({ k, S, result, 0, vector<vector<int>>() });
	}

	for (size_t i = 0; i < v.size(); i++) {
		test_case tc = v[i];

		get_lotto_ball(0, false, tc);
		get_lotto_ball(0, true, tc);

		sort(tc.out_v.begin(), tc.out_v.end());

		for (size_t j = 0; j < tc.out_v.size(); j++) {
			vector<int> out = tc.out_v[j];

			for (int x : out) {
				cout << x << ' ';
			}
			if (i != v.size() - 1 || j != tc.out_v.size() - 1) {
				cout << '\n';
			}
		}

		if (i != v.size() - 1) {
			cout << '\n';
		}
	}

	return 0;
}
