#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int value;

		cin >> value;
		v.push_back(value);
	}

	vector<int> dp(n);

	int m = v[0];
	dp[0] = v[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		m = max(m, dp[i]);
	}

	cout << m << '\n';
	return 0;
}