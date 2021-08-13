#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<vector<int>> ET;
struct MaxResult {
	vector<int> indicies;
	int count;
};

MaxResult max_of_max(vector<int>& v) {
	if (v.size() == 0) {
		return { vector<int>(), 0 };
	}

	MaxResult mr = { vector<int>(1, 0), v[0] };

	for (int i = 1; i < v.size(); i++) {
		int prev = mr.count;
		mr.count = max(mr.count, v[i]);

		if (mr.count != prev) {
			mr.indicies = vector<int>();
			mr.indicies.push_back(i);
		}
		else if (mr.count == v[i]) {
			mr.indicies.push_back(i);
		}
	}

	return mr;
}

int select(const int n, const ET& et) {
	//DYNAMIC PROGRAMMING
	
	ET dp(n, vector<int>(4, -1));
	vector<int> posv;
	
	for (int i = 0; i < 4; i++) {
		dp[0][i] = et[0][0];
	}
	posv.push_back(0);

	for (int i = 1; i < n; i++) {
		int ets = et[i].size();

		for (int j = 0; j < posv.size(); j++) {
			int count = 0;
			int pos = posv[j];

			int posp1 = pos + 1 > ets - 1 ? 0 : et[i][pos + 1];
			int posp2 = pos + 2 > ets - 1 ? 0 : et[i][pos + 2];

			dp[i][0] = dp[i - 1][0] + et[i][pos];
			dp[i][1] = dp[i - 1][0] + posp1;

			dp[i][2] = dp[i - 1][1] + posp1;
			dp[i][3] = dp[i - 1][1] + posp2;
		}

		MaxResult mr = max_of_max(dp[i]);
		posv = mr.indicies;
	}
	
	MaxResult mr = max_of_max(dp[n - 1]);
	return mr.count;
}

int main() {
	//ESSENCE REAVER

	ET et;
	int n;

	cin >> n;
	et = ET(n, vector<int>());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int essence;
			cin >> essence;

			et[i].push_back(essence);
		}
	}

	cout << select(n, et) << '\n';
	return 0;
}