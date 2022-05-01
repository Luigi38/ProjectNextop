#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct crossed {
	int p;
	pair<int, int> range;
};

void rotate(const int N, vector<pair<int, int>>& v) {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		v[i].first = y;
		v[i].second = -x;
	}
}

int check_availability(const vector<crossed>& div, const pair<int, int>& range) {
	vector<int> prefix(range.second - range.first + 2, 0);

	for (int i = 0; i < div.size(); i++) {
		//prefix indicies
		int pis = div[i].range.first - range.first;
		int pie = div[i].range.second - range.first + 1;

		prefix[pis]++;
		prefix[pie]--;
	}

	int sum = 0;
	int available = 0;

	for (int i = 0; i < prefix.size(); i++) {
		sum += prefix[i];
		available = max(available, sum);
	}

	return available;
}

int get_max_crossed_h(const int N, vector<pair<int, int>>& v) {
	vector<crossed> div;
	pair<int, int> range;

	int prev = v[0].second;
	int start = v[0].second;
	int end = -655360;
	int step = 0;

	if (prev == v[1].second) {
		step = 0;
		start = v[1].second;
		end = v[0].second;
	}
	else {
		step = 1;
	}

	//sort by x
	for (int i = 1; i < N; i++) {
		range.first = min(range.first, v[i].second);
		range.second = max(range.second, v[i].second);

		if (i == N - 1 && end != -655360) {
			int y1 = min(v[i].second, end);
			int y2 = max(v[i].second, end);

			div.push_back({ v[i].first, { v[i].second, end } });
			break;
		}

		if (step == 0) {
			start = v[i].second;
			step++;
		}
		else {
			int y1 = min(start, v[i].second);
			int y2 = max(start, v[i].second);

			div.push_back({ v[i].first, { y1, y2 } });
			step = 0;
		}
	}

	return check_availability(div, range);
}

int get_max_crossed(const int N, vector<pair<int, int>>& v) {
	int H, V;

	H = get_max_crossed_h(N, v);

	rotate(N, v);
	V = get_max_crossed_h(N, v);

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