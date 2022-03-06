#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct fs {
	vector<bool> result;
	vector<int> outv;
};

void dfs(const int index, const int N, const bool select, const vector<int>& g, fs& dummy) {
	dummy.result.push_back(select);

	if (index >= N) {
		int gi = 0;

		for (int i = 0; i < N; i++) if (dummy.result[i]) gi += g[i];
		if (gi > 0) dummy.outv.push_back(gi);

		dummy.result.pop_back();
		return;
	}

	dfs(index + 1, N, false, g, dummy);
	dfs(index + 1, N, true, g, dummy);

	dummy.result.pop_back();
}

int get_impossible_number(const int S, const vector<int>& poss) {
	int count = 0;
	int i = 0;
	
	for (int n = 1; n <= S; n++) {
		if (poss[i] == n) i++;
		else count++;
	}
	
	return count;
}

int main() {
	int k;
	int S = 0;
	vector<int> g;

	cin >> k;

	for (int i = 0; i < k; i++) {
		int gi;
		cin >> gi;

		g.push_back(gi);
		S += gi;
	}

	for (int i = 0; i < k; i++) {
		g.push_back(-g[i]);
	}

	k *= 2;

	fs dummy = { vector<bool>() , vector<int>() };
	dfs(0, k, false, g, dummy);
	
	dummy = { vector<bool>(), dummy.outv };
	dfs(0, k, true, g, dummy);

	sort(dummy.outv.begin(), dummy.outv.end());

	auto outv_end = unique(dummy.outv.begin(), dummy.outv.end());
	dummy.outv.erase(outv_end, dummy.outv.end());

	cout << get_impossible_number(S, dummy.outv) << '\n';
	return 0;
}