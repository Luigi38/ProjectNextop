#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct fs {
	vector<int> result;
	vector<int> outv;
	int hap;
};

void dfs(const int index, const int N, const int select, const vector<int>& g, fs& dummy) {
	if (index >= N) {
		if (dummy.hap > 0) dummy.outv.push_back(dummy.hap);
		return;
	}

	dummy.result.push_back(select);
	if (select == 1) dummy.hap -= g[index]; //left
	else if (select == 2) dummy.hap += g[index]; //right

	dfs(index + 1, N, 0, g, dummy);
	dfs(index + 1, N, 1, g, dummy);
	dfs(index + 1, N, 2, g, dummy);

	if (select == 1) dummy.hap += g[index]; //left
	else if (select == 2) dummy.hap -= g[index]; //right
	dummy.result.pop_back();
}

int get_impossible_number(const int S, const vector<int>& poss) { //no problem, test passed
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

	fs dummy = { vector<int>() , vector<int>(), 0 };
	dfs(0, k, 0, g, dummy);

	dummy = { vector<int>(), dummy.outv, 0 };
	dfs(0, k, 1, g, dummy);

	dummy = { vector<int>(), dummy.outv, 0 };
	dfs(0, k, 2, g, dummy);

	sort(dummy.outv.begin(), dummy.outv.end());

	auto outv_end = unique(dummy.outv.begin(), dummy.outv.end());
	dummy.outv.erase(outv_end, dummy.outv.end());

	cout << get_impossible_number(S, dummy.outv) << '\n';
	return 0;
}