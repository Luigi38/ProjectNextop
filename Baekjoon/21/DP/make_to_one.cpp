#include <iostream>
#include <vector>
using namespace std;

//x % 3 == 0 => x / 3
//x % 2 == 0 => x / 2
//x - 1

int make(const int N, vector<int>& dp) {
	if (dp[N] != -1) {
		return dp[N];
	}

	int count = make(N - 1, dp);

	if (N % 3 == 0) {
		count = min(count, make(N / 3, dp));
	}
	if (N % 2 == 0) {
		count = min(count, make(N / 2, dp));
	}

	dp[N] = count + 1;
	return dp[N];
}

int main() {
	int N;
	cin >> N;

	vector<int> dp(N + 1, -1);
	dp[1] = 0;

	cout << make(N, dp) << '\n';
	return 0;
}
