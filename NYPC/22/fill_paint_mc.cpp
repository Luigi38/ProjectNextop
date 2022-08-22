#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int fill_H(vector<vector<int>>& v, const int index, const int color) {
	int prev_color = 0;

	for (int i = 0; i < v[index].size(); i++) {
		if (prev_color == 0 && v[index][i] != 0) prev_color = v[index][i];
		v[index][i] = color;
	}

	return prev_color;
}

int fill_V(vector<vector<int>>& v, const int index, const int color) {
	int prev_color = 0;

	for (int i = 0; i < v.size(); i++) {
		if (prev_color == 0 && v[i][index] != 0) prev_color = v[i][index];
		v[i][index] = color;
	}

	return prev_color;
}

int is_path_H(const vector<vector<int>>& v, const int index) {
	int footprint = 0;

	for (int i = 0; i < v[index].size(); i++) {
		if (v[index][i] != 0) footprint++;
	}

	return footprint;
}

int is_path_V(const vector<vector<int>>& v, const int index) {
	int footprint = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i][index] != 0) footprint++;
	}

	return footprint;
}

int is_annoyed_H(const vector<vector<int>>& v, const int index) {
	int footprint = 0;
	int color = 0;

	for (int i = 0; i < v[index].size(); i++) {
		if (color == 0 && color != v[index][i]) color = v[index][i];
		if (v[index][i] != 0) footprint++;
		if (color != 0 && v[index][i] != 0 && color != v[index][i]) return 0;
	}

	return footprint;
}

int is_annoyed_V(const vector<vector<int>>& v, const int index) {
	int footprint = 0;
	int color = 0;

	for (int i = 0; i < v.size(); i++) {
		if (color == 0 && color != v[i][index]) color = v[i][index];
		if (v[i][index] != 0) footprint++;
		if (color != 0 && v[i][index] != 0 && color != v[i][index]) return 0;
	}

	return footprint;
}

string get_filled_output(const char hv, const int index, const int color) {
	stringstream ss;

	ss << hv << ' ' << index + 1 << ' ' << color;
	return ss.str();
}

bool pop_annoyed(const int N, const int M, vector<vector<int>>& v, stack<string>& s) {
	bool popped = false;
	vector<pair<int, pair<char, int>>> hv;

	for (int i = 0; i < N; i++) {
		int footprint = is_annoyed_H(v, i);
		if (footprint > 0) hv.push_back({ footprint, { 'H', i } });
	}

	for (int i = 0; i < M; i++) {
		int footprint = is_annoyed_V(v, i);
		if (footprint > 0) hv.push_back({ footprint, { 'V', i } });
	}

	sort(hv.begin(), hv.end(), greater<>());

	for (pair<int, pair<char, int>>& h : hv) {
		if (h.second.first == 'H') {
			int color = fill_H(v, h.second.second, 0);

			s.push(get_filled_output('H', h.second.second, color));
		}
		else if (h.second.first == 'V') {
			int color = fill_V(v, h.second.second, 0);

			s.push(get_filled_output('V', h.second.second, color));
		}

		if (!popped) popped = true;
		break;
	}

	return popped;
}

bool equals_with(const int N, const int M, const vector<vector<int>>& v, stack<string>& s) {
	vector<vector<int>> v2(N, vector<int>(M, 0));

	while (!s.empty()) {
		char hv = s.top()[0];
		int number = 0;
		int color = 0;

		for (int i = 2; i < s.top().size() - 1; i++) {
			if (s.top()[i] != ' ') number = number * 10 + s.top()[i] - '0';
			else color = s.top()[i + 1] - '0';
		}

		if (hv == 'H') fill_H(v2, number - 1, color);
		else if (hv == 'V') fill_V(v2, number - 1, color);

		s.pop();
	}

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (v[i][j] != 0 && v[i][j] != v2[i][j]) return false;
	return true;
}

int main() {
	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;

		vector<vector<int>> v;
		stack<string> s;

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			vector<int> h;

			for (int j = 0; j < M; j++) {
				int color;

				cin >> color;
				h.push_back(color);
			}
			v.push_back(h);
		}

		vector<vector<int>> vc(v);

		while (true) if (!pop_annoyed(N, M, v, s)) break;
		cout << "Case #" << t + 1 << ": " << (equals_with(N, M, vc, s) ? "MC" : "NMC") << '\n';
	}

	return 0;
}