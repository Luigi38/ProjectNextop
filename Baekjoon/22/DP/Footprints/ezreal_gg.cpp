#define CALIBRATION 1000000007
#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

struct option {
	vector<int> result;
	vector<ull> v;
};

void dfs(const int select, const int index, const int N, option& op) {
	op.result.push_back(select);

	if (index == N - 1) {
		ull gg = 0ULL;

		for (int i = 0; i < op.result.size(); i++) gg = 10 * gg + op.result[i];
		op.v.push_back(gg);
	}
	else {
		dfs(1, index + 1, N, op);
		dfs(5, index + 1, N, op);
	}

	op.result.pop_back();
}

int mc_send_note(const vector<ull>& v) {
	int count = 0;

	for (ull gg : v) if (gg % 15 == 0) count++;
	return count % CALIBRATION;
}

int league_of_legends(const int N, vector<ull>& dp, vector<ull>& dp2) {
	for (int n = 2; n <= N; n++) {
		for (int i = 0; i < 15; i++) {
			//(10A + B) % 15 == ((10A % 15) + (B % 15)) % 15
			//(10 * A) % 15 == ((10 % 15) * (A % 15)) % 15
			//(10 * A) % 15 == (10 * (A % 15)) % 15
			// 10Am15 = (10 * (A % 15)) % 15
			//=> (10A + B) % 15 == (10Am15 + (B % 15)) % 15
			//see details at https://boj.kr/10430

			if (dp[i] == 0) continue;

			int TAm15 = (10 * i) % 15;
			int index = (TAm15 + 1) % 15;
			int index2 = (TAm15 + 5) % 15;

			dp2[index] += dp[i];
			dp2[index2] += dp[i];
		}

		dp.clear();
		dp = dp2;

		dp2.clear();
		dp2.assign(15, 0ULL);
	}

	return dp[0] % CALIBRATION;
}

bool part_of_monte_carlo(const int N, vector<ull>& dp, vector<ull>& dp2) {
	int gg1 = league_of_legends(N, dp, dp2);
	int gg2 = 0;

	option op = { vector<int>(), vector<ull>() };
	dfs(1, 0, N, op);

	op = { vector<int>(), op.v };
	dfs(5, 0, N, op);

	gg2 = mc_send_note(op.v);

	if (gg1 == gg2) cout << "OK! (" << N << ", gg = " << gg1 << ")\n";
	else cout << "WTF!!! (" << N << ", gg1 = " << gg1 << ", gg2 = " << gg2 << ")\n";

	return gg1 == gg2;
}

void monte_carlo(const int N, vector<ull>& dp, vector<ull>& dp2) {
	vector<ull> backup_dp(dp);
	vector<ull> backup_dp2(dp2);

	for (int n = 1; n <= N; n++) {
		part_of_monte_carlo(n, dp, dp2);

		dp = backup_dp;
		dp2 = backup_dp2;
	}
}

int main() {
	int N;
	vector<ull> dp(15, 0ULL); //remainder count (index : 0 ~ 14)
	vector<ull> dp2(15, 0ULL);

	dp[1]++;
	dp[5]++;

	cin >> N;
	cout << league_of_legends(N, dp, dp2) << '\n';
	//monte_carlo(N, dp, dp2);
	//part_of_monte_carlo(N, dp, dp2);

	return 0;
}