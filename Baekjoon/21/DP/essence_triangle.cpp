#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<vector<int>> ET;

int select(const int a, const int b, const int n, const ET& et, ET& dp) {
	if (b < 0 || b > a) {
		return 0;
	}
	if (dp[a][b] != -1) {
		return dp[a][b];
	}

	dp[a][b] = max(select(a - 1, b - 1, n, et, dp), select(a - 1, b, n, et, dp)) + et[a][b];
	return dp[a][b];
}

int main() {
	ET et;
	ET dp;
	int n;

	cin >> n;
	et = ET(n, vector<int>());
	dp = ET(n, vector<int>());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int essence;
			cin >> essence;

			et[i].push_back(essence);
			dp[i].push_back(-1);
		}
	}

	dp[0][0] = et[0][0];

	int count = 0;

	for (int i = 0; i < n; i++) {
		count = max(count, select(n - 1, i, n, et, dp));
	}

	cout << count << '\n';
	return 0;
}