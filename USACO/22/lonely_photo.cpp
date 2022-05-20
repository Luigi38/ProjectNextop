#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	string s;

	cin >> N >> s;

	vector<int> count_g(N, 0);
	vector<int> count_h(N, 0);
	vector<int> count_d(N, 0);
	int sum = 0;

	long long photos = 0;

	for (int i = 0; i < N; i++) {
		if (s[i] == 'G') sum++;
		count_g[i] = sum;
	}
	sum = 0;

	for (int i = 0; i < N; i++) {
		if (s[i] == 'H') sum++;
		count_h[i] = sum;
	}

	char prev = s[0];
	sum = 0;

	for (int i = 0; i < N; i++) {
		if (s[i] != prev) {
			sum++;
			prev = s[i];
		}

		count_d[i] = sum;
	}

	prev = s[0];

	for (int i = 0; i < N; i++) {
		auto current = count_d.begin() + i;

		if (s[i] != prev && i != N - 1 && s[i] != s[i + 1]) { //...G...
			auto left = lower_bound(count_d.begin(), count_d.end(), count_d[i - 1]);
			auto right = upper_bound(count_d.begin(), count_d.end(), count_d[i + 1]);
			right--;

			photos += (long long)(right - current) * (current - left);
		} //np
		if (i != N - 1 && s[i] != s[i + 1]) { //G...
			auto it = upper_bound(count_d.begin(), count_d.end(), count_d[i + 1]);
			it--;

			photos += (long long)(it - current) - 1;
		}
		if (s[i] != prev) { //...G
			auto it = lower_bound(count_d.begin(), count_d.end(), count_d[i - 1]);

			photos += (long long)(current - it) - 1;
			prev = s[i];
		}
		
	}

	cout << photos << '\n';
	return 0;
}