#include <iostream>
#include <vector>
using namespace std;

int rise(const int i, vector<vector<int>>& dp, vector<int>& stairs) {
	for (int i = 1; i < dp.size(); i++) {
		int im20 = i - 2 < 0 ? 0 : dp[i - 2][0];
		int im21 = i - 2 < 0 ? 0 : dp[i - 2][1];

		dp[i][0] = max(im20, im21) + stairs[i]; 
		dp[i][1] = dp[i - 1][0] + stairs[i];
	}

	return max(dp[dp.size() - 1][0], dp[dp.size() - 1][1]);
}

int main() {
	vector<int> stairs;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int score;
		cin >> score;

		stairs.push_back(score);
	}

	vector<vector<int>> dp(N, vector<int>(2));
	dp[0][0] = stairs[0];

	cout << rise(N, dp, stairs) << '\n';
	return 0;
}