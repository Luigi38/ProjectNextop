#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//honey
	int N;
	vector<int> S;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int honey;
		cin >> honey;

		S.push_back(honey);
	}

	vector<int> max_v;
	vector<int> max_v_rev;

	int tmp = 0;

	for (int i = 0; i < N; i++) {
		tmp += S[i];
		max_v.push_back(tmp);
	}

	tmp = 0;

	for (int i = N - 1; i >= 0; i--) {
		tmp += S[i];
		max_v_rev.push_back(tmp);
	}
	reverse(max_v_rev.begin(), max_v_rev.end());

	int dog_honey = 0;

	for (int i = 0; i < N; i++) { //honey bee 1
		for (int j = i + 1; j < N; j++) { //honey bee 2
			for (int k = 0; k < N; k++) { //honey barrel
				if (i == k || j == k) continue;

				int h = 0;

				if (i < k) {
					h += max_v[k] - max_v[i];

					if (j < k) {
						h -= S[j];
					}
				}
				else {
					h += max_v_rev[k] - max_v_rev[i];

					if (j > k) {
						h -= S[j];
					}
				}

				// i + 1 => k ( k - i )
				// j + 1 => k ( k - j )

				// i - 1 => k ( k - i )
				// j - 1 => k ( k - j )

				if (j < k) {
					h += max_v[k] - max_v[j];
				}
				else {
					h += max_v_rev[k] - max_v_rev[j];
				}

				dog_honey = max(dog_honey, h);
			}
		}
	}

	cout << dog_honey << '\n';
	return 0;
}