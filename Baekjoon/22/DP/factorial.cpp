#include <iostream>
#include <vector>
using namespace std;

int factorial(const int N, vector<int>& dp) {
	if (dp[N] != 0) return dp[N];

	dp[N] = N * factorial(N - 1, dp);
	return dp[N];
}

int main() {
	int N;
	vector<int> dp(13, 0);

	dp[0] = 1;

	cin >> N;
	cout << factorial(N, dp) << '\n';

	return 0;
}