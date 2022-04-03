#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct crossed {
	int p;
	vector<pair<int, int>> range;
};

bool compare_by_v(const pair<int, int>& a, const pair<int, int>& b) {
	return true;
}

int get_max_crossed_h(const int N, vector<pair<int, int>>& v) {
	vector<crossed> div;

	int prev_x = v[0].first;
	int start = v[0].second;
	int step = 0;

	div.push_back({ prev_x, vector<pair<int, int>>() });

	for (int i = 1; i < N; i++) {
		if (prev_x == v[i].first) {
			if (step == 0) step++;
			else step = 0;

			if (step == 0) {
				start = v[i].second;
			}
			else {
				div[div.size() - 1].range.push_back({ start, v[i].second });
			}
		}
		else {
			div.push_back({ v[i].first, vector<pair<int, int>>() });
			start = v[i].second;

			step = 0;
			prev_x = v[i].first;
		}
	}

	return 0;
}

int get_max_crossed_v(const int N, vector<pair<int, int>>& v) {
	return 0;
}

int get_max_crossed(const int N, vector<pair<int, int>>& v) {
	int H, V;
	
	sort(v.begin(), v.end());
	H = get_max_crossed_h(N, v);

	sort(v.begin(), v.end());
	V = get_max_crossed_v(N, v);

	return max(H, V);
}

int main() {
	int N;
	vector<pair<int, int>> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;

		cin >> x >> y;
		v.push_back({ x, y });
	}

	cout << get_max_crossed(N, v) << '\n';
	return 0;
}